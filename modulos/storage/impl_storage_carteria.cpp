#include "storage.hpp"
#include <cstdlib>
#include <string>

using namespace std;

bool Storage::get_carteiras_usuario(const Cpf& cpf, lista<Carteira>** ls) {
    auto curr_cart = this->carteiras;
    lista<Carteira>* carts_usuario;
    bool achou_alguma = false;

    while (curr_cart != nullptr) {
        if (curr_cart->value.GetCpfAssociado().Get() == cpf.Get()) {
            achou_alguma = true;
            if (carts_usuario == nullptr) {
                carts_usuario = new lista<Carteira>;
                carts_usuario->value = curr_cart->value;
            } else {
                carts_usuario->push(curr_cart->value);
            }
        }

        curr_cart = curr_cart->next;
    }

    *ls = carts_usuario;
    return achou_alguma;
}

bool Storage::get_carteira(StorageCarteira& carteira) {
    lista<StorageCarteira>* curr_node = this->carteiras;

    while (curr_node != nullptr) {
        if (curr_node->value.GetCodigo().Get() == carteira.GetCodigo().Get()) {
            carteira.SetNome(curr_node->value.GetNome());
            carteira.SetCpfAssociado(curr_node->value.GetCpfAssociado());
            carteira.SetPerfil(curr_node->value.GetPerfil());
            return true;
        }
        curr_node = curr_node->next;
    }
    return false;
}

bool Storage::remover_carteira(const StorageCarteira& carteira) {
    lista<StorageCarteira>* prev_node = nullptr;
    lista<StorageCarteira>* curr_node = this->carteiras;

    while (curr_node != nullptr) {
        if (curr_node->value.GetConstCodigo().Get() == carteira.GetConstCodigo().Get()) {
            if (prev_node == nullptr) {
                this->carteiras = curr_node->next;
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

// não checa se o aquele código já existe existe
bool Storage::add_carteira(const StorageCarteira& carteira) {
    StorageCarteira cart_armazenada;
    Codigo novo_codigo;

    novo_codigo.Set(to_string(++Storage::maior_codigo_de_carteira));
    cart_armazenada.SetCpfAssociado(carteira.GetConstCpfAssociado());
    cart_armazenada.SetCodigo(novo_codigo);
    cart_armazenada.SetNome(carteira.GetConstNome());
    cart_armazenada.SetPerfil(carteira.GetConstPerfil());

    if (this->contas == nullptr) {
        this->carteiras = new lista<StorageCarteira>;
        this->carteiras->value = cart_armazenada;
    }

    this->carteiras->push(cart_armazenada);
    return true;
}
