#pragma once
#include <unordered_set>
#include <string>

class Code {
private:
    int value;  // Stores the numeric value
    bool isValid(int val) const;  // Validator function

public:
    int Get() const;
    void Set(int newValue);
};

class Name {
private:
    std::string value;
    bool isValid(const std::string& val) const;  // Validator function

public:
    const std::string& Get() const;
    void Set(const std::string& newValue);
};

class TradeCode {
private:
    std::string value;
    bool isValid(const std::string& val) const;  // Validator function

public:
    const std::string& Get() const;
    void Set(const std::string& newValue);
};

class Date {
private:
    std::string value;
    bool isValid(const std::string& val) const;  // Validator function

public:
    const std::string& Get() const;
    void Set(const std::string& newValue);
};

class Profile {
private:
    std::string value;
    std::unordered_set<std::string> validProfiles = {"Conservador", "Moderado", "Agressivo"};
    bool isValid(const std::string& val) const;  // Validator function

public:
    const std::string& Get() const;
    void Set(const std::string& newValue);
};

class Amount {
private:
    int value;
    bool isValid(int val) const;  // Validator function

public:
    int Get() const;
    void Set(int newValue);
};

class Password {
private:
    std::string value;
    bool isValid(const std::string& val) const;  // Validator function

public:
    const std::string& Get() const;
    void Set(const std::string& newValue);
};

class Money {
private:
    double value;
    bool isValid(double val) const;  // Validator function

public:
    double Get() const;
    void Set(double newValue);
};

class Cpf {
private:
    std::string value;
    bool isValid(const std::string& val) const;  // Validator function

public:
    const std::string& Get() const;
    void Set(const std::string& newValue);
};
