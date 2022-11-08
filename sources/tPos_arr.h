#ifndef _TPOS_ARR_H_
#define _TPOS_ARR_H_

#include "tPos.h"

typedef struct tPos_arr tPos_arr;
typedef tPos_arr* tPos_arrPt;


tPos_arrPt InicializaPosArr();

void AdicionaPonto(tPos_arrPt posArr, tPos_pt pos);

void LiberaPosArr(tPos_arrPt* posArr);

tPos_pt RetTpos(tPos_arrPt posArr, int idx);

int RetTamPosArr(tPos_arrPt posArr);

tPos_arrPt LeDoArquivoBinario(char* caminho);

#endif