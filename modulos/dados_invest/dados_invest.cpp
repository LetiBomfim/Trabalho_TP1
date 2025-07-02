#include "dados_invest.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

DadosHist* DadosHist::singleton = nullptr;

DadosHist* DadosHist::get_singleton() {
    if (DadosHist::singleton == nullptr) {
        DadosHist::singleton = new DadosHist();
    }

    return DadosHist::singleton;
}

bool DadosHist::set_valor_ordem(Ordem& ordem) {
    string codigo = ordem.GetConstCodigoDeNegociacao().Get();
    string linha;
    codigo.append(12-codigo.length(), ' ');

    cout << "CODIGO    = "<< codigo << endl;

    ifstream Arquivo("DADOS_HISTORICOS.txt");    // Abrir arquivo.

    while (getline (Arquivo, linha)) {
        if(codigo.compare(linha.substr(12,12)) == 0) {
            string data = linha.substr(2,8);
            if (data == ordem.GetConstData().Get()) {
                cout << "correspondencia encontrada" << endl;
                ordem.GetDinheiro().Set(std::stod(linha.substr(113,13))/100);
                return true;
            }
        }
    }

    return false;
}
