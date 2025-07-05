#pragma once
#include "../entidades/entidades.hpp"
#include "../estruturas/estruturas.hpp"

class InterServAuth {
    public:
        virtual bool autenticar(const Cpf&, const Senha&) = 0;
};

class InterServConta {
    public:
        virtual void criar(const Conta&) = 0;
        virtual void ler(Conta& conta) = 0;
        virtual void editar(const Conta& conta) = 0;
        virtual void excluir(const Cpf& cpf) = 0;
};



/**
 * @brief Define o contrato para operações de gerenciamento de carteiras e ordens de investimento,
 * incluindo criação, edição, exclusão e listagem.
 */
class InterServInvest {
    public:
        /**
         * @brief Cria uma nova carteira para o usuário, caso o mesmo seja válido.
         * @param carteira Objeto contendo os dados do portfólio de investimentos.
         * @param cpf Identificador do usuário proprietário da carteira.
         * @throw invalid_argument
         */
        virtual void criar_cart(const Carteira&, const Cpf&) = 0;
        /**
         * @brief Atualiza as informações de uma carteira já existente.
         * @param carteira.
         */
        virtual void editar_cart(const Carteira&) = 0;
        /**
         * @brief exclui uma carteira já existente .
         * @param carteira.
         */
        virtual void excluir_cart(const Carteira&) = 0;
        /**
         * @brief Armazena o cpf do usuário em uma lista, se somente se, o mesmo ainda não tenha sido cadastrado.
         * @param cpf.
         * @return nulltpr caso o cpf informado já tenha sido cadastrado.
         * @return lst Ponteiro para uma lista de carteira, se somete se, o cpf ainda não tenha sido cadastrado.
         */
        virtual lista<Carteira>* listar_cart(const Cpf&) = 0;
        /**
        * @brief Cria uma nova ordem de investimento para uma carteira existente, caso os dados informados seja válidos.
        * @param ordem Objeto contendo os dados da ordem, como código de negociação, data e quantidade.
        * @throw invalid_argument
        */
        virtual void criar_ordem(const Ordem&) = 0;
        /**
         * @brief exclui a ordem de uma carteira já existente.
         * @param codigo número que identifica uma ordem específica
         * @throw invalid_argument
         */
        virtual void excluir_ordem(const Codigo&) = 0;
        /**
         * @brief Armazena a ordem  de uma carteria  em uma lista.
         * @param carteira Objeto que contém as informações referentes aos ativos financeiros que um investidor possui.
         * @throw invalid_argument
         * @return nulltptr Caso a carteira do usuário ainda não tenha sido cadastrada.
         * @return ls Ponteiro para a lista de ordens,se somente se, todas as informações declaradas forem válidas. 
         */
        virtual lista<StorageOrdem>* listar_ordem(const Carteira&) = 0;
};

class InterApresAuth {
    public:
            virtual bool autenticar(Cpf&) = 0;
};

class InterApresConta {
    public:
        virtual void executar(const Cpf*) = 0;
};

/**
 * @brief Define o contrato para controladores da camada de apresentação do módulo de investimentos.
 * Responsável por iniciar e gerenciar o fluxo de interação do usuário com as funcionalidades de investimento.
 */
class InterApresInvest {
    public:
       /**
         * @brief Inicia o fluxo de apresentação das operações de investimento para o usuário informado.
         * @param cpf Identificador do usuário autenticado.
         */
        virtual void executar(const Cpf&) = 0;
};

/**
 * @brief Define o contrato para operações de acesso e manipulação dos dados persistentes do sistema.
 * Inclui métodos para contas, carteiras e ordens de investimento.
 */
class InterStorage {

    public:
        // funções relacionadas à conta
        /**
         * @brief Recupera os dados de uma conta.
         * @param conta Referência para o objeto conta a ser preenchido.
         * @return true se a conta foi encontrada, false caso contrário.
         */
        virtual bool get_conta(Conta&) = 0;
        /**
        * @brief Remove uma conta do armazenamento.
        * @param conta Objeto representando a conta a ser removida.
        * @return true se a remoção foi bem-sucedida, false caso contrário.
        */
        virtual bool remover_conta(const Conta&) = 0;

        /**
         * @brief Adiciona uma nova conta ao armazenamento.
         * @param conta Objeto representando a conta a ser adicionada.
         * @return true se a adição foi bem-sucedida, false caso contrário.
         */
        virtual bool add_conta(const Conta&) = 0;

        // funções relacionadas à carteira
        /**
        * @brief Conta o número de carteiras associadas a um usuário.
        * @param cpf Identificador do usuário.
        * @return Quantidade de carteiras do usuário.
        */
        virtual int32_t count_carteiras_usuario(const Cpf&) = 0;
        /**
        * @brief Recupera todas as carteiras associadas a um usuário.
        * @param cpf Identificador do usuário.
        * @param carteiras Ponteiro para ponteiro de lista onde as carteiras serão armazenadas.
        * @return true se as carteiras foram encontradas, false caso contrário.
        */
        virtual bool get_carteiras_usuario(const Cpf&, lista<Carteira>**) = 0;
        /**
        * @brief Recupera os dados de uma carteira específica.
        * @param carteira Referência para o objeto carteira a ser preenchido.
        * @return true se a carteira foi encontrada, false caso contrário.
        */
        virtual bool get_carteira(StorageCarteira&) = 0;
        /**
        * @brief Remove uma carteira do armazenamento.
        * @param carteira Objeto representando a carteira a ser removida.
        * @return true se a remoção foi bem-sucedida, false caso contrário.
        */
        virtual bool remover_carteira(const StorageCarteira&) = 0;
        /**
        * @brief Adiciona uma nova carteira ao armazenamento.
        * @param carteira Objeto representando a carteira a ser adicionada.
        * @return true se a adição foi bem-sucedida, false caso contrário.
        */
        virtual bool add_carteira(const StorageCarteira&) = 0;
        /**
        * @brief Adiciona uma carteira ao armazenamento sem validações adicionais.
        * @param carteira Objeto representando a carteira a ser adicionada.
        * @return true se a adição foi bem-sucedida, false caso contrário.
        */
        virtual bool add_carteira_unchecked(const StorageCarteira&) = 0;

        // funções relacionadas à ordem
        /**
        * @brief Recupera todas as ordens associadas a uma carteira.
        * @param carteira Objeto representando a carteira.
        * @param ordens Ponteiro para ponteiro de lista onde as ordens serão armazenadas.
        * @return true se as ordens foram encontradas, false caso contrário.
        */
        virtual bool get_ordens_carteira(const Carteira&, lista<StorageOrdem>**) = 0;

        /**
        * @brief Recupera os dados de uma ordem específica.
        * @param ordem Referência para o objeto ordem a ser preenchido.
        * @return true se a ordem foi encontrada, false caso contrário.
        */
        virtual bool get_ordem(StorageOrdem&) = 0;
        /**
         * @brief Remove uma ordem do armazenamento.
         * @param codigo Código identificador da ordem a ser removida.
         * @return true se a remoção foi bem-sucedida, false caso contrário.
         */
        virtual bool remover_ordem(const Codigo&) = 0;
        /**
         * @brief Adiciona uma nova ordem ao armazenamento.
         * @param ordem Objeto representando a ordem a ser adicionada.
         * @return true se a adição foi bem-sucedida, false caso contrário.
         */
        virtual bool add_ordem(const Ordem&) = 0;
};

/**
 * @brief Define o contrato para atualização de valores de ordens com base em dados históricos.
 * Utilizada para garantir que as ordens estejam associadas aos valores corretos do mercado.
 */class InterDadosHist {
    public:
        /**
         * @brief Atualiza o valor de uma ordem com base nos dados históricos disponíveis.
         * @param ordem Referência para o objeto ordem a ser atualizado.
         * @return true se a atualização foi bem-sucedida, false caso contrário.
         */
        virtual bool set_valor_ordem(Ordem&) = 0;
};
