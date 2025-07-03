#include "storage.hpp"
#include "iostream"

using namespace std;

bool Storage::get_ordens_carteira(const Carteira& cart, lista<StorageOrdem>** ls) {
    auto curr_invest = this->investimentos;
    lista<StorageOrdem>* invest_carteira = nullptr;
    bool achou_algum = false;

    if (this->investimentos == nullptr) return false;

    while (curr_invest != nullptr) {
        if (curr_invest->value.GetConstCodigo().Get() == cart.GetConstCodigo().Get()) {
            achou_algum = true;
            if (invest_carteira == nullptr) {
                invest_carteira = new lista<StorageOrdem>;
                invest_carteira->value.SetCodigo(curr_invest->value.GetConstCodigo());
                invest_carteira->value.SetCodigoDeNegociacao(curr_invest->value.GetConstCodigoDeNegociacao());
                invest_carteira->value.SetData(curr_invest->value.GetConstData());
                invest_carteira->value.SetQuantidade(curr_invest->value.GetConstQuantidade());
                invest_carteira->value.SetDinheiro(curr_invest->value.GetConstDinheiro());
                invest_carteira->value.SetId(curr_invest->value.GetConstId());
            } else {
                StorageOrdem nova_ordem;
                nova_ordem.SetCodigo(curr_invest->value.GetConstCodigo());
                nova_ordem.SetCodigoDeNegociacao(curr_invest->value.GetConstCodigoDeNegociacao());
                nova_ordem.SetData(curr_invest->value.GetConstData());
                nova_ordem.SetQuantidade(curr_invest->value.GetConstQuantidade());
                nova_ordem.SetDinheiro(curr_invest->value.GetConstDinheiro());
                nova_ordem.SetId(curr_invest->value.GetConstId());
                invest_carteira->push(nova_ordem);
            }
        }

        curr_invest = curr_invest->next;
    }

    *ls = invest_carteira;
    return achou_algum;
}

bool Storage::get_ordem(StorageOrdem& ordem) {
    auto curr_invest = this->investimentos;

    while (curr_invest != nullptr) {
        if (curr_invest->value.GetConstId().Get() == ordem.GetConstId().Get()) {
            ordem.SetData(curr_invest->value.GetConstData());
            ordem.SetDinheiro(curr_invest->value.GetConstDinheiro());
            ordem.SetQuantidade(curr_invest->value.GetConstQuantidade());
            return true;
        }
        curr_invest = curr_invest->next;
    }

    return false;
}

bool Storage::remover_ordem(const Codigo& cod) {
    lista<StorageOrdem>* prev_invest = nullptr;
    auto curr_invest = this->investimentos;

    if (this->investimentos == nullptr) {
        return false;
    }

    while (curr_invest != nullptr) {
        if (curr_invest->value.GetConstId().Get() == cod.Get()) {
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
        prev_invest = curr_invest;
        curr_invest = curr_invest->next;
    }
    return false;
}

bool Storage::add_ordem(const Ordem& ordem) {
    Codigo new_cod;
    string str_novo_cod = to_string(++Storage::maior_codigo_de_ordem);
    str_novo_cod.insert(0, 5 - str_novo_cod.length(), '0');
    new_cod.Set(str_novo_cod);

    StorageOrdem st_ordem;
    st_ordem.SetCodigo(ordem.GetConstCodigo());
    st_ordem.SetCodigoDeNegociacao(ordem.GetConstCodigoDeNegociacao());
    st_ordem.SetData(ordem.GetConstData());
    st_ordem.SetDinheiro(ordem.GetConstDinheiro());
    st_ordem.SetQuantidade(ordem.GetConstQuantidade());
    st_ordem.SetId(new_cod);


    if (this->investimentos == nullptr) {
        this->investimentos = new lista<StorageOrdem>;
        this->investimentos->value = st_ordem;
        return true;
    }

    this->investimentos->push(st_ordem);
    return true;
}
