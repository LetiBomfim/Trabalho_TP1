#pragma once
#include "../../interfaces/interfaces.hpp"
#include "../storage/storage.hpp"
#include <stdexcept>

using namespace std ;

class ServConta: public InterServConta {
    private:
        InterStorage* storage = nullptr;

    public:
        ServConta() {
            this->storage = Storage::get_singleton();
        }

        void criar(const Conta& conta) {
            if (!storage->add_conta(conta)) {
                throw new invalid_argument("erro no serviço de criar conta");
            }
        };

        void ler(Conta& conta) {
            if (!storage->get_conta(conta)) {
                throw new invalid_argument("erro no serviço ler conta");
            }
        };

        void editar(const Conta& conta) {
            storage->remover_conta(conta);
            if (!storage->add_conta(conta)) {
                throw new invalid_argument("algo deu errado");
            }
        };

        void excluir(const Cpf& cpf) {
            Conta conta;
            conta.SetCpf(cpf);
            storage->remover_conta(conta);
        };
};
