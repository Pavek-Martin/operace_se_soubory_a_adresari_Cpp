#include <iostream>
#include <unistd.h>
#include <limits.h>
#include <cstdlib>
#include <string>

// zjisteni $PWD funguje !

using namespace std;

string pwd, p, k;
int d_pwd, n;

int main(int argc, char** argv) {
	
    char cwd[PATH_MAX];
    
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
    cout<<"pwd="<<'"'<<cwd<<'"'<<endl;
        
    pwd = cwd; // po string pwd da promennou cwd
    d_pwd = pwd.length();
	cout<<d_pwd<<" delka stringu pwd"<<endl; // delka promenne pwd
        
    // posledni znak retezce pwd
	p = "\\";  // musi byt takto a pak zobrazuje jako jedno lomitko ( podobne jak v bash )
	cout<<p<<" toto budu hledat jako posledni znak retezce pwd, promenna p"<<endl;
	
	k = pwd.substr(d_pwd -1,1); // posledni znak retezce "pwd" bude "k"
	cout<<k<<" nalezeni posledni znak retezce pwd, promenna k"<<endl;
	
	n = k.compare(p); // porovna objekty, vysledek do [int] n=
	cout<<n<<" ciselny vysledek porovnani "<<"p & k, promenna n"<<endl;
	
	if ( n!=0 ) { // kdyz se znaky neschodujou tak je n=1 nebo n=-1 
	// a kdyz se schodujou tak je n=0
	
	cout<<"verdikt: pridat lomitkona konec retezce pwd"<<endl;
	// prida znak lomitko na konec retezce pwd
	pwd+=p;
	}
    
	cout<<pwd<<" upravena konecna podoba promenne pwd"<<endl;
    
    
    // tady pokracuje else pro cwd  
    } else {
    perror("getcwd() error");
    return EXIT_FAILURE; // asi kvuli tomuto, dole radek "return EXIT_SUCCESS;"
    }
    
	system("pause");
    // return 0; // toto tentokrate nedavat
    //return EXIT_SUCCESS; // puvodni
}	

