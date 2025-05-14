#include "dominios.hpp"
#include <cctype>
#include <unordered_set>
#include <stdexcept>
#include <string>
#include <array>

/////////////////////
// Code Class
/////////////////////

bool Code::isValid(int val) const {
    return val >= -99999 && val <= 99999;
}

int Code::Get() const {
    return value;
}

void Code::Set(int newValue) {
    if (!isValid(newValue)) {
        throw std::invalid_argument("Code value must be a 5-digit number or less");
    }
    value = newValue;
}

/////////////////////
// Name Class
/////////////////////

bool Name::isValid(const std::string& val) const {
    if (val.length() > 20) return false;

    bool prevWasSpace = false;
    for (char c : val) {
        if (!(isalnum(c) || c == ' ')) {
            return false;
        }
        if (c == ' ') {
            if (prevWasSpace) return false;
            prevWasSpace = true;
        } else {
            prevWasSpace = false;
        }
    }
    return true;
}

const std::string& Name::Get() const {
    return value;
}

void Name::Set(const std::string& newValue) {
    if (!isValid(newValue)) {
        throw std::invalid_argument(
            "Name must be ≤20 chars, alphanumeric+spaces only, "
            "and no consecutive spaces"
        );
    }
    value = newValue;
}

/////////////////////
// TradeCode Class
/////////////////////

bool TradeCode::isValid(const std::string& val) const {
    if (val.length() > 12) return false;

    for (char c : val) {
        if (!(isalnum(c) || c == ' ')) {
            return false;
        }
    }
    return true;
}

const std::string& TradeCode::Get() const {
    return value;
}

void TradeCode::Set(const std::string& newValue) {
    if (!isValid(newValue)) {
        throw std::invalid_argument(
            "TradeCode must be ≤12 chars and contain only letters, numbers, and spaces"
        );
    }
    value = newValue;
}

/////////////////////
// Date Class
/////////////////////

bool Date::isValid(const std::string& val) const {
    if (val.length() != 10 || val[4] != '/' || val[7] != '/') {
        return false;
    }

    int year, month, day;
    try {
        year = std::stoi(val.substr(0, 4));
        month = std::stoi(val.substr(5, 2));
        day = std::stoi(val.substr(8, 2));
    } catch (...) {
        return false;
    }

    if (year < 1900 || year > 2100) return false;
    if (month < 1 || month > 12) return false;

    constexpr std::array<int, 12> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDay = daysInMonth[month - 1];

    if (month == 2 && (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))) {
        maxDay = 29;
    }

    return day >= 1 && day <= maxDay;
}

const std::string& Date::Get() const {
    return value;
}

void Date::Set(const std::string& newValue) {
    if (!isValid(newValue)) {
        throw std::invalid_argument(
            "Date must be in YYYY/MM/DD format with valid date values"
        );
    }
    value = newValue;
}

/////////////////////
// Profile Class
/////////////////////

bool Profile::isValid(const std::string& val) const {
    return validProfiles.find(val) != validProfiles.end();
}

const std::string& Profile::Get() const {
    return value;
}

void Profile::Set(const std::string& newValue) {
    if (!isValid(newValue)) {
        throw std::invalid_argument(
            "Profile must be one of the following: conservative, moderate, aggressive"
        );
    }
    value = newValue;
}

/////////////////////
// Amount Class
/////////////////////

bool Amount::isValid(int val) const {
    return val >= 1 && val <= 1000000;
}

int Amount::Get() const {
    return value;
}

void Amount::Set(int newValue) {
    if (!isValid(newValue)) {
        throw std::invalid_argument(
            "Amount must be between 1 and 1,000,000"
        );
    }
    value = newValue;
}

/////////////////////
// Password Class
/////////////////////

bool Password::isValid(const std::string& val) const {
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

const std::string& Password::Get() const {
    return value;
}

void Password::Set(const std::string& newValue) {
    if (!isValid(newValue)) {
        throw std::invalid_argument(
            "Password must be exactly 6 characters, contain at least one number, "
            "one lowercase letter, one uppercase letter, and one of these symbols: #, $, %, or &"
        );
    }
    value = newValue;
}

/////////////////////
// Money Class
/////////////////////

bool Money::isValid(double val) const {
    return val >= 0.01 && val <= 1000000.00;
}

double Money::Get() const {
    return value;
}

void Money::Set(double newValue) {
    if (!isValid(newValue)) {
        throw std::invalid_argument(
            "Money value must be between 0.01 and 1,000,000.00"
        );
    }
    value = newValue;
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
