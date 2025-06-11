// odebere atribut ReadOnly u vybraneho souboru nebo adresare
#include <iostream>
#include <windows.h>

using namespace std;

LPCSTR cesta_soubor; // tohle nevim co je za datovej typ ( LPCSTR )

int main(int argc, char** argv) {
    
    // zpracovani argumentu prikazoveho radku
	if ( argc == 1 ){ // kontrola jesli je argument ( cesta_soubor )
	cout<<"pouziti : file_attrib_read_only_argv_1.exe R:\\soubor_1.txt"<<endl; // zadava se v cmd jedno lomitko
	cout<<"pouziti : file_attrib_read_only_argv_1.exe R:\\adresar_1"<<endl;
	system("pause");
	exit(1);
	}
	
	// nazev souboru,nebo adresare, zde menit
    //LPCSTR cesta_soubor = "C:\\cesta\\k\\vasemu_souboru.txt";
    //LPCSTR cesta_soubor = "R:\\folder"; // nastavi ReadOnly pro adresar
	//LPCSTR cesta_soubor = "R:\\ccc\\eee.txt";
    //cesta_soubor = "R:\\soubor.txt";
	cesta_soubor = argv[1]; // preda argument promenne cesta
    
    // nacte aktualni atributy souboru
    DWORD attributes = GetFileAttributesA(cesta_soubor);
    if (attributes == INVALID_FILE_ATTRIBUTES) {
        cout<<"nelze nacist atributy "<<'"'<<cesta_soubor<<'"'<<endl;
        system("pause");
        return 1;
    }
    
    // odebrani priznaku ReadOnly
    attributes &= ~FILE_ATTRIBUTE_READONLY;
    if (!SetFileAttributesA(cesta_soubor, attributes)) {
    cout<<"nepodarilo se odebrat atribut ReadOnly "<<'"'<<cesta_soubor<<'"'<<endl;
    system("pause");
    return 1;
}

    cout<<"u souboru nebo adresare "<<'"'<<cesta_soubor<<'"'<<" byl uspesne odebran atribut ReadOnly"<<endl;

	system("pause");
	return 0;
}
 
 
