#include "controleglobal.hpp"
#include <cstdint>
#include <exception>
#include <iostream>
#include "../apr_auth/apr_auth.hpp"
#include "../../interfaces/interfaces.hpp"
#include "../apr_conta/apr_conta.hpp"
#include "../apr_invest/apr_invest.hpp"

using namespace std;

ControleGlobal* ControleGlobal::singleton = nullptr;

void ControleGlobal::Run() {
    while (true) {
        cout << "home page" << endl;
        int32_t escolha = this->ask_usuario();

        switch (escolha) {
            case (ControleGlobal::LOGIN):
                cout << "escolheu login" << endl;
                this->autenticado = this->apr_auth->autenticar(this->cpf_usuario);
                continue;
            case (ControleGlobal::REGISTER):
                cout << "escolheu registrar" << endl;
                this->apr_conta->executar(nullptr);
                continue;
            case (ControleGlobal::CONTA):
                cout << "escolheu conta" << endl;
                this->apr_conta->executar(&this->cpf_usuario);
                continue;
            case (ControleGlobal::INVESTIMENTO):
                cout << "escolheu investimento" << endl;
                this->apr_invest->executar(this->cpf_usuario);
                continue;
            default:
                cout << "alguma coisa está estranha" << endl;
        }
    }
}

int32_t ControleGlobal::ask_usuario() {
    while (true) {
        int32_t escolha;

        if (this->autenticado == false) {
            cout << "decida:\n0) login\n1) registrar-se" << endl;
        } else {
            cout << "decida:\n0) login\n1) registrar-se\n2) conta\n3) investimento" << endl;
        }
        try {
            cin >> escolha;
            if (!this->autenticado && escolha > 1 || escolha > 3) {
                cout << "entrada inválida" << endl;
                continue;
            }
            return escolha;
        } catch (exception err) {
            continue;
        }
    }
}

ControleGlobal::ControleGlobal() {
    this->apr_auth = new CtrlAprAuth();
    this->apr_conta = new CtrlAprConta();
    this->apr_invest = new CtrlAprInvest();
    ControleGlobal::singleton = this;
}

ControleGlobal* ControleGlobal::get_singleton() {
    return ControleGlobal::singleton;
}
