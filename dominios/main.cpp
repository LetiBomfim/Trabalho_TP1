#include "testes_dom.hpp"

int main() {
    CodeTest codeTest;
    codeTest.Run();

    NameTest nameTest;
    nameTest.Run();

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
