#ifndef PERFIL_HPP
#define PERFIL_HPP
#include <string>

class PerfilInvestidor {
public:
    virtual std::string getPerfil() const = 0;
};

class Conservador : public PerfilInvestidor {
public:
    std::string getPerfil() const override {
        return "Conservador";
    }
};

class Moderado : public PerfilInvestidor {
public:
    std::string getPerfil() const override {
        return "Moderado";
    }
};

class Agressivo : public PerfilInvestidor {
public:
    std::string getPerfil() const override {
        return "Agressivo";
    }
};

#endif
