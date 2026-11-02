#include <iostream>
using namespace std;

int main(){
    char str[] = "abc teste";

    // sem ponteiro
    // int cont = 0;
    // for(int i=0;str[i]!='\0';i++)
    //    cont++;
    // for(cont-1;cont>=0;cont--)
    //    cout << str[cont];
    // cout << endl;
    // -------------------------------------------------------
    // *p  == str[i] 
    // p++ == (p+1) modifica o valor de p (endereço apontado)
    // p-- == (p-1) volta uma posição de endereço
    char *p = str;

    while(*p!='\0') {
        p++;
    }
    p--;
    // enquando o valor de p (endereço apontado) for menor ou
    // igual ao que o endereço de str[0] , imprime o valor do endereço apontado
    while(p>=str) {
        cout << *p;
        p--;
    }
    cout << endl;
    return 0;
    //exemplo de saida para o exemplo acima: etset cba

}