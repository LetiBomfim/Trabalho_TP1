#pragma once
#include "../dominios/dominios.hpp"



class Conta {
private:
    Cpf cpf; 
    Nome nome; 
    Senha senha; 

public:
    
    Cpf& GetCpf() {
        return cpf;
    }

    const Cpf& GetConstCpf() const {
        return cpf;
    }

    
    Nome& GetNome() {
        return nome;
    }

    const Nome& GetConstNome() const {
        return nome;
    }

    
    Senha& GetSenha() {
        return senha;
    }

    const Senha& GetConstSenha() const {
        return senha;
    }


 
    void SetCpf(const Cpf& newCpf) {
        cpf = newCpf;
    }

    
    void SetNome(const Nome& novo_nome) {
        nome = novo_nome;
    }

    
    void SetSenha(const Senha& nova_senha) {
        senha = nova_senha;
    }
};


class Carteira {
private:
    Codigo codigo;  
    Nome nome;  
    Perfil perfil;  

public:

    Codigo& GetCodigo() {
        return codigo;
    }

    const Codigo& GetConstCodigo() const {
        return  codigo;
    }


    Nome& GetNome() {
        return nome;
    }

    const Nome& GetConstNome() const{
        return nome;
    }


    Perfil& GetPerfil() {
        return perfil;
    }

    const Perfil& GetConstPerfil() const {
        return perfil;
    }

    
    void SetCodigo(const Codigo& novo_codigo) {
        codigo = novo_codigo;
    }

    
    void SetNome(const Nome& novo_nome) {
        nome = novo_nome;
    }

    
    void SetPerfil(const Perfil& novo_perfil) {
        perfil = novo_perfil;
    }
};


class Ordem {
private:
    Codigo_de_Negociacao codigo_de_negociacao;  
    Dinheiro dinheiro;                          
    Quantidade quantidade;                      
    Data data;                                  
    Codigo codigo;                              

public:

    Codigo_de_Negociacao& GetCodigoDeNegociacao() {
        return codigo_de_negociacao;
    }

    const Codigo_de_Negociacao& GetConstCodigoDeNegociacao() const {
        return codigo_de_negociacao;
    }


    Dinheiro& GetDinheiro() {
        return dinheiro;
    }

    const Dinheiro& GetConstDinheiro() const {
        return dinheiro;
    }


    Quantidade& GetQuantidade() {
        return quantidade;
    }

    const Quantidade& GetConstQuantidade() const {
        return quantidade;
    }


    Data& GetData() {
        return data;
    }

    const Data& GetConstData() const {
        return data;
    }


    Codigo& GetCodigo() {
        return codigo;
    }

    const Codigo& GetConstCodigo() const {
        return codigo;
    }

 
    void SetCodigoDeNegociacao(const Codigo_de_Negociacao& novo_codigo_de_negociacao) {
        codigo_de_negociacao = novo_codigo_de_negociacao;
    }


    void SetDinheiro(const Dinheiro& novo_dinheiro) {
        dinheiro = novo_dinheiro;
    }

  
    void SetQuantidade(const Quantidade& nova_quantidade) {
        quantidade = nova_quantidade;
    }

   
    void SetData(const Data& nova_data) {
        data = nova_data;
    }


    void SetCodigo(const Codigo& novo_codigo) {
        codigo = novo_codigo;
    }
};


class StorageCarteira: public Carteira {
    Cpf cpf_associado;

    public:
        Cpf& GetCpfAssociado() {
            return this->cpf_associado;
        };

        const Cpf& GetConstCpfAssociado() const {
            return this->cpf_associado;
        }

        void SetCpfAssociado(const Cpf& cpf) {
            this->cpf_associado.Set(cpf.Get());
        }

};

class StorageOrdem: public Ordem {
    Codigo id;

    public:
        const Codigo& GetConstId() const {
            return id;
        }

        Codigo& GetId() {
            return id;
        }

        void SetId(const Codigo& codigo) {
            this->id = codigo;
        }
};
