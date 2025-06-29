#include "storage.hpp"
#include <cstdlib>
#include <string>

using namespace std;

bool Storage::get_carteiras_usuario(const Cpf& cpf, lista<Carteira>** ls) {
    auto curr_cart = this->carteiras;
    lista<Carteira>* carts_usuario = nullptr;
    bool achou_alguma = false;

    if (this->carteiras == nullptr) return false;

    while (curr_cart != nullptr) {
        if (curr_cart->value.GetCpfAssociado().Get() == cpf.Get()) {
            achou_alguma = true;
            if (carts_usuario == nullptr) {
                carts_usuario = new lista<Carteira>;
                carts_usuario->value.SetCodigo(curr_cart->value.GetConstCodigo());
                carts_usuario->value.SetNome(curr_cart->value.GetConstNome());
                carts_usuario->value.SetPerfil(curr_cart->value.GetConstPerfil());
            } else {
                Carteira nova_cart;
                nova_cart.SetCodigo(curr_cart->value.GetConstCodigo());
                nova_cart.SetPerfil(curr_cart->value.GetConstPerfil());
                nova_cart.SetNome(curr_cart->value.GetConstNome());
                carts_usuario->push(nova_cart);
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

// aloca um código padrão
bool Storage::add_carteira(const StorageCarteira& carteira) {
    StorageCarteira cart_armazenada;
    Codigo novo_codigo;
    string str_novo_cod = to_string(++Storage::maior_codigo_de_carteira);
    str_novo_cod.insert(0, 5 - str_novo_cod.length(), '0');
    novo_codigo.Set(str_novo_cod);
    cart_armazenada.SetCpfAssociado(carteira.GetConstCpfAssociado());
    cart_armazenada.SetCodigo(novo_codigo);
    cart_armazenada.SetNome(carteira.GetConstNome());
    cart_armazenada.SetPerfil(carteira.GetConstPerfil());

    if (this->carteiras == nullptr) {
        this->carteiras = new lista<StorageCarteira>;
        this->carteiras->value = cart_armazenada;
        return true;
    }

    this->carteiras->push(cart_armazenada);
    return true;
}

// usa o código presente na carteira fornecida
bool Storage::add_carteira_unchecked(const StorageCarteira& carteira) {
    StorageCarteira cart_armazenada;
    Codigo novo_codigo;

    cart_armazenada.SetCpfAssociado(carteira.GetConstCpfAssociado());
    cart_armazenada.SetCodigo(carteira.GetConstCodigo());
    cart_armazenada.SetNome(carteira.GetConstNome());
    cart_armazenada.SetPerfil(carteira.GetConstPerfil());

    if (this->contas == nullptr) {
        this->carteiras = new lista<StorageCarteira>;
        this->carteiras->value = cart_armazenada;
        return true;
    }

    this->carteiras->push(cart_armazenada);
    return true;
}
