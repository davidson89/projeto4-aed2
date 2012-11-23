#ifndef RUBRONEGRA_H
#define	RUBRONEGRA_H
#include "Folha.h"

class RubroNegra {
public:
    RubroNegra();
    virtual ~RubroNegra();
    void insere(int valor);
    void busca(int valor);
    void imprimeArvore();
private:
    Folha *raiz;
    Folha *nil;
    void insereRecursivo(Folha *f, int valor);
    void insereNil(Folha *f);
    void buscaRecursiva(Folha *f, int valor);
    Folha* rotacionaParaDireita(Folha *f);
    Folha* rotacionaParaEsquerda(Folha *f);
    void printPreOrdem(Folha *f);
    void desalocaArvore(Folha *f);
};

#endif	/* RUBRONEGRA_H */