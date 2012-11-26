#ifndef RUBRONEGRA_H
#define	RUBRONEGRA_H
#include "Folha.h"

class RubroNegra {
public:
    RubroNegra();
    virtual ~RubroNegra();
    void insere(int valor);
    void busca(int valor);
    void imprime_arvore();
private:
    Folha *raiz;
    Folha *nil;
    void insere_recursivo(Folha *f, int valor);
    void busca_recursiva(Folha *f, int valor);
    void rot_esq(Folha *f);
    void rot_dir(Folha *f);
    void rb_fixup(Folha *f);
    void imprime_pre_ordem(Folha *f);
    void desaloca_arvore(Folha *f);
};

#endif	/* RUBRONEGRA_H */