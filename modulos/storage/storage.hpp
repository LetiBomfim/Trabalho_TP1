#pragma once
#include "../../estruturas/estruturas.hpp"
#include "../../entidades/entidades.hpp"
#include "../../interfaces/interfaces.hpp"
#include <cstdint>

/**
 * @brief Serviço de armazenamento de dados do sistema.
 *
 *Responsável por gerenciar a persistência
 * e o acesso aos dados de contas, carteiras e ordens de investimento. 
 * Fornece métodos para adicionar, remover, buscar e listar
 * Implementa o padrão Singleton para garantir uma única instância durante a execução
 * do sistema.
 */
class Storage: public InterStorage {

    private:
        static Storage* singleton;
        lista<Conta>* contas;
        lista<StorageCarteira>* carteiras;
        lista<StorageOrdem>* investimentos;
        static int64_t maior_codigo_de_carteira;
        static int64_t maior_codigo_de_ordem;


    public:
    /**
     * @brief Recupera os dados de uma conta.
     * @param conta Referência para o objeto conta a ser preenchido.
     * @return true se a conta foi encontrada, false caso contrário.
     */
        bool get_conta(Conta&);
        /**
     * @brief Remove uma conta do armazenamento.
     * @param conta Objeto representando a conta a ser removida.
     * @return true se a remoção foi bem-sucedida, false caso contrário.
     */
        bool remover_conta(const Conta&);
        /**
     * @brief Adiciona uma nova conta ao armazenamento.
     * @param conta Objeto representando a conta a ser adicionada.
     * @return true se a adição foi bem-sucedida, false caso contrário.
     */
        bool add_conta(const Conta&);

        /**
     * @brief Conta o número de carteiras associadas a um usuário.
     * @param cpf Identificador do usuário.
     * @return Quantidade de carteiras do usuário.
     */
        int32_t count_carteiras_usuario(const Cpf&);

    /**
     * @brief Recupera todas as carteiras associadas a um usuário.
     * @param cpf Identificador do usuário.
     * @param carteiras Ponteiro para ponteiro de lista onde as carteiras serão armazenadas.
     * @return true se as carteiras foram encontradas, false caso contrário.
     */
        bool get_carteiras_usuario(const Cpf&, lista<Carteira>**);
         /**
     * @brief Recupera os dados de uma carteira específica.
     * @param carteira Referência para o objeto carteira a ser preenchido.
     * @return true se a carteira foi encontrada, false caso contrário.
     */
        bool get_carteira(StorageCarteira&);
         /**
     * @brief Remove uma carteira do armazenamento.
     * @param carteira Objeto representando a carteira a ser removida.
     * @return true se a remoção foi bem-sucedida, false caso contrário.
     */
        bool remover_carteira(const StorageCarteira&);
         /**
     * @brief Adiciona uma nova carteira ao armazenamento.
     * @param carteira Objeto representando a carteira a ser adicionada.
     * @return true se a adição foi bem-sucedida, false caso contrário.
     */
        bool add_carteira(const StorageCarteira&);
        /**
     * @brief Adiciona uma carteira ao armazenamento sem validações adicionais.
     * @param carteira Objeto representando a carteira a ser adicionada.
     * @return true se a adição foi bem-sucedida, false caso contrário.
     */
        bool add_carteira_unchecked(const StorageCarteira&);

        /**
     * @brief Recupera todas as ordens associadas a uma carteira.
     * @param carteira Objeto representando a carteira.
     * @param ordens Ponteiro para ponteiro de lista onde as ordens serão armazenadas.
     * @return true se as ordens foram encontradas, false caso contrário.
     */
        bool get_ordens_carteira(const Carteira&, lista<StorageOrdem>**);

         /**
     * @brief Recupera os dados de uma ordem específica.
     * @param ordem Referência para o objeto ordem a ser preenchido.
     * @return true se a ordem foi encontrada, false caso contrário.
     */
        bool get_ordem(StorageOrdem&);
          /**
     * @brief Remove uma ordem do armazenamento.
     * @param codigo Código identificador da ordem a ser removida.
     * @return true se a remoção foi bem-sucedida, false caso contrário.
     */
        bool remover_ordem(const Codigo&);
           /**
     * @brief Adiciona uma nova ordem ao armazenamento.
     * @param ordem Objeto representando a ordem a ser adicionada.
     * @return true se a adição foi bem-sucedida, false caso contrário.
     */
        bool add_ordem(const Ordem&);
    /**
     * @brief Recupera a instância singleton do serviço de armazenamento.
     * @return Ponteiro para a instância única de Storage.
     */
        static Storage* get_singleton();
};
