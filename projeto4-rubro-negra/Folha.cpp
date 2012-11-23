#include "stddef.h"
#include "Folha.h"

Folha::Folha() {
    this->cor = 'p';
    this->ehNil = true;
}

Folha::Folha(int valor, Folha *pai, Folha *nil) {
    this->valor = valor;
    this->cor = 'v';
    this->ehNil = false;
    this->pai = pai;
    this->folhaEsq = nil;
    this->folhaDir = nil;
}