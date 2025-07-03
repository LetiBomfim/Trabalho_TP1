#pragma once
#include "../../interfaces/interfaces.hpp"

class CtrlAprAuth: public InterApresAuth {
    private:
        InterServAuth* servico = nullptr;

        void ask_cpf_e_senha(Cpf&, Senha&);

    public:
        CtrlAprAuth();
        bool autenticar(Cpf&);
};
