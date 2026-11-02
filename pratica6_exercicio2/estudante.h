#ifndef INF112_ESTUDANTE_H
#define INF112_ESTUDANTE_H

#include "pessoa.h"
#include "turma.h"

class Estudante : public Pessoa {
private:
  int _matricula;
  // novo atributo
  Turma _turma;
public:
  Estudante(std::string nome, int matricula, Turma turma);
  int get_matricula() const;
  virtual std::string defina_meu_tipo() const override;
  // novos metodos
  Turma get_turma() const;
  void set_turma(Turma turma);
};

#endif