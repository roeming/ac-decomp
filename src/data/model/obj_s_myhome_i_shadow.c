#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

u8 obj_s_myhome_i_shadow_tex[] ATTRIBUTE_ALIGN(32) = {
#include "assets/obj_s_myhome_i_shadow_tex.inc"
};

Vtx obj_s_myhome_i_shadow_v[] = {
#include "assets/obj_s_myhome_i_shadow_v.inc"
};

Gfx obj_s_myhome_i_shadowT_model[] = {
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineLERP(0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIM_LOD_FRAC, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_DECAL2),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_I, G_IM_SIZ_4b, 16, 16, obj_s_myhome_i_shadow_tex),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(anime_1_txt, 22, 0),
    gsSPNTrianglesInit_5b(2, 0, 1, 2, 0, 2, 3, 0, 0, 0),
    gsSPNTrianglesInit_5b(2, 4, 5, 6, 4, 6, 7, 0, 0, 0),
    gsSPNTrianglesInit_5b(2, 8, 9, 10, 8, 10, 11, 0, 0, 0),
    gsSPNTrianglesInit_5b(6, 12, 13, 14, 12, 14, 15, 16, 17, 18),
    gsSPNTriangles_5b(17, 19, 18, 18, 20, 21, 18, 19, 20, 0, 0, 0),
    gsSPEndDisplayList(),
};
