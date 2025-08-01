#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

extern Vtx int_sum_hal_chest03_v[];
u16 int_sum_hal_chest03_pal[] ATTRIBUTE_ALIGN(32) = {
#include "assets/int_sum_hal_chest03_pal.inc"
};

u8 int_sum_hal_chest03_top_tex_txt[] = {
#include "assets/int_sum_hal_chest03_top_tex_txt.inc"
};

u8 int_sum_hal_chest03_hiki_tex_txt[] = {
#include "assets/int_sum_hal_chest03_hiki_tex_txt.inc"
};

u8 int_sum_hal_chest03_hikite_tex_txt[] = {
#include "assets/int_sum_hal_chest03_hikite_tex_txt.inc"
};

u8 int_sum_hal_chest03_kuki_tex_txt[] = {
#include "assets/int_sum_hal_chest03_kuki_tex_txt.inc"
};

u8 int_sum_hal_chest03_side_tex_txt[] = {
#include "assets/int_sum_hal_chest03_side_tex_txt.inc"
};

u8 int_sum_hal_chest03_front_tex_txt[] = {
#include "assets/int_sum_hal_chest03_front_tex_txt.inc"
};

Vtx int_sum_hal_chest03_v[] = {
#include "assets/int_sum_hal_chest03_v.inc"
};

Gfx int_sum_hal_chest03_door1_model[] = {
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, int_sum_hal_chest03_pal),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 32, 16, int_sum_hal_chest03_top_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_MIRROR, GX_MIRROR, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPVertex(int_sum_hal_chest03_v, 29, 0),
    gsSPNTrianglesInit_5b(2, 0, 1, 2, 0, 2, 3, 0, 0, 0),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPNTrianglesInit_5b(4, 4, 5, 6, 4, 6, 7, 8, 9, 10),
    gsSPNTriangles_5b(8, 10, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPNTrianglesInit_5b(2, 12, 13, 14, 12, 14, 15, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 32, 16, int_sum_hal_chest03_hiki_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_MIRROR, GX_CLAMP, 0, 0),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPNTrianglesInit_5b(3, 16, 17, 18, 19, 16, 18, 20, 19, 18),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 16, 16, int_sum_hal_chest03_hikite_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPNTrianglesInit_5b(4, 21, 22, 23, 23, 24, 25, 26, 27, 24),
    gsSPNTriangles_5b(24, 28, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsSPEndDisplayList(),
};

Gfx int_sum_hal_chest03_door_model[] = {
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, int_sum_hal_chest03_pal),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 16, 16, int_sum_hal_chest03_kuki_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPVertex(&int_sum_hal_chest03_v[29], 28, 0),
    gsSPNTrianglesInit_5b(4, 0, 1, 2, 3, 4, 1, 5, 6, 4),
    gsSPNTriangles_5b(7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 16, 32, int_sum_hal_chest03_side_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_MIRROR, GX_CLAMP, 0, 0),
    gsSPNTrianglesInit_5b(4, 10, 11, 12, 13, 10, 12, 14, 15, 16),
    gsSPNTriangles_5b(14, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 32, 64, int_sum_hal_chest03_front_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_MIRROR, GX_CLAMP, 0, 0),
    gsSPNTrianglesInit_5b(6, 18, 19, 20, 18, 20, 21, 20, 22, 21),
    gsSPNTriangles_5b(23, 24, 25, 24, 26, 25, 23, 27, 24, 0, 0, 0),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 32, 16, int_sum_hal_chest03_top_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_MIRROR, GX_MIRROR, 0, 0),
    gsSPVertex(&int_sum_hal_chest03_v[57], 15, 0),
    gsSPNTrianglesInit_5b(6, 0, 1, 2, 0, 3, 1, 4, 5, 2),
    gsSPNTriangles_5b(1, 4, 2, 4, 6, 5, 4, 7, 6, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 16, 16, int_sum_hal_chest03_hikite_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsSPNTrianglesInit_5b(3, 8, 9, 10, 11, 12, 13, 13, 8, 14),
    gsSPEndDisplayList(),
};

u8 cKF_ckcb_r_int_sum_hal_chest03_tbl[] = { 56, 7, 7 };

s16 cKF_kn_int_sum_hal_chest03_tbl[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2 };

s16 cKF_c_int_sum_hal_chest03_tbl[] = { 0, 900, 0 };

s16 cKF_ds_int_sum_hal_chest03_tbl[] = {
    1,  2000, 0, 10, 2000, 0, 1,  -24000, 0, 10, -24000, 0, 1,  1500, 0, 10, 1500, 0, 1,  0, 0, 10, 0, 0, 1,  0,  0,
    10, 0,    0, 1,  900,  0, 10, 900,    0, 1,  0,      0, 10, 0,    0, 1,  0,    0, 10, 0, 0, 1,  0, 0, 10, 28, 83
};

cKF_Animation_R_c cKF_ba_r_int_sum_hal_chest03 = { cKF_ckcb_r_int_sum_hal_chest03_tbl,
                                                   cKF_ds_int_sum_hal_chest03_tbl,
                                                   cKF_kn_int_sum_hal_chest03_tbl,
                                                   cKF_c_int_sum_hal_chest03_tbl,
                                                   -1,
                                                   10 };

cKF_Joint_R_c cKF_je_r_int_sum_hal_chest03_tbl[] = {
    { NULL, 1, cKF_JOINT_FLAG_DISP_OPA, { 2000, 41536, 1500 } },
    { int_sum_hal_chest03_door_model, 1, cKF_JOINT_FLAG_DISP_OPA, { 0, 0, 0 } },
    { int_sum_hal_chest03_door1_model, 0, cKF_JOINT_FLAG_DISP_OPA, { 1, 0, 0 } }
};

cKF_Skeleton_R_c cKF_bs_r_int_sum_hal_chest03 = { ARRAY_COUNT(cKF_je_r_int_sum_hal_chest03_tbl), 2,
                                                  cKF_je_r_int_sum_hal_chest03_tbl };
