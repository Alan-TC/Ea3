#include  "mapa.h"

struct tMapa{
    int qtdLinha;
    int qtdColuna;
    int qtdNavios;
    char** mapa;
};

tMapa_pt CriaUmMapaVazio(int qtdLinha, int qtdColunas) {
    tMapa_pt map = (tMapa_pt)malloc(sizeof(*map));
    int i = 0, j = 0;

    map->qtdLinha = qtdLinha;
    map->qtdColuna = qtdColunas;

    map->mapa = (char**)malloc(sizeof(char*)*map->qtdLinha);

    map->qtdNavios = 0;

    for(i = 0; i < map->qtdLinha; i++)
        map->mapa[i] = (char*)malloc(sizeof(char)*map->qtdColuna);

    for(i = 0; i < map->qtdLinha; i++){
        for(j = 0; j < map->qtdColuna; j++) {
            map->mapa[i][j] = '-';
        }
    }

    return map;
}


void LiberaMapa(tMapa_pt* mapa) {
    int i = 0;
    if(*mapa != NULL){
        for(i = 0; i < (*mapa)->qtdLinha; i++){
            free((*mapa)->mapa[i]);
            (*mapa)->mapa[i] = NULL;
        }
        free((*mapa)->mapa);
        (*mapa)->mapa = NULL;

        free(*mapa);
        *mapa = NULL; 
    }
}

void AdicionaNavio(tMapa_pt mapa, int linha, int coluna) {
   if(linha < mapa->qtdLinha){
    if(coluna < mapa->qtdColuna){
        if(mapa->mapa[linha][coluna] != 'o') {
            mapa->mapa[linha][coluna] = 'o';
            mapa->qtdNavios++;
            return;
        }
        return;
    }
   }
   printf("Linha ou coluna nao existem no mapa!\n");
}

int RetQtdNavios(tMapa_pt mapa) {
    return mapa->qtdNavios;
}

void MataNavio(tMapa_pt mapa, int linha, int coluna) {
    if(linha < mapa->qtdLinha){
        if(coluna < mapa->qtdColuna){
            if(mapa->mapa[linha][coluna] == 'o'){
                mapa->mapa[linha][coluna] = 'x';
                mapa->qtdNavios--;
                return;
            }
            return;
        }
   }
   printf("Linha ou coluna nao existem no mapa!\n");
}

void ImprimeMapa(tMapa_pt mapa){
    int i = 0, j = 0;

    for(i = 0; i < mapa->qtdLinha; i++){
        for(j = 0; j < mapa->qtdColuna; j++){
            printf("%c ", mapa->mapa[i][j]);
        }
        printf("\n");
    }
}