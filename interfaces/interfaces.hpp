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
        virtual void criar_ordem(const Ordem&) = 0;
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

class InterStorage {
    public:
        // funções relacionadas à conta
        virtual bool get_conta(Conta&) = 0;
        virtual bool remover_conta(const Conta&) = 0;
        virtual bool add_conta(const Conta&) = 0;

        // funções relacionadas à carteira
        virtual bool get_carteiras_usuario(const Cpf&, lista<Carteira>**) = 0;
        virtual bool get_carteira(StorageCarteira&) = 0;
        virtual bool remover_carteira(const StorageCarteira&) = 0;
        virtual bool add_carteira(const StorageCarteira&) = 0;
        virtual bool add_carteira_unchecked(const StorageCarteira&) = 0;

        // funções relacionadas à ordem
        virtual bool get_ordens_carteira(const Carteira&, lista<Ordem>**) = 0;
        virtual bool get_ordem(Ordem&) = 0;
        virtual bool remover_ordem(const Ordem&) = 0;
        virtual bool add_ordem(const Ordem&) = 0;
};
