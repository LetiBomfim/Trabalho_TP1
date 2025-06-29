#include "../../interfaces/interfaces.hpp"
#include "../storage/storage.hpp"
#include <iostream>

using namespace std;

class ServInvest: public InterServInvest {
    public:
        void criar_cart(const Carteira& carteira, const Cpf& cpf) {
            auto storage = Storage::get_singleton();
            StorageCarteira st_carteira;
            st_carteira.SetCpfAssociado(cpf);
            st_carteira.SetNome(carteira.GetConstNome());
            st_carteira.SetPerfil(carteira.GetConstPerfil());
            storage->add_carteira(st_carteira);
        };

        void editar_cart(const Carteira& carteira) {
            auto storage = Storage::get_singleton();

            // pega a carteira
            StorageCarteira cart;
            cart.SetCodigo(carteira.GetConstCodigo());
            storage->get_carteira(cart);

            //  realiza a edição
            cart.SetNome(carteira.GetConstNome());
            cart.SetPerfil(carteira.GetConstPerfil());

            // salva a edição
            storage->remover_carteira(cart);
            storage->add_carteira_unchecked(cart);
        };

        void excluir_cart(const Carteira& carteira) {
            auto storage = Storage::get_singleton();

            StorageCarteira st_carteira;
            st_carteira.SetCodigo(carteira.GetConstCodigo());

            storage->remover_carteira(st_carteira);
        };

        lista<Carteira>* listar_cart(const Cpf& cpf) {
            auto storage = Storage::get_singleton();

            lista<Carteira>* lst;

            storage->get_carteiras_usuario(cpf , &lst);
            cout << "função get carteiras não de pau" << endl;

            return lst;
        };

        void criar_ordem(const Carteira&, const Ordem&) {};
        void editar_ordem(const Ordem&) {};
        void excluir_ordem(const Ordem&) {};
        lista<Ordem>* listar_ordem(const Carteira&) {return nullptr;};
};
