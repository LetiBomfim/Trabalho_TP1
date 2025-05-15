#include "testes_dom.hpp"

int main() {
    CodigoTeste codigoTeste;
    codigoTeste.Run();

    NomeTeste nomeTeste;
    nomeTeste.Run();

    TradeCodeTest tradeCodeTest;
    tradeCodeTest.Run();

    DateTest dateTest;
    dateTest.Run();

    ProfileTest profileTest;
    profileTest.Run();

    AmountTest amountTest;
    amountTest.Run();

    PasswordTest passwordTest;
    passwordTest.Run();

    MoneyTest moneyTest;
    moneyTest.Run();

    CpfTest cpfTest;
    cpfTest.Run();

    return 0;
}
