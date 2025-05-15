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

        Password password;
        password.Set("A1b#c2");
        account.SetPassword(password);

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

        Password password;
        password.Set("123456");  // Invalid password (no symbol)
        account.SetPassword(password);

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

        Profile profile;
        profile.Set("moderate");
        wallet.SetProfile(profile);

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

        Profile profile;
        profile.Set("invalid_profile");  // Invalid profile
        wallet.SetProfile(profile);

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

        TradeCode tradeCode;
        tradeCode.Set("A1B2C3");
        command.SetTradeCode(tradeCode);

        Money money;
        money.Set(500.00);
        command.SetMoney(money);

        Amount amount;
        amount.Set(1000);
        command.SetAmount(amount);

        Date date;
        date.Set("2025/05/13");
        command.SetDate(date);

        Codigo codigo;
        codigo.Set(12345);
        command.SetCode(codigo);

        std::cout << "Command Test Passed (Valid)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error setting Command: " << e.what() << std::endl;
    }
}

void CommandTest::TestInvalidCommand() {
    try {
        Command command;

        TradeCode tradeCode;
        tradeCode.Set("A1B2C3");
        command.SetTradeCode(tradeCode);

        Money money;
        money.Set(500.00);
        command.SetMoney(money);

        Amount amount;
        amount.Set(1000);
        command.SetAmount(amount);

        Date date;
        date.Set("2025/13/32");  // Invalid date
        command.SetDate(date);

        Codigo codigo;
        codigo.Set(12345);
        command.SetCode(codigo);

        std::cout << "Command Test Failed (Invalid)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error setting Command: " << e.what() << std::endl;
    }
}
