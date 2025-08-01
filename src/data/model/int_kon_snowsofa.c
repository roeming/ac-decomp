#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

extern Vtx int_kon_snowsofa_v[];
u16 int_kon_snowsofa_pal[] ATTRIBUTE_ALIGN(32) = {
#include "assets/int_kon_snowsofa_pal.inc"
};

u8 int_kon_snowsofa01_tex[] = {
#include "assets/int_kon_snowsofa01_tex.inc"
};

u8 int_kon_snowsofa02_tex[] = {
#include "assets/int_kon_snowsofa02_tex.inc"
};

u8 int_kon_snowsofa03_tex[] = {
#include "assets/int_kon_snowsofa03_tex.inc"
};

u8 int_kon_snowsofa04_tex[] = {
#include "assets/int_kon_snowsofa04_tex.inc"
};

Vtx int_kon_snowsofa_v[] = {
#include "assets/int_kon_snowsofa_v.inc"
};

Gfx int_kon_snowsofa_model[] = {
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, int_kon_snowsofa_pal),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 16, 32, int_kon_snowsofa03_tex),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_MIRROR, GX_CLAMP, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPVertex(int_kon_snowsofa_v, 30, 0),
    gsSPNTrianglesInit_5b(4, 0, 1, 2, 3, 4, 5, 0, 2, 3),
    gsSPNTriangles_5b(0, 3, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 64, 16, int_kon_snowsofa02_tex),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_MIRROR, GX_CLAMP, 0, 0),
    gsSPNTrianglesInit_5b(20, 6, 7, 8, 9, 6, 8, 10, 11, 12),
    gsSPNTriangles_5b(12, 13, 10, 8, 11, 10, 7, 11, 8, 14, 15, 16),
    gsSPNTriangles_5b(14, 16, 17, 18, 19, 15, 18, 15, 14, 20, 19, 18),
    gsSPNTriangles_5b(20, 18, 21, 22, 23, 21, 23, 20, 21, 24, 25, 22),
    gsSPNTriangles_5b(25, 23, 22, 9, 26, 6, 27, 26, 9, 27, 28, 29),
    gsSPNTriangles_5b(29, 26, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 32, 64, int_kon_snowsofa01_tex),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_MIRROR, GX_CLAMP, 0, 0),
    gsSPVertex(&int_kon_snowsofa_v[30], 12, 0),
    gsSPNTrianglesInit_5b(10, 0, 1, 2, 0, 3, 1, 4, 5, 0),
    gsSPNTriangles_5b(5, 6, 7, 8, 3, 7, 0, 2, 9, 8, 7, 10),
    gsSPNTriangles_5b(7, 11, 10, 7, 6, 11, 4, 0, 9, 0, 0, 0),
    gsSPEndDisplayList(),
};

Gfx int_kon_snowsofaT_model[] = {
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, int_kon_snowsofa_pal),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 16, 16, int_kon_snowsofa04_tex),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPVertex(&int_kon_snowsofa_v[42], 8, 0),
    gsSPNTrianglesInit_5b(6, 0, 1, 2, 2, 3, 0, 3, 1, 0),
    gsSPNTriangles_5b(4, 5, 6, 4, 6, 7, 7, 5, 4, 0, 0, 0),
    gsSPEndDisplayList(),
};
