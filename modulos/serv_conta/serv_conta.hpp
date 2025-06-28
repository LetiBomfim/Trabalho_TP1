#pragma once
#include "../../interfaces/interfaces.hpp"
#include "../storage/storage.hpp"
#include <stdexcept>

using namespace std ;

class MockServConta: public InterServConta {
    public:
        void criar(const Conta& conta) {
            Storage* storage = Storage::get_singleton();

            if (!storage->add_conta(conta)) {
                throw new invalid_argument("erro no serviço de criar conta");
            }
        };

        void ler(Conta& conta) {
            Storage* storage = Storage::get_singleton();

            if (!storage->get_conta(conta)) {
                throw new invalid_argument("erro no serviço ler conta");
            }
        };

        void editar(const Conta& conta) {};
        void excluir(const Cpf& cpf) {};
};
