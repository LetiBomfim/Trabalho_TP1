#pragma once
#include "../../estruturas/estruturas.hpp"
#include "../../entidades/entidades.hpp"
#include <cstdint>

class Storage {

    private:
        static Storage* singleton;
        lista<Conta>* contas;
        lista<StorageCarteira>* carteiras;
        lista<Ordem>* investimentos;
        static int64_t maior_codigo_de_carteira;


    public:
        bool get_conta(Conta&);
        bool remover_conta(const Conta&);
        bool add_conta(const Conta&);

        bool get_carteiras_usuario(const Cpf&, lista<Carteira>**);
        bool get_carteira(StorageCarteira&);
        bool remover_carteira(const StorageCarteira&);
        bool add_carteira(const StorageCarteira&);

        bool get_ordens_carteira(const Carteira&);
        bool get_ordem(const Carteira&, const Ordem&);
        bool remover_ordem(const Carteira&, const Ordem&);
        bool add_ordem(const Carteira&, const Ordem&);

        static Storage* get_singleton();
};
