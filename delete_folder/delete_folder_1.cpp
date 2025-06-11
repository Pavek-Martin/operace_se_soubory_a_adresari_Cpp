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
        // Pokud se adresáø nedá otevøít, napøíklad neexistuje èi z dùvodu nedostateènıch práv.
        return -1;
    }
    
    struct dirent* entry;
    int result = 0;

    while ((entry = readdir(dir)) != nullptr) {
        // Pøeskoèíme speciální poloky "." a ".."
        if (std::strcmp(entry->d_name, ".") == 0 || std::strcmp(entry->d_name, "..") == 0)
            continue;

        // Sestavíme úplnou cestu k nalezené poloce.
        size_t pathLen = std::strlen(path);
        size_t nameLen = std::strlen(entry->d_name);
        // +2 je pro oddìlovaè '/' a ukonèovací nulovı znak.
        size_t fullPathLen = pathLen + nameLen + 2;
        char* fullPath = new char[fullPathLen];
        std::snprintf(fullPath, fullPathLen, "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (stat(fullPath, &statbuf) == 0) {
            if (S_ISDIR(statbuf.st_mode)) {
                // Rekurzivní volání, pokud se jedná o adresáø.
                if (removeDirectory(fullPath) != 0) {
                    result = -1;
                }
            } else {
                // Pokud jde o soubor, pokusíme se jej smazat.
                if (unlink(fullPath) != 0) {
                    result = -1;
                }
            }
        } else {
            result = -1;
        }
        delete[] fullPath; // Uvolníme dynamicky alokovanou pamì.

        // Pokud došlo k chybì, mùeme ukonèit cyklus.
        if (result != 0) break;
    }
    closedir(dir);

    // Nakonec smaeme ji prázdnı adresáø.
    if (result == 0 && rmdir(path) != 0) {
        result = -1;
    }
    return result;
}

int main() {
    const char* dirPath = "/cesta/k/adresari"; // Nahraïte skuteènou cestou k adresáøi.
    
    if (removeDirectory(dirPath) == 0) {
        std::cout << "Adresáø byl úspìšnì odstranìn.\n";
    } else {
        std::cerr << "Nastala chyba pøi mazání adresáøe.\n";
    }
    
    system("pause");
    return 0;
}

