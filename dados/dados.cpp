#include "dados.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

void salvarCompra(const Compra& c) {
    std::ofstream arquivo("historico.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << c.codigoNegociacao << ";" << c.cpf << ";" << c.data << ";" 
                << c.perfil << ";" << c.quantidade << ";" << c.valor << std::endl;
        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo para escrita.\n";
    }
}

std::vector<Compra> lerHistorico() {
    std::vector<Compra> historico;
    std::ifstream arquivo("historico.txt");
    std::string linha;

    while (getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string campo;
        Compra c;

        getline(ss, c.codigoNegociacao, ';');
        getline(ss, c.cpf, ';');
        getline(ss, c.data, ';');
        getline(ss, c.perfil, ';');
        getline(ss, campo, ';');
        c.quantidade = std::stoi(campo);
        getline(ss, campo, ';');
        c.valor = std::stof(campo);

        historico.push_back(c);
    }

    return historico;
}

void exibirHistorico() {
    std::vector<Compra> lista = lerHistorico();
    std::cout << "\n=== Histórico de Compras ===\n";
    for (const Compra& c : lista) {
        std::cout << "Ativo: " << c.codigoNegociacao
                  << " | CPF: " << c.cpf
                  << " | Data: " << c.data
                  << " | Perfil: " << c.perfil
                  << " | Quantidade: " << c.quantidade
                  << " | Valor: " << c.valor
                  << std::endl;
    }
}
