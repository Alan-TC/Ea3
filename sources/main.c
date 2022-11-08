//alessandro.baldi@edu.ufes.br (nome.sobrenome)

#include "mapa.h"
#include "tPos_arr.h"

int main(int argc, char** argv) {
    int i = 0, x = 0, y = 0;
    tMapa_pt mapa = CriaUmMapaVazio(10, 10);
    tPos_arrPt posicoes = LeDoArquivoBinario(argv[1]);

    for(i = 0; i < RetTamPosArr(posicoes); i++) {
        AdicionaNavio(mapa, RetornaX(RetTpos(posicoes, i)) - 1, RetornaY(RetTpos(posicoes, i)) - 1);
    }
    ImprimeMapa(mapa);

    while(RetQtdNavios(mapa)) {
        scanf("%d %d", &x, &y);
        MataNavio(mapa, x-1, y-1);
        ImprimeMapa(mapa);
        printf("\n\n");
    }

    return 0;
}