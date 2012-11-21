#include <stddef.h>
#include <iostream>
#include "RubroNegra.h"

using namespace std;

RubroNegra::RubroNegra() {
    this->pai = NULL;
}

void RubroNegra::add(int valor) {
    if (this->pai == NULL) {
        this->pai = new Folha(valor);
        this->pai->cor == 'p';
    } else insereRecursivo(this->pai, valor);
}

void RubroNegra::insereRecursivo(Folha* f, int valor) {
    if (valor < f.valor) {
        if (f->folhaEsq == NULL) f->folhaEsq = new Folha(valor);
        else return insereRecursivo(f->folhaEsq, valor);
    }
    if (valor > f.valor) {
        if (f->folhaDir == NULL) f->folhaDir = new Folha(valor);
        else return insereRecursivo(f->folhaDir, valor);
    }
    //chamar um metodo para verificar integridade da arvore e fazer as devidas rotacoes e alteracoes de cor
}

void RubroNegra::busca(int valor) {
    buscaRecursiva(this->pai, valor);
}

void RubroNegra::buscaRecursiva(Folha* f, int valor) {
    if (f == NULL) return;
    if (valor < f->valor) {
        cout << f->valor << ";";
        return buscaRecursiva(f->folhaEsq, valor);
    } else if (valor > f.valor) {
        cout << f->valor << ";";
        return buscaRecursiva(f->folhaDir, valor);
    } else cout << f->valor << ";";
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