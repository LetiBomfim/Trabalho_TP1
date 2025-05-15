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
        codigo.Set(12345);  
        assert(codigo.Get() == 12345);
        std::cout << "Teste de código passou no teste" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Teste de código falhou: " << e.what() << std::endl;
    }

    // Teste de caso inválido
    try {
        Codigo codigo;
        codigo.Set(123456);  
        std::cout << "Teste de código falhou: Exceção não foi lançada." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Teste de código inválido passou: " << e.what() << std::endl;
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
        std::cout << "Teste de nome falhou: Exceção não foi lançada." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Teste de nome inválido passou: " << e.what() << std::endl;
    }
}

// Implementação do Teste da Classe Codigo_de_Negociacao
void Codigo_de_NegociacaoTeste::Run() {
    // Teste de caso válido
    try {
        Codigo_de_Negociacao codigo_de_negociacao;
        codigo_de_negociacao.Set("A1B2C3"); 
        assert(codigo_de_negociacao.Get() == "A1B2C3");
        std::cout << "Teste do código de negociação passou" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Teste do código de negociação falhou: " << e.what() << std::endl;
    }

    // Teste de caso inválido
    try {
        Codigo_de_Negociacao codigo_de_negociacao;
        codigo_de_negociacao.Set("A1B@C3");  
        std::cout << "Teste de código de negociação falhou: Exceção não foi lançada." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Teste de código de negociação inválido passou: " << e.what() << std::endl;
    }
}

// Implementação do Teste da Classe Data
void DataTeste::Run() {
    // Teste de caso válido
    try {
        Data data;
        data.Set("2025/05/13");  
        assert(data.Get() == "2025/05/13");
        std::cout << "Teste de data passou!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Teste de data falhou: " << e.what() << std::endl;
    }

    // Teste de caso inválido
    try {
        Data data;
        data.Set("2025/13/32");  
        std::cout << "Teste de data falhou: Exceção não foi lançada." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Teste de data inválido passou: " << e.what() << std::endl;
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
        std::cout << "Teste de perfil falhou: Exceção não foi lançada." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Teste de perfil inválido passou: " << e.what() << std::endl;
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
        std::cout << "Teste de valor falhou: Exceção não foi lançada." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Teste de valor inválido passou: " << e.what() << std::endl;
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
        std::cout << "Teste de senha falhou: Exceção não foi lançada." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Teste de senha inválido passou: " << e.what() << std::endl;
    }
}

//  Implementação do Teste da Classe Dinheiro
void MoneyTest::Run() {
    // Teste de caso válido
    try {
        Money money;
        money.Set(999999.99);  
        assert(money.Get() == 999999.99);
        std::cout << "Money test passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Money test failed: " << e.what() << std::endl;
    }

    // Teste de caso inválido
    try {
        Money money;
        money.Set(1000000.01);  
        std::cout << "Money test failed: Exception not thrown." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Money invalid test passed: " << e.what() << std::endl;
    }
}

//  Implementação do Teste da Classe CPF
void CpfTest::Run() {
    // Teste de caso válido
    try {
        Cpf cpf;
        cpf.Set("123.456.789-01");  
        assert(cpf.Get() == "123.456.789-01");
        std::cout << "CPF test passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "CPF test failed: " << e.what() << std::endl;
    }

    // Teste de caso inválido
    try {
        Cpf cpf;
        cpf.Set("123.456.78-01");  
        std::cout << "CPF test failed: Exception not thrown." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "CPF invalid test passed: " << e.what() << std::endl;
    }
}
