#pragma once
#include "../../interfaces/interfaces.hpp"

class CtrlAprAuth: public InterApresAuth {
    private:
        InterServAuth* servico = nullptr;
        Cpf cpf;
        Senha senha;

        void ask_cpf_e_senha();

    public:
        CtrlAprAuth();
        bool autenticar();
};
