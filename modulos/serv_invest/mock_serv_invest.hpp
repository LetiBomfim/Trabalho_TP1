#include "../../interfaces/interfaces.hpp"

class MockServInvest: public InterServInvest {
    public:
        virtual void criar() {};
        virtual void editar(const Ordem& conta) {};
        virtual void excluir(const Ordem& cpf) {};
        virtual void listar(Ordem* ordens) {};
};
