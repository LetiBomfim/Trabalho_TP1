#pragma once
#include "../entidades/entidades.hpp"
#include "../estruturas/estruturas.hpp"

class InterServAuth {
    public:
        virtual bool autenticar(const Cpf&, const Senha&) = 0;
};

class InterServConta {
    public:
        virtual void criar(const Conta&) = 0;
        virtual void ler(Conta& conta) = 0;
        virtual void editar(const Conta& conta) = 0;
        virtual void excluir(const Cpf& cpf) = 0;
};

class InterServInvest {
    public:
        virtual void criar_cart(const Carteira&, const Cpf&) = 0;
        virtual void editar_cart(const Carteira&) = 0;
        virtual void excluir_cart(const Carteira&) = 0;
        virtual lista<Carteira>* listar_cart(const Cpf&) = 0;
        virtual void criar_ordem(const Carteira&, const Ordem&) = 0;
        virtual void excluir_ordem(const Ordem&) = 0;
        virtual lista<Ordem>* listar_ordem(const Carteira&) = 0;
};

class InterApresAuth {
    public:
            virtual bool autenticar(Cpf&) = 0;
};

class InterApresConta {
    public:
        virtual void executar(const Cpf*) = 0;
};

class InterApresInvest {
    public:
        virtual void executar(const Cpf&) = 0;
};
