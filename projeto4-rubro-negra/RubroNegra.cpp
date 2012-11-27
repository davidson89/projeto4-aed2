#include <stddef.h>
#include <iostream>
#include "RubroNegra.h"

using namespace std;

/**
 * Construtor. Faz o ponteiro para a raiz da árvore apontar para nulo e cria a primeira instância da classe Folha, o objeto nil.
 **/
RubroNegra::RubroNegra() {
    this->raiz = NULL;
    this->nil = new Folha();
}

/**
 * Caso a árvore não possua nenhum nó um nó é criado fazendo com que o ponteiro raiz aponte para esse nó. Caso a árvore já possua um nó o método insere_recursivo é invocado.
 * @param valor a ser inserido.
 **/
void RubroNegra::insere(int valor) {
    if (this->raiz == NULL) {
        this->raiz = new Folha(valor, this->nil, this->nil);
        this->raiz->cor = 'p';
    } else insere_recursivo(this->raiz, valor);
}

/**
 * Percorre a árvore recursivamente procurando o local onde o novo nó deve ser inserido. Após inserir invoca o método rb_fixup.
 * @param nó raiz da árvore / subárvore.
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
 * Reestrutura a árvore de acordo com o que for necessário (mudança de cor e/ou rotação) para manter as propriedades da árvore Rubro Negra.
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
                f = f->pai->pai; //continuando o processo a partir do avô
            } else {
                if (f == f->pai->folhaDir) { //caso 2: f é filho direito
                    f = f->pai;
                    rot_esq(f); //rotaciona à esquerda no pai de f
                }
                f->pai->cor = 'p'; //caso 3: f é filho esquerdo
                f->pai->pai->cor = 'v'; //avô vira vermelho
                rot_dir(f->pai->pai); //rotaciona à direita no avô de f
            }
        } else { //pai de f é filho direito
            Folha *aux = f->pai->pai->folhaEsq; //aux aponta pro tio de f
            if (aux->cor = 'v') { //caso 1: tio vermelho
                f->pai->cor = 'p'; //pai vira preto
                aux->cor = 'p'; //tio vermelho vira preto
                f->pai->pai->cor = 'v'; //avô vira vermelho
                f = f->pai->pai; //continuando o processo a partir do avô
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
 * Rotaciona a árvore / subárvore para a esquerda.
 * @param nó raiz da árvore / subárvore.
 **/
void RubroNegra::rot_esq(Folha *f) {
    Folha *aux = f->folhaDir;
    f->folhaDir = aux->folhaEsq;
    if (aux->folhaEsq != this->nil) {
        aux->pai->folhaEsq = f;
    }
    aux->pai = f->pai;
    if (f->pai == this->nil) {
        this->raiz = aux;
    } else {
        if (f == f->pai->folhaEsq) f->pai->folhaEsq = aux;
        else f->pai->folhaDir = aux;
    }
    aux->folhaEsq = f;
    f->pai = aux;
}

/**
 * Rotaciona a árvore / subárvore para a direita.
 * @param nó raiz da árvore / subárvore.
 **/
void RubroNegra::rot_dir(Folha *f) {
    Folha *aux = f->folhaEsq;
    f->folhaEsq = aux->folhaDir;
    if (aux->folhaDir != this->nil) {
        aux->pai->folhaDir = f;
    }
    aux->pai = f->pai;
    if (f->pai == this->nil) {
        this->raiz = aux;
    } else {
        if (f == f->pai->folhaDir) f->pai->folhaDir = aux;
        else f->pai->folhaDir = aux;
    }
    aux->folhaDir = f;
    f->pai = aux;
}

/**
 * Invoca o métodos busca_recursiva passando como parâmetros o ponteiro para raiz da árvore e o número a ser procurado.
 * @param valor a ser procurado.
 **/
void RubroNegra::busca(int valor) {
    busca_recursiva(this->raiz, valor);
}

/**
 * Percorre a árvore recursivamente imprimindo seu caminho na procura por um determinado valor.
 * @param nó raiz da árvore / subárvore.
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
 * Invoca o método imprime_pre_ordem.
 **/
void RubroNegra::imprime_arvore() {
    imprime_pre_ordem(this->raiz);
}

/**
 * Percorre árvore recursivamente a partir do nó raiz imprimindo o caminho realizado.
 * @param nó raiz da árvore / subárvore.
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
 * Percorre a árvore recursivamente a partir do nó raiz desalocando todoas as instâncias da classe Folha, menos o objeto nil.
 * @param nó raiz da árvore / subárvore.
 **/
void RubroNegra::desaloca_arvore(Folha *f) {
    if (!f->ehNil) {
        desaloca_arvore(f->folhaEsq);
        desaloca_arvore(f->folhaDir);
        delete f;
    }
}

/**
 * Destrutor. Desaloca todos as instâncias da classe Folha através do método desaloca_arvore. Também desaloca o objeto nil.
 **/
RubroNegra::~RubroNegra() {
    desaloca_arvore(this->raiz);
    delete nil;
}