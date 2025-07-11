#include "apr_invest.hpp"
#include <cstdint>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sys/types.h>
#include "float.h"
#include "string"
#include "ctime"

using namespace std;

void CtrlAprInvest::executar(const Cpf& cpf) {
        cout << cpf.Get() << endl;
        int32_t escolha;
        while (true) {
            escolha = this->ask_usuario();

            switch (escolha) {
                case LISTAR_CARTEIRA:
                    this->listar_cart(cpf);
                    continue;
                case EDITAR_CARTEIRA:
                    this->editar_cart();
                    continue;
                case EXCLUIR_CARTEIRA:
                    this->excluir_cart();
                    continue;
                case CRIAR_CARTEIRA:
                    this->criar_cart(cpf);
                    continue;
                case LISTAR_INVESTIMENTO:
                    this->listar_invest();
                    continue;
                case CRIAR_INVESTIMENTO:
                    this->criar_invest();
                    continue;
                case EXCLUIR_INVESTIMENTO:
                    this->excluir_invest();
                    continue;
                case SAIR:
                    return;
            }
        }
}

int32_t CtrlAprInvest::ask_usuario() {
    while (true) {
        int32_t escolha;

        try {
            cout << "decida:\n0) listar carteiras\n1) editar carteira\n2) excluir carteira\n3) criar carterira\n4) listar investimentos\n5) criar investimentos\n6) excluir investimentos\n7) sair" << endl;
            cin >> escolha;
            if (escolha > 7) {
                cout << "entrada inválida" << endl;
                continue;
            }
            return escolha;
        } catch (exception err) {
            continue;
        }
    }
}

void CtrlAprInvest::criar_cart(const Cpf& cpf) {
    Carteira carteira;
    Nome nome;
    Perfil perfil;
    string tmp;
    cout << "criar carteira selecionado:" << endl;

    cout << "insira o nome da carteira" << endl;
    try {
        cin >> tmp;
        nome.Set(tmp);
        carteira.SetNome(nome);
    } catch (invalid_argument) {
        cout << "nome inválido\noperação cancelada\nvoltando para a pagina de investimento" << endl;
        return;
    }

    cout << "insira o perfil da carteira:\n0) conservador\n1) moderado\n2) agressivo" << endl;
    try {
        cin >> tmp;
        if (tmp == "0") {
            perfil.Set("Conservador");
        } else if (tmp == "1") {
            perfil.Set("Moderado");
        } else if (tmp == "2") {
            perfil.Set("Agressivo");
        }
        carteira.SetPerfil(perfil);
    } catch (invalid_argument) {
        cout << "perfil inválido\noperação cancelada\nvoltando para a pagina de investimento" << endl;
        return;
    }

    try {
        this->serv_invest->criar_cart(carteira, cpf);
    } catch (invalid_argument e) {
        cout << e.what() << endl;
        cout << "erro ao criar carteira\noperação cancelada\nvoltando para a pagina de investimento" << endl;
    }
}
void CtrlAprInvest::editar_cart() {
    Carteira carteira;
    Nome nome;
    Codigo codigo;
    Perfil perfil;
    string tmp;


    cout << "editar carteira selecionado:" << endl;

    cout << "insira o código da carteira a ser editada" << endl;
    try {
        cin >> tmp;
        codigo.Set(tmp);
        carteira.SetCodigo(codigo);
    } catch (invalid_argument) {
        cout << "código inválido\noperação cancelada\nvoltando para a pagina de investimento" << endl;
        return;
    }

    cout << "insira o novo nome da carteira" << endl;
    try {
        cin >> tmp;
        nome.Set(tmp);
        carteira.SetNome(nome);
    } catch (invalid_argument) {
        cout << "nome inválido\noperação cancelada\nvoltando para a pagina de investimento" << endl;
        return;
    }

    cout << "insira o novo perfil da carteira:\n0) Conservador\n1) Moderado\n2) Agressivo" << endl;
    try {
        cin >> tmp;
        if (tmp == "0") {
            perfil.Set("Conservador");
        } else if (tmp == "1") {
            perfil.Set("Moderado");
        } else if (tmp == "2") {
            perfil.Set("Agressivo");
        }
        carteira.SetPerfil(perfil);
    } catch (invalid_argument) {
        cout << "perfil inválido\noperação cancelada\nvoltando para a pagina de investimento" << endl;
        return;
    }

    try {
        this->serv_invest->editar_cart(carteira);
    } catch (invalid_argument) {
        cout << "erro ao criar carteira\noperação cancelada\nvoltando para a pagina de investimento" << endl;
    }
}

void CtrlAprInvest::excluir_cart() {
    Carteira carteira;
    Codigo codigo;
    string tmp;
    cout << "excluir carteira selecionado:" << endl;

    cout << "insira o código da carteira a ser excluida" << endl;
    try {
        cin >> tmp;
        codigo.Set(tmp);
        carteira.SetCodigo(codigo);
    } catch (invalid_argument) {
        cout << "código inválido\noperação cancelada\nvoltando para a pagina de investimento" << endl;
        return;
    }

    try {
        this->serv_invest->excluir_cart(carteira);
    } catch (invalid_argument) {
        cout << "erro ao criar carteira\noperação cancelada\nvoltando para a pagina de investimento" << endl;
    }
}

void CtrlAprInvest::listar_cart(const Cpf& cpf) {
    cout << "listando carteiras" << endl;

    auto lista = this->serv_invest->listar_cart(cpf);
    if (lista == nullptr) {
        cout << "não há carteiras a serem listadas" << endl;
        return;
    }

    auto node = lista;

    while (node != nullptr) {
        cout << "codigo: " << node->value.GetCodigo().Get() << endl;
        cout << "nome: " << node->value.GetNome().Get() << endl;
        cout << "perfil: " << node->value.GetPerfil().Get() << endl;
        cout << endl;
        node = node->next;
    }

    lista->free();
    delete lista;
}

void CtrlAprInvest::criar_invest() {
    Codigo cod_cart;
    Codigo_de_Negociacao cod_invest;
    Quantidade quant;
    Dinheiro dinheiro;
    Data data;
    Ordem investimento;
    string tmp;
    int dtmp;
    cout << "criação de investimento selecionado:" << endl;

    cout << "insira o código da carteira do novo investimento" << endl;
    try {
        cin >> tmp;
        cod_cart.Set(tmp);
        investimento.SetCodigo(cod_cart);
    } catch (invalid_argument) {
        cout << "código inválido\noperação cancelada\nvoltando para a pagina de investimento" << endl;
        return;
    }


    cout << "insira o código de negoçiação do ativo" << endl;
    try {
        cin >> tmp;
        cod_invest.Set(tmp);
        investimento.SetCodigoDeNegociacao(cod_invest);
    } catch (invalid_argument) {
        cout << "código inválido\noperação cancelada\nvoltando para a pagina de investimento" << endl;
        return;
    }


    cout << "inisira a quantidade desejada" << endl;
    try {
        cin >> dtmp;
        quant.Set(dtmp);
        investimento.SetQuantidade(quant);
    } catch (invalid_argument) {
        cout << "valor inválido\noperação cancelada\nvoltando para a pagina de investimento" << endl;
        return;
    }

    cout << "inisira a o dia do mes do investimento" << endl;
    try {
        cin >> dtmp;
    } catch (invalid_argument) {
        cout << "valor inválido\noperação cancelada\nvoltando para a pagina de investimento" << endl;
        return;
    }


    auto t = time(0);
    string mday = to_string(dtmp);
    mday.insert(0, 2 - mday.length(), '0');
    string month = "01";
    string year = "2025";
    string full_dt_str = year + month + mday;

    data.Set(full_dt_str);

    // como eu não tenho um banco de dados do qual puxar o valor, eu vou apenas colocar 10 reais para todo investimento.
    dinheiro.Set(10.0);
    investimento.SetDinheiro(dinheiro);

    investimento.SetData(data);

    try {
        this->serv_invest->criar_ordem(investimento);
    } catch (invalid_argument e) {
        cout << e.what() << endl;
        cout << "erro ao criar investimento\noperação cancelada\nvoltando para a pagina de investimento" << endl;
    }
}

void CtrlAprInvest::excluir_invest() {
    Codigo cod_cart;
    Codigo_de_Negociacao cod_invest;
    Quantidade quant;
    Data data;
    Ordem investimento;
    string tmp;
    int dtmp;

    cout << "exclusão de investimento selecionado:" << endl;

    cout << "insira o id do investimento a ser excluido" << endl;
    try {
        cin >> tmp;
        cod_cart.Set(tmp);
        investimento.SetCodigo(cod_cart);
    } catch (invalid_argument) {
        cout << "código inválido\noperação cancelada\nvoltando para a pagina de investimento" << endl;
        return;
    }

    try {
        this->serv_invest->excluir_ordem(cod_cart);
    } catch (invalid_argument) {
        cout << "erro ao editar investimento\noperação cancelada\nvoltando para a pagina de investimento" << endl;
    }
}

void CtrlAprInvest::listar_invest() {
    Codigo cod_cart;
    string tmp;
    Carteira carteira;

    cout << "insira o código da carteira de investimentos" << endl;
    try {
        cin >> tmp;
        cod_cart.Set(tmp);
        carteira.SetCodigo(cod_cart);
    } catch (invalid_argument) {
        cout << "código inválido\noperação cancelada\nvoltando para a pagina de investimento" << endl;
        return;
    }


    cout << "listando ordens" << endl;
    lista<StorageOrdem>* lst = nullptr;
    try {
        lst = this->serv_invest->listar_ordem(carteira);
    } catch (invalid_argument e) {
        cout << e.what() << endl;
        return;
    }

    if (lst == nullptr) {
        cout << "não existem ordens a serem listadas" << endl;
        return;
    }

    auto node = lst;

    while (node != nullptr) {
        cout << "id: " << node->value.GetConstId().Get() << endl;
        cout << "codigo: " << node->value.GetCodigoDeNegociacao().Get() << endl;
        cout << "data: " << node->value.GetData().Get() << endl;
        cout << "carteira: " << node->value.GetCodigo().Get() << endl;
        cout << "quantidade: " << node->value.GetQuantidade().Get() << endl;
        cout << "valor: " << node->value.GetDinheiro().Get() << endl;
        cout << endl;
        node = node->next;
    }

    lst->free();
    delete lst;
}
