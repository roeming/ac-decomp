#include "libforest/gbi_extensions.h"

extern u8 bush_pal_dummy[];
extern u8 earth_pal_dummy[];
extern u8 stone_tex_dummy[];
extern u8 grass_tex_dummy[];
extern u8 bush_b_tex_dummy[];
extern u8 bush_a_tex_dummy[];
extern u8 earth_tex_dummy[];

static Vtx grd_s_f_ko_1_v[] = {
#include "assets/field/bg/grd_s_f_ko_1_v.inc"
};

extern Gfx grd_s_f_ko_1_modelT[] = {
    gsSPEndDisplayList(),
};

extern Gfx grd_s_f_ko_1_model[] = {
    gsSPTexture(0, 0, 0, 0, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, bush_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(bush_a_tex_dummy, G_IM_FMT_CI, 64, 64, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&grd_s_f_ko_1_v[197], 32, 0),
    gsSPNTrianglesInit_5b(
        14, // tri count
        0, 1, 2, // tri0
        3, 4, 1, // tri1
        5, 6, 7 // tri2
    ),
    gsSPNTriangles_5b(
        8, 7, 4, // tri0
        9, 10, 6, // tri1
        11, 12, 13, // tri2
        14, 13, 15 // tri3
    ),
    gsSPNTriangles_5b(
        16, 15, 17, // tri0
        18, 19, 20, // tri1
        21, 17, 19, // tri2
        22, 20, 23 // tri3
    ),
    gsSPNTriangles_5b(
        24, 23, 25, // tri0
        26, 27, 28, // tri1
        29, 30, 27, // tri2
        0, 0, 0 // tri3
    ),
    gsSPVertex(&grd_s_f_ko_1_v[228], 9, 0),
    gsSPNTrianglesInit_5b(
        4, // tri count
        0, 1, 2, // tri0
        3, 2, 4, // tri1
        5, 6, 1 // tri2
    ),
    gsSPNTriangles_5b(
        7, 8, 6, // tri0
        0, 0, 0, // tri1
        0, 0, 0, // tri2
        0, 0, 0 // tri3
    ),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPLoadTextureBlock_4b_Dolphin(bush_b_tex_dummy, G_IM_FMT_CI, 64, 32, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_f_ko_1_v[0], 32, 0),
    gsSPNTrianglesInit_5b(
        14, // tri count
        0, 1, 2, // tri0
        3, 4, 1, // tri1
        5, 6, 7 // tri2
    ),
    gsSPNTriangles_5b(
        8, 7, 4, // tri0
        9, 10, 6, // tri1
        11, 12, 10, // tri2
        13, 14, 12 // tri3
    ),
    gsSPNTriangles_5b(
        15, 16, 17, // tri0
        18, 19, 20, // tri1
        21, 17, 19, // tri2
        22, 20, 23 // tri3
    ),
    gsSPNTriangles_5b(
        24, 23, 25, // tri0
        26, 27, 28, // tri1
        29, 28, 30, // tri2
        0, 0, 0 // tri3
    ),
    gsSPVertex(&grd_s_f_ko_1_v[31], 9, 0),
    gsSPNTrianglesInit_5b(
        4, // tri count
        0, 1, 2, // tri0
        3, 2, 4, // tri1
        5, 4, 6 // tri2
    ),
    gsSPNTriangles_5b(
        7, 6, 8, // tri0
        0, 0, 0, // tri1
        0, 0, 0, // tri2
        0, 0, 0 // tri3
    ),
    gsDPLoadTLUT_Dolphin(15, 16, 1, earth_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(grass_tex_dummy, G_IM_FMT_CI, 32, 32, 15, GX_REPEAT, GX_REPEAT, 0, 0),
    gsSPVertex(&grd_s_f_ko_1_v[40], 32, 0),
    gsSPNTrianglesInit_5b(
        25, // tri count
        0, 1, 2, // tri0
        1, 3, 2, // tri1
        4, 5, 6 // tri2
    ),
    gsSPNTriangles_5b(
        5, 7, 6, // tri0
        8, 9, 4, // tri1
        9, 8, 10, // tri2
        11, 9, 10 // tri3
    ),
    gsSPNTriangles_5b(
        12, 13, 14, // tri0
        13, 15, 14, // tri1
        13, 16, 15, // tri2
        16, 17, 18 // tri3
    ),
    gsSPNTriangles_5b(
        18, 17, 19, // tri0
        19, 17, 20, // tri1
        17, 21, 20, // tri2
        17, 22, 21 // tri3
    ),
    gsSPNTriangles_5b(
        17, 23, 22, // tri0
        24, 25, 23, // tri1
        24, 26, 25, // tri2
        26, 27, 25 // tri3
    ),
    gsSPNTriangles_5b(
        25, 22, 23, // tri0
        11, 28, 29, // tri1
        28, 27, 29, // tri2
        29, 27, 30 // tri3
    ),
    gsSPNTriangles_5b(
        27, 26, 30, // tri0
        7, 30, 26, // tri1
        0, 0, 0, // tri2
        0, 0, 0 // tri3
    ),
    gsSPVertex(&grd_s_f_ko_1_v[71], 32, 0),
    gsSPNTrianglesInit_5b(
        30, // tri count
        0, 1, 2, // tri0
        2, 3, 0, // tri1
        2, 4, 3 // tri2
    ),
    gsSPNTriangles_5b(
        4, 5, 3, // tri0
        3, 5, 6, // tri1
        5, 7, 6, // tri2
        5, 8, 7 // tri3
    ),
    gsSPNTriangles_5b(
        6, 7, 9, // tri0
        7, 10, 9, // tri1
        11, 12, 13, // tri2
        9, 11, 13 // tri3
    ),
    gsSPNTriangles_5b(
        9, 10, 11, // tri0
        14, 1, 0, // tri1
        14, 15, 1, // tri2
        14, 16, 15 // tri3
    ),
    gsSPNTriangles_5b(
        17, 18, 19, // tri0
        19, 20, 21, // tri1
        17, 15, 18, // tri2
        15, 22, 18 // tri3
    ),
    gsSPNTriangles_5b(
        15, 16, 22, // tri0
        22, 16, 13, // tri1
        13, 23, 22, // tri2
        13, 12, 23 // tri3
    ),
    gsSPNTriangles_5b(
        21, 24, 25, // tri0
        24, 26, 25, // tri1
        24, 27, 26, // tri2
        27, 28, 26 // tri3
    ),
    gsSPNTriangles_5b(
        29, 28, 27, // tri0
        29, 30, 28, // tri1
        31, 30, 29, // tri2
        0, 0, 0 // tri3
    ),
    gsDPLoadTextureBlock_4b_Dolphin(earth_tex_dummy, G_IM_FMT_CI, 64, 64, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_f_ko_1_v[103], 32, 0),
    gsSPNTrianglesInit_5b(
        15, // tri count
        0, 1, 2, // tri0
        3, 0, 4, // tri1
        5, 6, 7 // tri2
    ),
    gsSPNTriangles_5b(
        6, 3, 8, // tri0
        9, 10, 11, // tri1
        12, 9, 13, // tri2
        10, 5, 14 // tri3
    ),
    gsSPNTriangles_5b(
        15, 16, 17, // tri0
        18, 19, 20, // tri1
        19, 15, 21, // tri2
        22, 23, 24 // tri3
    ),
    gsSPNTriangles_5b(
        16, 22, 25, // tri0
        23, 26, 27, // tri1
        26, 28, 29, // tri2
        30, 18, 31 // tri3
    ),
    gsSPVertex(&grd_s_f_ko_1_v[135], 32, 0),
    gsSPNTrianglesInit_5b(
        14, // tri count
        0, 1, 2, // tri0
        3, 0, 4, // tri1
        1, 5, 6 // tri2
    ),
    gsSPNTriangles_5b(
        7, 8, 9, // tri0
        10, 11, 12, // tri1
        5, 13, 6, // tri2
        3, 4, 14 // tri3
    ),
    gsSPNTriangles_5b(
        15, 14, 16, // tri0
        17, 16, 18, // tri1
        19, 20, 21, // tri2
        22, 19, 23 // tri3
    ),
    gsSPNTriangles_5b(
        24, 25, 26, // tri0
        25, 22, 27, // tri1
        28, 29, 30, // tri2
        0, 0, 0 // tri3
    ),
    gsSPVertex(&grd_s_f_ko_1_v[166], 14, 0),
    gsSPNTrianglesInit_5b(
        6, // tri count
        0, 1, 2, // tri0
        3, 4, 5, // tri1
        4, 6, 7 // tri2
    ),
    gsSPNTriangles_5b(
        8, 0, 9, // tri0
        10, 11, 12, // tri1
        1, 13, 2, // tri2
        0, 0, 0 // tri3
    ),
    gsDPLoadTextureBlock_4b_Dolphin(stone_tex_dummy, G_IM_FMT_CI, 64, 64, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_f_ko_1_v[180], 17, 0),
    gsSPNTrianglesInit_5b(
        10, // tri count
        0, 1, 2, // tri0
        3, 0, 4, // tri1
        5, 6, 7 // tri2
    ),
    gsSPNTriangles_5b(
        6, 3, 8, // tri0
        9, 10, 11, // tri1
        12, 9, 13, // tri2
        10, 14, 15 // tri3
    ),
    gsSPNTriangles_5b(
        14, 5, 16, // tri0
        4, 8, 3, // tri1
        15, 11, 10, // tri2
        0, 0, 0 // tri3
    ),
    gsSPEndDisplayList(),
};