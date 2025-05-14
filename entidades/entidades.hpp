#pragma once
#include "../dominios/dominios.hpp"

class Account {
private:
    Cpf cpf;
    Name name;
    Password password;

public:
    // Get methods
    Cpf& GetCpf() {
        return cpf;
    }

    Name& GetName() {
        return name;
    }

    Password& GetPassword() {
        return password;
    }

    // Set methods
    void SetCpf(const Cpf& newCpf) {
        cpf = newCpf;
    }

    void SetName(const Name& newName) {
        name = newName;
    }

    void SetPassword(const Password& newPassword) {
        password = newPassword;
    }
};

class Wallet {
private:
    Code code;
    Name name;
    Profile profile;

public:
    // Get methods
    Code& GetCode() {
        return code;
    }

    Name& GetName() {
        return name;
    }

    Profile& GetProfile() {
        return profile;
    }

    // Set methods
    void SetCode(const Code& newCode) {
        code = newCode;
    }

    void SetName(const Name& newName) {
        name = newName;
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
    Code code;

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

    Code& GetCode() {
        return code;
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

    void SetCode(const Code& newCode) {
        code = newCode;
    }
};
