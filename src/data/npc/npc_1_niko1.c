#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

u8 cKF_ckcb_r_npc_1_niko1_tbl[] = { 56, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 7, 7, 0, 7, 0, 0 };

s16 cKF_kn_npc_1_niko1_tbl[] = { 2, 5, 5, 2, 3, 2, 2, 5, 5, 2, 5, 2, 2, 5, 2, 2, 5, 5, 2, 5, 2, 2, 5, 2, 2, 5, 2,
                                 2, 6, 2, 2, 4, 2, 2, 4, 4, 2, 4, 2, 2, 4, 4, 2, 4, 2, 2, 2, 2, 2, 5, 4, 2, 2, 2 };

s16 cKF_c_npc_1_niko1_tbl[] = { 0,    0, 900, 0,   0, 1800, 0, 0, 1800, 0, 900, 0, 0,   0,
                                -900, 0, 0,   900, 0, -900, 0, 0, 0,    0, 0,   0, -900 };

s16 cKF_ds_npc_1_niko1_tbl[] = {
    1,  0,    0,    33, 0,    0,    1,  1000, 0,   9,  1050, 0,   17, 1000, 0,    25, 1050, 0,   33, 1000, 0,
    1,  0,    0,    9,  60,   0,    17, 40,   0,   25, 60,   0,   33, 0,    0,    1,  0,    0,   33, 0,    0,
    1,  0,    0,    17, -40,  0,    33, 0,    0,   1,  0,    0,   33, 0,    0,    1,  -175, 0,   33, -175, 0,
    1,  -100, 0,    9,  0,    0,    17, -135, 0,   25, 0,    0,   33, -100, 0,    1,  25,   0,   9,  0,    0,
    17, 25,   0,    25, 0,    0,    33, 25,   0,   1,  0,    0,   33, 0,    0,    1,  200,  0,   9,  0,    0,
    17, 245,  0,    25, 0,    0,    33, 200,  0,   1,  0,    0,   33, 0,    0,    1,  0,    0,   33, 0,    0,
    1,  -100, 0,    9,  50,   0,    17, -145, 0,   25, 50,   0,   33, -100, 0,    1,  0,    0,   33, 0,    0,
    1,  175,  0,    33, 175,  0,    1,  -100, 0,   9,  0,    0,   17, -135, 0,    25, 0,    0,   33, -100, 0,
    1,  -25,  0,    9,  0,    0,    17, -25,  0,   25, 0,    0,   33, -25,  0,    1,  0,    0,   33, 0,    0,
    1,  200,  0,    9,  0,    0,    17, 245,  0,   25, 0,    0,   33, 200,  0,    1,  0,    0,   33, 0,    0,
    1,  0,    0,    33, 0,    0,    1,  -100, 0,   9,  50,   0,   17, -145, 0,    25, 50,   0,   33, -100, 0,
    1,  0,    0,    33, 0,    0,    1,  0,    0,   33, 0,    0,   1,  60,   0,    9,  -60,  0,   17, 60,   0,
    25, -60,  0,    33, 60,   0,    1,  0,    0,   33, 0,    0,   1,  0,    0,    33, 0,    0,   1,  82,   1348,
    4,  170,  0,    11, -170, 0,    19, 170,  0,   27, -170, 0,   33, 82,   1348, 1,  0,    0,   33, 0,    0,
    1,  0,    0,    33, 0,    0,    1,  52,   -78, 2,  50,   0,   18, 150,  0,    33, 52,   -78, 1,  0,    0,
    33, 0,    0,    1,  0,    0,    33, 0,    0,   1,  58,   316, 5,  80,   0,    21, -80,  0,   33, 58,   294,
    1,  -564, 240,  5,  -550, 0,    21, -650, 0,   33, -564, 252, 1,  0,    0,    33, 0,    0,   1,  -57,  468,
    7,  0,    0,    23, -180, 0,    33, -57,  468, 1,  0,    0,   33, 0,    0,    1,  0,    0,   33, 0,    0,
    1,  58,   317,  5,  80,   0,    21, -80,  0,   33, 58,   293, 1,  564,  -272, 5,  550,  0,   21, 650,  0,
    33, 564,  -266, 1,  0,    0,    33, 0,    0,   1,  -57,  468, 7,  0,    0,    23, -180, 0,   33, -57,  468,
    1,  0,    0,    33, 0,    0,    1,  0,    0,   33, 0,    0,   1,  0,    0,    33, 0,    0,   1,  0,    0,
    33, 0,    0,    1,  0,    0,    33, 0,    0,   1,  30,   0,   9,  80,   0,    17, 30,   0,   25, 80,   0,
    33, 30,   0,    1,  0,    -273, 9,  -50,  0,   25, 50,   0,   33, 0,    -273, 1,  0,    0,   33, 0,    0,
    1,  0,    0,    33, 0,    0,    1,  0,    0,   33, 0,    0
};

aNPC_Animation_c cKF_ba_r_npc_1_niko1 = {
    { cKF_ckcb_r_npc_1_niko1_tbl, cKF_ds_npc_1_niko1_tbl, cKF_kn_npc_1_niko1_tbl, cKF_c_npc_1_niko1_tbl, -1, 33 },
    1.0f,
    33.0f,
    cKF_FRAMECONTROL_REPEAT,
    -5.0f,
    NULL,
    aNPC_EYE_TEX0,
    5,
    NULL,
    aNPC_MOUTH_TEX1,
    0,
    -1,
    -1,
    NULL,
    NULL,
};
