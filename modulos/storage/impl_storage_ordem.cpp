#include "storage.hpp"
#include "iostream"

using namespace std;

bool Storage::get_ordens_carteira(const Carteira& cart, lista<Ordem>** ls) {
    auto curr_invest = this->investimentos;
    lista<Ordem>* invest_carteira = nullptr;
    bool achou_algum = false;

    if (this->investimentos == nullptr) return false;

    while (curr_invest != nullptr) {
        if (curr_invest->value.GetConstCodigo().Get() == cart.GetConstCodigo().Get()) {
            achou_algum = true;
            if (invest_carteira == nullptr) {
                invest_carteira = new lista<Ordem>;
                invest_carteira->value.SetCodigo(curr_invest->value.GetConstCodigo());
                invest_carteira->value.SetCodigoDeNegociacao(curr_invest->value.GetConstCodigoDeNegociacao());
                invest_carteira->value.SetData(curr_invest->value.GetConstData());
                invest_carteira->value.SetQuantidade(curr_invest->value.GetConstQuantidade());
                invest_carteira->value.SetDinheiro(curr_invest->value.GetConstDinheiro());
            } else {
                Ordem nova_ordem;
                nova_ordem.SetCodigo(curr_invest->value.GetConstCodigo());
                nova_ordem.SetCodigoDeNegociacao(curr_invest->value.GetConstCodigoDeNegociacao());
                nova_ordem.SetData(curr_invest->value.GetConstData());
                nova_ordem.SetQuantidade(curr_invest->value.GetConstQuantidade());
                nova_ordem.SetDinheiro(curr_invest->value.GetConstDinheiro());
                invest_carteira->push(nova_ordem);
            }
        }

        curr_invest = curr_invest->next;
    }

    *ls = invest_carteira;
    return achou_algum;
}

bool Storage::get_ordem(Ordem& ordem) {
    auto curr_invest = this->investimentos;

    while (curr_invest != nullptr) {
        if (curr_invest->value.GetCodigo().Get() == ordem.GetConstCodigo().Get()) {
            if (curr_invest->value.GetConstCodigoDeNegociacao().Get() == ordem.GetConstCodigoDeNegociacao().Get()) {
                ordem.SetData(curr_invest->value.GetConstData());
                ordem.SetDinheiro(curr_invest->value.GetConstDinheiro());
                ordem.SetQuantidade(curr_invest->value.GetConstQuantidade());
                return true;
            }
        }
        curr_invest = curr_invest->next;
    }

    return false;
}

bool Storage::remover_ordem(const Ordem& ordem) {
    lista<Ordem>* prev_invest = nullptr;
    auto curr_invest = this->investimentos;

    if (this->investimentos == nullptr) {
        return false;
    }

    while (curr_invest != nullptr) {
        if (curr_invest->value.GetConstCodigo().Get() == ordem.GetConstCodigo().Get()) {
            if (curr_invest->value.GetConstCodigoDeNegociacao().Get() == ordem.GetConstCodigoDeNegociacao().Get()) {
                cout << "investimento encontrado" << endl;
                if (prev_invest == nullptr) {
                    cout << "lista única" << endl;
                    this->investimentos = curr_invest->next;

                    delete curr_invest;
                    return true;
                } else {
                    cout << "lista multipla" << endl;
                    prev_invest->next = curr_invest->next;
                    delete curr_invest;
                    return true;
                }
            }
        }
        prev_invest = curr_invest;
        curr_invest = curr_invest->next;
    }
    return false;
}

bool Storage::add_ordem(const Ordem& ordem) {

    if (this->investimentos == nullptr) {
        this->investimentos = new lista<Ordem>;
        this->investimentos->value = ordem;
        return true;
    }

    this->investimentos->push(ordem);
    return true;
}
