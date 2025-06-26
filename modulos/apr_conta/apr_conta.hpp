#pragma once
#include "../../interfaces/interfaces.hpp"
#include <cstdint>

using namespace std ;

class CtrlAprConta: public InterApresConta {
    static const int32_t LER = 0;
    static const int32_t ATUALIZAR = 1;
    static const int32_t EXCLUIR = 2;
    static const int32_t CRIAR = 3;
    static const int32_t SAIR = 4;

    private:
    InterServConta* serv_conta = nullptr;

    Cpf cpf_usuario;
    int32_t ask_usuario();
    bool criar_conta();
    void ler_conta();
    void atualizar_conta();
    void excluir();


    public:
        CtrlAprConta();
        void executar(const Cpf* cpf);
};
