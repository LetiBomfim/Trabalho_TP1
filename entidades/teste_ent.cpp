#include "teste_ent.hpp"
#include "entidades.hpp"
#include <iostream>

// Implementação da Classe ContaTeste
void ContaTeste::Run() {
    TestValidAccount();
    TestInvalidAccount();
}

void ContaTeste::TestValidAccount() {
    try {
        Conta conta;

        Cpf cpf;
        cpf.Set("123.456.789-01");
        conta.SetCpf(cpf);

        Nome nome;
        nome.Set("Fernando Chacon");
        conta.SetNome(nome);

        Senha senha;
        senha.Set("A1b#c2");
        conta.SetSenha(senha);

        std::cout << "Teste de Conta válida passou - Valido" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Ocorreu erro ao definir Conta: " << e.what() << std::endl;
    }
}

void ContaTeste::TestInvalidAccount() {
    try {
        Conta conta;

        Cpf cpf;
        cpf.Set("123.456.789-01");
        conta.SetCpf(cpf);

        Nome nome;
        nome.Set("Fernando Chacon");
        conta.SetNome(nome);

        Senha senha;
        senha.Set("123456");
        conta.SetSenha(senha);

        std::cout << "Teste de Conta falhou - Invalido" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Teste de Conta inválida passou: Ocorreu erro ao definir Conta: " << e.what() << std::endl;
    }
}

// Implementação da Classe CarteiraTeste
void CarteiraTeste::Run() {
    TestValidWallet();
    TestInvalidWallet();
}

void CarteiraTeste::TestValidWallet() {
    try {
        Carteira carteira;

        Codigo codigo;
        codigo.Set("12345");
        carteira.SetCodigo(codigo);

        Nome nome;
        nome.Set("Minha Carteira");
        carteira.SetNome(nome);

        Perfil perfil;
        perfil.Set("Moderado");
        carteira.SetPerfil(perfil);

        std::cout << "Teste de Carteira válida passou - Valido" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Ocorreu erro ao definir Carteira: " << e.what() << std::endl;
    }
}

void CarteiraTeste::TestInvalidWallet() {
    try {
        Carteira carteira;

        Codigo codigo;
        codigo.Set("12345");
        carteira.SetCodigo(codigo);

        Nome nome;
        nome.Set("Minha Carteira");
        carteira.SetNome(nome);

        Perfil perfil;
        perfil.Set("perfil_invalido");
        carteira.SetPerfil(perfil);

        std::cout << "Teste de Carteira falhou - Invalido" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Teste de carteira inválida passou: Ocorreu erro ao definir Carteira: " << e.what() << std::endl;
    }
}

// Implementação da Classe OrdemTeste
void OrdemTeste::Run() {
    TestValidCommand();
    TestInvalidCommand();
}

void OrdemTeste::TestValidCommand() {
    try {
        Ordem ordem;

        Codigo_de_Negociacao codigo_de_negociacao;
        codigo_de_negociacao.Set("A1B2C3");
        ordem.SetCodigoDeNegociacao(codigo_de_negociacao);

        Dinheiro dinheiro;
        dinheiro.Set(500.00);
        ordem.SetDinheiro(dinheiro);

        Quantidade quantidade;
        quantidade.Set(1000);
        ordem.SetQuantidade(quantidade);

        Data data;
        data.Set("20250513");
        ordem.SetData(data);

        Codigo codigo;
        codigo.Set("12345");
        ordem.SetCodigo(codigo);

        std::cout << "Teste de Ordem válida passou - Valido" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Ocorreu erro ao definir Ordem: " << e.what() << std::endl;
    }
}

void OrdemTeste::TestInvalidCommand() {
    try {
        Ordem ordem;

        Codigo_de_Negociacao codigo_de_negociacao;
        codigo_de_negociacao.Set("A1B2C3");
        ordem.SetCodigoDeNegociacao(codigo_de_negociacao);

        Dinheiro dinheiro;
        dinheiro.Set(500.00);
        ordem.SetDinheiro(dinheiro);

        Quantidade quantidade;
        quantidade.Set(1000);
        ordem.SetQuantidade(quantidade);

        Data data;
        data.Set("20251332");
        ordem.SetData(data);

        Codigo codigo;
        codigo.Set("12345"); 
        ordem.SetCodigo(codigo);

        std::cout << "Teste de Ordem falhou - Invalido" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Teste de ordem inválida passou: Ocorreu erro ao definir Ordem: " << e.what() << std::endl;
    }
}
