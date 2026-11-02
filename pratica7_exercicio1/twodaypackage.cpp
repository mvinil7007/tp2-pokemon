#include "twodaypackage.hpp"

TwoDayPackage::TwoDayPackage(const std::string& nome,const std::string& endereco,unsigned int peso,unsigned int custo,unsigned int taxaFixa)
  : Package(nome, endereco, peso, custo) , _taxaFixa(taxaFixa) {

}

double TwoDayPackage::calculateCost() const {
    return Package::calculateCost() + static_cast<double>(_taxaFixa);
}