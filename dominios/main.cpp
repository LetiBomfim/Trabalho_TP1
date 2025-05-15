#include "testes_dom.hpp"

int main() {
    CodigoTeste codigoTeste;
    codigoTeste.Run();

    NomeTeste nomeTeste;
    nomeTeste.Run();

    Codigo_de_NegociacaoTeste codigo_de_negociacaoTeste;
    codigo_de_negociacaoTeste.Run();

    DataTeste dataTeste;
    dataTeste.Run();

    PerfilTeste perfilTeste;
    perfilTeste.Run();

    QuantidadeTeste quantidadeTeste;
    quantidadeTeste.Run();

    SenhaTeste senhaTeste;
    senhaTeste.Run();

    MoneyTest moneyTest;
    moneyTest.Run();

    CpfTest cpfTest;
    cpfTest.Run();

    return 0;
}
