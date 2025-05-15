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
    Perfil perfil;

public:
    // Get methods
    Codigo& GetCodigo() {
        return codigo;
    }

    Nome& GetNome() {
        return nome;
    }

    Perfil& GetPerfil() {
        return perfil;
    }

    // Set methods
    void SetCodigo(const Codigo& novo_codigo) {
        codigo = novo_codigo;
    }

    void SetNome(const Nome& novo_nome) {
        nome = novo_nome;
    }

    void SetPerfil(const Perfil& novo_perfil) {
        perfil = novo_perfil;
    }
};


class Command {
private:
    Codigo_de_Negociacao codigo_de_negociacao;
    Money money;
    Quantidade quantidade;
    Data data;
    Codigo codigo;

public:
    // Get methods
    Codigo_de_Negociacao& GetCodigoDeNegociacao() {
        return codigo_de_negociacao;
    }

    Money& GetMoney() {
        return money;
    }

    Quantidade& GetQuantidade() {
        return quantidade;
    }

    Data& GetData() {
        return data;
    }

    Codigo& GetCodigo() {
        return codigo;
    }

    // Set methods
    void SetCodigoDeNegociacao(const Codigo_de_Negociacao& novo_codigo_de_negociacao) {
        codigo_de_negociacao = novo_codigo_de_negociacao;
    }

    void SetMoney(const Money& newMoney) {
        money = newMoney;
    }

    void SetAmount(const Quantidade& nova_quantidade) {
        quantidade = nova_quantidade;
    }

    void SetDate(const Data& nova_data) {
        data = nova_data;
    }

    void SetCodigo(const Codigo& novo_codigo) {
        codigo = novo_codigo;
    }
};
