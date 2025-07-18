#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "impressao.h"
#include "velha.h"

void imprimevelha(JV* v){

    for(int i = 0; i < 3; i++){
    
        printf(" %c | %c | %c \n", v->velha[i][0], v->velha[i][1], v->velha[i][2]);
        if(i != 2) printf("---|---|---\n");
        
    }

}

void alternaplayers(JV* v, int jogador){

        if(jogador == 0){

            printf("jogador 1");
            pegajogada();
            v->velha[v->x][v->y] = 'X';
            imprimevelha(v);
        }
        if(jogador == 1){

            printf("jogador 2");
            pegajogada();
            v->velha[v->x][v->y] = 'O';
            imprimevelha(v);
        }
}

void iniciavelha(JV* v){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            v->velha[i][j] = ' ';
        }
    }
}
