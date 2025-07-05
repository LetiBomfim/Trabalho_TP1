#pragma once
#include "../../interfaces/interfaces.hpp"
#include <cstdint>

using namespace std ;

/**
 * @brief Controlador da camada de apresentação para operações relacionadas à conta.
 * Implementa a interface InterApresConta.
 */
class CtrlAprConta: public InterApresConta {
    static const int32_t LER = 0;       ///< Opção do menu para ler os dados da conta.
    static const int32_t ATUALIZAR = 1; ///< Opção do menu para atualizar os dados da conta.
    static const int32_t EXCLUIR = 2;   ///< Opção do menu para excluir a conta.
    static const int32_t CRIAR = 3;     ///< Opção do menu para criar uma nova conta.
    static const int32_t SAIR = 4;      ///< Opção do menu para sair da operação.

private:
    InterServConta* serv_conta = nullptr; ///< Ponteiro para o serviço de conta.

    Cpf cpf_usuario; ///< CPF do usuário logado.

    /**
     * @brief Exibe opções ao usuário e retorna a opção escolhida.
     * @return Código inteiro representando a ação desejada.
     */
    int32_t ask_usuario();

    /**
     * @brief Solicita os dados para criação de uma nova conta.
     * @return true se a conta for criada com sucesso, false caso contrário.
     */
    bool criar_conta();

    /**
     * @brief Lê e exibe os dados da conta associada ao CPF informado.
     * @param cpf CPF da conta a ser lida.
     */
    void ler_conta(const Cpf& cpf);

    /**
     * @brief Solicita atualização dos dados da conta do usuário.
     * @return true se a conta for atualizada com sucesso, false caso contrário.
     */
    bool atualizar_conta();

    /**
     * @brief Exclui a conta associada ao CPF informado.
     * @param cpf CPF da conta a ser excluída.
     * @return true se a exclusão for bem-sucedida, false caso contrário.
     */
    bool excluir_conta(const Cpf& cpf);

public:
    /**
     * @brief Construtor padrão do controlador.
     */
    CtrlAprConta();

    /**
     * @brief Executa o fluxo de apresentação para um usuário autenticado.
     * @param cpf Ponteiro para o CPF do usuário logado.
     */
    void executar(const Cpf* cpf);
};
