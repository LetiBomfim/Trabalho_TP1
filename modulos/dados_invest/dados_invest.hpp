#include "../../interfaces/interfaces.hpp"

class DadosHist: public InterDadosHist {
    private:
        static DadosHist* singleton;

    public:
        static DadosHist* get_singleton();
        bool set_valor_ordem(Ordem&);
};
