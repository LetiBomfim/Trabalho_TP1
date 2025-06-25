#include "dominios/testes_dom.hpp"
#include "entidades/teste_ent.hpp"
#include <iostream>
#include <memory>
#include "perfil.hpp"
#include "compra.hpp"
#include "dados.hpp"
#include "servico.hpp"

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

void menuPrincipal() {
    std::unique_ptr<PerfilInvestidor> perfil;
    int opcaoPerfil;

    std::cout << "=== Selecione o seu perfil de investidor ===\n";
    std::cout << "1. Conservador\n";
    std::cout << "2. Moderado\n";
    std::cout << "3. Agressivo\n";
    std::cout << "Opção: ";
    std::cin >> opcaoPerfil;
    std::cin.ignore(); // Limpa buffer

    switch (opcaoPerfil) {
        case 1:
            perfil = std::make_unique<Conservador>();
            break;
        case 2:
            perfil = std::make_unique<Moderado>();
            break;
        case 3:
            perfil = std::make_unique<Agressivo>();
            break;
        default:
            std::cout << "Opção inválida. Encerrando.\n";
            return;
    }

    int opcao;
    do {
        std::cout << "\n===== MENU PRINCIPAL =====\n";
        std::cout << "1. Registrar nova compra\n";
        std::cout << "2. Ver histórico de compras\n";
        std::cout << "3. Sair\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore(); // Limpa o \n do buffer

        switch (opcao) {
            case 1: {
                Compra nova = criarCompra(perfil->getPerfil());
                salvarCompra(nova);
                std::cout << "Compra salva com sucesso!\n";
                break;
            }
            case 2:
                exibirHistorico();
                break;
            case 3:
                std::cout << "Encerrando o sistema. Até logo!\n";
                break;
            default:
                std::cout << "Opção inválida!\n";
        }
    } while (opcao != 3);
}

int main() {
    menuPrincipal();
    return 0;
}