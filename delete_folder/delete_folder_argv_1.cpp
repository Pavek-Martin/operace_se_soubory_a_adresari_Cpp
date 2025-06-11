#include <iostream>
#include <cstring>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstdio>

using namespace std;

int removeDirectory(const char* path) {
    DIR* dir = opendir(path);
    if (!dir) { 
        // pokud se adresar neda otevrit, napriklad neexistuje ci z duvodu nedostatecnych prav.
        return -1;
    }
    
    struct dirent* entry;
    int result = 0;

    while ((entry = readdir(dir)) != nullptr) {
        // preskoci specialni polozky "." a ".."
        if (std::strcmp(entry->d_name, ".") == 0 || std::strcmp(entry->d_name, "..") == 0)
            continue;

        // sestavi uplnou cestu k nalezene polozce.
        size_t pathLen = std::strlen(path);
        size_t nameLen = std::strlen(entry->d_name);
        // +2 je pro oddelovac '/' a ukoncovaci nulovy znak.
        size_t fullPathLen = pathLen + nameLen + 2;
        char* fullPath = new char[fullPathLen];
        std::snprintf(fullPath, fullPathLen, "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (stat(fullPath, &statbuf) == 0) {
            if (S_ISDIR(statbuf.st_mode)) {
                // rekurzivni volani, pokud se jedna o adresár.
                if (removeDirectory(fullPath) != 0) {
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
	
    //const char* dirPath = "/cesta/k/adresari"; // Nahraïte skuteènou cestou k adresáøi.
    const char* dirPath = "R:\\Nová složka"; // ZDE MENIT ! pozna soubor a adresar
    
    //const char* dirPath = "R:\\abcd"; // ZDE MENIT !
    
    
    if (removeDirectory(dirPath) == 0) {
    cout<<"adresar "<<'"'<<dirPath<<'"'<<" byl uspesne odstranen"<<endl;
    } else {
    cout<<"nastala chyba pri mazani adresare "<<'"'<<dirPath<<'"'<<endl; // pozna soubor od adresare
    }
    
    system("pause");
    return 0;
}


