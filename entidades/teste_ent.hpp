#pragma once

class ContaTeste {
public:
   
    void Run();

private:
   
    void TestValidAccount();
    
    void TestInvalidAccount();
};

// Declaração da Classe de Teste de Carteira


class CarteiraTeste {
public:
 
    void Run();

private:

    void TestValidWallet();

    void TestInvalidWallet();
};

// Declaração da Classe de Teste de Ordem

class OrdemTeste {
public:

    void Run();

private:

    void TestValidCommand();

    void TestInvalidCommand();
};
