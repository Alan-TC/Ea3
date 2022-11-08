#include "tPos.h"

struct tPos{
    int x;
    int y;
};

tPos_pt CriaPos(int x, int y) {
    tPos_pt p = malloc(sizeof(*p));

    p->x = x;
    p->y = y;

    return p;
}

void LiberaPos(tPos_pt* p) {
    if(*p != NULL){
        free(*p);
        *p = NULL;
    }
}

int RetornaX(tPos_pt p) {
    return p->x;
}

int RetornaY(tPos_pt p) {
    return p->y;
}