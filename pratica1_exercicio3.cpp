#include <iostream>
using namespace std;

//-------------------------------------------------------------------------------
// (a) Notação de arranjo tradicional com []

// a[] cria o ponteiro a que armazena o primeiro endereço de str (&str[0])
// a[i] ou *(a+i) é o valor da varialvel , &a[i] ou (a+i) ou é o endereço da variavel

int calculaTamanhoString1 ( char a[]) { 
    int cont = 0;
    for(int i=0;a[i]!='\0';i++)         
       cont++;
    return cont;
}
//-------------------------------------------------------------------------------

// (b) Aritmética de ponteiros utilizando *(b + i)

// o ponteiro b guarda o endereço str[0] e não o muda, calcula &b[i] = &str[i] e acessa str[i] (valor)
// endereço: (b+i)  = &b[i] -> &str[i]
// variavel: *(b+i) = b[i] ->  str[i]

int calculaTamanhoString2 ( char b[]) { 
    int cont=0;
    for(int i=0;*(b+i)!='\0';i++)
       cont++;
    return cont;
}
//-------------------------------------------------------------------------------
// (c) Deslocamento por incremento de ponteiro (sem 'int' declarados e sem '[]')

// cria o ponteiro "ptr" e armazena nela o ponteiro (b) que aponta para &str[0]
// ptr armazena &str[0], por isso o for sem inicialização
// *ptr é a desrefenciação da variavel str[i] , caso essa variavel seja = "\0" o for para
// ptr++ = (ptr+1) , mudando a posição do ponteiro
// apontando agora para &str[i+1]
// A subtração de ponteiros (ptr - b) calcula a distância de elementos na memória
// sizeof diz o tamanho de um único caracter na memoria(1 byte)
// &str[50] - &str[0] / 1 = 50/1 = 50.

int calculaTamanhoString3(char b[]) {
    char *ptr = b; 
    for (; *ptr != '\0'; ptr++) {
        //ex: str = 'ab'                                                   (endereço de str) + (i*sizeof(tipo)) = endereço atual
        //ex: desreferencia *ptr     = str[0] = 'a' != '\0' , ptr = (ptr+1)   ex: 1100 + (1*1) = 1101
        //                  *(ptr+1) = str[1] = 'b' != '\0' , ptr = (ptr+1+1) ex: 1100 + (1*2) = 1102
        //                  *(ptr+2) = str[2] = '\0' , stop!
    }
    // ex: str ou valor de b = &str[0] = 1100 , valor de ptr = 1102
    // ex: (1102 - 1100)/1 = 2 , logo retorna o int 2!
    return (ptr - b) / sizeof(char); 
}
//------------------------------------------------------------------------------
int main() {
    char str[51];
    cout << "Digite alguma string ... ( com ate 50 caracteres ):";
    cin.getline( str , 50);
    cout << "Tamanhos calculados :" << endl ;
    cout << calculaTamanhoString1 (str) << " " << calculaTamanhoString2(str) << " " << calculaTamanhoString3 ( str ) ;
    cout << endl ;
    cout << " ih cachoeira ";
    return 0;
}