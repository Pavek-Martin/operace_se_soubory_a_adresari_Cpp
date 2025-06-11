#include <iostream>
#include <windows.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <cstring>
#include <string>
using namespace std;


const char* adresar;

// zde deklarovana funkce CreateFolder
    void vytvor_adresar(const char* cesta) {
	//cout<<adresar<<endl;
	if (CreateDirectory(adresar, NULL)) {
    cout<<"byl vytvoren novy adresar "<<'"'<<adresar<<'"'<<endl;
    } else {
	cout<<"adresar "<<'"'<<adresar<<'"'<<" se nepodarilo vytvorit"<<endl;
    }

}


int main() {
    
	// volani funce vytvor_adresar 
    adresar = "R:\\adresar_4"; // zde menit
    vytvor_adresar(adresar);
        
    system("pause");
    return 0;
}


