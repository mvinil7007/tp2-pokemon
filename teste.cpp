#include <iostream>
#include <cstdlib> // rand() e srand()
#include <ctime>   // time()
using namespace std;

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

            // preenche os arranjos com números aleatorios de 0 a 9
            // rand() % 10: escolhe um número aleatorio e calcúla seu resto

            for (int i=0;i<n;i++){
                a[i] = rand() % 10;
                b[i] = rand() % 10;
            }

            // imprimir os valores

            // para a
            for (int i=0;i<n;i++){
                if (i == n-1){
                cout << a[i] << "," << endl;
                break;
                }
                cout << a[i] << ","; 
            }

            // para b
            for (int i=0;i<n;i++){
                if (i == n-1){
                cout << b[i] << "," << endl;
                break;
                }
                cout << b[i] << ","; 
            }

            // variaveis de contagem
            int Par=0 , Impar=0 , c;
            
            // calculando se a soma dos pares é par ou impar
            for (int i=0;i<n;i++){
                c = (a[i] + b[i]);
                if(c%2==0)
                Par++;
                else
                Impar++;
            }

            cout << "Par:" << Par << endl;
            cout << "Impar:" << Impar << endl;

            // deletar os vetores criados em heap
            delete[] a;
            delete[] b;
        }
    }
    return 0;
}