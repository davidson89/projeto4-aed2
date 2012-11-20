#include <stddef.h>
#include "Folha.h"

Folha::Folha(int valor) {
    this->valor = valor;
    this->cor = 'v';
    this->folhaDir = NULL;
    this->folhaEsq = NULL;
}

void Folha::setCor(Folha *f, char c) {
    f->cor = c;
}

char Folha::getCor(Folha *f) {
    return f->cor;
}