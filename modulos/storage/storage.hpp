#pragma once
#include "../../estruturas/estruturas.hpp"
#include "../../entidades/entidades.hpp"

class Storage {

    private:
        static Storage* singleton;
        lista<Conta>* contas;
        lista<StorageCarteira>* carteiras;
        lista<Ordem>* investimentos;


    public:
        bool get_conta(Conta&);
        bool remover_conta(Conta&);
        bool add_conta(const Conta&);

        bool get_carteiras_usuario(const Cpf&);
        bool get_carteira(const Codigo&);
        bool remover_carteira(const Codigo&);
        bool add_carteira(const Carteira&, const Cpf&);

        bool get_ordens_carteira(const Carteira&);
        bool get_ordem(const Carteira&, const Ordem&);
        bool remover_ordem(const Carteira&, const Ordem&);
        bool add_ordem(const Carteira&, const Ordem&);

        static Storage* get_singleton();
};
