#include "../../interfaces/interfaces.hpp"

using namespace std ;

class MockServConta: public InterServConta {
    public:
        void criar() {};
        void ler(Conta& conta) {};
        void editar(const Conta& conta) {};
        void excluir(const Cpf& cpf) {};
};
