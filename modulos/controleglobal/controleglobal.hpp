#pragma once
#include "../../interfaces/interfaces.hpp"

#include <cstdint>

using namespace std ;

class ControleGlobal {
    static const int32_t LOGIN = 0;
    static const int32_t REGISTER = 1;
    static const int32_t CONTA = 2;
    static const int32_t INVESTIMENTO = 3;


    private:
        InterApresAuth* apr_auth = nullptr;
        InterApresConta* apr_conta = nullptr;
        InterApresInvest* apr_invest = nullptr;

        int32_t escolha = LOGIN;
        bool autenticado = false;
        Cpf cpf_usuario;
        int32_t ask_usuario();

    public:
        static ControleGlobal* singleton;

        // seta a autenticação caso seja necessário
        static void SetAuth(bool estado) {
            ControleGlobal::singleton->autenticado = estado;
        };

        // Realiza o setup do projeto
        ControleGlobal();

        // Ponto de entrada do sistema
        void Run();

};
