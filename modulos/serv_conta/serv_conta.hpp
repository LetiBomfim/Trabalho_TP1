#pragma once
#include "../../interfaces/interfaces.hpp"
#include "../storage/storage.hpp"
#include <stdexcept>

using namespace std ;

/**
 * @brief Serviço responsável pelas operações de conta.
 */
class ServConta: public InterServConta {
    private:
        InterStorage* storage = nullptr;

    public:
        /**
         * @brief Construtor da classe ServConta.
         * Inicializa o ponteiro de armazenamento com o singleton da classe Storage.
         */
        ServConta() {
            this->storage = Storage::get_singleton();
        }

        /**
         * @brief Cria uma nova conta.
         * @param conta Objeto contendo os dados da conta a ser criada.
         * @throw invalid_argument Caso a conta não possa ser criada.
         */
        void criar(const Conta& conta) {
            if (!storage->add_conta(conta)) {
                throw new invalid_argument("erro no serviço de criar conta");
            }
        };

        /**
         * @brief Lê os dados de uma conta existente.
         * @param conta Objeto Conta com o CPF preenchido. A função preenche os demais dados.
         * @throw invalid_argument Caso a conta não seja encontrada.
         */
        void ler(Conta& conta) {
            if (!storage->get_conta(conta)) {
                throw new invalid_argument("erro no serviço ler conta");
            }
        };

        /**
         * @brief Edita uma conta existente substituindo-a por uma nova.
         * @param conta Objeto Conta com os dados atualizados.
         * @throw invalid_argument Caso não seja possível salvar a nova conta.
         */
        void editar(const Conta& conta) {
            storage->remover_conta(conta);
            if (!storage->add_conta(conta)) {
                throw new invalid_argument("algo deu errado");
            }
        };

        /**
         * @brief Exclui uma conta com base no CPF fornecido.
         * @param cpf CPF associado à conta a ser removida.
         */
        void excluir(const Cpf& cpf) {
            Conta conta;
            conta.SetCpf(cpf);
            storage->remover_conta(conta);
        };
};
