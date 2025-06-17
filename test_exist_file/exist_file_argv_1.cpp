#include <iostream>
#include <string>
#include <sys/stat.h>
 
using namespace std;

bool fileExists(const string& fileName) {
    struct stat buffer;
    return (stat(fileName.c_str(), &buffer) == 0);
}

int main(int argc, char **argv) {
	
	// spracovani argumentu
	if ( argc == 1 ){ // kontrola jesli je argument (cesta)
	cout<<"pouziti : exist_file_argv_1.exe R:\\soubor.txt"<<endl; // zadava se v cmd jedno lomitko
	system("pause");
	exit(1);
	}

    //const char* cesta = argv[1]; // preda argument promenne cesta
    string cesta = argv[1]; // preda argument promenne cesta
	  
    
    std::string fileName;
    std::cout << "Zadejte název souboru: ";
    std::getline(std::cin, fileName);
    
    
	if (fileExists(fileName)) {
        cout << "Soubor \"" << fileName << "\" existuje." << endl;
    } else {
        cout << "Soubor \"" << fileName << "\" neexistuje nebo nelze získat jeho informace." << endl;
    }
    
    //system ("pause");
    return 0;
      
}


