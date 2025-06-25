#ifndef COMPRA_HPP
#define COMPRA_HPP
#include <string>

struct Compra {
    std::string codigoNegociacao;
    std::string cpf;
    std::string data;
    std::string perfil; // Conservador, Moderado, Agressivo
    int quantidade;
    float valor;
};

#endif
