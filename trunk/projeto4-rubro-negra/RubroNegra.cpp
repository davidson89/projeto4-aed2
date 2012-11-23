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
        this->raiz = new Folha(valor, NULL, this->nil);
        this->raiz->cor = 'p';
    } else insere_recursivo(this->raiz, valor);
}

void RubroNegra::insere_recursivo(Folha* f, int valor) {
    if (valor < f->valor) {
        if (f->folhaEsq == this->nil) f->folhaEsq = new Folha(valor, f, this->nil);
        else insere_recursivo(f->folhaEsq, valor);
    }
    if (valor > f->valor) {
        if (f->folhaDir == this->nil) f->folhaDir = new Folha(valor, f, this->nil);
        else insere_recursivo(f->folhaDir, valor);
    }
    //chamar um metodo para verificar integridade da arvore e fazer as devidas rotacoes e alteracoes de cor
}

void RubroNegra::rot_esq(Folha *f) {

}

void RubroNegra::rot_dir(Folha *f) {

}

void RubroNegra::busca(int valor) {
    busca_recursiva(this->raiz, valor);
}

void RubroNegra::busca_recursiva(Folha* f, int valor) {
    if (f == this->nil) return;
    if (valor < f->valor) {
        cout << f->valor << ";";
        busca_recursiva(f->folhaEsq, valor);
    } else if (valor > f->valor) {
        cout << f->valor << ";";
        busca_recursiva(f->folhaDir, valor);
    } else cout << f->valor << ";";
}

void RubroNegra::imprime_arvore() {
    imprime_pre_ordem(this->raiz);
}

void RubroNegra::imprime_pre_ordem(Folha *f) {
    if (f == this->nil) cout << "()";
    else {
        cout << "(" << f->valor << f->cor << ",";
        imprime_pre_ordem(f->folhaEsq);
        cout << ",";
        imprime_pre_ordem(f->folhaDir);
        cout << ")";
    }
}

void RubroNegra::desaloca_arvore(Folha *f) {
    if (f != this->nil) {
        desaloca_arvore(f->folhaEsq);
        desaloca_arvore(f->folhaDir);
    }
    delete f;
}

RubroNegra::~RubroNegra() {
    desaloca_arvore(this->raiz);
}