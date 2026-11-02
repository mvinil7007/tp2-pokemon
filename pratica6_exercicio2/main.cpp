#include <iostream>

#include "estudante.h"
#include "pessoa.h"
#include "turma.h"

void f(Pessoa &pessoa) {
  std::cout << "Na função: " << pessoa.defina_meu_tipo() << std::endl;
}

int main() {
  Pessoa pessoa("Julio Reis.");
  // Criando a turma
  Turma turmaProg("INF112", 2026);

  Estudante estudante("Jane Doe", 20180101, turmaProg);

  std::cout << "A pessoa é: " << pessoa.defina_meu_tipo() << std::endl;
  std::cout << "O estudante é: " << estudante.defina_meu_tipo() << std::endl;

  f(pessoa);
  f(estudante);

  // Teste do novo atributo
  std::cout << "A turma do estudante é: " << estudante.get_turma().getCodigo() 
            << " de " << estudante.get_turma().getAno() << std::endl;
  return 0;
}