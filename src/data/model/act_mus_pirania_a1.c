#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

extern Vtx act_mus_pirania_a1_v[];
static u16 int_sum_pirania_pal[] ATTRIBUTE_ALIGN(32) = {
#include "assets/act_mus_pirania_a1/int_sum_pirania_pal.inc"
};

u8 act_mus_pirania_body_txt[] = {
#include "assets/act_mus_pirania_body_txt.inc"
};

Vtx act_mus_pirania_a1_v[] = {
#include "assets/act_mus_pirania_a1_v.inc"
};

Gfx act_mus_pirania_sakana_body_model[] = {
    gsSPMatrix(anime_6_mdl, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW),
    gsSPVertex(act_mus_pirania_a1_v, 6, 0),
    gsSPMatrix(&anime_6_mdl[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW),
    gsDPLoadTLUT_Dolphin(15, 16, 1, int_sum_pirania_pal),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 32, 32, act_mus_pirania_body_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsSPVertex(&act_mus_pirania_a1_v[6], 18, 6),
    gsSPNTrianglesInit_5b(11, 5, 7, 6, 0, 8, 2, 5, 9, 1),
    gsSPNTriangles_5b(5, 11, 10, 2, 13, 12, 3, 2, 14, 4, 15, 16),
    gsSPNTriangles_5b(4, 17, 18, 2, 20, 19, 3, 21, 22, 5, 4, 23),
    gsSPVertex(&act_mus_pirania_a1_v[24], 17, 0),
    gsSPNTrianglesInit_5b(15, 0, 1, 2, 0, 3, 4, 5, 6, 7),
    gsSPNTriangles_5b(8, 5, 9, 10, 5, 8, 0, 4, 1, 11, 3, 0),
    gsSPNTriangles_5b(8, 12, 13, 13, 10, 8, 11, 0, 2, 9, 5, 7),
    gsSPNTriangles_5b(14, 3, 11, 12, 8, 9, 7, 6, 15, 14, 16, 3),
    gsSPEndDisplayList(),
};

Gfx act_mus_pirania_sakana_head_model[] = {
    gsDPLoadTLUT_Dolphin(15, 16, 1, int_sum_pirania_pal),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 32, 32, act_mus_pirania_body_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsSPVertex(&act_mus_pirania_a1_v[41], 15, 0),
    gsSPNTrianglesInit_5b(12, 0, 1, 2, 3, 4, 5, 3, 6, 4),
    gsSPNTriangles_5b(7, 8, 5, 9, 4, 10, 11, 12, 0, 13, 11, 2),
    gsSPNTriangles_5b(14, 11, 13, 2, 1, 13, 5, 4, 7, 2, 11, 0),
    gsSPNTriangles_5b(5, 8, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsSPEndDisplayList(),
};

cKF_Joint_R_c cKF_je_r_act_mus_pirania_a1_tbl[] = {
    { NULL, 1, cKF_JOINT_FLAG_DISP_OPA, { 57, 65499, 699 } },
    { act_mus_pirania_sakana_head_model, 1, cKF_JOINT_FLAG_DISP_OPA, { 0, 0, 0 } },
    { act_mus_pirania_sakana_body_model, 0, cKF_JOINT_FLAG_DISP_OPA, { 700, 0, 0 } }
};

cKF_Skeleton_R_c cKF_bs_r_act_mus_pirania_a1 = { ARRAY_COUNT(cKF_je_r_act_mus_pirania_a1_tbl), 2,
                                                 cKF_je_r_act_mus_pirania_a1_tbl };
