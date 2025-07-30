#include "header.h"

DataChild makeDataChild (int nomorProperti, string jenisProperti, string alamatProperti, float hargaProperti){
	DataChild data;

    data.nomorProperti = nomorProperti;
	strcpy(data.jenisProperti, jenisProperti);
	strcpy(data.alamatProperti, alamatProperti);
	data.hargaProperti = hargaProperti;
	
	return data;
}

AddressChild alokasiChild (DataChild data){
	AddressChild ac;

	ac = (AddressChild) malloc (sizeof(NodeChild));
	
	ac->next = NULL;
	ac->dataChild = data;
	
	return ac;
}

AddressChild findChild (AddressParent aCari, int nomorCari){
    AddressChild temp = NULL;

    temp = aCari->firstChild;

    while (temp != NULL){
        if (temp->dataChild.nomorProperti == nomorCari){
            return temp;
        }
        
        temp = temp->next;
		
    }
	return NULL;
}

bool isUniqueChild (Multilist l, AddressParent aCompare, int NomorCompare){
	AddressChild temp = aCompare->firstChild;
	
	while (temp != NULL){
		if (temp->dataChild.nomorProperti == NomorCompare){
			return false;
		}
		
		temp = temp->next;
	}
	
	return true;
}

void insertFirstChild (Multilist l, AddressParent aParent, DataChild data){
	if (aParent != NULL){
		AddressChild dataBaru = alokasiChild(data);
		dataBaru->next = aParent->firstChild;
		
		aParent->firstChild = dataBaru;
	}
}

void insertAfterChild (Multilist l, AddressParent aParent, AddressChild aChild, DataChild data){
    if (aParent != NULL){
		if (!haveChild(aParent)){
			insertFirstChild(l, aParent, data);
		} else {
			AddressChild temp = aParent->firstChild;
			AddressChild dataBaru = alokasiChild(data);
			
			while (temp->next != aChild){
				temp = temp->next;
			}
			
			temp->next = dataBaru;
		}
	}
}

void insertLastChild (Multilist l, AddressParent aParent, DataChild data){
	if (aParent != NULL){
		if (!haveChild(aParent)){
			insertFirstChild(l, aParent, data);
		} else {
			AddressChild temp = aParent->firstChild;
			AddressChild dataBaru = alokasiChild(data);
			
			while (temp->next != NULL){
				temp = temp->next;
			}
			
			temp->next = dataBaru;
		}
	}
}

void updateChild (Multilist l, AddressParent aParent, AddressChild aUbah, string jenisBaru, string alamatBaru, float hargaBaru){
    strcpy(aUbah->dataChild.alamatProperti, alamatBaru);
    strcpy(aUbah->dataChild.jenisProperti, jenisBaru);
    aUbah->dataChild.hargaProperti = hargaBaru;
}

void deleteFirstChild (Multilist l, AddressParent aParent){	
	if (aParent != NULL){
		if (haveChild(aParent)){
			AddressChild temp = aParent->firstChild;
			aParent->firstChild = aParent->firstChild->next;

			aParent->dataParent.totalPenjualan += temp->dataChild.hargaProperti;

			free(temp);
		}
	}
}

void deleteAtChild (Multilist l, AddressParent aParent, AddressChild aChild){
    if (aParent != NULL){
		if (haveChild(aParent)){
			if (aParent->firstChild->next == NULL){
				deleteFirstChild(l, aParent);
			} else {
				AddressChild temp = aParent->firstChild;
				AddressChild hapus;

				while (temp->next != NULL){
					if (temp->next == aChild){
						hapus = temp->next;
						temp->next = temp->next->next;

						aParent->dataParent.totalPenjualan += hapus->dataChild.hargaProperti;

						free(hapus);
						hapus = NULL;
					}
				}
			}
		}
	}
}

void deleteLastChild (Multilist l, AddressParent aParent){	
	if (aParent != NULL){
		if (haveChild(aParent)){
			if (aParent->firstChild->next == NULL){
				deleteFirstChild(l, aParent);
			} else {
				AddressChild temp = aParent->firstChild;
				
				while (temp->next->next != NULL){
					temp = temp->next;
				}
				
				aParent->dataParent.totalPenjualan += temp->next->dataChild.hargaProperti;

				free(temp->next);
				temp->next = NULL;
			}
		}
	}
}

void printChild (AddressChild child){
	printf("\n\n\t\t");
	printf("=== Properti %s === \n\t\t", child->dataChild.alamatProperti);
	printf("[-] Nomor Properti  : %d \n\t\t", child->dataChild.nomorProperti);
	printf("[-] Jenis Properti  : %s \n\t\t", child->dataChild.jenisProperti);
    printf("[-] Harga Properti  : %.2f \n\t\t", child->dataChild.hargaProperti);
}

void printChildTanah (AddressChild child){
    if (strcmpi(child->dataChild.jenisProperti, "Tanah") == 0){
    	printf("\n\n\t============ Properti Jenis 'Tanah' ============");
        printChild (child);
    }
}

void printChildRumah (AddressChild child){
	if (strcmpi(child->dataChild.jenisProperti, "Rumah") == 0){
		printf("\n\n\t============ Properti Jenis 'Rumah' ============");
        printChild (child);
    }
}

void printAllChild (AddressParent parent){
	AddressChild temp = parent->firstChild;
	
	while (temp != NULL){
		printChild(temp);
		temp = temp->next;
	}
}

void printSortedChild(AddressParent parent){
	AddressChild temp = parent->firstChild;
	
	while (temp != NULL){
		
		printChildTanah(temp);
		printChildRumah(temp);
		temp = temp->next;
	}
	printf("\n\n\t Jumlah properti jenis 'Tanah': %d", countChildTanah(parent));
	printf("\n\t Jumlah properti jenis 'Rumah': %d", countChildRumah(parent));
	printf("\n\t=================================================");
}

int countChildTanah (AddressParent parent){
    AddressChild temp = parent->firstChild;
	int counter = 0;

	while (temp != NULL){
		if (strcmpi(temp->dataChild.jenisProperti, "Tanah") == 0){
            counter++;
        }
		
		temp = temp->next;
	}

	return counter;
}

int countChildRumah (AddressParent parent){
    AddressChild temp = parent->firstChild;
	int counter = 0;

	while (temp != NULL){
		if (strcmpi(temp->dataChild.jenisProperti, "Rumah") == 0){
            counter++;
        }
		
		temp = temp->next;
	}

	return counter;
}


