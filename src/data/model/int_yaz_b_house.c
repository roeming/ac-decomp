#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

extern Vtx int_yaz_b_house_v[];
u16 int_yaz_b_house_pal[] ATTRIBUTE_ALIGN(32) = {
#include "assets/int_yaz_b_house_pal.inc"
};

u8 int_yaz_b_house_kabu_tex_txt[] = {
#include "assets/int_yaz_b_house_kabu_tex_txt.inc"
};

u8 int_yaz_b_house_kabe01_tex_txt[] = {
#include "assets/int_yaz_b_house_kabe01_tex_txt.inc"
};

u8 int_yaz_b_house_kabe02_tex_txt[] = {
#include "assets/int_yaz_b_house_kabe02_tex_txt.inc"
};

u8 int_yaz_b_house_ita_tex_txt[] = {
#include "assets/int_yaz_b_house_ita_tex_txt.inc"
};

u8 int_yaz_b_house_pole_tex_txt[] = {
#include "assets/int_yaz_b_house_pole_tex_txt.inc"
};

Vtx int_yaz_b_house_v[] = {
#include "assets/int_yaz_b_house_v.inc"
};

Gfx int_yaz_b_house_body_model[] = {
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, int_yaz_b_house_pal),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 16, 32, int_yaz_b_house_kabu_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_MIRROR, GX_CLAMP, 0, 0),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 124, 124),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPVertex(int_yaz_b_house_v, 16, 0),
    gsSPNTrianglesInit_5b(2, 0, 1, 2, 0, 2, 3, 0, 0, 0),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPNTrianglesInit_5b(2, 4, 5, 6, 4, 6, 7, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 32, 40, int_yaz_b_house_kabe01_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsSPNTrianglesInit_5b(4, 8, 9, 10, 8, 10, 11, 12, 13, 14),
    gsSPNTriangles_5b(12, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsSPVertex(&int_yaz_b_house_v[16], 22, 0),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPNTrianglesInit_5b(10, 0, 1, 2, 3, 4, 5, 6, 7, 8),
    gsSPNTriangles_5b(6, 8, 9, 10, 11, 12, 10, 12, 13, 14, 15, 16),
    gsSPNTriangles_5b(14, 16, 17, 18, 19, 20, 18, 20, 21, 0, 0, 0),
    gsDPSetTile_Dolphin(8, 0, 15, GX_MIRROR, GX_CLAMP, 0, 0),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 252, 156),
    gsSPVertex(&int_yaz_b_house_v[38], 28, 0),
    gsSPNTrianglesInit_5b(14, 0, 1, 2, 0, 2, 3, 4, 5, 6),
    gsSPNTriangles_5b(4, 6, 7, 8, 9, 10, 8, 10, 11, 12, 13, 14),
    gsSPNTriangles_5b(12, 14, 15, 16, 17, 18, 16, 18, 19, 20, 21, 22),
    gsSPNTriangles_5b(20, 22, 23, 24, 25, 26, 24, 26, 27, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 32, 40, int_yaz_b_house_kabe02_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_MIRROR, GX_CLAMP, 0, 0),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 252, 156),
    gsSPVertex(&int_yaz_b_house_v[66], 13, 0),
    gsSPNTrianglesInit_5b(2, 0, 1, 2, 0, 2, 3, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 32, 16, int_yaz_b_house_ita_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_REPEAT, 0, 0),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 124, 124),
    gsSPNTrianglesInit_5b(2, 4, 5, 6, 4, 6, 7, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 16, 32, int_yaz_b_house_pole_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsSPNTrianglesInit_5b(4, 8, 9, 10, 8, 11, 9, 8, 12, 11),
    gsSPNTriangles_5b(8, 10, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsSPEndDisplayList(),
};
