#include "apr_auth.hpp"
#include "../serv_auth/mock_auth_service.hpp"
#include <iostream>
#include <stdexcept>

using namespace std ;

CtrlAprAuth::CtrlAprAuth() {
    this->servico = new MockAuthService();
}

bool CtrlAprAuth::autenticar() {
    this->ask_cpf_e_senha();
    return this->servico->autenticar(this->cpf, this->senha);
}

void CtrlAprAuth::ask_cpf_e_senha() {
    while (true) {
        try {
            string cpf_str = "";
            cout << "Insira o cpf:" << endl;
            cin >> cpf_str;
            this->cpf.Set(cpf_str);
        } catch (invalid_argument) {
            cout << "cpf inválido" << endl;
            continue;
        }

        try {
            string senha_str = "";
            cout << "Insira a senha:" << endl;
            cin >> senha_str;
            this->senha.Set(senha_str);
            break;
        } catch(invalid_argument) {
            cout << "senha iválida" << endl;
            continue;
        }
    }
}
