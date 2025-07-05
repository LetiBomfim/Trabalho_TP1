#include "../../interfaces/interfaces.hpp"

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
