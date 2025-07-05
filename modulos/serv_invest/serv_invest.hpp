#include "../../interfaces/interfaces.hpp"
#include "../storage/storage.hpp"
#include "../dados_invest/dados_invest.hpp"
#include <stdexcept>

using namespace std;

/**
 * @brief Serviço de gerenciamento de investimentos.
 *
 * Fornece as operações de negócio para manipulação de carteiras e ordens de investimento no sistema. 
 * Realiza validações. Também ,permite criar, editar, excluir e listar carteiras e ordens.
 */
class ServInvest: public InterServInvest {
    private:
        InterStorage* storage = nullptr;
        InterDadosHist* dados_hist = nullptr;

    public:

         /**
        * @brief Construtor padrão. Inicializa os serviços de armazenamento e dados históricos.
        */
        ServInvest() {
            this->storage = Storage::get_singleton();
            this->dados_hist = DadosHist::get_singleton();
        }

    /**
     * @brief Cria uma nova carteira para o usuário, caso o mesmo seja válido.
     * @param carteira Objeto contendo os dados da carteira.
     * @param cpf Identificador do usuário proprietário da carteira.
     * @throw invalid_argument 
     */
        void criar_cart(const Carteira& carteira, const Cpf& cpf) {
            Conta conta;
            conta.SetCpf(cpf);
            if(!this->storage->get_conta(conta)) {
                throw invalid_argument("o referido cpf não existe no banco de dados");
            }

            StorageCarteira st_carteira;
            if (storage->count_carteiras_usuario(cpf) >= 5) {
                throw invalid_argument("não é possível criar mais uma carteira, o máximo é 5");
            };

            st_carteira.SetCpfAssociado(cpf);
            st_carteira.SetNome(carteira.GetConstNome());
            st_carteira.SetPerfil(carteira.GetConstPerfil());
            storage->add_carteira(st_carteira);
        };

         /**
        * @brief Atualiza as informações de uma carteira já existente.
        * @param carteira Objeto contendo os dados atualizados da carteira.
        */
        void editar_cart(const Carteira& carteira) {
            // pega a carteira
            StorageCarteira cart;
            cart.SetCodigo(carteira.GetConstCodigo());
            storage->get_carteira(cart);

            //  realiza a edição
            cart.SetNome(carteira.GetConstNome());
            cart.SetPerfil(carteira.GetConstPerfil());

            // salva a edição
            storage->remover_carteira(cart);
            storage->add_carteira_unchecked(cart);
        };


        /**
         * @brief Exclui uma carteira já existente.
         * @param carteira Objeto identificando a carteira a ser excluída.
         */
        void excluir_cart(const Carteira& carteira) {
            StorageCarteira st_carteira;
            st_carteira.SetCodigo(carteira.GetConstCodigo());

            storage->remover_carteira(st_carteira);
        };

         /**
        * @brief Lista todas as carteiras de um usuário.
        * @param cpf Identificador do usuário.
        * @return Ponteiro para uma lista de carteiras pertencentes ao usuário, ou nullptr se não houver carteiras.
        */
        lista<Carteira>* listar_cart(const Cpf& cpf) {
            lista<Carteira>* lst = nullptr;


            if (!storage->get_carteiras_usuario(cpf , &lst)) {
                return nullptr;
            }

            return lst;
        };

        /**
        * @brief Cria uma nova ordem de investimento para uma carteira existente.
        * @param ordem Objeto contendo os dados da ordem.
        * @throw invalid_argument .
        */
        void criar_ordem(const Ordem& ordem) {
            Ordem storage_ordem;
            storage_ordem.SetCodigoDeNegociacao(ordem.GetConstCodigoDeNegociacao());
            storage_ordem.SetCodigo(ordem.GetConstCodigo());
            storage_ordem.SetData(ordem.GetConstData());
            storage_ordem.SetQuantidade(ordem.GetConstQuantidade());

            StorageCarteira cart;
            cart.SetCodigo(ordem.GetConstCodigo());
            if (!this->storage->get_carteira(cart)) {
                throw invalid_argument("a carteira indicada pela ordem não existe");
            }

            if (!this->dados_hist->set_valor_ordem(storage_ordem)) {
                throw invalid_argument("o valor dessa ordem nesse dia não consta nos dados históricos");
            }

            if (!storage->add_ordem(storage_ordem)) {
                throw invalid_argument("alguma coisa deu errado na criação da ordem");
            }
        };

    /**
     * @brief Exclui uma ordem de investimento.
     * @param cod Código identificador da ordem.
     * @throw invalid_argument .
     */
        void excluir_ordem(const Codigo& cod) {
            if (!storage->remover_ordem(cod)) {
                throw new invalid_argument("alguma coisa deu errado na remoção da ordem");
            }
        };

    /**
     * @brief Lista todas as ordens de uma carteira.
     * @param carteira Objeto identificando a carteira.
     * @return nulltptr se não houver ordens.
     * @return Ponteiro para uma lista de ordens associadas à carteira.
     * @throw invalid_argument .
     */
        lista<StorageOrdem>* listar_ordem(const Carteira& carteira) {
            lista<StorageOrdem>* ls = nullptr;

            StorageCarteira st_carteira;
            st_carteira.SetCodigo(carteira.GetConstCodigo());
            if (!this->storage->get_carteira(st_carteira)) {
                throw invalid_argument("a carteira indicada não existe");
            }

            if (!storage->get_ordens_carteira(carteira, &ls)) {
                return ls;
            }

            return ls;
        }
};
