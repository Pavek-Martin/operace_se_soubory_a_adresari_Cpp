#include <iostream>
#include <string>
#include <sys/stat.h>
 
using namespace std;

bool existuje_soubor(const string& nazev_souboru) {
    struct stat buffer;
    return (stat(nazev_souboru.c_str(), &buffer) == 0);
}

int main(int argc, char **argv) {
	
	// spracovani argumentu
	if ( argc == 1 ){ // kontrola jesli je argument (cesta)
	cout<<"pouziti : exist_file_argv_2.exe R:\\soubor.txt"<<endl; // zadava se v cmd jedno lomitko
	system("pause");
	exit(1);
	}
    
	string soubor = argv[1]; // preda argument argv[1] promenne soubor
    
	if (existuje_soubor(soubor)) {
    cout<<"soubor "<<'"'<<soubor<<'"'<<" existuje"<<endl;
    } else {
    cout<<"soubor "<<'"'<<soubor<<'"'<<" NEexistuje nebo nelze ziskat jeho informace"<<endl;
    }
    
    system ("pause");
    return 0; 
}


