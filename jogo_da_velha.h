#define _jogo_da_velha_

using namespace std;

#define TAM 9

void inicializa_tabela(char tabela[TAM]){
    for(int i = 0; i<TAM; i++){
        tabela[i] = i + '1';
    }
}

void imprimir_tabela(char tabela[TAM]){
    cout << " " << tabela[0] << " | " << tabela[1] << " | " << tabela[2] << "\n";
    cout<< "---+---+---\n";
    cout<< " " << tabela[3] << " | " << tabela[4] << " | " << tabela[5] << "\n";
    cout<< "---+---+---\n";
    cout<< " " << tabela[6] << " | " << tabela[7] << " | " << tabela[8] << "\n";
}

int verifica_posicao(int posicao, char tabela[TAM]){
    if(posicao > 9 || posicao < 1)
        return -1;    
    if((tabela[posicao-1]) == 'X' || tabela[posicao-1] == 'O')
        return 0;
    else 
        return 1;
}

void atualiza_tabela(char tabela[TAM], int posicao, int jogador_vez){
    tabela[posicao - 1] = (jogador_vez == 1) ? 'X' : 'O';
}

bool verifica_vitoria(char tabela[TAM], int jogadas){
    for(int i = 0; i < 9; i += 3){
        if(tabela[i] == tabela[i+1] && tabela[i+1] == tabela[i+2] && (tabela[i] == 'X' || tabela[i] == 'O'))
            return true;
    }

    for(int i = 0; i < 3; i++){
        if(tabela[i] == tabela[i+3] && tabela[i+3] == tabela[i+6] && (tabela[i] == 'X' || tabela[i] == 'O'))
            return true;
    }

    if((tabela[0] == tabela[4] && tabela[4] == tabela[8] && (tabela[0] == 'X' || tabela[0] == 'O')) ||
       (tabela[2] == tabela[4] && tabela[4] == tabela[6] && (tabela[2] == 'X' || tabela[2] == 'O')))
        return true;

    return false;

}

void verifica_empate(int jogadas, char tabela[TAM]){
    if(jogadas == TAM){
        system("cls");
        cout<< "DEU VELHA!\n\n\n";
        imprimir_tabela(tabela);
        exit(0);
    }
}

int escolher_posicao(int jogador_vez){
    int posicao;
    cout<< "\n\nJogador " << jogador_vez << " escolha sua posição: ";
    cin>>posicao;

    return posicao;
}