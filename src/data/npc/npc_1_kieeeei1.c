#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

u8 cKF_ckcb_r_npc_1_kieeeei1_tbl[] = { 56, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 7, 7, 0, 7, 0, 0 };

s16 cKF_kn_npc_1_kieeeei1_tbl[] = { 2, 6, 2, 2, 4, 2, 2, 3, 4, 2, 4, 2, 3, 7, 3, 2, 3, 4, 2, 4, 2, 3, 7, 3, 2, 7, 2,
                                    2, 8, 2, 2, 7, 5, 3, 7, 5, 2, 4, 2, 3, 7, 5, 2, 4, 2, 4, 2, 2, 2, 5, 5, 2, 4, 2 };

s16 cKF_c_npc_1_kieeeei1_tbl[] = { 0,    0, 900, 0,   0, 1800, 0, 0, 1800, 0, 900, 0, 0,   0,
                                   -900, 0, 0,   900, 0, -900, 0, 0, 0,    0, 0,   0, -900 };

s16 cKF_ds_npc_1_kieeeei1_tbl[] = {
    1,  0,    0,    14, 0,    0,    1,  1000, 0, 5,  850,  0,    9,  1200, 0,    10, 1000, 0,    11, 1100, 0,
    14, 1100, 0,    1,  0,    0,    14, 0,    0, 1,  0,    0,    14, 0,    0,    1,  0,    0,    5,  80,   0,
    9,  -400, 0,    14, -400, 0,    1,  0,    0, 14, 0,    0,    1,  -175, -181, 14, -175, 0,    1,  -100, 0,
    8,  -300, 0,    14, -300, 0,    1,  25,   0, 5,  100,  0,    8,  25,   0,    14, 25,   0,    1,  0,    0,
    14, 0,    0,    1,  200,  0,    5,  750,  0, 8,  0,    0,    14, 0,    0,    1,  0,    0,    14, 0,    0,
    1,  0,    0,    9,  0,    0,    14, 0,    0, 1,  -100, 0,    5,  -450, 0,    8,  80,   1909, 9,  100,  0,
    10, -75,  0,    11, 0,    0,    14, 0,    0, 1,  0,    -28,  9,  -23,  -52,  14, -23,  0,    1,  175,  181,
    14, 175,  0,    1,  -100, 0,    8,  -300, 0, 14, -300, 0,    1,  -25,  0,    5,  -100, 0,    8,  -25,  0,
    14, -25,  0,    1,  0,    0,    14, 0,    0, 1,  200,  0,    5,  750,  0,    8,  0,    0,    14, 0,    0,
    1,  0,    0,    14, 0,    0,    1,  0,    0, 9,  0,    0,    14, 0,    0,    1,  -100, 0,    5,  -450, 0,
    8,  80,   1909, 9,  100,  0,    10, -75,  0, 11, 0,    0,    14, 0,    0,    1,  0,    28,   9,  23,   52,
    14, 23,   0,    1,  0,    0,    14, 0,    0, 1,  60,   0,    3,  150,  0,    6,  -450, 0,    11, 100,  0,
    12, -150, 0,    13, -100, 0,    14, -100, 0, 1,  0,    0,    14, 0,    0,    1,  0,    0,    14, 0,    0,
    1,  82,   0,    3,  -200, 0,    5,  250,  0, 10, -300, 0,    11, 100,  0,    12, -100, 0,    13, 50,   0,
    14, -30,  0,    1,  0,    0,    14, 0,    0, 1,  0,    0,    14, 0,    0,    1,  2,    -78,  3,  -250, 0,
    6,  180,  0,    9,  130,  0,    10, 200,  0, 11, 160,  0,    14, 160,  0,    1,  0,    0,    4,  40,   0,
    7,  -70,  0,    10, 0,    0,    14, 0,    0, 1,  0,    0,    8,  -500, 0,    14, -500, 0,    1,  58,   0,
    5,  -700, 0,    8,  -570, 3229, 10, -240, 0, 11, -400, 0,    12, -320, 0,    14, -320, 0,    1,  -564, 240,
    5,  -150, 0,    8,  -150, 0,    10, -600, 0, 14, -600, 0,    1,  0,    0,    14, 0,    0,    1,  -57,  468,
    8,  -700, 0,    10, 0,    0,    14, 0,    0, 1,  0,    0,    14, 0,    0,    1,  0,    0,    8,  500,  0,
    14, 500,  0,    1,  58,   317,  5,  -700, 0, 8,  -570, 3547, 10, -240, 0,    11, -400, 0,    12, -320, 0,
    14, -320, 0,    1,  564,  -272, 5,  150,  0, 8,  150,  0,    10, 600,  0,    14, 600,  0,    1,  0,    0,
    14, 0,    0,    1,  -57,  468,  8,  -750, 0, 10, 0,    0,    14, 0,    0,    1,  0,    0,    14, 0,    0,
    1,  0,    0,    7,  900,  0,    9,  0,    0, 14, 0,    0,    1,  0,    0,    14, 0,    0,    1,  0,    0,
    14, 0,    0,    1,  0,    0,    14, 0,    0, 1,  0,    0,    3,  -200, 0,    6,  100,  1271, 9,  130,  0,
    14, 130,  0,    1,  0,    0,    4,  30,   0, 7,  -50,  0,    10, 0,    0,    14, 0,    0,    1,  0,    0,
    14, 0,    0,    1,  0,    0,    7,  0,    0, 11, -150, 0,    14, -150, 0,    1,  0,    0,    14, 0,    0
};

static u8 npc_1_muka10_tex_index[] = { 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4 };

static u8 npc_1_muka11_tex_index[] = { 0, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3 };

aNPC_Animation_c cKF_ba_r_npc_1_kieeeei1 = {
    { cKF_ckcb_r_npc_1_kieeeei1_tbl, cKF_ds_npc_1_kieeeei1_tbl, cKF_kn_npc_1_kieeeei1_tbl, cKF_c_npc_1_kieeeei1_tbl, -1,
      14 },
    1.0f,
    14.0f,
    cKF_FRAMECONTROL_STOP,
    -4.0f,
    npc_1_muka11_tex_index,
    aNPC_EYE_TEX0,
    -1,
    npc_1_muka10_tex_index,
    aNPC_MOUTH_TEX0,
    -1,
    11,
    eEC_EFFECT_URANAI,
    NULL,
    NULL,
};
