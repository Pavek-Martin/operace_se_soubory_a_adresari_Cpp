// argv jako cesta k vytvoreni adresare
#include <iostream>
#include <windows.h> // if (CreateDirectory(adresar, NULL)) {
using namespace std;

const char* adresar;

// zde deklarovana funkce "vytvor_adresar"
    void vytvor_adresar(const char* cesta) {
	//cout<<adresar<<endl;
	if (CreateDirectory(adresar, NULL)) {
    cout<<"byl vytvoren novy adresar "<<'"'<<adresar<<'"'<<endl;
    } else {
	cout<<"adresar "<<'"'<<adresar<<'"'<<" se nepodarilo vytvorit"<<endl;
	system("pause");
	exit(1);
    }
}


int main(int argc, char **argv) {
	if (argc == 1 ){ // kontrola jesli je argument (cesta)
		cout<<"pouziti : mkdir_argv_1.exe R:\\adresar_1"<<endl;
		system("pause");
		exit(1);
	}

	// volani funce vytvor_adresar 
    adresar = argv[1]; // preda argument promenne adresar
    vytvor_adresar(adresar);
        
    system("pause");
    return 0;
}


