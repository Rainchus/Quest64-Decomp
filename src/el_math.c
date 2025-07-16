#include "common.h"
#include "el_math.h"

u32 RNG(u32 MAX) {
	if (MAX != 0) {
		return (((rand_seed = (rand_seed * 0x41C64E6D) + 0x3039) >> 0x10)) % MAX;
	}
	return 0;
}

f32 fast_arctan_radians(f32 x) {
    f32 conv = 0.0f;
    s32 sector;
    s32 i;
    
    if (x > 1.0f) {
        sector = 1;
        x = 1.0f / x;
    } else if (x < -1.0f) {
        sector = -1;
        x = 1.0f / x;
    } else {
        sector = 0;
    }

    for (i = 12; i > 0; i--) {
        conv = ((SQ(i) * x * x) / (i * 2 + 1 + conv));
    }

    if (sector > 0) {
        return M_PI / 2 - (x / (1.0f + conv));
    } else if (sector < 0) {
        return - M_PI / 2 - (x / (1.0f + conv));
    } else {
        return x / (1.0f + conv);
    }
}

void normalize2D(f32* x, f32* y) {
    f32 inverse_length;
   
    inverse_length = 1.0f / _nsqrtf((*x * *x) + (*y * *y));
    *x *= inverse_length;
    *y *= inverse_length;
}

f32 approx_atan2f(f32 arg0, f32 arg1) { //What direction (angle) is the point (x, y) relative to the center (0,0)
    f32 var_f2;
    
    if (arg1 == 0.0f) {
        var_f2 = arg0 >= 0.0f ? M_PI/2 : -M_PI/2;
    } else if (arg1 > 0.0f) {
        var_f2 = fast_arctan_radians(arg0 / arg1);
    } else if ((arg1 < 0.0f) && (arg0 <= 0.0f)) {
        var_f2 = fast_arctan_radians(arg0 / arg1) - M_PI;
    } else {
        var_f2 = fast_arctan_radians(arg0 / arg1) + M_PI;

    }
    return var_f2;
}

void rotateCoordinatesByAngle(f32 angle, Coordinates2D* coordinates) { //@BUG? Instead of simply rotating the coordinates, 
    f32 sinAngle;                                                      //this funciton also mirrors the coordinates. This is non-standard
    f32 cosAngle;
    f32 xcoord;

    sinAngle = sinf(angle);
    cosAngle = cosf(angle);
    xcoord = coordinates->x;
    coordinates->x = (coordinates->y * sinAngle) - (xcoord * cosAngle);
    coordinates->y = (coordinates->y * cosAngle) + (xcoord * sinAngle);
}

void Matrix_RotateScaleTranslate(MtxF *m, f32 roll, f32 pitch, f32 yaw, f32 scale, f32 transX, f32 transY, f32 transZ) {
	f32 sRoll;    
	f32 sPitch;
	f32 sYaw;
	f32 cRoll;    
	f32 cPitch;    
	f32 cYaw;

	sRoll = sinf(roll);
	cRoll = cosf(roll);
	sPitch = sinf(pitch);
	cPitch = cosf(pitch);
	sYaw = sinf(yaw);
	cYaw = cosf(yaw);

	m->mf[0][0] = (f32) (((cYaw * cPitch) + ((sYaw * sRoll) * sPitch)) * scale);
	m->mf[0][1] = (f32) ((sYaw * cRoll) * scale);
	m->mf[0][2] = (f32) ((((-sPitch) * cYaw) + ((sYaw * sRoll) * cPitch)) * scale);
	m->mf[0][3] = 0.0f;
	m->mf[1][0] = (f32) ((((-sYaw) * cPitch) + ((cYaw * sRoll) * sPitch)) * scale);
	m->mf[1][1] = (f32) ((cYaw * cRoll) * scale);
	m->mf[1][2] = (f32) ((((-sYaw) * (-sPitch)) + ((cYaw * sRoll) * cPitch)) * scale);
	m->mf[1][3] = 0.0f;
	m->mf[2][0] = (f32) ((cRoll * sPitch) * scale);
	m->mf[2][1] = (f32) ((-sRoll) * scale);
	m->mf[2][2] = (f32) ((cRoll * cPitch) * scale);
	m->mf[2][3] = 0.0f;
	m->mf[3][0] = transX;
	m->mf[3][1] = transY;
	m->mf[3][2] = transZ;
	m->mf[3][3] = 1.0f; 
}

void func_80023500(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    Matrix_RotateScaleTranslate(&D_8008D030, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    guMtxF2L((f32 (*)[4]) &D_8008D030, arg0);
}

void Matrix_RotateZYX(MtxF *m, f32 roll, f32 pitch, f32 yaw) {
    f32 sRoll;
    f32 sPitch;
    f32 sYaw;
    f32 cRoll;
    f32 cPitch;
    f32 cYaw;
  
    sRoll = sinf(roll);
    cRoll = cosf(roll);
    sPitch = sinf(pitch);
    cPitch = cosf(pitch);
    sYaw = sinf(yaw);
    cYaw = cosf(yaw);

    m->mf[0][0] = (cYaw * cPitch) + (sYaw * sRoll * sPitch);
    m->mf[0][1] = sYaw * cRoll;
    m->mf[0][2] = (-sPitch * cYaw) + (sYaw * sRoll * cPitch);
    m->mf[0][3] = 0.0f;

    m->mf[1][0] = (-sYaw * cPitch) + (cYaw * sRoll * sPitch);
    m->mf[1][1] = cYaw * cRoll;
    m->mf[1][2] = (-sYaw * -sPitch) + (cYaw * sRoll * cPitch);
    m->mf[1][3] = 0.0f;

    m->mf[2][0] = cRoll * sPitch;
    m->mf[2][1] = -sRoll;
    m->mf[2][2] = cRoll * cPitch;
    m->mf[2][3] = 0.0f;

    m->mf[3][0] = 0.0f;
    m->mf[3][1] = 0.0f;
    m->mf[3][2] = 0.0f;
    m->mf[3][3] = 1.0f;
}

void func_800236CC(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3) {
    Matrix_RotateZYX(&D_8008D030, arg1, arg2, arg3);
    guMtxF2L((f32 (*)[4]) &D_8008D030, arg0);
}

void Matrix_LookAtXZ(MtxF *m, f32 fromX, f32 fromY, f32 fromZ, f32 toX, f32 toY, f32 toZ) {
  
	f32 len3D;
	f32 deltaZ;
	f32 deltaY2;
	f32 lenXZ;
	f32 deltaX;
	f32 upScale;
	f32 forwardX;
	f32 forwardZ;
	f32 rightScale;

	deltaX = toX - fromX;
	deltaZ = toZ - fromZ;
	lenXZ = _nsqrtf((deltaX * deltaX) + (deltaZ * deltaZ));
	if (lenXZ == 0.0f) {
		forwardX = 0.0f;
		forwardZ = 1.0f;
	} else {
		forwardX = deltaX / lenXZ;
		forwardZ = deltaZ / lenXZ;
	}

	deltaY2 = toY - fromY;
	len3D = _nsqrtf((lenXZ * lenXZ) + (deltaY2 * deltaY2));

	if (len3D == 0.0f) {
		rightScale = 0.0f;
		upScale = 1.0f;
	} else {
		rightScale = (-deltaY2) / len3D;
		upScale = lenXZ / len3D;
	}

	m->mf[0][0] = forwardZ;
	m->mf[0][1] = 0.0f;
	m->mf[0][2] = -forwardX;
	m->mf[0][3] = 0.0f;

	m->mf[1][0] = rightScale * forwardX;
	m->mf[1][1] = upScale;
	m->mf[1][2] = rightScale * forwardZ;
	m->mf[1][3] = 0.0f;

	m->mf[2][0] = upScale * forwardX;
	m->mf[2][1] = -rightScale;
	m->mf[2][2] = upScale * forwardZ;
	m->mf[2][3] = 0.0f;

	m->mf[3][0] = fromX;
	m->mf[3][1] = fromY;
	m->mf[3][2] = fromZ;
	m->mf[3][3] = 1.0f;
}

void func_8002387C(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    Matrix_LookAtXZ(&D_8008D030, arg1, arg2, arg3, arg4, arg5, arg6);
    guMtxF2L((f32 (*)[4]) &D_8008D030, arg0);
}

void func_800238E4(unk23df4s* arg0, f32 arg1, f32 arg2, f32 arg3, f32* arg4, f32* arg5, f32* arg6) {
    *arg4 = (arg0->unk8 * arg3) + ((arg0->unk0 * arg1) + (arg0->unk4 * arg2));
    *arg5 = (arg0->unk18 * arg3) + ((arg0->unk10 * arg1) + (arg0->unk14 * arg2));
    *arg6 = (arg0->unk28 * arg3) + ((arg0->unk20 * arg1) + (arg0->unk24 * arg2));
}

void func_80023974(unk23df4s* arg0, f32 arg1, f32 arg2, f32 arg3, f32* arg4, f32* arg5, f32* arg6) {
    *arg4 = (arg0->unk20 * arg3) + ((arg0->unk0 * arg1) + (arg0->unk10 * arg2));
    *arg5 = (arg0->unk24 * arg3) + ((arg0->unk4 * arg1) + (arg0->unk14 * arg2));
    *arg6 = -((arg0->unk28 * arg3) + ((arg0->unk8 * arg1) + (arg0->unk18 * arg2)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/el_math/func_80023A08.s")

void func_80023BCC(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3) {
    func_80023A08(&D_8008D030, arg1, arg2, arg3);
    guMtxF2L((f32 (*)[4]) &D_8008D030, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/el_math/func_80023C1C.s")

void Matrix_Scale(MtxF *mtx, f32 sx, f32 sy, f32 sz) {
	mtx->mf[0][0] *= sx;
	mtx->mf[0][1] *= sx;
	mtx->mf[0][2] *= sx;
	mtx->mf[1][0] *= sy;
	mtx->mf[1][1] *= sy;
	mtx->mf[1][2] *= sy;
	mtx->mf[2][0] *= sz;
	mtx->mf[2][1] *= sz;
	mtx->mf[2][2] *= sz;
}

void Matrix_Multiply(MtxF *a, MtxF *b, MtxF *dest) {

	f32 a00 = a->mf[0][0];
	f32 a01 = a->mf[0][1];
	f32 a02 = a->mf[0][2];

	f32 a10 = a->mf[1][0];
	f32 a11 = a->mf[1][1];
	f32 a12 = a->mf[1][2];

	f32 a20 = a->mf[2][0];
	f32 a21 = a->mf[2][1];
	f32 a22 = a->mf[2][2];

	f32 a30 = a->mf[3][0];
	f32 a31 = a->mf[3][1];
	f32 a32 = a->mf[3][2];

	f32 b00 = b->mf[0][0];
	f32 b01 = b->mf[0][1];
	f32 b02 = b->mf[0][2];

	f32 b10 = b->mf[1][0];
	f32 b11 = b->mf[1][1];
	f32 b12 = b->mf[1][2];

	f32 b20 = b->mf[2][0];
	f32 b21 = b->mf[2][1];
	f32 b22 = b->mf[2][2];

	f32 b30 = b->mf[3][0];
	f32 b31 = b->mf[3][1];
	f32 b32 = b->mf[3][2];

	dest->mf[0][0] = ((a00 * b00) + (a10 * b01)) + (a20 * b02);
	dest->mf[1][0] = ((a00 * b10) + (a10 * b11)) + (a20 * b12);
	dest->mf[2][0] = ((a00 * b20) + (a10 * b21)) + (a20 * b22);
	dest->mf[3][0] = (((a00 * b30) + (a10 * b31)) + (a20 * b32)) + a30;

	dest->mf[0][1] = ((a01 * b00) + (a11 * b01)) + (a21 * b02);
	dest->mf[1][1] = ((a01 * b10) + (a11 * b11)) + (a21 * b12);
	dest->mf[2][1] = ((a01 * b20) + (a11 * b21)) + (a21 * b22);
	dest->mf[3][1] = (((a01 * b30) + (a11 * b31)) + (a21 * b32)) + a31;

	dest->mf[0][2] = ((a02 * b00) + (a12 * b01)) + (a22 * b02);
	dest->mf[1][2] = ((a02 * b10) + (a12 * b11)) + (a22 * b12);
	dest->mf[2][2] = ((a02 * b20) + (a12 * b21)) + (a22 * b22);
	dest->mf[3][2] = (((a02 * b30) + (a12 * b31)) + (a22 * b32)) + a32;

	dest->mf[0][3] = 0.0f; 
	dest->mf[1][3] = 0.0f;
	dest->mf[2][3] = 0.0f;
	dest->mf[3][3] = 1.f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/el_math/func_8002413C.s")
