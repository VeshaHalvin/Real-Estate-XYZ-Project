#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>


// Kustomisasi Tampilan
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE 	"\033[34m"
#define PINK 	"\x1b[38;5;206m"
#define LIGHTGREEN "\x1b[92m"

#define BG_GREEN "\x1b[42m"
#define BG_BLUE "\x1b[44m"
#define BG_MAGENTA "\x1b[45m"
#define BG_WHITE "\x1b[47m"

#define RESET   "\x1B[0m"
#define ANSI_BOLD_WHITE "\x1B[1;37m"



// Membuat tipe data & struktur data
typedef char string[100];

typedef struct Child* AddressChild;
typedef struct Parent* AddressParent;

typedef struct DataChild{
	int nomorProperti;
	string jenisProperti;
	string alamatProperti;
	float hargaProperti;
}DataChild; 

typedef struct DataParent{
	int NIPSales;
	string namaSales;
	int teleponSales;
    float totalPenjualan;
}DataParent;

typedef struct Child{
	DataChild dataChild;
	AddressChild next;
}NodeChild;

typedef struct Parent{
	DataParent dataParent;
	AddressParent next;
	
	AddressChild firstChild;
}NodeParent;

typedef struct{
	AddressParent firstParent;
}Multilist;


typedef struct Resign* AddressResign;

typedef struct Resign{
	AddressParent resign;
	AddressResign next;
}NodeResign;

typedef struct{
	AddressResign firstResign;
}List;



// Fungsi untuk list Parent
void createEmpty (Multilist *l);

bool isEmpty (Multilist l);
bool isOneElement (Multilist l);
bool haveChild (AddressParent ap);

DataParent makeDataParent (int NIP, string nama, int telepon);
AddressParent alokasiParent (DataParent data);
AddressParent findParent (Multilist l, int NIPCari);

bool isUniqueParent (Multilist l, int NIPCompare);
void insertFirstParent (Multilist *l, DataParent data);
void insertAfterParent (Multilist *l, int NIPCari, DataParent data);
void insertLastParent (Multilist *l, DataParent data);
void updateParent (AddressParent aUbah, string namaBaru, int teleponBaru);

void deleteFirstParent (Multilist *l);
void deleteAtParent (Multilist *l, int NIPCari);
void deleteLastParent (Multilist *l);
void deleteAllChild (AddressParent parent);

void printParent (AddressParent parent);
void printAll (Multilist l);
void printAllParent (Multilist l);



// Fungsi untuk list Child
DataChild makeDataChild (int nomorProperti, string jenisProperti, string alamatProperti, float hargaProperti);

AddressChild alokasiChild (DataChild data);
AddressChild findChild (AddressParent aCari, int nomorCari);

bool isUniqueChild (Multilist l, AddressParent aCompare, int NomorCompare);
void insertFirstChild (Multilist l, AddressParent aParent, DataChild data);
void insertAfterChild (Multilist l, AddressParent aParent, AddressChild aChild, DataChild data);
void insertLastChild (Multilist l, AddressParent aParent, DataChild data);
void updateChild (Multilist l, AddressParent aParent, AddressChild aUbah, string jenisBaru, string alamatBaru, float hargaBaru);

void deleteFirstChild (Multilist l, AddressParent aParent);
void deleteAtChild (Multilist l, AddressParent aParent, AddressChild aChild);
void deleteLastChild (Multilist l, AddressParent aParent);

void printChild (AddressChild child);
void printChildTanah (AddressChild child);
void printChildRumah (AddressChild child);
void printAllChild (AddressParent parent);
void printSortedChild(AddressParent parent);

int countChildTanah (AddressParent parent);
int countChildRumah (AddressParent parent);



// Fungsi Umum
void loadingAnimation ();
void pinkBox ();
void buatCover ();

void tampilMenu ();
void menuSales ();
void menuAdmin ();
void submenuSales ();
void submenuProp ();
void menuOwner ();

void createEmptyResign (List *r);
bool isEmptyResign (List r);
AddressResign alokasiResign (AddressParent pending);
void insertResign (List *r, AddressParent pending);
void approveResign (List *r, Multilist *l);
void printAllResign (List r);

