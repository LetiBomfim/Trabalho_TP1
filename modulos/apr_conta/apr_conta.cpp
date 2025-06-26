
#include "apr_conta.hpp"
#include "../serv_conta/mock_serv_conta.hpp"
#include <cstdint>
#include "iostream"

using namespace std ;

CtrlAprConta::CtrlAprConta() {
    this->serv_conta = new MockServConta();
}

void CtrlAprConta::executar(const Cpf* cpf) {
    int32_t escolha;

    while (true) {
        if (cpf == nullptr) {
            if (this->criar_conta()) {
                cout << "conta criada com sucesso!" << endl;
                return;
            }
        }

        escolha = this->ask_usuario();

        Conta conta;
        switch (escolha) {
            case CtrlAprConta::LER:
                cout << "lendo conta:" << endl;
                this->serv_conta->ler(conta);
                continue;
            case CtrlAprConta::ATUALIZAR:
                cout << "editando conta:" << endl;
                this->serv_conta->editar(conta);
                continue;
            case CtrlAprConta::EXCLUIR:
                cout << "excluindo conta:" << endl;
                this->serv_conta->excluir(*cpf);
                continue;
            case CtrlAprConta::SAIR:
                cout << "voltando para o menu" << endl;
                return;
        }

        }
}

int32_t CtrlAprConta::ask_usuario() {
    while (true) {
        int32_t escolha;

        try {
            cout << "decida:\n0) ler\n1) atualizar\n2) excluir\n3) criar\n4) sair" << endl;
            cin >> escolha;
            if (escolha > 4) {
                cout << "entrada inválida" << endl;
                continue;
            }
            return escolha;
        } catch (exception err) {
            continue;
        }
    }
}


bool CtrlAprConta::criar_conta() {
    return true;
}

void CtrlAprConta::ler_conta() {};
void CtrlAprConta::atualizar_conta() {};
