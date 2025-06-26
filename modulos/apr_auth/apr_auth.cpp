#include "apr_auth.hpp"
#include "../serv_auth/mock_auth_service.hpp"
#include <iostream>
#include <stdexcept>

using namespace std ;

CtrlAprAuth::CtrlAprAuth() {
    this->servico = new MockAuthService();
}

bool CtrlAprAuth::autenticar(Cpf& cpf) {
    Senha senha;
    this->ask_cpf_e_senha(cpf, senha);
    return this->servico->autenticar(cpf, senha);
}

void CtrlAprAuth::ask_cpf_e_senha(Cpf& cpf, Senha& senha) {
    while (true) {
        try {
            string cpf_str = "";
            cout << "Insira o cpf:" << endl;
            cin >> cpf_str;
            cpf.Set(cpf_str);
        } catch (invalid_argument) {
            cout << "cpf inválido" << endl;
            continue;
        }

        try {
            string senha_str = "";
            cout << "Insira a senha:" << endl;
            cin >> senha_str;
            senha.Set(senha_str);
            break;
        } catch(invalid_argument) {
            cout << "senha iválida" << endl;
            continue;
        }
    }
}
