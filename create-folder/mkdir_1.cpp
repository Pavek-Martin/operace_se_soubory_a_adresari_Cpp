#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <cstring>
#endif

using namespace std;

int main() {
    const char* adresar = "R:\\aaa\\bbb_2"; // napred musi bej "R:\aaa\ a pak teprve udela i bbb_2
    // prebyje i r:\aaa\ (read only folder)

#ifdef _WIN32
    if (CreateDirectory(adresar, NULL))
    cout<<"byl vytvoren novy adresar "<<'"'<<adresar<<'"'<<endl;
    else
    cout<<"adresar "<<'"'<<adresar<<'"'<<" se nepodarilo vytvorit"<<endl;
#else 
    // 0755 znamen�: vlastn�k m��e ��st, zapisovat a spou�t�t, ostatn� mohou ��st a spou�t�t.
    if (mkdir(adresar, 0755) == 0)
    cout << "Adres�� byl �sp�n� vytvo�en."<<endl;
    else
    cout<< "Chyba p�i vytv��en� adres��e: " << strerror(errno) <<endl;
#endif

    system("pause");
    return 0;
}


