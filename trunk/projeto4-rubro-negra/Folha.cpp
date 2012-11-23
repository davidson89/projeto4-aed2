#include "stddef.h"
#include "Folha.h"

Folha::Folha() {
    this->cor = 'p';
    this->ehNil = true;
}

Folha::Folha(int valor, Folha *nil) {
    this->valor = valor;
    this->cor = 'v';
    this->ehNil = false;
    this->folhaEsq = nil;
    this->folhaDir = nil;
}