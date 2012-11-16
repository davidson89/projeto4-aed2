#include <stddef.h>
#include "Folha.h"

Folha::Folha(int valor) {
    this->valor = valor;
    this->cor = 'v';
    this->folhaDir = NULL;
    this->folhaEsq = NULL;
}

Folha::setCor(Folha f, char c) {
    f.cor = c;
}

Folha::getCor(Folha f) {
    return f.cor;
}