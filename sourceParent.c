#include "header.h"

#include <stdio.h>
#include <unistd.h>

void createEmpty (Multilist *l){
	l->firstParent = NULL;
}

bool isEmpty (Multilist l){
	return l.firstParent == NULL;
}

bool isOneElement (Multilist l){
    return l.firstParent->next == NULL;
}

bool haveChild (AddressParent ap){
	return ap->firstChild != NULL;
}

DataParent makeDataParent (int NIP, string nama, int telepon){
	DataParent data;
	
    data.NIPSales = NIP;
	strcpy(data.namaSales, nama);
	data.teleponSales = telepon;
    data.totalPenjualan = 0;
	
	return data;
}

AddressParent alokasiParent (DataParent data){
	AddressParent ap;
	
	ap = (AddressParent) malloc (sizeof(NodeParent));
	
	ap->next = NULL;
	ap->firstChild = NULL;
	ap->dataParent = data;
	
	return ap;
}

AddressParent findParent (Multilist l, int NIPCari){
	AddressParent temp = NULL;
	
	temp = l.firstParent;
	
    while (temp != NULL){
        if (temp->dataParent.NIPSales == NIPCari){
            return temp;
        }
        
        temp = temp->next;
    }
    return NULL;
}

bool isUniqueParent (Multilist l, int NIPCompare){
	AddressParent temp = l.firstParent;
	
	while (temp != NULL){
		if (temp->dataParent.NIPSales == NIPCompare){
			return false;
		}
		
		temp = temp->next;
	}
	
	return true;
}

void insertFirstParent (Multilist *l, DataParent data){
	AddressParent temp = alokasiParent(data);
	
	temp->next = l->firstParent;
	l->firstParent = temp;
}

void insertAfterParent (Multilist *l, int NIPCari, DataParent data){
	AddressParent dataBaru = alokasiParent(data);
	
	if (!isEmpty(*l)){
		AddressParent temp = findParent(*l, NIPCari);
		
		if (temp != NULL){
			dataBaru->next = temp->next;
			temp->next = dataBaru;
		}
	}
}

void insertLastParent (Multilist *l, DataParent data){
	AddressParent dataBaru = alokasiParent(data);
	
	if (isEmpty(*l)){
		insertFirstParent(l, data);
	} else {
		AddressParent temp = l->firstParent;
		
		while (temp->next != NULL){
			temp = temp->next;
		}
		
		temp->next = dataBaru;
	}
}

void updateParent (AddressParent aUbah, string namaBaru, int teleponBaru){
    strcpy(aUbah->dataParent.namaSales, namaBaru);
    aUbah->dataParent.teleponSales = teleponBaru;
}

void deleteFirstParent (Multilist *l){
	AddressParent temp = l->firstParent;
	
	if (!isEmpty(*l)){
		deleteAllChild(temp);
		
		l->firstParent = l->firstParent->next;
		free(temp);
	}
}

void deleteAtParent (Multilist *l, int NIPCari){
	AddressParent temp = l->firstParent;
	AddressParent hapus;
	
	if (!isEmpty(*l)){
		if (temp->dataParent.NIPSales == NIPCari){
			deleteFirstParent(l);
		} else {
			while (temp->next != NULL){
				if (temp->next->dataParent.NIPSales == NIPCari){
					hapus = temp->next;
					temp->next = temp->next->next;
					
					deleteAllChild(hapus);
					free(hapus);
					
					hapus = NULL;
					break;
				}
				
				temp = temp->next;
			}
		}
	}
}

void deleteLastParent (Multilist *l){
	AddressParent temp = l->firstParent;
	
	if (!isEmpty(*l)){
		if (temp->next == NULL){
			deleteFirstParent(l);
		} else {
			while (temp->next->next != NULL){
				temp = temp->next;
			}
			
			deleteAllChild(temp->next);
			free(temp->next);
			
			temp->next = NULL;
		}
	}
}

void deleteAllChild (AddressParent parent){
	AddressChild temp;
	
	while (haveChild(parent)){
		temp = parent->firstChild;
		parent->firstChild = parent->firstChild->next;
		
		free (temp);
	}
}

void printParent (AddressParent parent){
	printf("\n\t");
	printf("=== Sales %s === \n\t", parent->dataParent.namaSales);
	printf("[-] NIP Sales           : %d \n\t", parent->dataParent.NIPSales);
    printf("[-] Nomor Telepon Sales : %d \n\t", parent->dataParent.teleponSales);
    printf("[-] Total Penjualan     : %.2f \n\t", parent->dataParent.totalPenjualan);
}

void printAll (Multilist l){
	AddressParent temp = l.firstParent;
	
	while (temp != NULL){
		printParent (temp);
		printSortedChild (temp);
		
		printf("\n");
		temp = temp->next;
	}
}

void printAllnotSorted(Multilist l){
	AddressParent temp = l.firstParent;
	
	while (temp != NULL){
		printParent (temp);
		printAllChild (temp);
		
		printf("\n");
		temp = temp->next;
	}
}

void printAllParent (Multilist l){
	AddressParent temp = l.firstParent;
	
	while (temp != NULL){
		printParent(temp);
		
		printf("\n");
		temp = temp->next;
	}
}
