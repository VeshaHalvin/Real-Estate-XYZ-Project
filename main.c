#include "header.h"

int main(){
    Multilist l;
    DataParent P;
    DataChild C;
    
    List daftarResign;

	AddressParent aSales, aSales2;
	AddressChild aProperti, temp;
    
    createEmpty(&l);
    createEmptyResign(&daftarResign);

    int menu, submenu, nip, telp, noProp, mProp, nipTanggung;
    int piljenis, cek, cekInput=0;
    int mnSales, mAdmin, mOwner, subMenuSales, subMenuProp, submenuAdmin, subMenuInput;
    float harga;
    char confirmResign;
    string nama, jenis, alamat, pass, confirm, user;
	
 	system("cls");
 	
	buatCover();
    
    loadingAnimation();
    getche();
    
    do{
        system("cls");
        tampilMenu();
        printf("\n\t>>> "); scanf("%d", &menu);

        switch(menu){
            case 1 :
                if(cekInput==0){
                    printf("\n\t\t"YELLOW "Belum Terdapat Sales [!]" RESET);
                }else{
                    system("cls");
                    printf("\n\t\t" BLUE "HI SALES REAL ESTATE XYZ" RESET);
                    printf("\n\t NIP Sales : ");scanf("%d",&nip); 
                    aSales =  findParent(l,nip);
                    if(aSales==NULL){
                        printf("\n\t Invalid, NIP tidak ditemukan");
                        break;
                    }else{
                        do{
                            menuSales();
                            printf("\n\t>>> "); scanf("%d",&mnSales);

                            switch(mnSales){
                                case 1:
                                	if(!haveChild(aSales)){
                                		printf("\n\t\t" YELLOW "[!] BELUM TERDAPAT PROPERTI [!] \n" RESET);
									}else {
									printAllChild(aSales);
									}   
                                break;

                                case 2:
                                	if(!haveChild(aSales)){
                                		printf("\n\t\t" YELLOW "[!] BELUM TERDAPAT PROPERTI [!] \n" RESET);
									}else {
	                                    printf("\n\t============= List Properti ============");
	                                    printAllChild(aSales);
	                                    
	                                    printf("\n\t Input No Properti Yang Ingin Dijual : ");scanf("%d", &noProp);
	
	                                    aProperti = findChild(aSales, noProp);
	
	                                    if(aProperti == NULL){
	                                        printf("\n\t" YELLOW "Properti Tidak Ditemukan" RESET);
	                                        break;
	                                    }else{
	                                        deleteAtChild(l, aSales, aProperti);
	                                        printf("\n\t\t"LIGHTGREEN " Properti Berhasil Terjual"RESET);
	                                    }
									}
                                		
                                break;


                                case 3:
                                    printf("\n\t============= PENGUNDURAN DIRI ============");

                                    printf("\n\t Kepada Yth. Real Estate XYZ");
                                    printf("\n\t Dengan pernyataan ini saya mengundurkan diri sebagai sales Real Estate XYZ");
                                    printf("\n\n\t Apakah Anda Yakin Akan Mengundurkan Diri [Y/N] : ");
                                    fflush(stdin);gets(confirm);
                                        if(strcmpi(confirm,"Y")==0){
                                            insertResign(&daftarResign, aSales);
                                            printf("\n\t Permintaan Pengunduran Diri Berhasil Dikirim");
                                        }else  if (strcmpi(confirm,"N")){
                                            printf("\n\t Permintaan Pengunduran Diri Dibatalkan");
                                        }
                                break;      

                                case 0:
                                    printf("\n\t\t[*] Kembali Ke Main Menu [*]");
                                break;   
                            }getch();
                        }while(mnSales!=0);
                    }
                }
            break;    

            case 2 :
                do{
                    system("cls");
                    printf("\n\t"PINK "\t [ADMIN] " RESET "REAL ESTATE XYZ ");
                    printf("\n\t[ User : admin  | Password : admin]");
                    printf("\n\n\tUser        : ");fflush(stdin);gets(nama);
                    printf("\n\tPassword    : ");fflush(stdin);gets(pass);
                    if(strcmpi(nama, "Admin")==0 && strcmpi(pass, "Admin")==0){
                        printf("\n\t" LIGHTGREEN "\t [+] Berhasil Masuk" RESET);
                        cek = 1;
                    }else if(strcmpi(nama, "--")==0 && strcmpi(pass, "--")==0){
                    	break;
					}else{
                        printf("\n\t[!] Username atau Password Salah [!]");
                    }getch();
                }while(cek==0);
                cek=0;
                	if(strcmpi(nama, "--")==0 && strcmpi(pass, "--")==0){
                	break;
					}
		                do{
		                    menuAdmin();
		                    printf("\n\t>>> ");scanf("%d", &submenuAdmin);
		
		                    switch(submenuAdmin){
		                        case 1:
		                            do{
		                                submenuSales();
		                                printf("\n\t>>> ");scanf("%d", &subMenuSales);
		
		                                switch(subMenuSales){
		                                    case 1:
		                                        do{
		                                            if (isEmpty(l)){
		                                                subMenuInput = 1;
		                                            } else {
		                                                printf("\n\t [1] Insert First");
		                                                printf("\n\t [2] Insert After");
		                                                printf("\n\t [3] Insert Last");
		                                                printf("\n\t>>> "); scanf("%d", &subMenuInput);
		                                            }
		
		                                            if(subMenuInput == 1 || subMenuInput == 2 || subMenuInput == 3){
		                                                break;
		                                            }else{
		                                                printf("\n\t Menu Tidak Tersedia !");
		                                            }
		                                        }while(true);
		                                        
		                                        do{
		                                            printf("\n\t Input NIP Sales   	: ");scanf("%d", &nip);
		                                                if (isUniqueParent(l, nip)){
		                                                    break;
		                                                } else {
		                                                    printf("\n\t\t\t");
		                                                    printf("[!] ID Harus Unik [!] \n");
		                                                }
		                                        } while (true);
		
		                                        do{
		                                            printf("\n\t Input Nama Sales	: ");fflush(stdin);gets(nama);
		                                                if(strlen(nama)==0){
		                                                    printf("\n\t Nama Tidak Boleh Kosong");
		                                                }	
		                                        }while(strlen(nama)==0);
		
		                                        do{
		                                            printf("\n\t Input No Telp		: ");scanf("%d", &telp);
		                                            if (telp>0){
		                                                break;
		                                            } else {
		                                                printf("\n\t\t\t");
		                                                printf("[!] No Telp Harus Isi [!] \n");
		                                            }
		                                        } while (true);
		
		                                        switch(subMenuInput){
		                                            case 1:
		                                                insertFirstParent(&l, makeDataParent(nip, nama, telp));
		                                            break;
		                                            case 2 :
		                                                printf("\n\t Insert Setelah NIP	: ");scanf("%d", &nipTanggung);
		                                                insertAfterParent (&l, nipTanggung, makeDataParent(nip, nama, telp));
		                                            break;
		                                            case 3:
		                                                insertLastParent (&l, makeDataParent(nip, nama, telp));
		                                            break;
		                                        }
		                                        cekInput++;
		                                        printf("\n\t\t" LIGHTGREEN "[+] Berhasil Input Sales" RESET);
		                                    break;
		                                    
		                                    case 2:
		                                        if(!isEmpty(l)){
		                                            printf("\n\t============= List Sales ============");
		                                            printAllParent(l);
		
		                                            printf("\n\t Input NIP Sales : ");scanf("%d",&nip);
		                                            aSales =  findParent(l,nip);
		
		                                            if(aSales==NULL){
		                                                printf("\n\t Sales Tidak Ditemukan");
		                                                break;
		                                            }
		                                            
		                                            do{
		                                                printf("\n\t\t Input Nama Sales	 : ");fflush(stdin);gets(nama);
			                                            if(strlen(nama)==0){
			                                                printf("\n\t Nama Tidak Boleh Kosong");
			                                            }	
		                                            }while(strlen(nama)==0);
		
		                                            do{
		                                                printf("\n\t\t Input No Telp	 	 : ");scanf("%d", &telp);
		                                                if (telp>0){
		                                                    break;
		                                                } else {
		                                                    printf("\n\t\t\t");
		                                                    printf("\n\t [!] No Telpon Harus Diisi [!] \n");
		                                                }
		                                            } while (true);
		                                                    updateParent(aSales, nama, telp);
		                                                    printf("\n\t\t" LIGHTGREEN "[+] Berhasil Edit Sales" RESET);
		                                        }else{
		                                            printf("\n\t\t\t");
		                                            printf(YELLOW "[!] List Masih Kosong [!] \n" RESET);
		                                        }
		                                    break;
		
		                                    case 3:
		                                        if (!isEmpty(l)) {
                                                    if (isOneElement(l)) {
		                                                printf("\n\t" YELLOW "[!]Hanya ada 1 Sales, Tidak Bisa Dipecat!");
		                                                break;
                                                    }
		                                            printf("\n\tPemecatan Sales");
		                                            printf("\n\tList Sales  : ");
		                                            printAllParent(l);
		                                            printf("\n\n\tPilih NIP Sales yang ingin dipecat    : ");
		                                            scanf("%d", &nip);
		                                    
		                                            aSales = findParent(l, nip);
		                                            printParent(aSales);
		                                            printAllChild(aSales);
		                                
		                                            if (!haveChild(aSales)) {
		                                                deleteAtParent(&l, nip);
		                                                break;
		                                            }
		                                
		                                            printf("\n\tPilih NIP Sales yang ingin ditanggungkan   : ");
		                                            scanf("%d", &nipTanggung);
		                                            aSales2 = findParent(l, nipTanggung);
		                                
		                                            if (aSales2 != NULL) {
		                                                temp = aSales->firstChild;
		                                                while (temp != NULL) {
		                                                    insertLastChild(l, aSales2, makeDataChild(temp->dataChild.nomorProperti, temp->dataChild.jenisProperti, temp->dataChild.alamatProperti, temp->dataChild.hargaProperti));
		                                                    temp = temp->next;
		                                                }
		                                                deleteAtParent(&l, nip);
		                                            }
		                                            printf("\n\t\t Berhasil Pindah Data");
		                                        }else{
		                                            printf("\n\t\t\t");
		                                            printf(YELLOW "[!] List Masih Kosong [!] \n" RESET);
		                                        }
		                                    break;
		
		                                    case 4:
		                                        if (!isEmptyResign(daftarResign)){
		                                            if(isOneElement(l)){
                                                        printf("\n\t[!]Hanya ada 1 Sales, Tidak Bisa Dipecat!");
		                                                break;
                                                    }
                                                    printAllResign(daftarResign);
		                                            printf("\n\t Approve Resign Terbaru (Y/N) ?"); confirmResign = getche();
		                                            
		                                            if (confirmResign == 'Y' || confirmResign == 'y'){
		                                                approveResign(&daftarResign, &l);
		                                                printf("\n\t" LIGHTGREEN " Berhasil Approve Resign!" RESET);
                                                        cekInput--;
		                                            }
		                                        } else {
		                                            printf("\n\t\t\t");
		                                            printf(YELLOW "[!] List Masih Kosong [!] \n" RESET);
		                                        }
		                                    break;

		                                    case 0:
		                                        printf("\n\t\t[*] Kembali.... ");
		                                    break;
		                                }getch();      
	                            	}while(subMenuSales!=0);
                            
                        break;

                        case 2:
                        	if(cekInput==0){
                        		printf("\n\t\t"YELLOW"[!] BELUM TERDAPAT SALES");
							}else{
								do{	
                                submenuProp();
                                printf("\n\t>>> ");scanf("%d", &subMenuProp);

	                                switch(subMenuProp){
	                                    case 1:
	                                        if(!isEmpty(l)){
	                                            if(l.firstParent!=NULL){
	                                                printf("\n\t============= List Sales ============");
	                                                printAllParent(l);
	                                            }
	
	                                            printf("\n\t Input NIP Sales : ");scanf("%d",&nip);
	                                            
	                                            aSales =  findParent(l,nip);
	
	                                            if(aSales==NULL){
	                                                printf("\n\t Sales Tidak Ditemukan");
	                                                break;
	                                            }else{
	                                                if(aSales->firstChild!=NULL){
	                                                    printf("\n\t============= List Properti ============");
	                                                    printAllChild(aSales);
	                                                }
	                                                
	                                                do{
	                                                    printf("\n\t[1] Insert First Properti");
	                                                    printf("\n\t[2] Insert Last Properti");
	                                                    printf("\n\t>>> ");scanf("%d", &mProp);
	                                                    if(mProp==1 || mProp==2){
	                                               			break;
	                                                    }else{
	                                                    	printf("\n\t Menu Tidak Tersedia !");
	                                                    }
	                                                }while(true);
	
	                                                do{
	                                                    printf("\n\t Nomor Properti : ");scanf("%d", &noProp);
	                                                    if (isUniqueChild(l, aSales, noProp)){
	                                                    break;
	                                                    } else {
		                                                    printf("\n\t\t\t");
		                                                    printf("[!] Nomor Properti Sudah Digunakan [!] \n");
	                                                    }
	                                                } while (true);
	
	                                                do{
	                                                    cek = 0;
	                                                    
	                                                    printf("\t\t");
	                                                    printf("\n\t Input Jenis Properti : ");
	                                                    printf("\n\t\t [1] Tanah");
	                                                    printf("\n\t\t [2] Rumah");
	                                                    printf("\n\t\t >>> ");(scanf("%d", &piljenis));
	                                        
	                                                    if (piljenis == 1){
	                                                        strcpy(jenis, "Tanah");
	                                                        cek = 1;
	                                                    } else if (piljenis == 2) {
	                                                        strcpy(jenis, "Rumah");
	                                                        cek = 1;
	                                                    } else {
	                                                        printf("\n\t\t [!] Hanya Dapat Memilih Tanah atau Rumah");
	                                                    }
	                                                }while(cek == 0);
	
	                                                do{
	                                                    printf("\n\t Input Harga Properti : "); scanf("%f", &harga);
	                                                    if (harga > 0){
	                                                        break;
	                                                    } else {
	                                                        printf("[!] Harga Tidak Boleh Dibawah Nol [!] \n");
	                                                    }
	                                                } while (true); 
	
	                                                do{
	                                                    printf("\t\t");
	                                                    printf("\n\t Input Alamat Properti : "); fflush(stdin);gets(alamat);
	                                                    if (strlen(alamat) != 0){
	                                                        break;
	                                                    } else {
	                                                        printf("\n\t\t\t");
	                                                        printf("[!] Alamat Tidak Boleh Kosong [!] \n");
	                                                    }
	                                                } while (true); 
	
	                                                switch(mProp){
	                                                    case 1 :
	                                                        insertFirstChild (l, aSales, makeDataChild(noProp,jenis,alamat,harga));
	                                                    break;                            
	                                                    
	                                                    case 2 :
	                                                        insertLastChild(l,aSales, makeDataChild(noProp,jenis,alamat,harga));
	                                                    break;
	                                                }
                                                    
	                                                printf("\n\t\t" LIGHTGREEN "[+] Berhasil Input Properti" RESET);
	                                            }
	                                        } else {
	                                            printf("\n\t\t\t");
	                                            printf(YELLOW "[!] List Masih Kosong [!] \n" RESET);
	                                        }
	                                    break;
	
	                                    case 2:
	                                        if(!isEmpty(l)){
                                                if(l.firstParent->firstChild==NULL){
                                                        printf("\n\t"YELLOW"[!] Belum Terdapat Properti "RESET);
                                                        break;
                                                }
                                                    printf("\n\t============= List Sales ============");
                                                    printAllParent(l);
        
                                                    printf("\n\t Input NIP Sales : ");scanf("%d",&nip);
                                                    aSales =  findParent(l,nip);
	                                                    if(aSales==NULL){
	                                                        printf("\n\t" YELLOW "[!] Sales Tidak Ditemukan" RESET);
	                                                        break;
	                                                    }else{
	                                                            printf("\n\t============= List Properti ============");
	                                                            printAllChild(aSales);
	            
	                                                            printf("\n\t Nomor Properti : ");scanf("%d", &noProp);
	                                                            aProperti = findChild(aSales, noProp);
	                                                            if(aSales==NULL){
	                                                                printf("\n\t" YELLOW "[!] Properti Tidak Ditemukan" RESET);
	                                                                break;
	                                                            }else{
	                                                                do{
	                                                                    cek = 0;
	                                                                    
	                                                                    printf("\t\t");
	                                                                    printf("\n\t Input Jenis Properti : ");
	                                                                    printf("\n\t\t [1] Tanah");
	                                                                    printf("\n\t\t [2] Rumah");
	                                                                    printf("\n\t\t >>> ");(scanf("%d", &piljenis));
	                                                        
	                                                                    if (piljenis == 1){
	                                                                        strcpy(jenis, "Tanah");
	                                                                        cek = 1;
	                                                                    } else if (piljenis == 2) {
	                                                                        strcpy(jenis, "Rumah");
	                                                                        cek = 1;
	                                                                    } else {
	                                                                        printf("\n\t\t [!] Hanya Dapat Memilih Tanah atau Rumah");
	                                                                    }
	                                                                }while(cek == 0);
	            
	                                                                do{
	                                                                    printf("\t\t");
	                                                                    printf("Input Alamat Properti : "); fflush(stdin);gets(alamat);
	                                                                    if (strlen(alamat) != 0){
	                                                                        break;
	                                                                    } else {
	                                                                        printf("\n\t\t\t");
	                                                                        printf("[!] Alamat Tidak Boleh Kosong [!] \n");
	                                                                    }
	                                                                } while (true); 
	            
	                                                                do{
	                                                                    printf("\t\t");
	                                                                    printf("Input Harga Properti : "); scanf("%f", &harga);
	                                                                    if (harga > 0){
	                                                                        break;
	                                                                    } else {
	                                                                        printf("\n\t\t\t");
	                                                                        printf("[!] Harga Tidak Boleh Dibawah Nol [!] \n");
	                                                                    }
	                                                                } while (true);
	                                                                updateChild(l, aSales, aProperti, jenis, alamat, harga);
	                                                                printf("\n\t" LIGHTGREEN "Data Properti %d Berhasil Diubah"RESET, aProperti->dataChild.nomorProperti);
	                                                            }
	                                                    }
	                                        }else{
	                                            printf("\n\t\t\t");
	                                            printf(YELLOW "[!] List Masih Kosong [!] \n" RESET);
	                                        }
	                                    break;
	
	                                    case 0:
	                                        printf("\n\t\t[*] Kembali.... ");
	                                    break;
	                                }getch();
                            	}while(subMenuProp!=0); 
							}
                            
                        break;

                        case 3:
                            if (!isEmpty(l)){
                                printAllnotSorted(l);
                            }else{
                                printf("\n\t\t\t");
		                        printf(YELLOW "[!] List Masih Kosong [!] \n" RESET);
                            }
                        break;
                        case 0:
		                    printf("\n\t\t[*] Kembali.... ");
		                break;
                        
                    }getch();
                }while(submenuAdmin!=0);
            break;

            case 3 :
                system("cls");
                printf("\n\t\t OWNER REAL ESTATE XYZ ");
                printf("\n\t[ User : owner  | Password : owner]");
            	printf("\n\n\t User      : ");fflush(stdin);gets(user);
                printf("\n\t Password  : ");fflush(stdin);gets(pass);
            	if(strcmpi(user,"Owner")==0 && strcmpi(user, "owner")==0){
            		do{
                    	system("cls");
                        menuOwner();
                        printf("\n\t >>> ");scanf("%d", &mOwner);
                        
                        switch(mOwner){
                            case 1 : 
                            	if(!isEmpty(l)){
                                	printAll(l);
                                }else{
                           			printf("\n\t\t" YELLOW "[!] Belum Terdapat Sales" RESET);
								}
                            break;

                            case 2 :
                            	if(!isEmpty(l)){
	                                printf("\n\tMasukan NIP Sales   : ");scanf("%d", &nip);
	                                aSales =  findParent(l,nip);
	                                	if(aSales != NULL){
	                                		if (!haveChild(aSales)) {
                        						printf("\n\t\t" YELLOW "[!] Belum Terdapat Properti" RESET);
                    						} else {
	                                		printAllChild(aSales);
	                                		}
										}else{
											printf("\n\t\t" YELLOW "[!] Tidak Terdapat Sales Dengan NIP Tersebut" RESET);
										}
	                                
                           		}else{
                           			printf("\n\t\t" YELLOW "[!] Belum Terdapat Sales" RESET);
								}
                            break;

                            case 3 :
                            	if(!isEmpty(l)){
	                            	if(l.firstParent->firstChild==NULL){
	                                    printf("\n\t\t"YELLOW"[!] Belum Terdapat Properti "RESET);
	                                    break;
	                            	}
	                                printSortedChild(aSales);
	                            }else{
	                            	printf("\n\t\t" YELLOW "[!] Belum Terdapat Sales" RESET);
								}
                            break;
                            
                            case 0:
		                        printf("\n\t\t[*] Kembali.... ");
		                    break;	
                        }getch();
					}while(mOwner!=0);	
				}else{
                    printf("\n\t Username atau Password Yang Dimasukkan Salah [!]");
                }
            break;

            case 0 :
            	pinkBox();
            break;
            	
        }getche();
    }while(menu!=0);
return 0;   
}


