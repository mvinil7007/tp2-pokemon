#include <iostream>
using namespace std;

struct Imagem {
    int **pixels; // ponteiro de ponteiro que vai guardar os pixels da imagem
    int nrows;    
    int ncolumns; 
};

void leImagem(Imagem &im) {
    string codigo;
    cin >> codigo;
    cin >> im.ncolumns >> im.nrows; 
    
    im.pixels = new int*[im.nrows]; // cria um vetor de ponteiro(linhas)
    for(int i=0;i<im.nrows;i++){
       im.pixels[i] = new int[im.ncolumns]; // cria um vetor de inteiros(colunas)
       for(int j=0;j<im.ncolumns;j++){
            cin >> im.pixels[i][j];
        }    
    }
}

void deletaImagem(Imagem &im) {
    // deleta as variavel apontadas pelos ponteiros (im.pixels[i][j])
    // porém os ponteiros ainda continuam em heap
    for(int i=0;i<im.nrows;i++)
        delete []im.pixels[i];
    
    // delela o bloco que o ponteiro im.pixels aponta (im.pixels[i])   
    delete []im.pixels;   
}

void imprimeImagem(Imagem &im) {
    cout << "P1" << endl;
    cout << im.ncolumns << " " << im.nrows << endl;

    for(int i=0;i<im.nrows;i++){
        for(int j=0;j<im.ncolumns;j++)
            if (j==im.ncolumns-1)
                cout << im.pixels[i][j] << endl;
            else 
                cout << im.pixels[i][j] << " ";       
    }
}

void inverteCorImagem(Imagem &im) {
    // Se for 0: 1 - 0 = 1
    // Se for 1: 1 - 1 = 0
    for(int i=0;i<im.nrows;i++)
       for(int j=0;j<im.ncolumns;j++){
            im.pixels[i][j] = 1 - im.pixels[i][j]; }
}

int main() {

    Imagem im;

    leImagem(im);

    inverteCorImagem(im);

    imprimeImagem(im);

    deletaImagem(im);
    
    return 0;
}