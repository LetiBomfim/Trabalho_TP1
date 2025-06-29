#include "storage.hpp"

using namespace std;

bool Storage::get_conta(Conta& conta) {
    lista<Conta>* curr_node = this->contas;

    while (curr_node != nullptr) {
        if (curr_node->value.GetCpf().Get() == conta.GetCpf().Get()) {
            conta.SetNome(curr_node->value.GetNome());
            conta.SetSenha(curr_node->value.GetSenha());
            return true;
        }
        curr_node = curr_node->next;
    }
    return false;
}

// não checa se o cpf existe
bool Storage::add_conta(const Conta& conta) {
    Conta conta_armazenada;
    conta_armazenada.SetCpf(conta.GetConstCpf());
    conta_armazenada.SetNome(conta.GetConstNome());
    conta_armazenada.SetSenha(conta.GetConstSenha());

    if (this->contas == nullptr) {
        this->contas = new lista<Conta>;
        this->contas->value = conta_armazenada;
        return true;
    }

    this->contas->push(conta_armazenada);
    return true;
}

bool Storage::remover_conta(const Conta& conta) {
    lista<Conta>* prev_node = nullptr;
    lista<Conta>* curr_node = this->contas;

    if (curr_node == nullptr) {
        return false;
    }

    while (curr_node != nullptr) {
        if (curr_node->value.GetConstCpf().Get() == conta.GetConstCpf().Get()) {
            if (prev_node == nullptr) {
                this->contas = curr_node->next;
                delete curr_node;
                return true;
            }

            prev_node->next = curr_node->next;
            delete curr_node;
            return true;
        }
        curr_node = curr_node->next;
    }

    return false;
}
