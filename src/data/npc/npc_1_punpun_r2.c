#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

u8 cKF_ckcb_r_npc_1_punpun_r2_tbl[] = { 56, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 7, 7, 0, 7, 0, 0 };

s16 cKF_kn_npc_1_punpun_r2_tbl[] = { 2, 2, 2, 2,  3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                     2, 2, 2, 12, 3, 2, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2 };

s16 cKF_c_npc_1_punpun_r2_tbl[] = { 0,    0, 900, 0,   0, 1800, 0, 0, 1800, 0, 900, 0, 0,   0,
                                    -900, 0, 0,   900, 0, -900, 0, 0, 0,    0, 0,   0, -900 };

s16 cKF_ds_npc_1_punpun_r2_tbl[] = {
    1,  0,    0,    21, 0,    0,    1,  0,    0,    21, 0,    0,    1,  150,   0,   21, 150,   0,    1,  0,    0,
    21, 0,    0,    1,  -30,  0,    16, -80,  0,    21, -30,  0,    1,  100,   0,   21, 100,   0,    1,  0,    0,
    21, 0,    0,    1,  0,    0,    21, 0,    0,    1,  0,    0,    21, 0,     0,   1,  0,     0,    21, 0,    0,
    1,  0,    0,    21, 0,    0,    1,  0,    0,    21, 0,    0,    1,  0,     0,   21, 0,     0,    1,  0,    0,
    21, 0,    0,    1,  0,    0,    21, 0,    0,    1,  0,    0,    21, 0,     0,   1,  0,     0,    21, 0,    0,
    1,  0,    0,    21, 0,    0,    1,  0,    0,    21, 0,    0,    1,  0,     0,   21, 0,     0,    1,  0,    0,
    21, 0,    0,    1,  0,    0,    21, 0,    0,    1,  0,    0,    21, 0,     0,   1,  0,     0,    21, 0,    0,
    1,  0,    0,    21, 0,    0,    1,  0,    0,    21, 0,    0,    1,  0,     0,   21, 0,     0,    1,  0,    0,
    21, 0,    0,    1,  0,    0,    21, 0,    0,    1,  0,    0,    21, 0,     0,   1,  0,     0,    7,  -5,   0,
    8,  5,    0,    9,  -5,   0,    10, 5,    0,    11, -15,  0,    12, 15,    0,   13, -30,   0,    14, 30,   0,
    15, -10,  0,    16, 10,   0,    21, 0,    0,    1,  -250, -159, 16, -300,  0,   21, -250,  -159, 1,  -100, 0,
    21, -100, 0,    1,  0,    0,    16, -100, 0,    21, 0,    0,    1,  0,     0,   16, 180,   0,    21, 0,    0,
    1,  -300, 0,    21, -300, 0,    1,  0,    0,    21, 0,    0,    1,  -1000, 0,   21, -1000, 0,    1,  0,    0,
    21, 0,    0,    1,  403,  -73,  21, 403,  -73,  1,  -548, -73,  21, -548,  -73, 1,  98,    75,   21, 98,   75,
    1,  0,    0,    21, 0,    0,    1,  -793, -106, 21, -793, -106, 1,  0,     0,   21, 0,     0,    1,  -545, 459,
    21, -545, 459,  1,  293,  -576, 21, 293,  -576, 1,  -500, 833,  21, -500,  833, 1,  0,     0,    21, 0,    0,
    1,  200,  -188, 16, 160,  0,    21, 200,  -188, 1,  0,    0,    21, 0,     0,   1,  0,     0,    21, 0,    0,
    1,  0,    0,    21, 0,    0,    1,  0,    0,    21, 0,    0
};

aNPC_Animation_c cKF_ba_r_npc_1_punpun_r2 = {
    { cKF_ckcb_r_npc_1_punpun_r2_tbl, cKF_ds_npc_1_punpun_r2_tbl, cKF_kn_npc_1_punpun_r2_tbl, cKF_c_npc_1_punpun_r2_tbl,
      -1, 21 },
    1.0f,
    21.0f,
    cKF_FRAMECONTROL_REPEAT,
    0.0f,
    NULL,
    aNPC_EYE_TEX0,
    4,
    NULL,
    aNPC_MOUTH_TEX2,
    4,
    -1,
    eEC_EFFECT_PUN,
    NULL,
    NULL,
};
