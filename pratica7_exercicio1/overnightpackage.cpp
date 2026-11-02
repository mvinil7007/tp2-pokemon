#include "overnightpackage.hpp"

OvernightPackage::OvernightPackage(const std::string& nome,const std::string& endereco,unsigned int peso,unsigned int custo,unsigned int taxaAdicionalPorKg)
 :  Package(nome, endereco, peso, custo) , _taxaAdicionalPorKg(taxaAdicionalPorKg) {

}

double OvernightPackage::calculateCost() const {
    unsigned int novoCustoPorKg = getCusto() +  _taxaAdicionalPorKg;
    return static_cast<double>(getPeso()*novoCustoPorKg);
}