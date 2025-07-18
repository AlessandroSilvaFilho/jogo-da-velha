
struct jvelha{

    char velha[3][3];
    int jogadas;
    int x, y;

};

typedef struct jvelha JV;

void imprimevelha(JV* v);
void alternaplayers(JV* v, int jogador);
void iniciavelha(JV* v);