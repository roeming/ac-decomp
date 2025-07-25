#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

u8 cKF_ckcb_r_npc_1_tamakome1_tbl[] = { 56, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 7, 7, 0, 7, 0, 0 };

s16 cKF_kn_npc_1_tamakome1_tbl[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 2,
                                     3, 5, 2, 5, 2, 5, 5, 5, 5, 2, 2, 2, 5, 5, 5, 2, 5, 2, 2, 2, 2, 2, 5, 2, 2, 2, 2 };

s16 cKF_c_npc_1_tamakome1_tbl[] = { 0,    0, 900, 0,   0, 1800, 0, 0, 1800, 0, 900, 0, 0,   0,
                                    -900, 0, 0,   900, 0, -900, 0, 0, 0,    0, 0,   0, -900 };

s16 cKF_ds_npc_1_tamakome1_tbl[] = {
    1,  0,    0, 13, 0,    0, 1,  1000, 0, 13, 1000, 0, 1,  0,    0, 13, 0,    0, 1,  -50,  0, 13, -50,  0, 1,  0,    0,
    13, 0,    0, 1,  0,    0, 13, 0,    0, 1,  -228, 0, 13, -228, 0, 1,  -83,  0, 13, -83,  0, 1,  30,   0, 13, 30,   0,
    1,  0,    0, 13, 0,    0, 1,  200,  0, 13, 200,  0, 1,  0,    0, 13, 0,    0, 1,  0,    0, 13, 0,    0, 1,  -115, 0,
    13, -115, 0, 1,  0,    0, 13, 0,    0, 1,  175,  0, 13, 175,  0, 1,  -100, 0, 13, -100, 0, 1,  -25,  0, 13, -25,  0,
    1,  0,    0, 13, 0,    0, 1,  200,  0, 13, 200,  0, 1,  0,    0, 13, 0,    0, 1,  0,    0, 13, 0,    0, 1,  -100, 0,
    13, -100, 0, 1,  0,    0, 13, 0,    0, 1,  0,    0, 13, 0,    0, 1,  -50,  0, 4,  50,   0, 7,  -50,  0, 10, 50,   0,
    13, -50,  0, 1,  0,    0, 13, 0,    0, 1,  0,    0, 10, 0,    0, 13, 0,    0, 1,  -30,  0, 4,  80,   0, 7,  -30,  0,
    10, 80,   0, 13, -30,  0, 1,  0,    0, 13, 0,    0, 1,  -100, 0, 4,  -75,  0, 7,  -100, 0, 10, -75,  0, 13, -100, 0,
    1,  -150, 0, 13, -150, 0, 1,  25,   0, 4,  0,    0, 7,  25,   0, 10, 0,    0, 13, 25,   0, 1,  200,  0, 4,  250,  0,
    7,  200,  0, 10, 250,  0, 13, 200,  0, 1,  -800, 0, 4,  -750, 0, 7,  -800, 0, 10, -750, 0, 13, -800, 0, 1,  -150, 0,
    4,  -250, 0, 7,  -150, 0, 10, -250, 0, 13, -150, 0, 1,  0,    0, 13, 0,    0, 1,  -500, 0, 13, -500, 0, 1,  0,    0,
    13, 0,    0, 1,  -350, 0, 4,  -300, 0, 7,  -350, 0, 10, -300, 0, 13, -350, 0, 1,  -500, 0, 4,  -450, 0, 7,  -500, 0,
    10, -450, 0, 13, -500, 0, 1,  500,  0, 4,  600,  0, 7,  500,  0, 10, 600,  0, 13, 500,  0, 1,  0,    0, 13, 0,    0,
    1,  -750, 0, 4,  -650, 0, 7,  -750, 0, 10, -650, 0, 13, -750, 0, 1,  0,    0, 13, 0,    0, 1,  200,  0, 13, 200,  0,
    1,  550,  0, 13, 550,  0, 1,  0,    0, 13, 0,    0, 1,  0,    0, 13, 0,    0, 1,  -175, 0, 4,  -150, 0, 7,  -175, 0,
    10, -150, 0, 13, -175, 0, 1,  0,    0, 13, 0,    0, 1,  0,    0, 13, 0,    0, 1,  0,    0, 13, 0,    0, 1,  0,    0,
    13, 0,    0
};

aNPC_Animation_c cKF_ba_r_npc_1_tamakome1 = {
    { cKF_ckcb_r_npc_1_tamakome1_tbl, cKF_ds_npc_1_tamakome1_tbl, cKF_kn_npc_1_tamakome1_tbl, cKF_c_npc_1_tamakome1_tbl,
      -1, 13 },
    1.0f,
    13.0f,
    cKF_FRAMECONTROL_REPEAT,
    10.0f,
    NULL,
    aNPC_EYE_TEX0,
    0,
    NULL,
    aNPC_MOUTH_TEX0,
    0,
    -1,
    -1,
    NULL,
    NULL,
};
