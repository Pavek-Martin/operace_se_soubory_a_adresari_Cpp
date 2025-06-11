#include <iostream>
#include <windows.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <cstring>

using namespace std;

//const char* adresar = "R:\\aaa";
const char* adresar = "R:\\aaa\\bbb_6"; // napred musi bej "R:\aaa\ a pak teprve udela i bbb_2
// prebyje i r:\aaa\ (read only folder)
    

int main() {

    if (CreateDirectory(adresar, NULL)) {
    cout<<"byl vytvoren novy adresar "<<'"'<<adresar<<'"'<<endl;
    } else {
	cout<<"adresar "<<'"'<<adresar<<'"'<<" se nepodarilo vytvorit"<<endl;
    }

    system("pause");
    return 0;
}

