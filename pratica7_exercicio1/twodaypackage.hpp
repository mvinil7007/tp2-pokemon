#ifndef TWODAYPACKAGE_HPP
#define TWODAYPACKAGE_HPP

#include "package.hpp"


class TwoDayPackage : public Package {
private:
    unsigned int _taxaFixa;
public:
    TwoDayPackage(const std::string& nome,const std::string& endereco,unsigned int peso,unsigned int custo,unsigned int taxaFixa);
    // sobrescrita da função
    double calculateCost() const override;

};

#endif