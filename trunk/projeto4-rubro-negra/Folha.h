#ifndef FOLHA_H
#define	FOLHA_H

class Folha {
public:
    Folha(int valor);
    int valor;
    char cor;
    Folha *pai;
    Folha *folhaDir;
    Folha *folhaEsq;
};

#endif	/* FOLHA_H */