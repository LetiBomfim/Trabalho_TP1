#include <cstdio>
#include "dominios.hpp"
#include <cctype>
#include <unordered_set>
#include <stdexcept>
#include <string>
#include <array>
#include <iostream>

// Classe relativa ao código --> Implementação por Letícia Gonçalves Bomfim (241002411)

bool Codigo::isValid(string val) const {
    if (val.length() != 5) return false;

    for (char c : val) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int Codigo::Get() const {
    return valor;
}

void Codigo::Set(string novo_valor) {
    if (!isValid(novo_valor)) {
        throw std::invalid_argument("O Código precisa ter 5 digitos e ser constituido apenas por números.");
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

// Classe relativa ao código de negociação --> Implementação por Vinícius Ferreira Marques de Oliveira (232012947)

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
            "O codigo de negociacao precisa ter até 12 caracteres e conter apenas digitos, letras e/ou espaços em branco."
        );
    }
    valor = novo_valor;
}

// Classe relativa a Data --> Implementação por Vinícius Ferreira Marques de Oliveira (232012947)
bool Data::isBissexto(int val) {
    return (val % 4 == 0 && (val % 100 != 0 || val % 400 == 0));
}

bool Data::isValid(const std::string& val) const {
    // Verificar tamanho.
    if (val.length() != 8) {
        return false;
    }

    // Verificar se todos os caracteres são dígitos.
    for (char c : val) {
        if (!isdigit(c)) {
            return false;
        }
    }

    int ano, mes, dia;
    try {
        // Extrair ano, mês e dia para o formato AAAAMMDD.
        ano = std::stoi(val.substr(0, 4)); 
        mes = std::stoi(val.substr(4, 2)); 
        dia = std::stoi(val.substr(6, 2)); 
    } catch (const std::out_of_range& oor) {
        return false;
    } catch (const std::invalid_argument& ia) {
        return false;
    }

    // Validar intervalo de mês.
    if (mes < 1 || mes > 12) {
        return false;
    }

    // Validar intervalo de dia.
    if (dia < 1 || dia > 31) {
        return false;
    }

    // Verificar dias válidos para cada mês.
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        return false;
    }

    // Verificar fevereiro e anos bissextos.
    if (mes == 2) {
        if (isBissexto(ano)) {
            if (dia > 29) {
                return false;
            }
        } else {
            if (dia > 28) {
                return false;
            }
        }
    }

    return true; 
}

void Data::Set(const std::string& novo_valor) {
    if (!isValid(novo_valor)) {
        throw std::invalid_argument(
            "A data deve estar no formato AAAAMMDD com valores de data validos."
        );
    }
    valor = novo_valor;
}

// Classe relativa ao Perfil --> Implementação por Eduardo Silva Barbosa (222005439)

bool Perfil::isValid(const std::string& val) const {
    return perfilvalido.find(val) != perfilvalido.end();
}

const std::string& Perfil::Get() const {
    return valor;
}

void Perfil::Set(const std::string& novo_valor) {
    if (!isValid(novo_valor)) {
        throw std::invalid_argument(
            "O Perfil deve ser um dos seguintes: Conservador, Moderado ou Agressivo."
        );
    }
    valor = novo_valor;
}

// Classe relativa a Quantidade --> Implementação por Sarah Novais Magalhães (232006476)

bool Quantidade::isValid(int val) const {
    return val >= 1 && val <= 1000000;
}

int Quantidade::Get() const {
    return valor;
}

void Quantidade::Set(int novo_valor) {
    if (!isValid(novo_valor)) {
        throw std::invalid_argument(
            "A Quantidade deve ser de 1 a 1.000.000."
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

// Classe relativa a CPF --> Implementação por Eduardo Silva Barbosa (222005439) e Sarah Novais Magalhães (232006476)

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
