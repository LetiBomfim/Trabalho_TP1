#pragma once
#include "../entidades/entidades.hpp"

class InterServAuth {
    public:
        virtual bool autenticar(const Cpf&, const Senha&) = 0;
};

class InterServConta {
    public:
        virtual void criar() = 0;
        virtual void ler(Conta& conta) = 0;
        virtual void editar(const Conta& conta) = 0;
        virtual void excluir(const Cpf& cpf) = 0;
};

class InterServInvest {
    public:
        virtual void criar() = 0;
        virtual void editar(const Ordem& conta) = 0;
        virtual void excluir(const Ordem& cpf) = 0;
        virtual void listar(Ordem* ordens) = 0;
};

class InterApresAuth {
    public:
        virtual bool autenticar() = 0;
};

class InterApresConta {
    public:
        virtual void executar() = 0;
};

class InterApresInvest {
    public:
        virtual void executar() = 0;
};
