#include <stddef.h>
#include <iostream>
#include "RubroNegra.h"

using namespace std;

RubroNegra::RubroNegra() {
    this->raiz = NULL;
    this->nil = new Folha();
}

void RubroNegra::insere(int valor) {
    if (this->raiz == NULL) {
        this->raiz = new Folha(valor, this->nil);
        this->raiz->pai = NULL;
        this->raiz->cor = 'p';
    } else insereRecursivo(this->raiz, valor);
}

void RubroNegra::insereRecursivo(Folha* f, int valor) {
    if (valor < f->valor) {
        if (f->folhaEsq == this->nil) f->folhaEsq = new Folha(valor, this->nil);
        else insereRecursivo(f->folhaEsq, valor);
    }
    if (valor > f->valor) {
        if (f->folhaDir == this->nil) f->folhaDir = new Folha(valor, this->nil);
        else insereRecursivo(f->folhaDir, valor);
    }
    //chamar um metodo para verificar integridade da arvore e fazer as devidas rotacoes e alteracoes de cor
}

void RubroNegra::busca(int valor) {
    buscaRecursiva(this->raiz, valor);
}

void RubroNegra::buscaRecursiva(Folha* f, int valor) {
    if (f == this->nil) return;
    if (valor < f->valor) {
        cout << f->valor << ";";
        buscaRecursiva(f->folhaEsq, valor);
    } else if (valor > f->valor) {
        cout << f->valor << ";";
        buscaRecursiva(f->folhaDir, valor);
    } else cout << f->valor << ";";
}

void RubroNegra::imprimeArvore() {
    printPreOrdem(this->raiz);
}

void RubroNegra::printPreOrdem(Folha *f) {
    if (f == this->nil) cout << "()";
    else {
        cout << "(" << f->valor << f->cor << ",";
        printPreOrdem(f->folhaEsq);
        cout << ",";
        printPreOrdem(f->folhaDir);
        cout << ")";
    }
}

void RubroNegra::desalocaArvore(Folha *f) {
    if (f != this->nil) {
        desalocaArvore(f->folhaEsq);
        desalocaArvore(f->folhaDir);
    }
    delete f;
}

RubroNegra::~RubroNegra() {
    desalocaArvore(this->raiz);
}