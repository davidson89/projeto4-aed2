#ifndef FOLHA_H
#define	FOLHA_H

class Folha {
public:
    Folha();
    Folha(int valor, Folha *pai, Folha *nil);
    int valor;
    char cor;
    bool ehNil;
    Folha *pai;
    Folha *folhaDir;
    Folha *folhaEsq;
};

#endif	/* FOLHA_H */