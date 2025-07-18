#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "velha.h"
#include "impressao.h"

JV v;

void pegajogada(){

    printf("\nfaca sua jogada: ");

    scanf("%d %d", &v.x, &v.y);

    v.x--; v.y--;

    if(v.velha[v.x][v.y] != ' '){

        printf("posicao invalida, tente novamente:\n");
        pegajogada();
    }
    else{
        
        v.jogadas++;
    }
}


void jogarnovamente(){

    char resposta;
    printf("voce quer jogar novamente?s/n\n");

    scanf(" %c", &resposta);

    if(resposta == 's'){
        iniciavelha(&v);
        v.jogadas = 0;
        imprimevelha(&v);
    }
    else exit(1);

}

int ganhou(){

    for(int i = 0; i < 3; i++){

        if(v.velha[i][0] != ' ' && v.velha[i][0] == v.velha[i][1] && v.velha[i][1] == v.velha[i][2]) return 1;

        if(v.velha[0][i] != ' ' && v.velha[0][i] == v.velha[1][i] && v.velha[1][i] == v.velha[2][i]) return 1;

        if(v.velha[1][1] != ' ' && v.velha[0][0] == v.velha[1][1] && v.velha[1][1] == v.velha[2][2]) return 1;

        if(v.velha[1][1] != ' ' && v.velha[0][2] == v.velha[1][1] && v.velha[1][1] == v.velha[2][0]) return 1;

    }

    return 0;
}
int empatou(){

    if(v.jogadas != 9){

        return 0;
    }
    else{

        return 1;
    }
}

int main(){

    iniciavelha(&v);
    imprimevelha(&v);
    int jogador = 0;

        do{

            alternaplayers(&v, jogador);
            if(empatou() || ganhou()){

                jogarnovamente();

            }

            jogador = jogador ^ 1;
        }while (1);
        
}