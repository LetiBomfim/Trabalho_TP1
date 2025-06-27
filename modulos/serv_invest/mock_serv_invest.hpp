#include "../../interfaces/interfaces.hpp"

class MockServInvest: public InterServInvest {
    public:

    virtual void criar_cart(const Carteira&, const Cpf&) {};
    virtual void editar_cart(const Carteira&) {};
    virtual void excluir_cart(const Carteira&) {};
    virtual lista<Carteira>* listar_cart(const Cpf&) {return nullptr;};
    virtual void criar_ordem(const Carteira&, const Ordem&) {};
    virtual void editar_ordem(const Ordem&) {};
    virtual void excluir_ordem(const Ordem&) {};
    virtual lista<Ordem>* listar_ordem(const Carteira&) {return nullptr;};
};
