#pragma once
#include "../../estruturas/estruturas.hpp"
#include "../../entidades/entidades.hpp"
#include "../../interfaces/interfaces.hpp"
#include <cstdint>

class Storage: public InterStorage {

    private:
        static Storage* singleton;
        lista<Conta>* contas;
        lista<StorageCarteira>* carteiras;
        lista<StorageOrdem>* investimentos;
        static int64_t maior_codigo_de_carteira;
        static int64_t maior_codigo_de_ordem;


    public:
        bool get_conta(Conta&);
        bool remover_conta(const Conta&);
        bool add_conta(const Conta&);

        int32_t count_carteiras_usuario(const Cpf&);
        bool get_carteiras_usuario(const Cpf&, lista<Carteira>**);
        bool get_carteira(StorageCarteira&);
        bool remover_carteira(const StorageCarteira&);
        bool add_carteira(const StorageCarteira&);
        bool add_carteira_unchecked(const StorageCarteira&);

        bool get_ordens_carteira(const Carteira&, lista<StorageOrdem>**);
        bool get_ordem(StorageOrdem&);
        bool remover_ordem(const Codigo&);
        bool add_ordem(const Ordem&);

        static Storage* get_singleton();
};
