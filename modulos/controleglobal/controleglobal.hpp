#pragma once
#include "../../interfaces/interfaces.hpp"

#include <cstdint>

using namespace std ;

/**
 * @brief Controlador principal do sistema.
 *
 * Esta classe centraliza o fluxo de execução da aplicação, coordenando a navegação entre os módulos
 * de autenticação, conta e investimento.
 */
class ControleGlobal {
    static const int32_t LOGIN = 0;
    static const int32_t REGISTER = 1;
    static const int32_t CONTA = 2;
    static const int32_t INVESTIMENTO = 3;


    private:
    static ControleGlobal* singleton;
        InterApresAuth* apr_auth = nullptr;
        InterApresConta* apr_conta = nullptr;
        InterApresInvest* apr_invest = nullptr;

        int32_t escolha = LOGIN;
        bool autenticado = false;
        Cpf cpf_usuario;
        int32_t ask_usuario();

    public:
        // seta a autenticação caso seja necessário
         /**
        * @brief Define o estado de autenticação do sistema.
        * @param estado Valor booleano indicando se o usuário está autenticado.
        */
        static void SetAuth(bool estado) {
            ControleGlobal::singleton->autenticado = estado;
        };


        /**
         * @brief Recupera a instância singleton do controlador global.
         * @return Ponteiro para a instância única de ControleGlobal.
         */
        static ControleGlobal* get_singleton();

        // Realiza o setup do projeto
        /**
        * @brief Construtor padrão. Realiza o setup inicial do sistema.
        */
        ControleGlobal();

        // Ponto de entrada do sistema
        /**
        * @brief Ponto de entrada principal do sistema. Inicia o fluxo de execução da aplicação.
        */
        void Run();

};
