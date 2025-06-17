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

int main() {
    const int MAX_PATH_LENGTH = 256;
    char cesta[MAX_PATH_LENGTH];
    
    cout<<"zadej cestu k adresari : ";
    cin.getline(cesta, MAX_PATH_LENGTH);
    
    if (existuje_adresar(cesta)) {
        cout<<"adresar "<<cesta<<" existuje"<<endl;
	} else {
        cout<<"adresar "<<cesta<<" NEexistuje"<<endl;    
	}
    
	system("pause");
    return 0;
}


