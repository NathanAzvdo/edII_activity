#include "Lista.h"

Lista::Lista() {
    cabeca = 0;
    ultimo = 0;
    qtd = 0;
}

Lista::~Lista() {
    libera();
}

void Lista::insere_inicio(int i) {
    no_dado* novo = new no_dado(i, cabeca);
    cabeca = novo;
    
    if (qtd == 0) {
        ultimo = novo;
    }
    qtd++;
}

void Lista::insere_fim(int i) {
    no_dado* novo = new no_dado(i, 0);
    
    if (vazia()) {
        cabeca = novo;
        ultimo = novo;
    } else {
        ultimo->prox = novo;
        ultimo = novo;
    }
    qtd++;
}

void Lista::imprime() {
    if (!isEmpty(cabeca)) {
        cout << "Info: ";
        for (no_dado* p = cabeca; p != NULL; p = p->prox) {
            cout << p->info << " - ";
        }
        cout << endl;
    } else {
        cout << "Lista vazia!" << endl;
    }
}

void Lista::imprime_inicio() {
    if (!vazia()) {
        cout << "Inicio: " << cabeca->info << endl;
    } else {
        cout << "Lista vazia!" << endl;
    }
}

void Lista::imprime_fim() {
    if (!vazia()) {
        cout << "Fim: " << ultimo->info << endl;
    } else {
        cout << "Lista vazia!" << endl;
    }
}

bool Lista::vazia() {
    return isEmpty(cabeca);
}

bool Lista::busca(int i) {
    for (no_dado* p = cabeca; p != NULL; p = p->prox) {
        if (p->info == i) {
            return true;
        }
    }
    return false;
}

bool Lista::retira(int i) {
    no_dado* ant = NULL;
    no_dado* p = cabeca;
    
    while (p != NULL && p->info != i) {
        ant = p;
        p = p->prox;
    }
    
    if (p == NULL) {
        return false;
    }
    
    if (ant == NULL) {
        cabeca = p->prox;
    } else {
        ant->prox = p->prox;
    }
    
    if (p == ultimo) {
        ultimo = ant;
    }
    if (cabeca == NULL) {
        ultimo = NULL;
    }
    
    free(p);
    qtd--;
    return true;
}

bool Lista::retira_inicio() {
    if (vazia()) {
        return false;
    }
    
    no_dado* p = cabeca;
    cabeca = p->prox;
    
    if (cabeca == NULL) {
        ultimo = NULL;
    }
    
    free(p);
    qtd--;
    return true;
}

bool Lista::retira_fim() {
    if (vazia()) {
        return false;
    }
    
    if (cabeca == ultimo) {
        free(cabeca);
        cabeca = NULL;
        ultimo = NULL;
    } else {
        no_dado* p = cabeca;
        while (p->prox != ultimo) {
            p = p->prox;
        }
        free(ultimo);
        ultimo = p;
        ultimo->prox = NULL;
    }
    
    qtd--;
    return true;
}

int Lista::tamanho() {
    return qtd;
}

void Lista::libera() {
    no_dado* p = cabeca;
    while (p != NULL) {
        no_dado* t = p->prox;
        free(p);
        p = t;
    }
    cabeca = 0;
    ultimo = 0;
    qtd = 0;
}

bool Lista::isEmpty(no_dado* l) {
    return l == 0;
}