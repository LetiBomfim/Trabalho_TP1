#pragma once
#include "../../interfaces/interfaces.hpp"
#include "../../modulos/apr_auth/apr_auth.hpp"
#include <cstdint>

using namespace std ;

class ControleGlobal {
    static const int32_t AUTH = 0;
    static const int32_t CONTA = 2;
    static const int32_t INVESTIMENTO = 3;

    private:
        InterApresAuth* apr_auth = nullptr;
        InterApresConta* apr_conta = nullptr;
        InterApresInvest* apr_invest = nullptr;

        int32_t escolha = AUTH;

        void menu();
        int32_t ask_usuario();

    public:
        // Realiza o setup do projeto
        ControleGlobal() {
            this->apr_auth = new CtrlAprAuth();
        };

        // Ponto de entrada do sistema
        void Run();
};
