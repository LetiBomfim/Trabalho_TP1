#pragma once
#include "../../interfaces/interfaces.hpp"
#include "../storage/storage.hpp"

/**
 * @brief Serviço responsável por autenticar usuários com base em CPF e senha.
 */
class AuthService: public InterServAuth {
    private:
        InterStorage* storage = nullptr;

    public:
        /**
         * @brief Construtor da classe AuthService.
         * Inicializa o ponteiro de armazenamento com o singleton da classe Storage.
         */
        AuthService() {
            this->storage = Storage::get_singleton();
        }

        /**
         * @brief Autentica um usuário com base no CPF e senha fornecidos.
         * @param cpf CPF do usuário.
         * @param senha Senha do usuário.
         * @return true se as credenciais forem válidas, false caso contrário.
         */
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
