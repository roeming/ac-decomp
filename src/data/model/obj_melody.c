#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"

u8 obj_melody_shadow_tex[] ATTRIBUTE_ALIGN(32) = {
#include "assets/obj_melody_shadow_tex.inc"
};

Vtx obj_melody_shadow_v[] = {
#include "assets/obj_melody_shadow_v.inc"
};

Gfx obj_melody_shadowT_mat_model[] = {
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_I, G_IM_SIZ_4b, 32, 32, obj_melody_shadow_tex),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 15, GX_MIRROR, GX_MIRROR, 0, 0), gsSPEndDisplayList()
};

Gfx obj_melody_shadowT_gfx_model[] = { gsSPNTrianglesInit_5b(2, 0, 1, 2, 0, 2, 3, 0, 0, 0), gsSPEndDisplayList() };
