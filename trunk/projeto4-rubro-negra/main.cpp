#include <iostream>
#include <stdio.h>
#include "RubroNegra.h"

using namespace std;

int main(int argc, char** argv) {
    char *filename = argv[1];
    FILE *arq = fopen(filename, "r");
    if (arq == NULL) {
        cout << "Nao foi possivel abrir o arquivo de entrada." << endl;
        return 0;
    }
    RubroNegra *arvore = new RubroNegra();
    char comando;
    int valor = 0;
    while (!feof(arq)) {
        fscanf(arq, "%s", &comando);
        fscanf(arq, "%d", &valor);
        if (comando == 'i') {
            cout << "> " << comando << " " << valor << endl;
            arvore->insere(valor);
            arvore->imprimeArvore();
            cout << endl;
        }
        if (comando == 'b') {
            cout << "> " << comando << " " << valor << endl;
            arvore->busca(valor);
            cout << endl;
        }
    }
    fclose(arq);
    delete arvore;
    return 0;
}