#include "../../interfaces/interfaces.hpp"

/**
 * @brief Implementação do serviço de dados históricos de investimentos.
 *
 * Esta classe fornece operações para atualização dos valores de ordens de investimento
 * com base em dados históricos do mercado. Utiliza o padrão Singleton para garantir
 * que apenas uma instância seja utilizada durante a execução do sistema.
 */
class DadosHist: public InterDadosHist {
    private:
        static DadosHist* singleton;

    public:
         /**
        * @brief Recupera a instância singleton do serviço de dados históricos.
        * @return Ponteiro para a instância única de DadosHist.
        */
        static DadosHist* get_singleton();
        /**
        * @brief Atualiza o valor de uma ordem de investimento com base nos dados históricos disponíveis.
        * @param ordem Referência para o objeto ordem a ser atualizado.
        * @return true se a atualização foi bem-sucedida, false caso contrário.
        */
        bool set_valor_ordem(Ordem&);
};
