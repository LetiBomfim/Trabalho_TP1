#include "dominios.hpp"
#include <cctype>
#include <unordered_set>
#include <stdexcept>
#include <string>
#include <array>

// Classe relativa ao código --> Implementação por Letícia Bomfim (241002411) 

bool Codigo::isValid(int val) const {
    return val >= -99999 && val <= 99999;
}

int Codigo::Get() const {
    return valor;
}

void Codigo::Set(int novo_valor) {
    if (!isValid(novo_valor)) {
        throw std::invalid_argument("Code value must be a 5-digit number or less");
    }
    valor = novo_valor;
}

// Classe relativa ao nome --> Implementação por 

bool Nome::isValid(const std::string& val) const {
    if (val.length() > 20) return false;

    bool espaco = false; // bool que verifica se o caracter anterior é um espaço
    for (char c : val) {
        if (!(isalnum(c) || c == ' ')) {
            return false;
        }
        if (c == ' ') {
            if (espaco) return false;
            espaco = true;
        } else {
            espaco = false;
        }
    }
    return true;
}

const std::string& Nome::Get() const {
    return valor;
}

void Nome::Set(const std::string& novo_valor) {
    if (!isValid(novo_valor)) {
        throw std::invalid_argument(
            "O nome precisa ter 20 ou menos characteres, e ser constituído apenas por alfanuméricos e espaços, "
            "e não pode ter espaços em branco em sequência"
        );
    }
    valor = novo_valor;
}

// Classe relativa ao código de negociação --> Implementação por 

bool Codigo_de_Negociacao::isValid(const std::string& val) const {
    if (val.length() > 12) return false;

    for (char c : val) {
        if (!(isalnum(c) || c == ' ')) {
            return false;
        }
    }
    return true;
}

const std::string& Codigo_de_Negociacao::Get() const {
    return valor;
}

void Codigo_de_Negociacao::Set(const std::string& novo_valor) {
    if (!isValid(novo_valor)) {
        throw std::invalid_argument(
            "O código de negociação precisa ter até 12 caracteres e conter apenas dígitos, letras e espaços em branco."
        );
    }
    valor = novo_valor;
}

// Classe relativa a Data --> Implementação por 

bool Data::isValid(const std::string& val) const {
    if (val.length() != 10 || val[4] != '/' || val[7] != '/') {
        return false;
    }

    int ano, mes, dia;
    try {
        ano = std::stoi(val.substr(0, 4));
        mes = std::stoi(val.substr(5, 2));
        dia = std::stoi(val.substr(8, 2));
    } catch (...) {
        return false;
    }

    if (ano < 1900 || ano > 2100) return false;
    if (mes < 1 || mes > 12) return false;

    constexpr std::array<int, 12> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDay = daysInMonth[mes - 1];

    if (mes == 2 && (ano % 400 == 0 || (ano % 100 != 0 && ano % 4 == 0))) {
        maxDay = 29;
    }

    return dia >= 1 && dia <= maxDay;
}

const std::string& Data::Get() const {
    return valor;
}

void Data::Set(const std::string& novo_valor) {
    if (!isValid(novo_valor)) {
        throw std::invalid_argument(
            "A data deve estar no formato AAAA/MM/DD com valores de data válidos."
        );
    }
    valor = novo_valor;
}

// Classe relativa ao Perfil --> Implementação por 

bool Perfil::isValid(const std::string& val) const {
    return perfilvalido.find(val) != perfilvalido.end();
}

const std::string& Perfil::Get() const {
    return valor;
}

void Perfil::Set(const std::string& novo_valor) {
    if (!isValid(novo_valor)) {
        throw std::invalid_argument(
            "O Perfil deve ser um dos seguintes: conservador, moderado, agressivo."
        );
    }
    valor = novo_valor;
}

// Classe relativa a Quantidade --> Implementação por 

bool Quantidade::isValid(int val) const {
    return val >= 1 && val <= 1000000;
}

int Quantidade::Get() const {
    return valor;
}

void Quantidade::Set(int novo_valor) {
    if (!isValid(novo_valor)) {
        throw std::invalid_argument(
            "A Quantidade deve estar entre 1 e 1.000.000."
        );
    }
    valor = novo_valor;
}

// Classe relativa a Senha --> Implementação por 

bool Senha::isValid(const std::string& val) const {
    if (val.length() != 6) return false;

    std::unordered_set<char> charSet;
    for (char c : val) {
        if (charSet.find(c) != charSet.end()) return false;
        charSet.insert(c);
    }

    bool hasNumber = false, hasLower = false, hasUpper = false, hasSymbol = false;
    for (char c : val) {
        if (isdigit(c)) hasNumber = true;
        else if (islower(c)) hasLower = true;
        else if (isupper(c)) hasUpper = true;
        else if (c == '#' || c == '$' || c == '%' || c == '&') hasSymbol = true;
    }

    return hasNumber && hasLower && hasUpper && hasSymbol;
}

const std::string& Senha::Get() const {
    return valor;
}

void Senha::Set(const std::string& novo_valor) {
    if (!isValid(novo_valor)) {
        throw std::invalid_argument(
            "A senha deve ter exatamente 6 caracteres, conter ao menos um número, "
            "uma letra minúscula, uma letra maiúscula e um dos seguintes símbolos: #, $, % ou &."
        );
    }
    valor = novo_valor;
}

// Classe relativa a Dinheiro --> Implementação por 

bool Dinheiro::isValid(double val) const {
    return val >= 0.01 && val <= 1000000.00;
}

double Dinheiro::Get() const {
    return valor;
}

void Dinheiro::Set(double novo_valor) {
    if (!isValid(novo_valor)) {
        throw std::invalid_argument(
            "O valor monetário deve estar entre 0,01 e 1.000.000,00."
        );
    }
    valor = novo_valor;
}

/////////////////////
// Cpf Class
/////////////////////

bool Cpf::isValid(const std::string& val) const {
    if (val.length() != 14) return false;

    for (size_t i = 0; i < val.length(); ++i) {
        if (i == 3 || i == 7) {
            if (val[i] != '.') return false;
        } else if (i == 11) {
            if (val[i] != '-') return false;
        } else {
            if (!isdigit(val[i])) return false;
        }
    }

    return true;
}

const std::string& Cpf::Get() const {
    return value;
}

void Cpf::Set(const std::string& newValue) {
    if (!isValid(newValue)) {
        throw std::invalid_argument(
            "CPF must be in the format XXX.XXX.XXX-XX, where X is a digit"
        );
    }
    value = newValue;
}
