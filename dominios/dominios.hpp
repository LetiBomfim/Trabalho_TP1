#include <unordered_set>
#include <string>

/// @file dominios.hpp
/// @brief Declaracao das classes de dominio utilizadas no sistema financeiro.

/// @class Codigo
/// @brief Representa um numero presente no intervalo de -99999 a 99999.
class Codigo { 
private:
    int valor;  ///< Valor armazenado do codigo.

        /**
     * @brief Verifica se o valor fornecido esta no intervalo de -99999 a 99999.
     * @param val Valor do tipo inteiro a ser validado.
     * @return true se o parametro for um inteiro maior que -99999 e menor que 99999
     */

    bool isValid(int val) const;  // Função de validação da classe

public:
    /**
     * @brief Retorna o valor armazenado atualmente.
     * @return Valor inteiro do codigo.
     */
    int Get() const;

        /**
     * @brief Define um novo valor para o codigo.
     * @param novo_valor Novo valor inteiro para definicao.
     * @throw std::invalid_argument se o valor tiver mais que cinco digitos.
     */
    void Set(int novo_valor);
};

/// @class Nome
/// @brief Representa uma string para caracterizar o usuario com no maximo 20 caracteres.
class Nome {
private:
    std::string valor;

        /**
     * @brief Verifica se o parametro possui menos de 20 caracteres e nao é um espaco.
     * @param val Nome a ser validado.
     * @return true se obedecer as regras de formataçao.
     */
    bool isValid(const std::string& val) const;  // Função de validação da classe

public:
    /**
     * @brief Retorna o nome que esta armazenado.
     * @return Referencia constante ao nome.
     */
    const std::string& Get() const;

        /**
     * @brief Define um novo valor nome.
     * @param novo_valor Novo nome.
     * @throw std::invalid_argument se tiver mais que 20 caracteres ou nao for constituido apenas por alfanumericos e espacos.
     */
    void Set(const std::string& novo_valor);
};

/// @class Codigo_de_Negociacao
/// @brief Representa um codigo de negociaçao de ate 12 caracteres.
class Codigo_de_Negociacao {
private:
    std::string valor;

        /**
     * @brief Verifica se o codigo de negociaçao tem menos de 12 caracteres.
     * @param val Codigo a ser validado.
     * @return true se obedecer ao tamanho.
     */
    bool isValid(const std::string& val) const;  // Função de validação da classe

public:
    /**
     * @brief Retorna o codigo de negociaçao.
     * @return Referencia constante ao codigo de negocioacao armazenado.
     */
    const std::string& Get() const;

        /**
     * @brief Define o codigo de negociaçao com validacao.
     * @param novo_valor Novo codigo.
     * @throw std::invalid_argument se o valor tiver mais que 12 caracteres ou conter caracteres especiais.
     */
    void Set(const std::string& novo_valor);
};

/// @class Data
/// @brief Representa um marco temporal no formato AAAA/MM/DD.
class Data {
private:
    std::string valor;

        /**
     * @brief Verifica se a data possui dez digitos com barras
     * @param val Data a ser validada.
     * @return true caso cumpra o formato requerido e exista.
     */
    bool isValid(const std::string& val) const;  // Função de validação da classe

public:
    /**
     * @brief Retorna a data armazenada.
     * @return Referencia constante a string da data.
     */

    const std::string& Get() const;

        /**
     * @brief Define uma nova data.
     * @param novo_valor Data no formato AAAA/MM/DD.
     * @throw std::invalid_argument se a data nao estiver no formato AAAA/MM/DD.
     */
    void Set(const std::string& novo_valor);
};

/// @class Perfil
/// @brief Representa a caracteristica do usuario no mundo dos investimentos.
class Perfil {
private:
    std::string valor;
    /// Conjunto de perfis válidos.
    std::unordered_set<std::string> perfilvalido = {"Conservador", "Moderado", "Agressivo"};
        /**
     * @brief Verifica se o perfil inserido eh valido.
     * @param val Valor do perfil a ser verificado.
     * @return true se estiver entre conservador, moderado, agressivo.
     */
    bool isValid(const std::string& val) const;  // Função de validação da classe

public:
    /**
     * @brief Retorna o perfil armazenado.
     * @return Referencia constante a string do perfil.
     */
    const std::string& Get() const;

        /**
     * @brief Define o perfil.
     * @param novo_valor Novo valor de perfil.
     * @throw std::invalid_argument se o valor não for conservador, moderado ou agressivo.
     */
    void Set(const std::string& novo_valor);
};

/// @class Quantidade
/// @brief Representa uma quantidade de ativos ou operaçoes.
class Quantidade {
private:
    int valor;

        /**
     * @brief Verifica se a quantidade eh valida.
     * @param val Valor a ser verificado.
     * @return true se estiver entre 1 e 1.000.000.
     */
    bool isValid(int val) const;  // Função de validação da classe

public:
   /**
     * @brief Retorna a quantidade atual.
     * @return Valor inteiro da quantidade.
     */
    int Get() const;

       /**
     * @brief Define uma nova quantidade.
     * @param novo_valor Novo valor.
     * @throw std::invalid_argument se o valor nao estiver entre 1 e 1.000.000.
     */
    void Set(int novo_valor);
};


/// @class Senha
/// @brief Representa um conjunto de caracteres com funcao de segurança.
class Senha {
private:
    std::string valor;

        /**
     * @brief Verifica se a senha eh valida.
     * @param val Senha a ser verificada.
     * @return true se cumprir todos os criterios de ter 6 digitos e possuir numero, letra, maiuscula e caracter especial.
     */
    bool isValid(const std::string& val) const;  // Função de validação da classe

public:
    /**
     * @brief Retorna a senha armazenada.
     * @return Referencia constante a senha.
     */
    const std::string& Get() const;

        /**
     * @brief Define uma nova senha.
     * @param novo_valor Nova senha.
     * @throw std::invalid_argument se nao cumprir os criterios de seguranca.
     */
    void Set(const std::string& novo_valor);
};

/// @class Dinheiro
/// @brief Representa um valor monetario.
class Dinheiro {
private:
    double valor;

        /**
     * @brief Verifica se o valor esta dentro do intervalo permitido.
     * @param val Valor a ser verificado.
     * @return true se estiver entre 0,01 e 1.000.000,00.
     */
    bool isValid(double val) const;  // Função de validação da classe

public:
    /**
     * @brief Retorna o valor monetario atual.
     * @return Valor monetario double.
     */
    double Get() const;

        /**
     * @brief Define um novo valor monetario.
     * @param novo_valor Novo valor.
     * @throw std::invalid_argument se for invalido.
     */
    void Set(double novo_valor);
};



/// @class Cpf
/// @brief Representa um numero unico de identificacao pessoal no formato XXX.XXX.XXX-XX.
class Cpf {
private:
    std::string valor;

        /**
     * @brief Verifica se o CPF tem o formato correto.
     * @param val CPF a ser verificado.
     * @return true se o formato for valido.
     */
    bool isValid(const std::string& val) const;  // Função de validação da classe

public:
    /**
     * @brief Retorna o CPF atual.
     * @return Referencia constante a string do CPF.
     */
    const std::string& Get() const;
        /**
     * @brief Define um novo CPF.
     * @param novo_valor Novo CPF no formato XXX.XXX.XXX-XX.
     * @throw std::invalid_argument se o formato estiver incorreto.
     */
    void Set(const std::string& novo_valor);
};
