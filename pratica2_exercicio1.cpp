#include <iostream>
#include <cstdlib> // rand() e srand()
#include <ctime>   // time()
using namespace std;
                             //ptr[]
void preencheAleatorios ( int *ptr, int N) {
    // preenche os arranjos com números aleatorios de 0 a 9
    // rand() % 10: escolhe um número aleatorio e calcúla seu resto 
    for (int i=0;i<N;i++)
        ptr[i] = rand() % 10; // ou *(ptr+1)
}

void imprime ( int *ptr , int N) {
    for (int i=0;i<N;i++) {
        if (i==N-1)
            cout << ptr[i] << "," << endl;
        else
            cout << ptr[i] << ","; 
    }
}

void contaParImpar ( int *a, int *b, int N, int &par, int &impar) {
    par = 0;
    impar = 0;   
    int c;
    for (int i=0;i<N; i++) {
        c = (a[i]+b[i]);
        if (c%2==0)
            par++;
        else
            impar++;
    }
}

int main(){

    // time(0): é uma função que volta umm número gigante baseado nos segundos
    // passados de uma data especifica até o tempo atual
    // srand:passa esse número como valor semente(inicial) para a função rand()

    srand(time(0));
    int n=1;

    while(n>0){
        cout << "Digite a quantidade de jogadas a simular: ";
        cin >> n;
        if(n!=-1){

            // a é armazenado na stack e armazena o primeiro endereço
            // do array "a" que é "a[0]" e está na heap 

            int *a = new int[n];  
            int *b = new int[n];

            preencheAleatorios(a, n);
            preencheAleatorios(b, n);
            
            imprime(a,n);
            imprime(b,n);

            // variaveis de contagem
            int par=0 , impar=0 , c;
            
            contaParImpar(a,b,n,par,impar);

            cout << "Par: " << par << endl;
            cout << "Impar: " << impar << endl;

            // deletar os vetores criados em heap
            delete[] a;
            delete[] b;
        }
    }
    return 0;
}