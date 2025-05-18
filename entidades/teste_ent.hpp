/**
 * @file teste_ent.hpp
 * @brief Declaracao das classes de teste para entidades do sistema
 */

/**
 * @class ContaTeste
 * @brief Classe de teste para a entidade Conta
 * 
 * Responsavel por testar os cenarios validos e invalidos da entidade Conta,
 * incluindo validacao de CPF, Nome e Senha.
 */
class ContaTeste {
public:
    /**
     * @brief Executa todos os testes da classe Conta
     */
    void Run();  

private:
    /**
     * @brief Testa um cenario valido de criacao de Conta
     * 
     * Verifica se a entidade Conta aceita valores validos para CPF, Nome e Senha
     */
    void TestValidAccount();  
        /**
     * @brief Testa um cenario invalido de criacao de Conta
     * 
     * Verifica se a entidade Conta rejeita valores invalidos para os atributos
     */ 
    void TestInvalidAccount();
};

// // Declaração da Classe de Teste de Carteira

/**
 * @class CarteiraTeste
 * @brief Classe de teste para a entidade Carteira
 * 
 * Responsavel por testar os cenarios validos e invalidos da entidade Carteira,
 * incluindo validacao de Codigo, Nome e Perfil.
 */
class CarteiraTeste {
public:
    /**
     * @brief Executa todos os testes da classe Carteira
     */
    void Run();  

private:
    /**
     * @brief Testa um cenario valido de criacao de Carteira
     * 
     * Verifica se a entidade Carteira aceita valores validos para Codigo, Nome e Perfil
     */
    void TestValidWallet();  
        /**
     * @brief Testa um cenario invalido de criacao de Carteira
     * 
     * Verifica se a entidade Carteira rejeita valores invalidos para os atributos
     */ 
    void TestInvalidWallet(); 
};

// Declaração da Classe de Teste de Ordem
/**
 * @class OrdemTeste
 * @brief Classe de teste para a entidade Ordem
 * 
 * Responsavel por testar os cenarios validos e invalidos da entidade Ordem,
 * incluindo validacao de Codigo de Negociacao, Dinheiro, Quantidade e Data.
 */
class OrdemTeste {
public:
    /**
     * @brief Executa todos os testes da classe Ordem
     */
    void Run();  

private:
    /**
     * @brief Testa um cenario valido de criacao de Ordem
     * 
     * Verifica se a entidade Ordem aceita valores validos para todos os atributos
     */
    void TestValidCommand(); 
        
    /**
     * @brief Testa um cenario invalido de criacao de Ordem
     * 
     * Verifica se a entidade Ordem rejeita valores invalidos para os atributos
     */  
    void TestInvalidCommand(); 
};
