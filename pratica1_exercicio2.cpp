#include <iostream>

void leiaInteiros1 ( int &x , int &y) { // x é apenas um "apelido" para a
 std::cin >> x >> y;
}

void leiaInteiros2 ( int *x , int *y) { // x é um ponteiro que aponta para o endereço de a
 std::cin >> *x >> *y;
}

int main() {
 int a , b ;
 // passagem por referencia
 leiaInteiros1(a,b);
 std::cout << a << " " << b << std::endl;
 // utilize ponteiros
 leiaInteiros2(&a,&b);
 std::cout << a << " " << b << std::endl;
 return 0;
 }