#include <stddef.h>
#include <iostream>
#include "RubroNegra.h"

RubroNegra::RubroNegra() {
    this->pai = NULL;
}

RubroNegra::add(int valor) {
    if (this->pai == NULL) {
        Folha *folha = new Folha(valor);
        this->pai = folha;
        folha->cor == 'p';
    }
    //continuar
}

RubroNegra::busca(int valor) {

}

RubroNegra::printTree(Folha *f) {
    if (this->pai == NULL) cout << "()";
    else {
        cout << "(" << f->valor << f->cor << ",";
        printTree(f->folhaEsq);
        cout << ",";
        printTree(f->folhaDir);
        cout << ")";
    }
}

RubroNegra::~RubroNegra() {
}