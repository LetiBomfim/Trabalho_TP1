#include "dominios/testes_dom.hpp"
#include "entidades/teste_ent.hpp"


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

    DinheiroTeste dinheiroTeste;
    dinheiroTeste.Run();

    CpfTeste cpfTeste;
    cpfTeste.Run();

     ContaTeste contaTeste;
    contaTeste.Run();

    CarteiraTeste carteiraTeste;
    carteiraTeste.Run();

    OrdemTeste ordemTeste;
    ordemTeste.Run();


    return 0;
}
