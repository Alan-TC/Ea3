#ifndef _MAPA_H_
#define _MAPA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct tMapa tMapa;
typedef tMapa* tMapa_pt;

tMapa_pt CriaUmMapaVazio(int qtdLinha, int qtdColunas);

void LiberaMapa(tMapa_pt* mapa);

void AdicionaNavio(tMapa_pt mapa, int linha, int coluna);

int RetQtdNavios(tMapa_pt mapa);

void MataNavio(tMapa_pt mapa, int linha, int coluna);

void ImprimeMapa(tMapa_pt mapa);

#endif