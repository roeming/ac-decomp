#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

u8 cKF_ckcb_r_npc_1_get1_tbl[] = { 56, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 7, 7, 0, 7, 0, 0 };

s16 cKF_kn_npc_1_get1_tbl[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2,
                                2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 3, 2, 2, 2, 3, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };

s16 cKF_c_npc_1_get1_tbl[] = { 0,    0, 900, 0,   0, 1800, 0, 0, 1800, 0, 900, 0, 0,   0,
                               -900, 0, 0,   900, 0, -900, 0, 0, 0,    0, 0,   0, -900 };

s16 cKF_ds_npc_1_get1_tbl[] = {
    1,  0,    0, 11, 0,    0, 1,  1000, 0,   11, 1000, 0, 1,  0,    0,    11, 200,  0, 1,  0,    0, 11, 0,    0,
    1,  0,    0, 11, -100, 0, 1,  0,    0,   11, 0,    0, 1,  -175, 0,    11, -175, 0, 1,  -100, 0, 11, -200, 0,
    1,  25,   0, 11, 25,   0, 1,  0,    0,   11, 0,    0, 1,  200,  0,    11, 200,  0, 1,  0,    0, 11, 0,    0,
    1,  0,    0, 11, 0,    0, 1,  -100, 0,   11, -100, 0, 1,  0,    0,    11, 0,    0, 1,  175,  0, 11, 175,  0,
    1,  -100, 0, 11, -100, 0, 1,  -25,  0,   11, -25,  0, 1,  0,    0,    11, 0,    0, 1,  200,  0, 11, 200,  0,
    1,  0,    0, 11, 0,    0, 1,  0,    0,   11, 0,    0, 1,  -100, 0,    11, -100, 0, 1,  0,    0, 11, 0,    0,
    1,  0,    0, 11, 0,    0, 1,  60,   0,   10, 250,  0, 11, 240,  -513, 1,  0,    0, 11, 0,    0, 1,  0,    0,
    11, 0,    0, 1,  82,   0, 11, 150,  0,   1,  0,    0, 11, 0,    0,    1,  0,    0, 11, 0,    0, 1,  2,    0,
    11, 100,  0, 1,  0,    0, 11, 0,    0,   1,  0,    0, 11, -600, 0,    1,  58,   0, 11, -700, 0, 1,  -564, 0,
    6,  -350, 0, 11, 0,    0, 1,  0,    0,   11, 0,    0, 1,  -57,  468,  6,  -450, 0, 11, -50,  0, 1,  0,    0,
    11, 0,    0, 1,  0,    0, 11, 600,  0,   1,  58,   0, 11, -700, 0,    1,  564,  0, 6,  350,  0, 11, 0,    0,
    1,  0,    0, 11, 0,    0, 1,  -57,  468, 6,  -450, 0, 11, -57,  0,    1,  0,    0, 11, 0,    0, 1,  0,    0,
    11, 300,  0, 1,  0,    0, 11, -50,  0,   1,  0,    0, 11, 175,  0,    1,  0,    0, 11, 0,    0, 1,  0,    0,
    11, 0,    0, 1,  0,    0, 11, 0,    0,   1,  0,    0, 11, 0,    0,    1,  0,    0, 11, 0,    0, 1,  0,    0,
    11, 0,    0
};

aNPC_Animation_c cKF_ba_r_npc_1_get1 = {
    { cKF_ckcb_r_npc_1_get1_tbl, cKF_ds_npc_1_get1_tbl, cKF_kn_npc_1_get1_tbl, cKF_c_npc_1_get1_tbl, -1, 11 },
    1.0f,
    11.0f,
    cKF_FRAMECONTROL_STOP,
    -10.0f,
    NULL,
    aNPC_EYE_TEX1,
    -1,
    NULL,
    aNPC_MOUTH_TEX1,
    0,
    -1,
    -1,
    NULL,
    NULL,
};
