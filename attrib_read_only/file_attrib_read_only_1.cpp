// pridava a odebira atribut ReadOnly u vybraneho souboru
#include <iostream>
#include <windows.h>

using namespace std;

LPCSTR cesta_soubor; // tohle nevim co je za datovej typ !!!

int main(int argc, char** argv) {
    
	// nazev souboru,nebo adresare, zde menit
    //LPCSTR cesta_soubor = "C:\\cesta\\k\\vasemu_souboru.txt";
    //LPCSTR cesta_soubor = "R:\\folder"; // nastavi ReadOnly pro adresar
	//LPCSTR cesta_soubor = "R:\\ccc\\eee.txt";
    cesta_soubor = "R:\\soubor.txt";
    
    // nacte aktualni atributy souboru
    DWORD attributes = GetFileAttributesA(cesta_soubor);
    if (attributes == INVALID_FILE_ATTRIBUTES) {
        cout<<"nelze nacist atributy souboru "<<'"'<<cesta_soubor<<'"'<<endl;
        return 1;
    }

    // prida priznak ReadOnly pomoci bitového OR
    attributes |= FILE_ATTRIBUTE_READONLY;
    
    // nastavi nove atributy souboru
    if (!SetFileAttributesA(cesta_soubor, attributes)) {
        cout<<"nepodarilo se nastavit atribut ReadOnly u souboru "<<'"'<<cesta_soubor<<'"'<<endl;
        return 1;
    }

    cout<<"u souboru "<<'"'<<cesta_soubor<<'"'<<" byl uspesne nastaven atribut ReadOnly"<<endl;

	system("pause");
	return 0;
}
 
 
