#ifndef LISTA_H
#define LISTA_H

#include "no_dado.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

class Lista {
private:
    no_dado* cabeca;
    no_dado* ultimo;
    int qtd;

    bool isEmpty(no_dado* l);

public:
    Lista();
    ~Lista();

    void insere_inicio(int i);
    void insere_fim(int i);
    
    void imprime();
    void imprime_inicio();
    void imprime_fim();
    
    bool vazia();
    bool busca(int i);
    bool retira(int i);
    
    bool retira_inicio();
    bool retira_fim();
    
    int tamanho();
    void libera();
};

#endif