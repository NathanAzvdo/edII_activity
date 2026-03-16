#include "Lista.h"
#include <iostream>

using namespace std;

void exibe_menu() {
    cout << "\n===============================" << endl;
    cout << "        MENU DA LISTA          " << endl;
    cout << "===============================" << endl;
    cout << "1.  Inserir no inicio" << endl;
    cout << "2.  Inserir no fim" << endl;
    cout << "3.  Retirar do inicio" << endl;
    cout << "4.  Retirar do fim" << endl;
    cout << "5.  Retirar valor especifico" << endl;
    cout << "6.  Buscar valor" << endl;
    cout << "7.  Imprimir inicio" << endl;
    cout << "8.  Imprimir fim" << endl;
    cout << "9.  Imprimir lista completa" << endl;
    cout << "10. Exibir tamanho da lista" << endl;
    cout << "11. Esvaziar lista" << endl;
    cout << "0.  Sair" << endl;
    cout << "Escolha uma opcao: ";
}

void processa_opcao(int opcao, Lista* l) {
    int valor;
    switch (opcao) {
        case 1:
            cout << "Digite o valor para inserir no inicio: ";
            cin >> valor;
            l->insere_inicio(valor);
            cout << "Inserido com sucesso!" << endl;
            break;
        case 2:
            cout << "Digite o valor para inserir no fim: ";
            cin >> valor;
            l->insere_fim(valor);
            cout << "Inserido com sucesso!" << endl;
            break;
        case 3:
            if (l->retira_inicio())
                cout << "Elemento removido do inicio com sucesso!" << endl;
            else
                cout << "Erro: Lista ja esta vazia!" << endl;
            break;
        case 4:
            if (l->retira_fim())
                cout << "Elemento removido do fim com sucesso!" << endl;
            else
                cout << "Erro: Lista ja esta vazia!" << endl;
            break;
        case 5:
            cout << "Digite o valor que deseja retirar: ";
            cin >> valor;
            if (l->retira(valor))
                cout << "Valor " << valor << " removido com sucesso!" << endl;
            else
                cout << "Valor nao encontrado na lista!" << endl;
            break;
        case 6:
            cout << "Digite o valor para buscar: ";
            cin >> valor;
            if (l->busca(valor))
                cout << "Dado encontrado!" << endl;
            else
                cout << "Dado nao encontrado!" << endl;
            break;
        case 7:
            l->imprime_inicio();
            break;
        case 8:
            l->imprime_fim();
            break;
        case 9:
            l->imprime();
            break;
        case 10:
            cout << "Tamanho da Lista: " << l->tamanho() << endl;
            break;
        case 11:
            l->libera();
            cout << "Lista liberada!" << endl;
            break;
        case 0:
            cout << "Encerrando o programa..." << endl;
            break;
        default:
            cout << "Opcao invalida! Tente novamente." << endl;
            break;
    }
}

void executar() {
    Lista* l = new Lista();
    int opcao = -1;
    
    while (opcao != 0) {
        exibe_menu();
        cin >> opcao;
        processa_opcao(opcao, l);
    }
    
    l->~Lista();
}

int main(int argc, char** argv) {
    executar();
    return 0;
}