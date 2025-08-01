#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

extern Vtx int_tak_isu03_v[];
u16 int_tak_isu03_pal[] ATTRIBUTE_ALIGN(32) = {
#include "assets/int_tak_isu03_pal.inc"
};

u8 int_tak_isu03_zabu_tex[] = {
#include "assets/int_tak_isu03_zabu_tex.inc"
};

u8 int_tak_isu03_under_tex[] = {
#include "assets/int_tak_isu03_under_tex.inc"
};

u8 int_tak_isu03_bou_tex[] = {
#include "assets/int_tak_isu03_bou_tex.inc"
};

u8 int_tak_isu03_asi_tex[] = {
#include "assets/int_tak_isu03_asi_tex.inc"
};

Vtx int_tak_isu03_v[] = {
#include "assets/int_tak_isu03_v.inc"
};

Gfx int_tak_isu03_onT_model[] = {
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, int_tak_isu03_pal),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 16, 16, int_tak_isu03_asi_tex),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_MIRROR, GX_CLAMP, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPVertex(int_tak_isu03_v, 28, 0),
    gsSPNTrianglesInit_5b(4, 0, 1, 2, 0, 2, 3, 4, 5, 6),
    gsSPNTriangles_5b(4, 6, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 16, 16, int_tak_isu03_bou_tex),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsSPNTrianglesInit_5b(8, 8, 9, 10, 8, 10, 11, 12, 13, 14),
    gsSPNTriangles_5b(12, 14, 15, 16, 17, 18, 16, 18, 19, 20, 21, 22),
    gsSPNTriangles_5b(20, 22, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 16, 16, int_tak_isu03_under_tex),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_MIRROR, GX_MIRROR, 0, 0),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPNTrianglesInit_5b(2, 24, 25, 26, 24, 26, 27, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 32, 32, int_tak_isu03_zabu_tex),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsSPVertex(&int_tak_isu03_v[28], 14, 0),
    gsSPNTrianglesInit_5b(18, 0, 1, 2, 3, 0, 2, 4, 3, 2),
    gsSPNTriangles_5b(5, 4, 2, 2, 6, 5, 5, 6, 7, 7, 4, 5),
    gsSPNTriangles_5b(7, 3, 4, 7, 0, 3, 7, 1, 0, 8, 1, 7),
    gsSPNTriangles_5b(7, 6, 9, 7, 9, 8, 10, 11, 12, 10, 12, 13),
    gsSPNTriangles_5b(8, 9, 2, 9, 6, 2, 2, 1, 8, 0, 0, 0),
    gsSPEndDisplayList(),
};
