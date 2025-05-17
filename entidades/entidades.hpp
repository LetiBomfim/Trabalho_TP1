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

    /// @brief Retorna uma referência ao nome do usuário.
    /// @return Referência ao obejto Nome.
    Nome& GetNome() {
        return nome;
    }
    
    /// @brief Retorna uma referência à senha do usuário.
    /// @return Referência ao objeto Senha.
    Senha& GetSenha() {
        return senha;
    }

    /// @brief Define um novo CPF para o usuário.
    /// @param newCpf newCpf Novo objeto Cpf.
    void SetCpf(const Cpf& newCpf) {
        cpf = newCpf;
    }

    /// @brief Define um novo nome para o usuário.
    /// @param novo_nome Novo objeto Nome.
    void SetNome(const Nome& novo_nome) {
        nome = novo_nome;
    }

    /// @brief Define uma nova senha para o usuário.
    /// @param nova_senha Novo objeto senha.
    void SetSenha(const Senha& nova_senha) {
        senha = nova_senha;
    }
};

/// @brief Representa uma carteira de investimentos com código, nome e perfil.
///
/// A carteira está associada a um usuário e contém um perfil de investidor,
/// além de um nome e um código identificador.
class Carteira {
private:
    Codigo codigo;  ///< Código indentificador da carteira.
    Nome nome;  /// < Nome da carteira.
    Perfil perfil;  ///< Perfil do investidor (ex: conservador, moderado, agressivo)

public:
    /// @brief Retorna o código da carteira.
    Codigo& GetCodigo() {
        return codigo;
    }

    /// @brief Retorna o nome da carteira.
    Nome& GetNome() {
        return nome;
    }

    /// @brief Retorna o perfil do investidor.
    Perfil& GetPerfil() {
        return perfil;
    }

    /// @brief Define um novo código para o código.
    /// @param novo_codigo Novo objeto Codigo.
    void SetCodigo(const Codigo& novo_codigo) {
        codigo = novo_codigo;
    }

    /// @brief Define um novo nome para a carteira.
    /// @param novo_nome Novo objeto Nome.
    void SetNome(const Nome& novo_nome) {
        nome = novo_nome;
    }

    /// @brief Define um novo perfil para a carteira.
    /// @param novo_perfilNovo Novo objeto Perfil.
    void SetPerfil(const Perfil& novo_perfil) {
        perfil = novo_perfil;
    }
};

/// @brief Representa uma ordem de compra ou venda de ativos.
///
/// Cada ordem contém informações como código de negociação, valor,
/// quantidade, data da ordem e a carteira à qual ela está associada.
class Ordem {
private:
    Codigo_de_Negociacao codigo_de_negociacao;  ///< Código do ativo negociado.
    Dinheiro dinheiro;                          ///< Valor financeiro da ordem.
    Quantidade quantidade;                      ///< Quantidade de ativos.
    Data data;                                  ///< Data da ordem.
    Codigo codigo;                              ///< Código da carteira vinculada à ordem.

public:
    /// @brief Retorna o código de negociação da ordem.
    Codigo_de_Negociacao& GetCodigoDeNegociacao() {
        return codigo_de_negociacao;
    }

    /// @brief Retorna o valor financeiro da ordem.
    Dinheiro& GetDinheiro() {
        return dinheiro;
    }

    /// @brief Retorna a quantidade de ativos na ordem.
    Quantidade& GetQuantidade() {
        return quantidade;
    }

    /// @brief Retorna a data da ordem.
    Data& GetData() {
        return data;
    }

    /// @brief Retorna o código da carteira associada à ordem.
    Codigo& GetCodigo() {
        return codigo;
    }

    /// @brief Define o código de negociação da ordem.
    void SetCodigoDeNegociacao(const Codigo_de_Negociacao& novo_codigo_de_negociacao) {
        codigo_de_negociacao = novo_codigo_de_negociacao;
    }

    /// @brief Define o valor financeiro da ordem.
    void SetDinheiro(const Dinheiro& novo_dinheiro) {
        dinheiro = novo_dinheiro;
    }

    /// @brief Define a quantidade de ativos da ordem.
    void SetQuantidade(const Quantidade& nova_quantidade) {
        quantidade = nova_quantidade;
    }

    /// @brief Define a data da ordem. 
    void SetData(const Data& nova_data) {
        data = nova_data;
    }

    /// @brief Define o código da carteira associada à ordem.
    void SetCodigo(const Codigo& novo_codigo) {
        codigo = novo_codigo;
    }
};
