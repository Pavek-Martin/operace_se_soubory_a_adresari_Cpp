#include <iostream>
#include <unistd.h>
#include <limits.h>
#include <cstdlib>

// zjisteni $PWD funguje !

using namespace std;

int main(int argc, char** argv) {
	
    char cwd[PATH_MAX];
    
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        cout<<"pwd="<<'"'<<cwd<<'"'<<endl;
    } else {
        perror("getcwd() error");
        return EXIT_FAILURE; // asi kvuli tomuto, dole radek "return EXIT_SUCCESS;"
    }
    system("pause");
    // return 0; // toto tentokrate nedavat
    //return EXIT_SUCCESS; // puvodni
}	

