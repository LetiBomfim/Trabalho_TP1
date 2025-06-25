#ifndef SERVICO_HPP
#define SERVICO_HPP
#include "compra.hpp"
#include <string>

bool validarCPF(const std::string& cpf);
bool validarData(const std::string& data);
Compra criarCompra(const std::string& perfilSelecionado);

#endif
