#include "servico.hpp"
#include <iostream>
#include <regex>

bool validarCPF(const std::string& cpf) {
    // Verifica se tem exatamente 11 dígitos numéricos
    return std::regex_match(cpf, std::regex("\\d{11}"));
}

bool validarData(const std::string& data) {
    // Verifica se está no formato dd/mm/aaaa
    return std::regex_match(data, std::regex("\\d{2}/\\d{2}/\\d{4}"));
}

Compra criarCompra(const std::string& perfilSelecionado) {
    Compra c;
    c.perfil = perfilSelecionado;

    std::cout << "Digite o código da negociação: ";
    std::getline(std::cin, c.codigoNegociacao);

    do {
        std::cout << "Digite o CPF (somente números): ";
        std::getline(std::cin, c.cpf);
    } while (!validarCPF(c.cpf));

    do {
        std::cout << "Digite a data (dd/mm/aaaa): ";
        std::getline(std::cin, c.data);
    } while (!validarData(c.data));

    std::cout << "Digite a quantidade: ";
    std::cin >> c.quantidade;
    std::cout << "Digite o valor (por unidade): ";
    std::cin >> c.valor;
    std::cin.ignore(); // Limpa o \n do buffer

    return c;
}
