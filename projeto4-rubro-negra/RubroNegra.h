#ifndef RUBRONEGRA_H
#define	RUBRONEGRA_H
#include "Folha.h"

class RubroNegra {
public:
    RubroNegra();
    virtual ~RubroNegra();
    void add(int valor);
    void busca(int valor);
    void printTree();
private:
    RubroNegra *pai;
    Folha* rotacionaParaDireita(Folha *f);
    Folha* rotacionaParaEsquerda(Folha *f);
    void printPreOrdem(Folha *f);
};

#endif	/* RUBRONEGRA_H */