#include "testes_dom.hpp"
#include "dominios.hpp"

#include <iostream>
#include <stdexcept>
#include <cassert>

// CodeTest Implementation
void CodeTest::Run() {
    // Valid test case
    try {
        Code code;
        code.Set(12345);  // Valid value
        assert(code.Get() == 12345);
        std::cout << "Code test passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Code test failed: " << e.what() << std::endl;
    }

    // Invalid test case
    try {
        Code code;
        code.Set(123456);  // Invalid value, too large
        std::cout << "Code test failed: Exception not thrown." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Code invalid test passed: " << e.what() << std::endl;
    }
}

// NameTest Implementation
void NameTest::Run() {
    // Valid test case
    try {
        Name name;
        name.Set("John Doe");  // Valid name
        assert(name.Get() == "John Doe");
        std::cout << "Name test passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Name test failed: " << e.what() << std::endl;
    }

    // Invalid test case
    try {
        Name name;
        name.Set("John   Doe");  // Invalid name with consecutive spaces
        std::cout << "Name test failed: Exception not thrown." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Name invalid test passed: " << e.what() << std::endl;
    }
}

// TradeCodeTest Implementation
void TradeCodeTest::Run() {
    // Valid test case
    try {
        TradeCode tradeCode;
        tradeCode.Set("A1B2C3");  // Valid trade code
        assert(tradeCode.Get() == "A1B2C3");
        std::cout << "TradeCode test passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "TradeCode test failed: " << e.what() << std::endl;
    }

    // Invalid test case
    try {
        TradeCode tradeCode;
        tradeCode.Set("A1B@C3");  // Invalid character '@'
        std::cout << "TradeCode test failed: Exception not thrown." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "TradeCode invalid test passed: " << e.what() << std::endl;
    }
}

// DateTest Implementation
void DateTest::Run() {
    // Valid test case
    try {
        Date date;
        date.Set("2025/05/13");  // Valid date
        assert(date.Get() == "2025/05/13");
        std::cout << "Date test passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Date test failed: " << e.what() << std::endl;
    }

    // Invalid test case
    try {
        Date date;
        date.Set("2025/13/32");  // Invalid date
        std::cout << "Date test failed: Exception not thrown." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Date invalid test passed: " << e.what() << std::endl;
    }
}

// ProfileTest Implementation
void ProfileTest::Run() {
    // Valid test case
    try {
        Profile profile;
        profile.Set("moderate");  // Valid profile
        assert(profile.Get() == "moderate");
        std::cout << "Profile test passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Profile test failed: " << e.what() << std::endl;
    }

    // Invalid test case
    try {
        Profile profile;
        profile.Set("extreme");  // Invalid profile
        std::cout << "Profile test failed: Exception not thrown." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Profile invalid test passed: " << e.what() << std::endl;
    }
}

// AmountTest Implementation
void AmountTest::Run() {
    // Valid test case
    try {
        Amount amount;
        amount.Set(500000);  // Valid amount
        assert(amount.Get() == 500000);
        std::cout << "Amount test passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Amount test failed: " << e.what() << std::endl;
    }

    // Invalid test case
    try {
        Amount amount;
        amount.Set(1000001);  // Invalid amount, too large
        std::cout << "Amount test failed: Exception not thrown." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Amount invalid test passed: " << e.what() << std::endl;
    }
}

// PasswordTest Implementation
void PasswordTest::Run() {
    // Valid test case
    try {
        Password password;
        password.Set("A1b#c2");  // Valid password
        assert(password.Get() == "A1b#c2");
        std::cout << "Password test passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Password test failed: " << e.what() << std::endl;
    }

    // Invalid test case
    try {
        Password password;
        password.Set("A1bc2");  // Invalid password (too short)
        std::cout << "Password test failed: Exception not thrown." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Password invalid test passed: " << e.what() << std::endl;
    }
}

// MoneyTest Implementation
void MoneyTest::Run() {
    // Valid test case
    try {
        Money money;
        money.Set(999999.99);  // Valid money value
        assert(money.Get() == 999999.99);
        std::cout << "Money test passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Money test failed: " << e.what() << std::endl;
    }

    // Invalid test case
    try {
        Money money;
        money.Set(1000000.01);  // Invalid value (too large)
        std::cout << "Money test failed: Exception not thrown." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Money invalid test passed: " << e.what() << std::endl;
    }
}

// CpfTest Implementation
void CpfTest::Run() {
    // Valid test case
    try {
        Cpf cpf;
        cpf.Set("123.456.789-01");  // Valid CPF
        assert(cpf.Get() == "123.456.789-01");
        std::cout << "CPF test passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "CPF test failed: " << e.what() << std::endl;
    }

    // Invalid test case
    try {
        Cpf cpf;
        cpf.Set("123.456.78-01");  // Invalid CPF (wrong length)
        std::cout << "CPF test failed: Exception not thrown." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "CPF invalid test passed: " << e.what() << std::endl;
    }
}
