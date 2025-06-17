#include <iostream>
#include <sys/stat.h> // if (stat(path, &info) != 0) {

using namespace std;

bool existuje_adresar(const char* path) {
    struct stat info;
    
    // stat vrati 0, pokud se podarilo nacist informace o souboru ci adresari
    if (stat(path, &info) != 0) {
    // nelze nacist informace – adresar pravdepodobne neexistuje
    return false;
    }
    
    // zkontroluje jestli nactena cesta odpovida adresari
    return (info.st_mode & S_IFDIR) != 0;
}


int main(int argc, char **argv) {
	
	// spracovani argumentu
	if ( argc == 1 ){ // kontrola jesli je argument (cesta)
	cout<<"pouziti : exist_folder_argv_1.exe R:\\adresar"<<endl; // zadava se v cmd jedno lomitko
	system("pause");
	exit(1);
	}

    const char* cesta = argv[1]; // preda argument promenne cesta
    
	// vyhodnoceni 
    if (existuje_adresar(cesta)) {
        cout<<"adresar "<<'"'<<cesta<<'"'<<" existuje"<<endl;
	} else {
        cout<<"adresar "<<'"'<<cesta<<'"'<<" NEexistuje nebo nelze ziskat jeho informace"<<endl;    
	}
	
	system("pause");
    return 0;
}


