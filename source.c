#include "header.h"

void loadingAnimation (){
    int i, jeda;
	int percent, color;
    for (i = 0; i <= 50; i++) {
        percent = 2 * i;

        if(percent <= 10){
        	color = 31;
		} else if (percent <= 99) {
			color = 33;
		} else {
			color = 32;
		}                  

        jeda = (50 - 26) / 2;        
        
        printf("\r\033[%dm%*s %-60s %d%%\033[0m", color, jeda, " \t\t  ", " ##################################################", percent);
        
        fflush(stdout); usleep(50000); 
    }
	
    printf("\n\t\t\t\t\t\t Loading Complete!\n");
}

void pinkBox (){
    system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\t\t TEAM REAL ESTATE XYZ : \n\n");
    printf("\t\t\t\t\033[1;37m|     220711649 - VESHA HALVIN WINRICH CHANDRA             |\n" RESET);
    printf("\t\t\t\t\033[1;35m|     220711773 - ANTHONY ALVIN NATHANIEL                  |\n" RESET);
    printf("\t\t\t\t\033[1;34m|     220711883 - NOVELLA JESTINE ESTRELITA                |\n" RESET);
    printf("\t\t\t\t\033[0m");
    
    getch();
}


void buatCover (){
    int i, j, banner, leftMargin, rightMargin;

    for (i = 0; i < 27; i++) {
        printf(" ");
        banner= 22;
        leftMargin  = (120 - banner) / 2;
        rightMargin = 120 - leftMargin - banner;

        for (j = 1; j < leftMargin; j++) printf(" ");

        if (i == 14) printf("\x1B[1;37m REAL ESTATE XYZ \x1B[0m");
        else         printf(" ");

        for (j = 0; j < rightMargin; j++) printf(" ");
        
        printf(" \n ", 220);
    }
}

void tampilMenu (){
    printf("\n\t\t" GREEN "REAL ESTATE XYZ" RESET);
    printf("\n\t" YELLOW "[1] " RESET "Sales");
    printf("\n\t" YELLOW "[2] " RESET "Admin");
    printf("\n\t" YELLOW "[3] " RESET "Owner");
    printf("\n\t" YELLOW "[0] " RESET "Exit");
}

void menuSales (){
	system("cls");
	printf("\n\t\t" BLUE "SALES REAL ESTATE XYZ" RESET);
	printf("\n\t [1] SHOW LIST PROPERTI");
	printf("\n\t [2] TRANSAKSI PENJUALAN PROPERTI");
	printf("\n\t [3] PENGUNDURAN DIRI");
	printf("\n\t [0] KELUAR");
}

void menuAdmin (){
    system("cls");
	printf("\n\t\t" YELLOW "ADMIN REAL ESTATE XYZ" RESET );
	printf("\n\t [1] SALES");
	printf("\n\t [2] PROPERTI");
    printf("\n\t [3] SHOW ALL DATA");
	printf("\n\t [0] KELUAR");
}

void submenuSales (){
	system("cls");
    printf("\n\t\t " YELLOW " [ADMIN] - MENU SALES" RESET );
	printf("\n\t [1] INPUT DATA SALES");
	printf("\n\t [2] EDIT DATA SALES");
	printf("\n\t [3] PEMECATAN SALES");
	printf("\n\t [4] KONFIRMASI PENGUNDURAN DIRI SALES");
	printf("\n\t [0] EXIT");
}


void submenuProp (){
	system("cls");
    printf("\n\t\t "YELLOW "[ADMIN] - MENU PROPERTI" RESET);
	printf("\n\t [1] INPUT PROPERTI");
	printf("\n\t [2] UPDATE DATA PROPERTI");
	printf("\n\t [0] EXIT");
}

void menuOwner (){
	printf("\n\t\t OWNER REAL ESTATE XYZ");
	printf("\n\t [1] SHOW DATA SALES & PROPERTI");
	printf("\n\t [2] DAFTAR PROPERTI");
	printf("\n\t [3] JUMLAH PROPERTI");
	printf("\n\t [0] KELUAR");
}

void createEmptyResign (List *r){
	r->firstResign = NULL;
}

bool isEmptyResign (List r){
	return r.firstResign == NULL;
}

AddressResign alokasiResign (AddressParent pending){
	AddressResign ar;

	ar = (AddressResign) malloc (sizeof(NodeResign));

    ar->resign = pending;
	ar->next = NULL;
	
	return ar;
}

void insertResign (List *r, AddressParent pending){
	AddressResign temp = alokasiResign(pending);
	
	temp->next = r->firstResign;
	r->firstResign = temp;
}

void approveResign (List *r, Multilist *l){
	if (!isEmptyResign((*r))){
		AddressResign del = r->firstResign;
		AddressParent approve = r->firstResign->resign;

        if (!haveChild(approve)){
            deleteAtParent(&(*l), approve->dataParent.NIPSales);
        } else {
            int nipTanggung;
            AddressParent tanggung;
            AddressChild temp;
            
			printf("\n");
            printAllParent(*l);
            printf("\n\t Pilih NIP Sales yang ingin ditanggungkan   : ");
            scanf("%d", &nipTanggung);
            tanggung = findParent((*l), nipTanggung);

            if (tanggung != NULL) {
                temp = approve->firstChild;
                while (temp != NULL) {
                    insertLastChild((*l), tanggung, makeDataChild(temp->dataChild.nomorProperti, temp->dataChild.jenisProperti, temp->dataChild.alamatProperti, temp->dataChild.hargaProperti));
                    temp = temp->next;
                }
                deleteAtParent(&(*l), approve->dataParent.NIPSales);
            }
        }
		
		r->firstResign = r->firstResign->next;
		free(del);
	}
}

void printAllResign (List r){
	AddressResign temp = r.firstResign;
	
	while (temp != NULL){
		printParent(temp->resign);
		
		printf("\n");
		temp = temp->next;
	}
}



 






