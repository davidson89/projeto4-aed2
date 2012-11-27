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
        this->raiz = new Folha(valor, this->nil, this->nil);
        this->raiz->cor = 'p';
    } else insere_recursivo(this->raiz, valor);
}

void RubroNegra::insere_recursivo(Folha* f, int valor) {
    if (valor < f->valor) {
        if (f->folhaEsq == this->nil) {
            Folha *aux = new Folha(valor, f, this->nil);
            f->folhaEsq = aux;
            return rb_fixup(aux);
        } else insere_recursivo(f->folhaEsq, valor);
    } else if (valor > f->valor) {
        if (f->folhaDir == this->nil) {
            Folha *aux = new Folha(valor, f, this->nil);
            f->folhaDir = aux;
            return rb_fixup(aux);
        } else insere_recursivo(f->folhaDir, valor);
    }
}

void RubroNegra::rb_fixup(Folha *f) {
    while (f->pai->cor == 'v') {
        if (f->pai == f->pai->pai->folhaEsq) { //pai de f é filho esquerdo
            Folha *aux = f->pai->pai->folhaDir; //aux aponta pro tio de f
            if (aux->cor = 'v') { //caso 1: tio vermelho
                f->pai->cor = 'p';
                aux->cor = 'p'; //tio vermelho vira preto
                f->pai->pai->cor = 'v'; //avô vira vermelho
            } else {
                if (f == f->pai->folhaDir) { //caso 2: f é filho direito
                    f = f->pai;
                    rot_esq(f); //rotaciona à esquerda no pai de f
                }
                f->pai->cor = 'p'; //caso 3: f é filho esquerdo
                f->pai->pai->cor = 'v'; //avô vira vermelho
                rot_dir(f->pai->pai); //rotaciona à direita no avô de f
            }
        } else {
            Folha *aux = f->pai->pai->folhaEsq; //aux aponta pro tio de f
            if (aux->cor = 'v') { //caso 1: tio vermelho
                f->pai->cor = 'p';
                aux->cor = 'p'; //tio vermelho vira preto
                f->pai->pai->cor = 'v'; //avô vira vermelho
            } else {
                if (f == f->pai->folhaEsq) { //caso 2: f é filho esquerdo
                    f = f->pai;
                    rot_dir(f); //rotaciona à direita no pai de f
                }
                f->pai->cor = 'p'; //caso 3: f é filho direito
                f->pai->pai->cor = 'v'; //avô vira vermelho
                rot_esq(f->pai->pai); //rotaciona à esquerda no avô de f
            }
        }
    }
    this->raiz->cor = 'p';
}

void RubroNegra::rot_esq(Folha *f) {
    Folha *aux = f->folhaDir;
    f->folhaDir = aux->folhaEsq;
    if (aux->folhaEsq != this->nil) {
        aux->folhaEsq->pai = f;
    }
    aux->pai = f->pai;
    if (f->pai == this->nil) {
        this->raiz = aux;
    } else {
        if (f == f->folhaEsq->pai) f->folhaEsq->pai = aux;
        else f->folhaDir->pai = aux;
    }
    aux->folhaEsq = f;
    f->pai = aux;
}

void RubroNegra::rot_dir(Folha *f) {
    Folha *aux = f->folhaEsq;
    f->folhaEsq = aux->folhaDir;
    if (aux->folhaDir != this->nil) {
        aux->folhaDir->pai = f;
    }
    aux->pai = f->pai;
    if (f->pai == this->nil) {
        this->raiz = aux;
    } else {
        if (f == f->folhaDir->pai) f->folhaDir->pai = aux;
        else f->folhaEsq->pai = aux;
    }
    aux->folhaDir = f;
    f->pai = aux;
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
    if (!f->ehNil) {
        desaloca_arvore(f->folhaEsq);
        desaloca_arvore(f->folhaDir);
    }
    if (!f->ehNil) delete f;
}

RubroNegra::~RubroNegra() {
    desaloca_arvore(this->raiz);
    delete nil;
}