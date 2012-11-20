#ifndef FOLHA_H
#define	FOLHA_H

class Folha {
public:
    Folha(int valor);
    int valor;
    char cor;
    Folha *folhaDir;
    Folha *folhaEsq;
    void setCor(Folha *f, char c);
    char getCor(Folha *f);
};

#endif	/* FOLHA_H */