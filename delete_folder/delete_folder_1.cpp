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
        // Pokud se adres�� ned� otev��t, nap��klad neexistuje �i z d�vodu nedostate�n�ch pr�v.
        return -1;
    }
    
    struct dirent* entry;
    int result = 0;

    while ((entry = readdir(dir)) != nullptr) {
        // P�esko��me speci�ln� polo�ky "." a ".."
        if (std::strcmp(entry->d_name, ".") == 0 || std::strcmp(entry->d_name, "..") == 0)
            continue;

        // Sestav�me �plnou cestu k nalezen� polo�ce.
        size_t pathLen = std::strlen(path);
        size_t nameLen = std::strlen(entry->d_name);
        // +2 je pro odd�lova� '/' a ukon�ovac� nulov� znak.
        size_t fullPathLen = pathLen + nameLen + 2;
        char* fullPath = new char[fullPathLen];
        std::snprintf(fullPath, fullPathLen, "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (stat(fullPath, &statbuf) == 0) {
            if (S_ISDIR(statbuf.st_mode)) {
                // Rekurzivn� vol�n�, pokud se jedn� o adres��.
                if (removeDirectory(fullPath) != 0) {
                    result = -1;
                }
            } else {
                // Pokud jde o soubor, pokus�me se jej smazat.
                if (unlink(fullPath) != 0) {
                    result = -1;
                }
            }
        } else {
            result = -1;
        }
        delete[] fullPath; // Uvoln�me dynamicky alokovanou pam�.

        // Pokud do�lo k chyb�, m��eme ukon�it cyklus.
        if (result != 0) break;
    }
    closedir(dir);

    // Nakonec sma�eme ji� pr�zdn� adres��.
    if (result == 0 && rmdir(path) != 0) {
        result = -1;
    }
    return result;
}

int main() {
    const char* dirPath = "/cesta/k/adresari"; // Nahra�te skute�nou cestou k adres��i.
    
    if (removeDirectory(dirPath) == 0) {
        std::cout << "Adres�� byl �sp�n� odstran�n.\n";
    } else {
        std::cerr << "Nastala chyba p�i maz�n� adres��e.\n";
    }
    
    system("pause");
    return 0;
}

