#include "testes_dom.hpp"
#include "dominios.hpp"

#include <iostream>
#include <stdexcept>
#include <cassert>

// Implementação do Teste da Classe Código
void CodigoTeste::Run() {
    // Teste de caso válido
    try {
        Codigo codigo;
        codigo.Set("12345");
        assert(codigo.Get() == "12345");
        std::cout << "Teste de codigo passou no teste" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Teste de codigo falhou: " << e.what() << std::endl;
    }

    // Teste de caso inválido
    try {
        Codigo codigo;
        codigo.Set("123456");
        std::cout << "Teste de codigo falhou: Exceçao nao foi lançada." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Teste de codigo invalido passou: " << e.what() << std::endl;
    }
}

// Implementação do Teste da Classe Nome
void NomeTeste::Run() {
    // Teste de caso válido
    try {
        Nome nome;
        nome.Set("Fernando Chacon");
        assert(nome.Get() == "Fernando Chacon");
        std::cout << "Teste de nome foi aprovado" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Teste de nome falhou: " << e.what() << std::endl;
    }

    // Teste de caso inválido
    try {
        Nome nome;
        nome.Set("Fernando   Chacon");
        std::cout << "Teste de nome falhou: Exceçao nao foi lançada." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Teste de nome invalido passou: " << e.what() << std::endl;
    }
}

// Implementação do Teste da Classe Codigo_de_Negociacao
void Codigo_de_NegociacaoTeste::Run() {
    // Teste de caso válido
    try {
        Codigo_de_Negociacao codigo_de_negociacao;
        codigo_de_negociacao.Set("A1B2C3");
        assert(codigo_de_negociacao.Get() == "A1B2C3");
        std::cout << "Teste do codigo de negociaçao passou" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Teste do codigo de negociaçao falhou: " << e.what() << std::endl;
    }

    // Teste de caso inválido
    try {
        Codigo_de_Negociacao codigo_de_negociacao;
        codigo_de_negociacao.Set("A1B@C3");
        std::cout << "Teste de codigo de negociaçao falhou: Exceçao nao foi lançada." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Teste de codigo de negociaçao invalido passou: " << e.what() << std::endl;
    }
}

// Implementação do Teste da Classe Data
void DataTeste::Run() {
    // Teste de caso válido
    try {
        Data data;
        data.Set("20250513");
        assert(data.Get() == "20250513");
        std::cout << "Teste de data passou!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Teste de data falhou: " << e.what() << std::endl;
    }

    // Teste de caso inválido
    try {
        Data data;
        data.Set("20251332");
        std::cout << "Teste de data falhou: Exceçao nao foi lançada." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Teste de data invalido passou: " << e.what() << std::endl;
    }
}

// Implementação do Teste da Classe Perfil
void PerfilTeste::Run() {
    // Teste de caso válido
    try {
        Perfil perfil;
        perfil.Set("Moderado");
        assert(perfil.Get() == "Moderado");
        std::cout << "Teste do perfil passou" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Teste do perfil falhou: " << e.what() << std::endl;
    }

    // Teste de caso inválido
    try {
        Perfil perfil;
        perfil.Set("Extreme");
        std::cout << "Teste de perfil falhou: Exceçao nao foi lançada." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Teste de perfil invalido passou: " << e.what() << std::endl;
    }
}

//  Implementação do Teste da Classe Quantidade
void QuantidadeTeste::Run() {
    // Teste de caso válido
    try {
        Quantidade quantidade;
        quantidade.Set(500000);
        assert(quantidade.Get() == 500000);
        std::cout << "Teste de quantidade passou!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Teste de quantidade falhou: " << e.what() << std::endl;
    }

    // Teste de caso inválido
    try {
        Quantidade quantidade;
        quantidade.Set(1000001);
        std::cout << "Teste de valor falhou: Exceçao nao foi lançada." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Teste de valor invalido passou: " << e.what() << std::endl;
    }
}

//  Implementação do Teste da Classe Senha
void SenhaTeste::Run() {
    // Teste de caso válido
    try {
        Senha senha;
        senha.Set("A1b#c2");
        assert(senha.Get() == "A1b#c2");
        std::cout << "Teste de senha passou!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Teste de senha falhou: " << e.what() << std::endl;
    }

    // Teste de caso inválido
    try {
        Senha senha;
        senha.Set("A1bc2");
        std::cout << "Teste de senha falhou: Exceçao nao foi lançada." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Teste de senha invalido passou: " << e.what() << std::endl;
    }
}

//  Implementação do Teste da Classe Dinheiro
void DinheiroTeste::Run() {
    // Teste de caso válido
    try {
        Dinheiro dinheiro;
        dinheiro.Set(999999.99);
        assert(dinheiro.Get() == 999999.99);
        std::cout << "Teste de dinheiro passou!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Teste de dinheiro falhou: " << e.what() << std::endl;
    }

    // Teste de caso inválido
    try {
        Dinheiro dinheiro;
        dinheiro.Set(1000000.01);
        std::cout << "Teste de dinheiro falhou: Exceçao nao foi lançada." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Teste de dinheiro invalido passou: " << e.what() << std::endl;
    }
}

//  Implementação do Teste da Classe CPF
void CpfTeste::Run() {
    // Teste de caso válido
    try {
        Cpf cpf;
        cpf.Set("123.456.789-01");
        assert(cpf.Get() == "123.456.789-01");
        std::cout << "Teste de CPF passou!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Teste de CPF falhou: " << e.what() << std::endl;
    }

    // Teste de caso inválido
    try {
        Cpf cpf;
        cpf.Set("123.456.78-01");
        std::cout << "Teste de CPF falhou: Exceçao nao foi lançada." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Teste de CPF invalido passou: " << e.what() << std::endl;
    }
}
