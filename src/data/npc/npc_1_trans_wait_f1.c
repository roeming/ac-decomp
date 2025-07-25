#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

u8 cKF_ckcb_r_npc_1_trans_wait_f1_tbl[] = { 56, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7,
                                            7,  0, 7, 7, 0, 7, 7, 7, 7, 0, 7, 0, 0 };

s16 cKF_kn_npc_1_trans_wait_f1_tbl[] = { 2, 3, 2, 2, 2, 2, 3, 3, 3, 2, 3, 2, 3, 3, 2, 3, 3, 3,
                                         2, 3, 2, 3, 3, 2, 2, 4, 2, 2, 4, 2, 2, 4, 4, 2, 2, 2,
                                         2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2 };

s16 cKF_c_npc_1_trans_wait_f1_tbl[] = { 0,    0, 900, 0,   0, 1800, 0, 0, 1800, 0, 900, 0, 0,   0,
                                        -900, 0, 0,   900, 0, -900, 0, 0, 0,    0, 0,   0, -900 };

s16 cKF_ds_npc_1_trans_wait_f1_tbl[] = {
    1,  0,    0, 17, 0,    0,    1,  1000, 0,   9,  950, 0,   17, 1000, 0,    1,  200,  0, 17, 200,  0,   1,  0,    0,
    17, 0,    0, 1,  -100, 0,    17, -100, 0,   1,  0,   0,   17, 0,    0,    1,  -175, 0, 9,  -120, 0,   17, -175, 0,
    1,  -200, 0, 9,  -300, 0,    17, -200, 0,   1,  25,  0,   9,  30,   0,    17, 25,   0, 1,  0,    0,   17, 0,    0,
    1,  200,  0, 9,  450,  0,    17, 200,  0,   1,  0,   0,   17, 0,    0,    1,  0,    0, 9,  -50,  0,   17, 0,    0,
    1,  -100, 0, 9,  -250, 0,    17, -100, 0,   1,  0,   0,   17, 0,    0,    1,  175,  0, 9,  120,  0,   17, 175,  0,
    1,  -100, 0, 9,  -250, 0,    17, -100, 0,   1,  -25, 0,   9,  -30,  0,    17, -25,  0, 1,  0,    0,   17, 0,    0,
    1,  200,  0, 9,  450,  0,    17, 200,  0,   1,  0,   0,   17, 0,    0,    1,  0,    0, 9,  100,  0,   17, 0,    0,
    1,  -100, 0, 9,  -300, 0,    17, -100, 0,   1,  0,   0,   17, 0,    0,    1,  0,    0, 17, 0,    0,   1,  60,   436,
    5,  100,  0, 12, 20,   0,    17, 60,   436, 1,  0,   0,   17, 0,    0,    1,  0,    0, 17, 0,    0,   1,  82,   466,
    6,  140,  0, 13, 50,   0,    17, 82,   466, 1,  0,   0,   17, 0,    0,    1,  -150, 0, 17, -150, 0,   1,  100,  0,
    5,  110,  0, 13, 90,   0,    17, 100,  0,   1,  50,  149, 5,  60,   0,    13, 40,   0, 17, 50,   148, 1,  -600, 0,
    17, -600, 0, 1,  -750, 0,    17, -750, 0,   1,  20,  0,   17, 20,   0,    1,  0,    0, 17, 0,    0,   1,  -50,  0,
    17, -50,  0, 1,  0,    0,    17, 0,    0,   1,  0,   0,   17, 0,    0,    1,  50,   0, 17, 50,   0,   1,  300,  0,
    17, 300,  0, 1,  0,    0,    17, 0,    0,   1,  -57, 0,   17, -57,  0,    1,  0,    0, 17, 0,    0,   1,  300,  0,
    17, 300,  0, 1,  -50,  0,    17, -50,  0,   1,  175, 0,   17, 175,  0,    1,  150,  0, 17, 150,  0,   1,  0,    0,
    17, 0,    0, 1,  0,    -150, 5,  -10,  0,   13, 10,  0,   17, 0,    -150, 1,  0,    0, 17, 0,    0,   1,  0,    0,
    17, 0,    0, 1,  0,    0,    17, 0,    0
};

aNPC_Animation_c cKF_ba_r_npc_1_trans_wait_f1 = {
    { cKF_ckcb_r_npc_1_trans_wait_f1_tbl, cKF_ds_npc_1_trans_wait_f1_tbl, cKF_kn_npc_1_trans_wait_f1_tbl,
      cKF_c_npc_1_trans_wait_f1_tbl, -1, 17 },
    1.0f,
    17.0f,
    cKF_FRAMECONTROL_REPEAT,
    -5.0f,
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
