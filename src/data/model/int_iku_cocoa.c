#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

extern Vtx int_iku_cocoa_v[];
u16 int_iku_cocoa_pal[] ATTRIBUTE_ALIGN(32) = {
#include "assets/int_iku_cocoa_pal.inc"
};

u8 int_iku_cocoa_c_tex_txt[] = {
#include "assets/int_iku_cocoa_c_tex_txt.inc"
};

u8 int_iku_cocoa_b_tex_txt[] = {
#include "assets/int_iku_cocoa_b_tex_txt.inc"
};

u8 int_iku_cocoa_a_tex_txt[] = {
#include "assets/int_iku_cocoa_a_tex_txt.inc"
};

Vtx int_iku_cocoa_v[] = {
#include "assets/int_iku_cocoa_v.inc"
};

Gfx int_iku_cocoa_on_model[] = {
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, int_iku_cocoa_pal),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 32, 64, int_iku_cocoa_c_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPVertex(int_iku_cocoa_v, 28, 0),
    gsSPNTrianglesInit_5b(2, 0, 1, 2, 0, 2, 3, 0, 0, 0),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPNTrianglesInit_5b(10, 4, 5, 6, 4, 6, 7, 8, 9, 10),
    gsSPNTriangles_5b(8, 10, 11, 12, 13, 14, 15, 16, 17, 15, 17, 18),
    gsSPNTriangles_5b(19, 20, 21, 19, 21, 22, 7, 23, 4, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 32, 32, int_iku_cocoa_b_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsSPNTrianglesInit_5b(2, 24, 25, 26, 24, 27, 25, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 32, 32, int_iku_cocoa_a_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPVertex(&int_iku_cocoa_v[28], 4, 0),
    gsSPNTrianglesInit_5b(2, 0, 1, 2, 0, 2, 3, 0, 0, 0),
    gsSPEndDisplayList(),
};

Gfx int_iku_cocoa_off_model[] = {
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, int_iku_cocoa_pal),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 32, 32, int_iku_cocoa_b_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPVertex(&int_iku_cocoa_v[32], 17, 0),
    gsSPNTrianglesInit_5b(4, 0, 1, 2, 0, 2, 3, 4, 5, 2),
    gsSPNTriangles_5b(4, 2, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPNTrianglesInit_5b(6, 7, 8, 9, 7, 9, 10, 11, 12, 13),
    gsSPNTriangles_5b(11, 13, 14, 8, 7, 15, 8, 15, 16, 0, 0, 0),
    gsSPEndDisplayList(),
};
