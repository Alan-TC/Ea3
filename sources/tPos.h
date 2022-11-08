#ifndef _TPOS_H_
#define _TPOS_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct tPos tPos;
typedef tPos* tPos_pt;

tPos_pt CriaPos(int x, int y);

void LiberaPos(tPos_pt* p);

int RetornaX(tPos_pt p);

int RetornaY(tPos_pt p);

#endif