#include <iostream>
//#include <cstring>
#include <dirent.h> // DIR* dir = opendir(path);
#include <sys/stat.h> // if (stat(fullPath, &statbuf) == 0) {
//#include <unistd.h>
//#include <cstdio>

using namespace std;

int smaz_adresar(const char* path) {
    DIR* dir = opendir(path);
    if (!dir) { 
        // pokud se adresar neda otevrit, napriklad neexistuje ci z duvodu nedostatecnych prav.
        return -1;
    }
    
    struct dirent* entry;
    int result = 0;

    while ((entry = readdir(dir)) != nullptr) {
        // preskoci specialni polozky "." a ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        continue;

        // sestavi uplnou cestu k nalezene polozce.
        size_t pathLen = strlen(path);
        size_t nameLen = strlen(entry->d_name);
        // +2 je pro oddelovac '/' a ukoncovaci nulovy znak.
        size_t fullPathLen = pathLen + nameLen + 2;
        char* fullPath = new char[fullPathLen];
        snprintf(fullPath, fullPathLen, "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (stat(fullPath, &statbuf) == 0) {
            if (S_ISDIR(statbuf.st_mode)) {
                // rekurzivni volani, pokud se jedna o adresar.
                if (smaz_adresar(fullPath) != 0) {
                    result = -1;
                }
            } else {
                // pokud jde o soubor, pokusime se jej smazat.
                if (unlink(fullPath) != 0) {
                    result = -1;
                }
            }
        } else {
            result = -1;
        }
        delete[] fullPath; // uvolnime dynamicky alokovanou pamet

        // pokud doslo k chybe, muzeme ukoncit cyklus.
        if (result != 0) break;
    }
    closedir(dir);

    // nakonec smaze jiz prazdny adresar
    if (result == 0 && rmdir(path) != 0) {
        result = -1;
    }
    return result;
}

int main(int argc, char **argv) {
	
	// spracovani argumentu
		if (argc == 1 ){ // kontrola jesli je argument (cesta)
		cout<<"pouziti : delete_folder_argv_2.exe R:\\adresar_1"<<endl; // zadava se v cmd jedno lomitko
		system("pause");
		exit(1);
	}
	
	const char* dirPath = argv[1]; // preda argument promenne dirPath

    //const char* dirPath = "/cesta/k/adresari"; // Nahraïte skuteènou cestou k adresáøi.
    //const char* dirPath = "R:\\Nová složka"; // ZDE MENIT ! pozna soubor a adresar
    //const char* dirPath = "R:\\abcd"; // ZDE MENIT !
    
    if (smaz_adresar(dirPath) == 0) {
    cout<<"adresar "<<'"'<<dirPath<<'"'<<" byl uspesne odstranen"<<endl;
    } else {
    cout<<"nastala chyba pri mazani adresare "<<'"'<<dirPath<<'"'<<endl; // pozna soubor od adresare
    }
    
    system("pause");
    return 0;
}


