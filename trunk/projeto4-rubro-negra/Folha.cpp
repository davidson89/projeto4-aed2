#include "stddef.h"
#include "Folha.h"

Folha::Folha(int valor) {
    this->valor = valor;
    this->cor = 'v';
    this->folhaDir = NULL;
    this->folhaEsq = NULL;
}