#include <stddef.h>
#include <iostream>
#include "RubroNegra.h"

using namespace std;

/**
 * RubroNegra - Construtor. Faz o ponteiro para a raiz da árvore apontar para nulo e cria a primeira instância da classe Folha, o objeto nil.
 **/
RubroNegra::RubroNegra() {
    this->raiz = NULL;
    this->nil = new Folha();
}

/**
 * insere - Caso a árvore não possua nenhum nó um nó é criado fazendo com que o ponteiro raiz aponte para esse nó. Caso a árvore já possua um nó o método insere_recursivo é invocado.
 * @param valor a ser inserido.
 **/
void RubroNegra::insere(int valor) {
    if (this->raiz == NULL) {
        this->raiz = new Folha(valor, this->nil, this->nil);
        this->raiz->cor = 'p';
    } else insere_recursivo(this->raiz, valor);
}

/**
 * insere_recursivo - Percorre a árvore recursivamente procurando o local onde o novo nó deve ser inserido. Após inserir invoca o método rb_fixup.
 * @param raiz da árvore / subárvore.
 * @param valor a ser inserido.
 **/
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

/**
 * rb_fixup - Reestrutura a árvore de acordo com o que for necessário (mudança de cor e/ou rotação) para manter as propriedades da árvore Rubro Negra.
 * @param nó a ser verificado.
 **/
void RubroNegra::rb_fixup(Folha *f) {
    while (f->pai->cor == 'v') {
        if (f->pai == f->pai->pai->folhaEsq) { //pai de f é filho esquerdo
            Folha *aux = f->pai->pai->folhaDir; //aux aponta pro tio de f
            if (aux->cor = 'v') { //caso 1: tio vermelho
                f->pai->cor = 'p'; //pai vira preto
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
                f->pai->cor = 'p'; //pai vira preto
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

/**
 * rot_esq - Rotaciona a árvore / subárvore para a esquerda.
 * @param raiz da árvore / subárvore.
 **/
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

/**
 * rot_dir - Rotaciona a árvore / subárvore para a direita.
 * @param raiz da árvore / subárvore.
 **/
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

/**
 * busca - Invoca o métodos busca_recursiva passando como parâmetros o ponteiro para raiz da árvore e o número a ser procurado.
 * @param valor a ser procurado.
 **/
void RubroNegra::busca(int valor) {
    busca_recursiva(this->raiz, valor);
}

/**
 * busca_recursiva - Percorre a árvore recursivamente imprimindo seu caminho na procura por um determinado valor.
 * @param raiz da árvore / subárvore.
 * @param valor a ser procurado.
 **/
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

/**
 * imprime_arvore - Invoca o método imprime_pre_ordem.
 **/
void RubroNegra::imprime_arvore() {
    imprime_pre_ordem(this->raiz);
}

/**
 * imprime_pre_ordem - Percorre árvore recursivamente a partir do nó raiz imprimindo o caminho realizado.
 * @param raiz da árvore / subárvore.
 **/
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

/**
 * desaloca_arvore - Percorre a árvore recursivamente a partir do nó raiz desalocando todoas as instâncias da classe Folha, menos o objeto nil.
 * @param raiz da árvore / subárvore.
 **/
void RubroNegra::desaloca_arvore(Folha *f) {
    if (!f->ehNil) {
        desaloca_arvore(f->folhaEsq);
        desaloca_arvore(f->folhaDir);
    }
    if (!f->ehNil) delete f;
}

/**
 * ~RubroNegra - Destrutor. Desaloca todos as instâncias da classe Folha através do método desaloca_arvore. Também desaloca o objeto nil.
 **/
RubroNegra::~RubroNegra() {
    desaloca_arvore(this->raiz);
    delete nil;
}