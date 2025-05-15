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
void DateTest::Run() {
    // Teste de caso válido
    try {
        Date date;
        date.Set("2025/05/13");  // Valid date
        assert(date.Get() == "2025/05/13");
        std::cout << "Date test passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Date test failed: " << e.what() << std::endl;
    }

    // Teste de caso inválido
    try {
        Date date;
        date.Set("2025/13/32");  // Invalid date
        std::cout << "Date test failed: Exception not thrown." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Date invalid test passed: " << e.what() << std::endl;
    }
}

// Implementação da Classe Perfil
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

// AmountTest Implementation
void AmountTest::Run() {
    // Valid test case
    try {
        Amount amount;
        amount.Set(500000);  // Valid amount
        assert(amount.Get() == 500000);
        std::cout << "Amount test passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Amount test failed: " << e.what() << std::endl;
    }

    // Invalid test case
    try {
        Amount amount;
        amount.Set(1000001);  // Invalid amount, too large
        std::cout << "Amount test failed: Exception not thrown." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Amount invalid test passed: " << e.what() << std::endl;
    }
}

// PasswordTest Implementation
void PasswordTest::Run() {
    // Valid test case
    try {
        Password password;
        password.Set("A1b#c2");  // Valid password
        assert(password.Get() == "A1b#c2");
        std::cout << "Password test passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Password test failed: " << e.what() << std::endl;
    }

    // Invalid test case
    try {
        Password password;
        password.Set("A1bc2");  // Invalid password (too short)
        std::cout << "Password test failed: Exception not thrown." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Password invalid test passed: " << e.what() << std::endl;
    }
}

// MoneyTest Implementation
void MoneyTest::Run() {
    // Valid test case
    try {
        Money money;
        money.Set(999999.99);  // Valid money value
        assert(money.Get() == 999999.99);
        std::cout << "Money test passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Money test failed: " << e.what() << std::endl;
    }

    // Invalid test case
    try {
        Money money;
        money.Set(1000000.01);  // Invalid value (too large)
        std::cout << "Money test failed: Exception not thrown." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Money invalid test passed: " << e.what() << std::endl;
    }
}

// CpfTest Implementation
void CpfTest::Run() {
    // Valid test case
    try {
        Cpf cpf;
        cpf.Set("123.456.789-01");  // Valid CPF
        assert(cpf.Get() == "123.456.789-01");
        std::cout << "CPF test passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "CPF test failed: " << e.what() << std::endl;
    }

    // Invalid test case
    try {
        Cpf cpf;
        cpf.Set("123.456.78-01");  // Invalid CPF (wrong length)
        std::cout << "CPF test failed: Exception not thrown." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "CPF invalid test passed: " << e.what() << std::endl;
    }
}
