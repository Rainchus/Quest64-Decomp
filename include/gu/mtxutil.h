#ifndef _MTXUTIL_H_
#define _MTXUTIL_H_

void guMtxF2L(float mf[4][4], Mtx *m);
void guMtxL2F(float mf[4][4], Mtx *m);
void guMtxIdentF(float mf[4][4]);
void guMtxIdent(Mtx *m);

#endif
