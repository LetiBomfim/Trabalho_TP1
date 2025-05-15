#pragma once
#include <unordered_set>
#include <string>

class Codigo {
private:
    int valor;  
    bool isValid(int val) const;  // Função de validação da classe

public:
    int Get() const;
    void Set(int novo_valor);
};

class Nome {
private:
    std::string valor;
    bool isValid(const std::string& val) const;  // Função de validação da classe

public:
    const std::string& Get() const;
    void Set(const std::string& novo_valor);
};

class Codigo_de_Negociacao {
private:
    std::string valor;
    bool isValid(const std::string& val) const;  // Função de validação da classe

public:
    const std::string& Get() const;
    void Set(const std::string& novo_valor);
};

class Date {
private:
    std::string value;
    bool isValid(const std::string& val) const;  // Função de validação da classe

public:
    const std::string& Get() const;
    void Set(const std::string& newValue);
};

class Profile {
private:
    std::string value;
    std::unordered_set<std::string> validProfiles = {"Conservador", "Moderado", "Agressivo"};
    bool isValid(const std::string& val) const;  // Função de validação da classe

public:
    const std::string& Get() const;
    void Set(const std::string& newValue);
};

class Amount {
private:
    int value;
    bool isValid(int val) const;  // Função de validação da classe

public:
    int Get() const;
    void Set(int newValue);
};

class Password {
private:
    std::string value;
    bool isValid(const std::string& val) const;  // Função de validação da classe

public:
    const std::string& Get() const;
    void Set(const std::string& newValue);
};

class Money {
private:
    double value;
    bool isValid(double val) const;  // Função de validação da classe

public:
    double Get() const;
    void Set(double newValue);
};

class Cpf {
private:
    std::string value;
    bool isValid(const std::string& val) const;  // Função de validação da classe

public:
    const std::string& Get() const;
    void Set(const std::string& newValue);
};
