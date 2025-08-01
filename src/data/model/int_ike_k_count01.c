#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

extern Vtx int_ike_k_count01_v[];
u16 int_ike_k_count01_pal[] ATTRIBUTE_ALIGN(32) = {
#include "assets/int_ike_k_count01_pal.inc"
};

u8 int_ike_k_counttop_tex_txt[] = {
#include "assets/int_ike_k_counttop_tex_txt.inc"
};

u8 int_ike_k_countside_tex_txt[] = {
#include "assets/int_ike_k_countside_tex_txt.inc"
};

u8 int_ike_k_countside2_tex_txt[] = {
#include "assets/int_ike_k_countside2_tex_txt.inc"
};

Vtx int_ike_k_count01_v[] = {
#include "assets/int_ike_k_count01_v.inc"
};

Gfx int_ike_k_count01_body_model[] = {
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, int_ike_k_count01_pal),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 32, 32, int_ike_k_counttop_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING | G_SHADING_SMOOTH | G_DECAL_LEQUAL),
    gsSPVertex(int_ike_k_count01_v, 25, 0),
    gsSPNTrianglesInit_5b(8, 0, 1, 2, 1, 3, 2, 3, 4, 2),
    gsSPNTriangles_5b(5, 0, 2, 4, 6, 2, 6, 7, 2, 7, 8, 2),
    gsSPNTriangles_5b(8, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 16, 16, int_ike_k_countside_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsSPNTrianglesInit_5b(16, 9, 10, 11, 10, 12, 13, 14, 15, 16),
    gsSPNTriangles_5b(14, 16, 17, 10, 13, 11, 15, 18, 19, 15, 19, 16),
    gsSPNTriangles_5b(9, 11, 20, 18, 21, 22, 18, 22, 19, 12, 14, 17),
    gsSPNTriangles_5b(21, 23, 24, 21, 24, 22, 12, 17, 13, 23, 9, 20),
    gsSPNTriangles_5b(23, 20, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 32, 32, int_ike_k_countside2_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsSPVertex(&int_ike_k_count01_v[25], 24, 0),
    gsSPNTrianglesInit_5b(16, 0, 1, 2, 3, 4, 5, 3, 6, 4),
    gsSPNTriangles_5b(6, 7, 8, 9, 10, 11, 9, 11, 1, 12, 0, 2),
    gsSPNTriangles_5b(12, 2, 13, 7, 12, 13, 10, 14, 15, 10, 15, 11),
    gsSPNTriangles_5b(7, 13, 8, 14, 3, 5, 14, 5, 15, 6, 8, 4),
    gsSPNTriangles_5b(0, 9, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_CI, G_IM_SIZ_4b, 16, 16, int_ike_k_countside_tex_txt),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_CLAMP, GX_CLAMP, 0, 0),
    gsSPNTrianglesInit_5b(6, 16, 17, 18, 18, 17, 19, 19, 17, 20),
    gsSPNTriangles_5b(21, 19, 20, 22, 23, 21, 20, 22, 21, 0, 0, 0),
    gsSPEndDisplayList(),
};
