#include "teste_ent.hpp"
#include "entidades.hpp"
#include <iostream>

// AccountTest Class Implementation
void AccountTest::Run() {
    TestValidAccount();
    TestInvalidAccount();
}

void AccountTest::TestValidAccount() {
    try {
        Account account;

        Cpf cpf;
        cpf.Set("123.456.789-01");
        account.SetCpf(cpf);

        Nome nome;
        nome.Set("Fernando Chacon");
        account.SetNome(nome);

        Senha senha;
        senha.Set("A1b#c2");
        account.SetSenha(senha);

        std::cout << "Account Test Passed (Valid)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error setting Account: " << e.what() << std::endl;
    }
}

void AccountTest::TestInvalidAccount() {
    try {
        Account account;

        Cpf cpf;
        cpf.Set("123.456.789-01");
        account.SetCpf(cpf);

        Nome nome;
        nome.Set("Fernando Chacon");
        account.SetNome(nome);

        Senha senha;
        senha.Set("123456");  // Invalid password (no symbol)
        account.SetSenha(senha);

        std::cout << "Account Test Failed (Invalid)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error setting Account: " << e.what() << std::endl;
    }
}

// WalletTest Class Implementation
void WalletTest::Run() {
    TestValidWallet();
    TestInvalidWallet();
}

void WalletTest::TestValidWallet() {
    try {
        Wallet wallet;

        Codigo codigo;
        codigo.Set(12345);
        wallet.SetCodigo(codigo);

        Nome nome;
        nome.Set("My Wallet");
        wallet.SetNome(nome);

        Perfil perfil;
        perfil.Set("moderate");
        wallet.SetPerfil(perfil);

        std::cout << "Wallet Test Passed (Valid)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error setting Wallet: " << e.what() << std::endl;
    }
}

void WalletTest::TestInvalidWallet() {
    try {
        Wallet wallet;

        Codigo codigo;
        codigo.Set(12345);
        wallet.SetCodigo(codigo);

        Nome nome;
        nome.Set("My Wallet");
        wallet.SetNome(nome);

        Perfil perfil;
        perfil.Set("invalid_profile");  // Invalid profile
        wallet.SetPerfil(perfil);

        std::cout << "Wallet Test Failed (Invalid)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error setting Wallet: " << e.what() << std::endl;
    }
}

// CommandTest Class Implementation
void CommandTest::Run() {
    TestValidCommand();
    TestInvalidCommand();
}

void CommandTest::TestValidCommand() {
    try {
        Command command;

        Codigo_de_Negociacao codigo_de_negociacao;
        codigo_de_negociacao.Set("A1B2C3");
        command.SetCodigoDeNegociacao(codigo_de_negociacao);

        Money money;
        money.Set(500.00);
        command.SetMoney(money);

        Quantidade quantidade;
        quantidade.Set(1000);
        command.SetQuantidade(quantidade);

        Data data;
        data.Set("2025/05/13");
        command.SetData(data);

        Codigo codigo;
        codigo.Set(12345);
        command.SetCodigo(codigo);

        std::cout << "Command Test Passed (Valid)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error setting Command: " << e.what() << std::endl;
    }
}

void CommandTest::TestInvalidCommand() {
    try {
        Command command;

        Codigo_de_Negociacao codigo_de_negociacao;
        codigo_de_negociacao.Set("A1B2C3");
        command.SetCodigoDeNegociacao(codigo_de_negociacao);

        Money money;
        money.Set(500.00);
        command.SetMoney(money);

        Quantidade quantidade;
        quantidade.Set(1000);
        command.SetQuantidade(quantidade);

        Data data;
        data.Set("2025/13/32");  
        command.SetData(data);

        Codigo codigo;
        codigo.Set(12345);
        command.SetCodigo(codigo);

        std::cout << "Command Test Failed (Invalid)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error setting Command: " << e.what() << std::endl;
    }
}
