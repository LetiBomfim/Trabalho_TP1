#include "teste_ent.hpp"

int main() {
    AccountTest accountTest;
    accountTest.Run();

    WalletTest walletTest;
    walletTest.Run();

    CommandTest commandTest;
    commandTest.Run();

    return 0;
}
