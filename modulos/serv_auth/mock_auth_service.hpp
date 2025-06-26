#pragma once
#include "../../interfaces/interfaces.hpp"


class MockAuthService: public InterServAuth {
    public:
        bool autenticar(const Cpf& cpf, const Senha& senha) {
            if (cpf.Get() == "000.000.000-00") {
                return false;
            }
            return true;
        };
};
