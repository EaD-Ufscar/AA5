//
//  main.cpp
//  AA5.1
//
//  Created by EliSor on 27/02/14.
//  Copyright (c) 2014 EliSor. All rights reserved.
//
/*
 Imagine uma fila de pessoas sentadas, onde não há a necessidade de ficar em pé um atrás do outro aguardando sua vez. Cada um tem uma senha (como nos bancos, atualmente) que indica sua posição na fila. A senha pode ser numérica ou alfa-numérica (você escolhe).
 Os funcionários dos bancos atendem o cliente apertando um botãozinho que apresenta em um display o número da senha do próximo cliente. Os números não precisam estar ordenados sequencialmente. A senha 1 já pode ter sido utilizada por alguém e agora será reutilizada. Assim, o que importa é a posição na fila. É atendido sempre cliente que está na primeira posição. Todos os outros clientes sobem uma posição quando o primeiro deixa a fila (o segundo vira primeiro, o terceiro vira segundo e assim por diante).
 Como cada banco tem um determinado número de cadeiras (tamanho da fila), você deverá implementar um sistema de fila (pense nos métodos da classe fila) que se adeque ao banco (tenha o tamanho que o banco deseje).
 Para isso, implemente a fila com alocação dinâmica de memória.
 */

//New alocar memoria
//Delete liberar memoria

#include <iostream>

using namespace std;

class FILA {
    
public:
    FILA();
    FILA(int quant);
    ~FILA();
    bool insere(int valor);
    int retira(void);
    void imprime(void);
    
private:
    int *elementos;
    int tamMax, tamAtual;
};

FILA::FILA() {
    elementos = new int[10];
    if (elementos != NULL) {
        tamMax = 10;
        tamAtual = 0;
    }
}

FILA::FILA(int quant){
    if (quant > 0) {
        elementos = new int[quant];
        if (elementos != NULL) {
            tamMax = quant;
            tamAtual = 0;
        } else {
            cout << "Erro ao alocar" << endl;
        }
    } else {
        cout << "Valor informado incorreto ou negativo!" << endl;
    }
}

FILA::~FILA(){
    delete [] elementos;
    elementos = 0;
}

bool FILA::insere(int valor){
    if (tamAtual < tamMax && valor > 0) {
        elementos[tamAtual++] = valor;
        return true;
    } else {
        return false;
    }
}

int FILA::retira(void){
    int i, valor;
    if (tamAtual > 0) {
        valor = elementos[0];
        for (i=0; i<tamAtual; i++)
            elementos[i] = elementos[i+1];
        tamAtual--;
        return valor;
    }
    else {
        return 0;
    }
}

void FILA::imprime(void){
    int i;
    for (i=0; i<tamAtual; i++) {
        cout << elementos[i] << " " << endl;;
    }
}

int main()
{
    int num, proximo, tamFila;
    char opcao;
    
    cout << "Qual o tamanho necessário para a fila: "<< endl;
    cin >> tamFila;
    
    FILA banco(tamFila);
    {
        FILA estadio_futebol;
    }
    
    do {
        cout << "i. inserir um elemento na fila" << endl;
        cout << "r. retirar um elemento da fila" << endl;
        cout << "p. imprimir a fila" << endl;
        cout << "s. sair" << endl;
        cout << "Entre com uma das opções do menu!" << endl;
        cin >> opcao;
        
        if (opcao == 'i') {
            cout << "Entre com um número";
            cin >> num;
            if (banco.insere(num))
                cout << "Foi inserido!" << endl;
            else
                cout << "Problema ao inserir" << endl;
        }
        
        if (opcao == 'p')
            banco.imprime();
        
        if (opcao == 'r') {
            proximo = banco.retira();
            if (proximo != 0)
                cout << "Agora é a vez do num. " << proximo << endl;
            else
                cout << "Não tem ninguem na fila!" << endl;
        }
    } while (opcao != 's');
    return 0;
}


