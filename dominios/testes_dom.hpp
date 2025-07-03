#pragma once
/**
 * @file testes_dom.h
 * @brief Verificacao das entidades do sistema e seu funcionamento atraves de testes unitarios
 */
class CodigoTeste;
class NomeTeste;
class Codigo_de_NegociacaoTeste;
class DataTeste;
class PerfilTeste;
class QuantidadeTeste;
class SenhaTeste;
class DinheiroTeste;
class CpfTeste;

// Classe de teste para Codigo
/**
 * @class CodigoTeste
 * @brief Classe de teste para validaçao da entidade Codigo.
 *
 * Faz testes unitarios para acompanhar o funcionamento da classe Codigo.
 */
class CodigoTeste {
public:
    /**
     * @brief Roda os testes unitarios referentes a classe Codigo.
     */
    void Run();
};

// Classe de teste para Nome
/**
 * @class NomeTeste
 * @brief Classe de teste para verificacao da entidade Nome.
 *
 * Implementa testes unitarios para validar o funcionamento da classe Nome.
 */
class NomeTeste {
public:
    /**
     * @brief Roda os testes unitarios referentes a classe Nome.
     */
    void Run();
};

// Classe de Teste para Código de Negociação
/**
 * @class Codigo_de_NegociacaoTeste
 * @brief Classe de teste para validacao da entidade Codigo de Negociacao.
 *
 * Implementa testes unitarios para verificar o funcionamento correto da classe Codigo de Negociacao.
 */
class Codigo_de_NegociacaoTeste {
public:
    /**
     * @brief Roda os testes unitarios referentes a classe Codigo de Negociacao.
     */
    void Run();
};

// Classe de Teste para Data
/**
 * @class DataTeste
 * @brief Classe de teste para validar a entidade Data.
 *
 * Implementa testes unitarios para verificar o funcionamento correto da classe Data.
 */
class DataTeste {
public:
    /**
     * @brief Roda todos os testes unitarios referentes a classe Data.
     */
    void Run();
};

// Classe de Teste para Perfil
/**
 * @class PerfilTeste
 * @brief Classe de teste para validacao da entidade Perfil.
 *
 * Implementa testes unitarios para verificar o funcionamento correto da classe Perfil.
 */
class PerfilTeste {
public:
    /**
     * @brief Roda todos os testes unitarios referentes a classe Perfil.
     */
    void Run();
};

// Classe de Teste para Quantidade
/**
 * @class QuantidadeTeste
 * @brief Classe de teste para validacao da entidade Quantidade.
 *
 * Implementa testes unitarios para verificar o funcionamento correto da classe Quantidade.
 */
class QuantidadeTeste {
public:
    /**
     * @brief Roda todos os testes unitarios referentes a classe Quantidade.
     */
    void Run();
};

// Classe de Teste para Senha
/**
 * @class SenhaTeste
 * @brief Classe de teste para validacao da entidade Senha.
 *
 * Implementa testes unitarios para verificar o funcionamento correto da classe Senha.
 */
class SenhaTeste {
public:
    /**
     * @brief Roda todos os testes unitarios referentes a classe Senha.
     */
    void Run();
};

// Classe de Teste para Dinheiro
/**
 * @class DinheiroTeste
 * @brief Classe de teste para validacao da entidade Dinheiro.
 *
 * Implementa testes unitarios para verificar o funcionamento correto da classe Dinheiro.
 */
class DinheiroTeste {
public:
    /**
     * @brief Roda todos os testes unitarios referentes a classe Dinheiro.
     */
    void Run();
};

// Classe de Teste para CPF
/**
 * @class CpfTeste
 * @brief Classe de teste para validacao da entidade CPF.
 *
 * Implementa testes unitarios para verificar o funcionamento correto da classe CPF.
 */
class CpfTeste {
public:
    /**
     * @brief Roda  os testes unitarios referentes a classe CPF.
     */
    void Run();
};
