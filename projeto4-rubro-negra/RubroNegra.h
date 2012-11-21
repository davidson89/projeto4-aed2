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
    Folha *pai;
    Folha *nil;
    void insereRecursivo(Folha *f, int valor);
    void buscaRecursiva(Folha *f, int valor);
    Folha* rotacionaParaDireita(Folha *f);
    Folha* rotacionaParaEsquerda(Folha *f);
    void printPreOrdem(Folha *f);
};

#endif	/* RUBRONEGRA_H */