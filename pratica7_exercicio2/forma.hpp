// interface
#ifndef FORMA_HPP
#define FORMA_HPP

#include <string>

class Forma {
public:
    virtual ~Forma() = default;
    virtual std::string get_nome() const = 0;
    virtual std::string get_cor() const = 0;
};

#endif // FORMA_HPP