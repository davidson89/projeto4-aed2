#include <stddef.h>
#include <iostream>
#include "RubroNegra.h"

using namespace std;

RubroNegra::RubroNegra() {
    this->pai = NULL;
}

void RubroNegra::add(int valor) {
    if (this->pai == NULL) {
        Folha *folha = new Folha(valor);
        this->pai = folha;
        folha->cor == 'p';
    }
    //continuar
}

void RubroNegra::busca(int valor) {

}

void RubroNegra::printTree() {
    printPreOrdem(this->pai);
}

void RubroNegra::printPreOrdem(Folha *f) {
    if (this->pai == NULL) cout << "()";
    else {
        cout << "(" << f->valor << f->cor << ",";
        printPreOrdem(f->folhaEsq);
        cout << ",";
        printPreOrdem(f->folhaDir);
        cout << ")";
    }
}

RubroNegra::~RubroNegra() {
}