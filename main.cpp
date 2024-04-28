#include <iostream>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "jogo_da_velha.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    char tabela[TAM] = {'1','2','3','4','5','6','7','8','9'};
    string jogador1, jogador2;
    int posicao, jogador_vez=1, jogadas = 0;

    cout<< "Digite o nome do Jogador 1: ";
    cin>>jogador1; 
    cout<< "Digite o nome do Jogador 2: ";
    cin>>jogador2; 
    system("cls");

    bool vitoria = verifica_vitoria(tabela, jogadas);

    do{
        cout<< "Jogador 1: " << jogador1 << endl << "Jogador 2: " << jogador2 << endl << endl;
        imprimir_tabela(tabela);
        posicao = escolher_posicao(jogador_vez);
        switch(verifica_posicao(posicao, tabela)){
            case 0:
                cout<< "Posição ja escolhida, escolha novemente!";
                posicao = escolher_posicao(jogador_vez);
                break;
            case 1:
                jogadas++;
                atualiza_tabela(tabela, posicao, jogador_vez);
                verifica_empate(jogadas, tabela);
                jogador_vez = (jogador_vez == 1) ? 2 : 1;
                vitoria = verifica_vitoria(tabela, jogadas);
                system("cls");
                break;
            case -1:
                cout<< "Posição inválida, tente novamente: ";
                posicao = escolher_posicao(jogador_vez);
                break;
        };
    }while(!vitoria);

    system("cls");
    imprimir_tabela(tabela);

    if(jogador_vez == 2)
        cout<< "\n\nParabéns " << jogador1 << " você ganhou a partida!";
    else
        cout<< "\n\nParabéns " << jogador2 << " você ganhou a partida!";    

    return 0;
}
