#pragma once
#include "../dominios/dominios.hpp"

class Account {
private:
    Cpf cpf;
    Nome nome;
    Password password;

public:
    // Get methods
    Cpf& GetCpf() {
        return cpf;
    }

    Nome& GetNome() {
        return nome;
    }

    Password& GetPassword() {
        return password;
    }

    // Set methods
    void SetCpf(const Cpf& newCpf) {
        cpf = newCpf;
    }

    void SetNome(const Nome& novo_nome) {
        nome = novo_nome;
    }

    void SetPassword(const Password& newPassword) {
        password = newPassword;
    }
};

class Wallet {
private:
    Codigo codigo;
    Nome nome;
    Profile profile;

public:
    // Get methods
    Codigo& GetCodigo() {
        return codigo;
    }

    Nome& GetNome() {
        return nome;
    }

    Profile& GetProfile() {
        return profile;
    }

    // Set methods
    void SetCodigo(const Codigo& novo_codigo) {
        codigo = novo_codigo;
    }

    void SetNome(const Nome& novo_nome) {
        nome = novo_nome;
    }

    void SetProfile(const Profile& newProfile) {
        profile = newProfile;
    }
};


class Command {
private:
    TradeCode tradeCode;
    Money money;
    Amount amount;
    Date date;
    Codigo codigo;

public:
    // Get methods
    TradeCode& GetTradeCode() {
        return tradeCode;
    }

    Money& GetMoney() {
        return money;
    }

    Amount& GetAmount() {
        return amount;
    }

    Date& GetDate() {
        return date;
    }

    Codigo& GetCodigo() {
        return codigo;
    }

    // Set methods
    void SetTradeCode(const TradeCode& newTradeCode) {
        tradeCode = newTradeCode;
    }

    void SetMoney(const Money& newMoney) {
        money = newMoney;
    }

    void SetAmount(const Amount& newAmount) {
        amount = newAmount;
    }

    void SetDate(const Date& newDate) {
        date = newDate;
    }

    void SetCode(const Codigo& novo_codigo) {
        codigo = novo_codigo;
    }
};
