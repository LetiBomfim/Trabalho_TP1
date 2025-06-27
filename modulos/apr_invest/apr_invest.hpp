#include "../../interfaces/interfaces.hpp"
#include "../serv_invest/mock_serv_invest.hpp"
#include <cstdint>

using namespace std;

class CtrlAprInvest: public InterApresInvest {
    static const int32_t LISTAR_CARTEIRA = 0;
    static const int32_t EDITAR_CARTEIRA = 1;
    static const int32_t CRIAR_CARTEIRA = 2;
    static const int32_t EXCLUIR_CARTEIRA = 3;
    static const int32_t LISTAR_INVESTIMENTO = 4;
    static const int32_t EDITAR_INVESTIMENTO = 5;
    static const int32_t CRIAR_INVESTIMENTO = 6;
    static const int32_t EXCLUIR_INVESTIMENTO = 7;



    private:
        InterServInvest* serv_invest = nullptr;

        int32_t ask_usuario();
        void criar_cart(const Cpf&);
        void editar_cart();
        void excluir_cart();
        void listar_cart(const Cpf&);
        void criar_invest();
        void editar_invest();
        void excluir_invest();
        void listar_invest();

    public:

        CtrlAprInvest() {
            this->serv_invest = new MockServInvest();
        }

        void executar(const Cpf&);
};
