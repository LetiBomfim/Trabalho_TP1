#include "../dominios/dominios.hpp"

/// @brief Representa uma conta de usuario contendo CPF, nome e senha.
/// 
/// Esta classe e usada para armazenar informacoes pessoais de um usuario
/// que acessa o sistema. Cada conta possui um CPF unico, um nome de identificacao
/// e uma senha de acesso.
class Conta {
private:
    Cpf cpf; ///< Objeto que representa o CPF do usuario.
    Nome nome; ///< Objeto que representa o CPF do usuario.
    Senha senha; ///< Objeto que representa a senha do usuario.

public:
    // Definição dos métodos Get
        /// @brief Retorna uma referencia ao CPF do usuario.
    /// @return Referencia ao objeto Cpf.
    Cpf& GetCpf() {
        return cpf;
    }

    Nome& GetNome() {
        return nome;
    }

    Senha& GetSenha() {
        return senha;
    }

    // Definição dos métodos Set
    void SetCpf(const Cpf& newCpf) {
        cpf = newCpf;
    }

    void SetNome(const Nome& novo_nome) {
        nome = novo_nome;
    }

    void SetSenha(const Senha& nova_senha) {
        senha = nova_senha;
    }
};


class Carteira {
private:
    Codigo codigo;
    Nome nome;
    Perfil perfil;

public:
    // Definição dos métodos Get
    Codigo& GetCodigo() {
        return codigo;
    }

    Nome& GetNome() {
        return nome;
    }

    Perfil& GetPerfil() {
        return perfil;
    }

    // Definição dos métodos Set
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


class Ordem {
private:
    Codigo_de_Negociacao codigo_de_negociacao;
    Dinheiro dinheiro;
    Quantidade quantidade;
    Data data;
    Codigo codigo;

public:
    // Definição dos métodos Get
    Codigo_de_Negociacao& GetCodigoDeNegociacao() {
        return codigo_de_negociacao;
    }

    Dinheiro& GetDinheiro() {
        return dinheiro;
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

    // Definição dos métodos Set
    void SetCodigoDeNegociacao(const Codigo_de_Negociacao& novo_codigo_de_negociacao) {
        codigo_de_negociacao = novo_codigo_de_negociacao;
    }

    void SetDinheiro(const Dinheiro& novo_dinheiro) {
        dinheiro = novo_dinheiro;
    }

    void SetQuantidade(const Quantidade& nova_quantidade) {
        quantidade = nova_quantidade;
    }

    void SetData(const Data& nova_data) {
        data = nova_data;
    }

    void SetCodigo(const Codigo& novo_codigo) {
        codigo = novo_codigo;
    }
};
