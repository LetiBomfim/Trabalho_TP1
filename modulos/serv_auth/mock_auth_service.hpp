#pragma once
#include "../../interfaces/interfaces.hpp"
#include "../storage/storage.hpp"


class MockAuthService: public InterServAuth {
    public:
        bool autenticar(const Cpf& cpf, const Senha& senha) {
            Storage* storage;
            Conta conta;

            storage = Storage::get_singleton();
            conta.SetCpf(cpf);

            if (!storage->get_conta(conta)) {
                return false;
            }

            if (conta.GetConstSenha().Get() != senha.Get()) {
                return false;
            }

            return true;
        };
};
