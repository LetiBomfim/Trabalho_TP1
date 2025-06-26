#include "../../interfaces/interfaces.hpp"
#include "../serv_invest/mock_serv_invest.hpp"

class CtrlAprInvest: public InterApresInvest {
    private:
        InterServInvest* serv_invest = nullptr;

    public:

    CtrlAprInvest() {
       this->serv_invest = new MockServInvest();
    }

    void executar() {

    }
};
