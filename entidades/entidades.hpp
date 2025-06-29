#pragma once
#include "../dominios/dominios.hpp"
/**
 * @file entidades.hpp
 * @brief Definicao das classes de entidades do sistema financeiro
 *
 * Contem as classes que representam as entidades principais:
 * - Conta (usuario do sistema);
 * - Carteira (portfolio de investimentos);
 * - Ordem (transacao financeira);
 */

/**
 * @class Conta
 * @brief Entidade que representa uma conta de usuario
 *
 * Armazena e gerencia as informacoes pessoais de um usuario:
 * - CPF (identificador unico);
 * - Nome (identificacao);
 * - Senha (acesso seguro);
 *
 */
class Conta {
private:
    Cpf cpf; ///< Objeto que representa o CPF do usuario.
    Nome nome; ///< Objeto que representa o CPF do usuario.
    Senha senha; ///< Objeto que representa a senha do usuario.

public:
    // Definição dos metodos Get
    /// @brief Retorna uma referencia ao CPF do usuario.
    /// @return Referencia ao objeto Cpf.
    Cpf& GetCpf() {
        return cpf;
    }

    const Cpf& GetConstCpf() const {
        return cpf;
    }

    /// @brief Retorna uma referência ao nome do usuario.
    /// @return Referência ao obejto Nome.
    Nome& GetNome() {
        return nome;
    }

    const Nome& GetConstNome() const {
        return nome;
    }

    /// @brief Retorna uma referencia a senha do usuario.
    /// @return Referência ao objeto Senha.
    Senha& GetSenha() {
        return senha;
    }

    const Senha& GetConstSenha() const {
        return senha;
    }


    /// @brief Define um novo CPF para o usuario.
    /// @param newCpf newCpf Novo objeto Cpf.
    void SetCpf(const Cpf& newCpf) {
        cpf = newCpf;
    }

    /// @brief Define um novo nome para o usuario.
    /// @param novo_nome Novo objeto Nome.
    void SetNome(const Nome& novo_nome) {
        nome = novo_nome;
    }

    /// @brief Define uma nova senha para o usuario.
    /// @param nova_senha Novo objeto senha.
    void SetSenha(const Senha& nova_senha) {
        senha = nova_senha;
    }
};

/**
 * @class Carteira
 * @brief Entidade que representa um portfolio de investimentos;
 *
 * Contem as informacoes de:
 * - Codigo identificador;
 * - Nome descritivo;
 * - Perfil de risco (conservador, moderado, agressivo);
 */
class Carteira {
private:
    Codigo codigo;  ///< Codigo indentificador da carteira.
    Nome nome;  /// < Nome da carteira.
    Perfil perfil;  ///< Perfil do investidor (ex: conservador, moderado, agressivo)

public:
     /**
     * @brief Obtem o codigo da carteira
     * @return Referencia para o objeto Codigo.
     */
    Codigo& GetCodigo() {
        return codigo;
    }

    const Codigo& GetConstCodigo() const {
        return  codigo;
    }

    /**
     * @brief Obtem o nome da carteira
     * @return Referencia para o objeto Nome.
     */
    Nome& GetNome() {
        return nome;
    }

    const Nome& GetConstNome() const{
        return nome;
    }

    /**
     * @brief Obtem o perfil da carteira
     * @return Referencia para o objeto Perfil.
     */
    Perfil& GetPerfil() {
        return perfil;
    }

    const Perfil& GetConstPerfil() const {
        return perfil;
    }

    /// @brief Define um novo codigo para o codigo.
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

/**
 * @class Ordem
 * @brief Entidade que representa uma transacao financeira.
 *
 * Contem todos os dados necessarios para:
 * - Identificacao do ativo (codigo de negociacao);
 * - Valor e quantidade da operacao;
 * - Data da transacao;
 * - Vinculo com a carteira;
 */
class Ordem {
private:
    Codigo_de_Negociacao codigo_de_negociacao;  ///< Codigo do ativo negociado.
    Dinheiro dinheiro;                          ///< Valor financeiro da ordem.
    Quantidade quantidade;                      ///< Quantidade de ativos.
    Data data;                                  ///< Data da ordem.
    Codigo codigo;                              ///< Codigo da carteira vinculada a ordem.

public:
       /**
     * @brief Obtem o codigo de negociacao.
     * @return Referencia para o objeto Codigo_de_Negociacao.
     */
    Codigo_de_Negociacao& GetCodigoDeNegociacao() {
        return codigo_de_negociacao;
    }

      /**
     * @brief Obtem o valor financeiro.
     * @return Referencia para o objeto Dinheiro.
     */
    Dinheiro& GetDinheiro() {
        return dinheiro;
    }

       /**
     * @brief Obtem a quantidade de ativos.
     * @return Referencia para o objeto Quantidade.
     */
    Quantidade& GetQuantidade() {
        return quantidade;
    }

      /**
     * @brief Obtem a data da ordem.
     * @return Referencia para o objeto Data.
     */
    Data& GetData() {
        return data;
    }

       /**
     * @brief Obtem o codigo da carteira.
     * @return Referencia para o objeto Codigo.
     */
    Codigo& GetCodigo() {
        return codigo;
    }

    /**
     * @brief Define o codigo de negociacao.
     * @param novo_codigo_de_negociacao Objeto validado.
     */
    void SetCodigoDeNegociacao(const Codigo_de_Negociacao& novo_codigo_de_negociacao) {
        codigo_de_negociacao = novo_codigo_de_negociacao;
    }

      /**
     * @brief Define o valor financeiro.
     * @param novo_dinheiro Objeto validado.
     */
    void SetDinheiro(const Dinheiro& novo_dinheiro) {
        dinheiro = novo_dinheiro;
    }

        /**
     * @brief Define a quantidade.
     * @param nova_quantidade Objeto validado
     */
    void SetQuantidade(const Quantidade& nova_quantidade) {
        quantidade = nova_quantidade;
    }

     /**
     * @brief Define a data da ordem.
     * @param nova_data Objeto validado.
     */
    void SetData(const Data& nova_data) {
        data = nova_data;
    }

     /**
     * @brief Define a carteira associada.
     * @param novo_codigo Objeto validado.
     */
    void SetCodigo(const Codigo& novo_codigo) {
        codigo = novo_codigo;
    }
};


class StorageCarteira: public Carteira {
    Cpf cpf_associado;

    public:
        Cpf& GetCpfAssociado() {
            return this->cpf_associado;
        };

        const Cpf& GetConstCpfAssociado() const {
            return this->cpf_associado;
        }

        void SetCpfAssociado(const Cpf& cpf) {
            this->cpf_associado.Set(cpf.Get());
        }

};
