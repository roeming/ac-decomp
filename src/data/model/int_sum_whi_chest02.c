#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

extern Vtx int_sum_whi_chest02_v[];
u16 int_sum_whi_chest02_pal[] ATTRIBUTE_ALIGN(32) = {
#include "assets/int_sum_whi_chest02_pal.inc"
};

u8 int_sum_whi_chest02_hiki_tex_txt[] = {
#include "assets/int_sum_whi_chest02_hiki_tex_txt.inc"
};

u8 int_sum_whi_chest02_hikiside_tex_txt[] = {
#include "assets/int_sum_whi_chest02_hikiside_tex_txt.inc"
};

u8 int_sum_whi_chest02_back_tex_txt[] = {
#include "assets/int_sum_whi_chest02_back_tex_txt.inc"
};

u8 int_sum_whi_chest02_front_tex_txt[] = {
#include "assets/int_sum_whi_chest02_front_tex_txt.inc"
};

Vtx int_sum_whi_chest02_v[] = {
#include "assets/int_sum_whi_chest02_v.inc"
};

Gfx int_sum_whi_chest02_doorL_model[] = {
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, int_sum_whi_chest02_pal),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 16, 32, int_sum_whi_chest02_hiki_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPVertex(int_sum_whi_chest02_v, 15, 0),
    gsSPNTrianglesInit_5b(2, 0, 1, 2, 0, 2, 3, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 16, 16, int_sum_whi_chest02_hikiside_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsSPNTrianglesInit_5b(3, 4, 5, 6, 7, 8, 9, 7, 9, 10),
    gsSPNTrianglesInit_5b(2, 11, 12, 13, 11, 14, 12, 0, 0, 0),
    gsSPEndDisplayList(),
};

Gfx int_sum_whi_chest02_base_model[] = {
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, int_sum_whi_chest02_pal),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 16, 64, int_sum_whi_chest02_back_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_MIRROR, GX_MIRROR, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPVertex(&int_sum_whi_chest02_v[30], 12, 0),
    gsSPNTrianglesInit_5b(6, 0, 1, 2, 0, 2, 3, 4, 5, 6),
    gsSPNTriangles_5b(4, 6, 7, 8, 9, 10, 8, 10, 11, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 32, 48, int_sum_whi_chest02_front_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_MIRROR, GX_CLAMP, 0, 0),
    gsSPVertex(&int_sum_whi_chest02_v[42], 24, 0),
    gsSPNTrianglesInit_5b(12, 0, 1, 2, 0, 2, 3, 4, 5, 6),
    gsSPNTriangles_5b(4, 6, 7, 8, 9, 10, 8, 10, 11, 12, 13, 14),
    gsSPNTriangles_5b(12, 14, 15, 16, 17, 18, 16, 18, 19, 20, 21, 22),
    gsSPNTriangles_5b(20, 22, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsSPEndDisplayList(),
};

Gfx int_sum_whi_chest02_doorR_model[] = {
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, int_sum_whi_chest02_pal),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 16, 32, int_sum_whi_chest02_hiki_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPVertex(&int_sum_whi_chest02_v[15], 15, 0),
    gsSPNTrianglesInit_5b(2, 0, 1, 2, 0, 2, 3, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 16, 16, int_sum_whi_chest02_hikiside_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsSPNTrianglesInit_5b(3, 4, 5, 6, 7, 8, 9, 7, 9, 10),
    gsSPNTrianglesInit_5b(2, 11, 12, 13, 11, 14, 12, 0, 0, 0),
    gsSPEndDisplayList(),
};

u8 cKF_ckcb_r_int_sum_whi_chest02_tbl[] = { 56, 7, 0, 7, 7 };

s16 cKF_kn_int_sum_whi_chest02_tbl[] = { 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 3 };

s16 cKF_c_int_sum_whi_chest02_tbl[] = { -900, 0, 0, 0, 0, 900 };

s16 cKF_ds_int_sum_whi_chest02_tbl[] = { 1,    -1470, 0,  12,   -1470, 0,    1,  3625, 0,    12,    3625, 0,    1,
                                         -110, 0,     12, -110, 0,     1,    0,  0,    12,   0,     0,    1,    0,
                                         0,    12,    0,  0,    1,     -900, 0,  12,   -900, 0,     1,    0,    0,
                                         12,   0,     0,  1,    0,     0,    12, 0,    0,    1,     1800, 0,    6,
                                         2250, 3785,  12, 2850, 0,     1,    0,  0,    12,   0,     0,    1,    0,
                                         0,    12,    0,  0,    1,     900,  0,  6,    450,  -3818, 12,   -150, 0 };

cKF_Animation_R_c cKF_ba_r_int_sum_whi_chest02 = { cKF_ckcb_r_int_sum_whi_chest02_tbl,
                                                   cKF_ds_int_sum_whi_chest02_tbl,
                                                   cKF_kn_int_sum_whi_chest02_tbl,
                                                   cKF_c_int_sum_whi_chest02_tbl,
                                                   -1,
                                                   12 };

cKF_Joint_R_c cKF_je_r_int_sum_whi_chest02_tbl[] = {
    { NULL, 1, cKF_JOINT_FLAG_DISP_OPA, { 64066, 3625, 65426 } },
    { int_sum_whi_chest02_base_model, 2, cKF_JOINT_FLAG_DISP_OPA, { 0, 0, 0 } },
    { NULL, 1, cKF_JOINT_FLAG_DISP_OPA, { 1500, 2915, 0 } },
    { int_sum_whi_chest02_doorR_model, 0, cKF_JOINT_FLAG_DISP_OPA, { 0, 0, 0 } },
    { int_sum_whi_chest02_doorL_model, 0, cKF_JOINT_FLAG_DISP_OPA, { 1500, 0, 0 } }
};

cKF_Skeleton_R_c cKF_bs_r_int_sum_whi_chest02 = { ARRAY_COUNT(cKF_je_r_int_sum_whi_chest02_tbl), 3,
                                                  cKF_je_r_int_sum_whi_chest02_tbl };
