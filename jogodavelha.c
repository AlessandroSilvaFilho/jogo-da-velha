#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "velha.h"

int velha [3][3];
int jogadas;
int x, y;
int jogadorx = 1;
int jogadory = 2;

void jogarnovamente(){

    char resposta;
    printf("voce quer jogar novamente?s/n\n");

    scanf(" %c", &resposta);

    if(resposta == 's'){
        iniciavelha();
        jogadas = 0;
    }
    else exit(1);

}

int ganhou(){

    for(int i = 0; i < 3; i++){

        if(velha[i][0] != ' ' && velha[i][0] == velha[i][1] && velha[i][1] == velha[i][2]) return 1;

        if(velha[0][i] != ' ' && velha[0][i] == velha[1][i] && velha[1][i] == velha[2][i]) return 1;

        if(velha[1][1] != ' ' && velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2]) return 1;

        if(velha[1][1] != ' ' && velha[0][2] == velha[1][1] && velha[1][1] == velha[2][0]) return 1;

        else{
    
            return 0;
        }
    }
}
int empatou(){

    if(jogadas != 9){

        return 0;
    }
    else{

        return 1;
    }
}

void alternaplayers(){

        printf("jogador %d", jogadorx);
        pegajogada();
        velha[x][y] = 'X';
        imprimevelha();
        if(!empatou() && !ganhou()){

            printf("jogador %d", jogadory);
            pegajogada();
            velha[x][y] = 'O';
            imprimevelha();
        }
}

void iniciavelha(){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            velha[i][j] = ' ';
        }
    }
}
void imprimevelha(){

    for(int i = 0; i < 3; i++){
    
        printf(" %c | %c | %c \n", velha[i][0], velha[i][1], velha[i][2]);
        if(i != 2) printf("---|---|---\n");
        
    }

}
void pegajogada(){

    printf("\nfaca sua jogada: ");

    scanf("%d %d", &x, &y);

    x--; y--;

    if(velha[x][y] != ' '){

        printf("posicao invalida, tente novamente:\n");
        pegajogada();
    }
    else{
        
        jogadas++;
    }
}

int main(){

    iniciavelha();

        do{

            alternaplayers();
            if(empatou() || ganhou()){

                jogarnovamente();

            }

        }while (1);
        
}