#include "storage.hpp"

bool Storage::get_carteiras_usuario(const Cpf& cpf, lista<Carteira>** ls) {
    auto curr_cart = this->carteiras;
    lista<Carteira>* carts_usuario;
    bool achou_alguma = false;

    while (curr_cart != nullptr) {
        if (curr_cart->value.GetCpfAssociado().Get() == cpf.Get()) {
            if (carts_usuario == nullptr) {
                carts_usuario = new lista<Carteira>;
                carts_usuario->value = curr_cart->value;
                continue;
            }

            carts_usuario->push(curr_cart->value);

        }
    }
}
