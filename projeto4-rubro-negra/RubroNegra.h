#ifndef RUBRONEGRA_H
#define	RUBRONEGRA_H
#include "Folha.h"

class RubroNegra {
public:
    RubroNegra();
    virtual ~RubroNegra();
    void add(int valor);
    void busca(int valor);
    void printTree(Folha *f);
private:
    RubroNegra *pai;
};

#endif	/* RUBRONEGRA_H */