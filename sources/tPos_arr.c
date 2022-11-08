#include "tPos_arr.h"

struct tPos_arr{
    int tamArr;
    int qtdPos;
    tPos_pt* pts;
};

tPos_arrPt InicializaPosArr() {
    tPos_arrPt pts = malloc(sizeof(*pts));

    pts->tamArr = 2;
    pts->pts = malloc(sizeof(*pts->pts)*pts->tamArr);

    pts->qtdPos = 0;

    return pts;
}

void AdicionaPonto(tPos_arrPt posArr, tPos_pt pos) {
    if(posArr->qtdPos >= posArr->tamArr){
        posArr->tamArr = posArr->tamArr*2;
        posArr->pts = realloc(posArr->pts, sizeof(*posArr->pts)*posArr->tamArr);
    }

    posArr->pts[posArr->qtdPos] = pos;
    posArr->qtdPos++;
}

void LiberaPosArr(tPos_arrPt* posArr) {
    int i = 0;
    if(*posArr != NULL) {
        for(i = 0; i < (*posArr)->qtdPos; i++) {
            LiberaPos(&(*posArr)->pts[i]);
        }
        free((*posArr)->pts);
        (*posArr)->pts = NULL;

        free(*posArr);
        *posArr = NULL;
    }
}

tPos_pt RetTpos(tPos_arrPt posArr, int idx) {
    return posArr->pts[idx];
}

int RetTamPosArr(tPos_arrPt posArr) {
    return posArr->qtdPos;
}

tPos_arrPt LeDoArquivoBinario(char* caminho){
    FILE * f = fopen(caminho, "rb");

    if(f == NULL){
        printf("Erro de abertura: %s\n", caminho);
        exit(1);
    }
    tPos_arrPt posArr = InicializaPosArr();
    tPos_pt pos = NULL;
    int x = 0, y = 0;

    while(!feof(f)){
        fread(&x, sizeof(int), 1, f);
        fread(&y, sizeof(int), 1, f);

        pos = CriaPos(x, y);
        AdicionaPonto(posArr, pos);
    }
    fclose(f);

    return posArr;
}