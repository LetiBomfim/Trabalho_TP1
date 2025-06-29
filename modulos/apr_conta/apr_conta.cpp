#include "apr_conta.hpp"
#include "../serv_conta/serv_conta.hpp"
#include "../controleglobal/controleglobal.hpp"
#include <cstdint>
#include <stdexcept>
#include <sys/types.h>
#include "iostream"

using namespace std ;

CtrlAprConta::CtrlAprConta() {
    this->serv_conta = new MockServConta();
}

void CtrlAprConta::executar(const Cpf* cpf) {
    int32_t escolha;
    cout << "pagina conta" << endl;

    while (true) {
        if (cpf == nullptr) {
            if (this->criar_conta()) {
                cout << "conta criada com sucesso" << endl;
                return;
            } else {
                cout << "falha na criação de conta" << endl;
                return;
            }
        }

        escolha = this->ask_usuario();

        switch (escolha) {
            case CtrlAprConta::LER:
                this->ler_conta(*cpf);
                continue;
            case CtrlAprConta::ATUALIZAR:
                this->atualizar_conta();
                continue;
            case CtrlAprConta::EXCLUIR:
                if (this->excluir_conta(*cpf)) {
                    ControleGlobal::get_singleton()->SetAuth(false);
                    cout << "voltando ao menu" << endl;
                    return;
                };
                continue;
            case CtrlAprConta::SAIR:
                cout << "voltando ao menu" << endl;
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
    cout << "criando conta" << endl;
    Conta conta;
    Nome nome;
    Cpf cpf;
    Senha senha;
    string tmp_str;

    try {
        cout << "insira seu nome" << endl;
        cin >> tmp_str;
        nome.Set(tmp_str);
    } catch (invalid_argument) {
        cout << "nome inválido\ncancelando operação" << endl;
        return false;
    }

    try {
        cout << "insira seu cpf" << endl;
        cin >> tmp_str;
        cpf.Set(tmp_str);
    } catch (invalid_argument) {
        cout << "cpf inválido\ncancelando operação" << endl;
        return false;
    }

    try {
        cout << "insira sua senha" << endl;
        cin >> tmp_str;
        senha.Set(tmp_str);
    } catch (invalid_argument) {
        cout << "senha inválido\ncancelando operação" << endl;
        return false;
    }

    conta.SetCpf(cpf);
    conta.SetNome(nome);
    conta.SetSenha(senha);

    this->serv_conta->criar(conta);

    cout << "conta criada com sucesso" << endl;
    return true;
}

void CtrlAprConta::ler_conta(const Cpf& cpf) {
    cout << "lendo conta" << endl;
    Conta conta;
    string tmp_str;

    conta.SetCpf(cpf);

    this->serv_conta->ler(conta);

    cout << conta.GetConstCpf().Get() << endl;
    cout << conta.GetConstNome().Get() << endl;
    cout << conta.GetConstSenha().Get() << endl;
};

bool CtrlAprConta::atualizar_conta() {
    cout << "editando conta" << endl;
    Conta conta;
    Nome nome;
    Cpf cpf;
    Senha senha;
    string tmp_str;

    try {
        cout << "insira seu cpf" << endl;
        cin >> tmp_str;
        cpf.Set(tmp_str);
    } catch (invalid_argument) {
        cout << "cpf inválido\ncancelando operação" << endl;
        return false;
    }

    try {
        cout << "insira seu novo nome" << endl;
        cin >> tmp_str;
        nome.Set(tmp_str);
    } catch (invalid_argument) {
        cout << "nome inválido\ncancelando operação" << endl;
        return false;
    }


    try {
        cout << "insira sua nova senha" << endl;
        cin >> tmp_str;
        senha.Set(tmp_str);
    } catch (invalid_argument) {
        cout << "senha inválido\ncancelando operação" << endl;
        return false;
    }

    conta.SetCpf(cpf);
    conta.SetNome(nome);
    conta.SetSenha(senha);

    try {
        this->serv_conta->editar(conta);
    } catch (invalid_argument) {
        cout << "ocorreu um erro ao editar a conta" << endl;
        return false;
    }

    cout << "conta editada com sucesso" << endl;
    return true;
};

bool CtrlAprConta::excluir_conta(const Cpf& cpf) {
    cout << "excluindo conta" << endl;
    try {
        this->serv_conta->excluir(cpf);
    } catch (invalid_argument) {
        cout << "ocorreu um erro ao excluir a conta" << endl;
        return false;
    }
    cout << "conta removida com sucesso" << endl;
    return true;
}
