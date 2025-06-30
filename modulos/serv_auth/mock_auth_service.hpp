#pragma once
#include "../../interfaces/interfaces.hpp"
#include "../storage/storage.hpp"


class AuthService: public InterServAuth {
    private:
        InterStorage* storage = nullptr;

    public:
        AuthService() {
            this->storage = Storage::get_singleton();
        }

        bool autenticar(const Cpf& cpf, const Senha& senha) {
            Conta conta;

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
