#ifndef DADOS_HPP
#define DADOS_HPP
#include "compra.hpp"
#include <vector>

void salvarCompra(const Compra& c);
std::vector<Compra> lerHistorico();
void exibirHistorico();

#endif
