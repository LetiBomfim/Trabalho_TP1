#include "apr_invest.hpp"

void CtrlAprInvest::executar(){
        int32_t escolha;
        while (true) {
            escolha = this->ask_usuario();

            switch (escolha) {
                case LISTAR_CARTEIRA:
                    continue;
                case EDITAR_CARTEIRA:
                    continue;
                case EXCLUIR_CARTEIRA:
                    continue;
                case CRIAR_CARTEIRA:
                    continue;
                case LISTAR_INVESTIMENTO:
                    continue;
                case CRIAR_INVESTIMENTO:
                    continue;
                case EXCLUIR_INVESTIMENTO:
                    continue;
            }

        }
}
