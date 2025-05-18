#include "dominios.hpp"
#include <cctype>
#include <unordered_set>
#include <stdexcept>
#include <string>
#include <array>

// Classe relativa ao código --> Implementação por Letícia Gonçalves Bomfim (241002411) 

bool Codigo::isValid(int val) const {
    return val >= -99999 && val <= 99999;
}

int Codigo::Get() const {
    return valor;
}

void Codigo::Set(int novo_valor) {
    if (!isValid(novo_valor)) {
        throw std::invalid_argument("Valor precisa ter 5 digitos ou menos");
    }
    valor = novo_valor;
}

// Classe relativa ao nome --> Implementação por Letícia Gonçalves Bomfim (241002411) 

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
            "O nome precisa ter 20 ou menos characteres, e ser constituido apenas por alfanumericos e espaços, "
            "e nao pode ter espaços em branco em sequencia"
        );
    }
    valor = novo_valor;
}

// Classe relativa ao código de negociação --> Implementação por VINICIUS FERREIRA MARQUES DE OLIVEIRA (232012947)

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
            "O codigo de negociacao precisa ter até 12 caracteres e conter apenas digitos, letras e espaços em branco."
        );
    }
    valor = novo_valor;
}

// Classe relativa a Data --> Implementação por VINICIUS FERREIRA MARQUES DE OLIVEIRA (232012947)

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

    constexpr std::array<int, 12> dias_do_mes = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int max = dias_do_mes[mes - 1];

    if (mes == 2 && (ano % 400 == 0 || (ano % 100 != 0 && ano % 4 == 0))) {
        max = 29; //valor máximo de dias
    }

    return dia >= 1 && dia <= max;
}

const std::string& Data::Get() const {
    return valor;
}

void Data::Set(const std::string& novo_valor) {
    if (!isValid(novo_valor)) {
        throw std::invalid_argument(
            "A data deve estar no formato AAAA/MM/DD com valores de data validos."
        );
    }
    valor = novo_valor;
}

// Classe relativa ao Perfil --> Implementação por EDUARDO SILVA BARBOSA (222005439)

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

// Classe relativa a Quantidade --> Implementação por SARAH NOVAIS MAGALHÃES (232006476)

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

// Classe relativa a Senha --> Implementação por Luisa Ribeiro de Oliveira (241024197)

bool Senha::isValid(const std::string& val) const {
    if (val.length() != 6) return false;

    std::unordered_set<char> charSet;
    for (char c : val) {
        if (charSet.find(c) != charSet.end()) return false;
        charSet.insert(c);
    }

    bool numero = false, letra = false, letra_maiuscula = false, simbolo = false;
    for (char c : val) {
        if (isdigit(c)) numero = true;
        else if (islower(c)) letra = true;
        else if (isupper(c)) letra_maiuscula = true;
        else if (c == '#' || c == '$' || c == '%' || c == '&') simbolo = true;
    }

    return numero && letra && letra_maiuscula && simbolo;
}

const std::string& Senha::Get() const {
    return valor;
}

void Senha::Set(const std::string& novo_valor) {
    if (!isValid(novo_valor)) {
        throw std::invalid_argument(
            "A senha deve ter exatamente 6 caracteres, conter ao menos um numero, "
            "uma letra minuscula, uma letra maiuscula e um dos seguintes simbolos: #, $, % ou &."
        );
    }
    valor = novo_valor;
}

// Classe relativa a Dinheiro --> Implementação por Luisa Ribeiro de Oliveira (241024197)

bool Dinheiro::isValid(double val) const {
    return val >= 0.01 && val <= 1000000.00;
}

double Dinheiro::Get() const {
    return valor;
}

void Dinheiro::Set(double novo_valor) {
    if (!isValid(novo_valor)) {
        throw std::invalid_argument(
            "O valor monetario deve estar entre 0,01 e 1.000.000,00."
        );
    }
    valor = novo_valor;
}

// Classe relativa a CPF --> Implementação por EDUARDO SILVA BARBOSA (222005439) e SARAH NOVAIS MAGALHÃES (232006476)

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
    return valor;
}

void Cpf::Set(const std::string& novo_valor) {
    if (!isValid(novo_valor)) {
        throw std::invalid_argument(
            "O CPF deve estar no formato XXX.XXX.XXX-XX, onde X eh um digito."
        );
    }
    valor = novo_valor;
}
