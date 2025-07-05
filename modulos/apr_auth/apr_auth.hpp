#pragma once
#include "../../interfaces/interfaces.hpp"

/**
 * @brief Controlador da camada de apresentação responsável pela autenticação de usuários.
 * Implementa a interface InterApresAuth.
 */
class CtrlAprAuth: public InterApresAuth {
private:
    InterServAuth* servico = nullptr; ///< Ponteiro para o serviço de autenticação.

    /**
     * @brief Solicita ao usuário o CPF e a senha.
     * @param cpf Objeto onde o CPF inserido será armazenado.
     * @param senha Objeto onde a senha inserida será armazenada.
     */
    void ask_cpf_e_senha(Cpf& cpf, Senha& senha);

public:
    /**
     * @brief Construtor padrão do controlador de autenticação.
     */
    CtrlAprAuth();

    /**
     * @brief Realiza o processo de autenticação.
     * @param cpf Objeto onde será armazenado o CPF do usuário autenticado.
     * @return true se a autenticação for bem-sucedida, false caso contrário.
     */
    bool autenticar(Cpf& cpf);
};