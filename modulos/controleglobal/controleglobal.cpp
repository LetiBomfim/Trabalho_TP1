#include "controleglobal.hpp"
#include <cstdint>
#include <exception>
#include <iostream>

using namespace std;

void ControleGlobal::Run() {
    while (true) {
        if (this->escolha == ControleGlobal::AUTH) {
            if (this->apr_auth->autenticar()) {
                cout << "autorizado" << endl;
                this->escolha = ControleGlobal::CONTA;
            }
        }


        menu();
    }
}

void ControleGlobal::menu() {
    //pergunta o que o usuário deseja fazer
    int32_t escolha = this->ask_usuario();

    switch (escolha) {
        case (ControleGlobal::CONTA):
            this->apr_conta->executar();
        case (ControleGlobal::INVESTIMENTO):
            this->apr_invest->executar();
    }
}

int32_t ControleGlobal::ask_usuario() {
    while (true) {
        int32_t escolha;
        cout << "decida:\n1) conta\n2) invest" << endl;
        try {
            cin >> escolha;
            return escolha;
        } catch (exception err) {
            continue;
        }
    }
}
