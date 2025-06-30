#include "../../interfaces/interfaces.hpp"
#include "../storage/storage.hpp"
#include <stdexcept>

using namespace std;

class ServInvest: public InterServInvest {
    private:
        InterStorage* storage = nullptr;

    public:

        ServInvest() {
            this->storage = Storage::get_singleton();
        }

        void criar_cart(const Carteira& carteira, const Cpf& cpf) {
            StorageCarteira st_carteira;
            st_carteira.SetCpfAssociado(cpf);
            st_carteira.SetNome(carteira.GetConstNome());
            st_carteira.SetPerfil(carteira.GetConstPerfil());
            storage->add_carteira(st_carteira);
        };

        void editar_cart(const Carteira& carteira) {
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
            StorageCarteira st_carteira;
            st_carteira.SetCodigo(carteira.GetConstCodigo());

            storage->remover_carteira(st_carteira);
        };

        lista<Carteira>* listar_cart(const Cpf& cpf) {
            lista<Carteira>* lst = nullptr;


            if (!storage->get_carteiras_usuario(cpf , &lst)) {
                return nullptr;
            }

            return lst;
        };

        void criar_ordem(const Ordem& ordem) {
            if (!storage->add_ordem(ordem)) {
                throw new invalid_argument("alguma coisa deu errado na criação da ordem");
            }
        };

        void excluir_ordem(const Ordem& ordem) {
            if (!storage->remover_ordem(ordem)) {
                throw new invalid_argument("alguma coisa deu errado na remoção da ordem");
            }
        };

        lista<Ordem>* listar_ordem(const Carteira& carteira) {
            lista<Ordem>* ls = nullptr;

            if (!storage->get_ordens_carteira(carteira, &ls)) {
                return ls;
            }

            return ls;
        }
};
