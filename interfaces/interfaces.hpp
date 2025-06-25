#include "../entidades/entidades.hpp"

class InterServAuth {
    public:
        virtual bool autenticar();
};

class InterServConta {
    public:
        virtual void criar();
        virtual void ler(Conta& conta);
        virtual void editar(const Conta& conta);
        virtual void excluir(const Cpf& cpf);
};

class InterServInvest {
    public:
        virtual void criar();
        virtual void editar(const Ordem& conta);
        virtual void excluir(const Ordem& cpf);
        virtual void listar(Ordem* ordens);
};

class InterApresAuth {
    public:
        virtual void autenticar();
};

class InterApresConta {
    public:
        virtual void executar();
};

class InterApresInvest {
    public:
    virtual void executar();
};
