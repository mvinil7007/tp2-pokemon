#ifndef OVERNIGHTPACKAGE_HPP
#define OVERNIGHTPACKAGE_HPP

#include "package.hpp"

class OvernightPackage : public Package {
private:
    unsigned int _taxaAdicionalPorKg; // Taxa adicional por quilo

public:
    OvernightPackage(const std::string& nome,const std::string& endereco,unsigned int peso,unsigned int custo,unsigned int taxaAdicionalPorKg);

    double calculateCost() const override;
};

#endif