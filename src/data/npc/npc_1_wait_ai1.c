#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

u8 cKF_ckcb_r_npc_1_wait_ai1_tbl[] = { 56, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 7, 7, 0, 7, 0, 0 };

s16 cKF_kn_npc_1_wait_ai1_tbl[] = { 2, 3, 2, 2, 3, 2, 2, 3, 3, 2, 3, 2, 2, 3, 3, 2, 3, 3, 2, 3, 2, 2, 3, 3, 2, 4, 3,
                                    2, 4, 4, 2, 4, 2, 2, 4, 4, 2, 2, 4, 2, 4, 4, 2, 2, 4, 2, 2, 2, 2, 4, 2, 2, 2, 2 };

s16 cKF_c_npc_1_wait_ai1_tbl[] = { 0,    0, 900, 0,   0, 1800, 0, 0, 1800, 0, 900, 0, 0,   0,
                                   -900, 0, 0,   900, 0, -900, 0, 0, 0,    0, 0,   0, -900 };

s16 cKF_ds_npc_1_wait_ai1_tbl[] = {
    1,  0,    0,   33, 0,    0,   1,  950,  0,   17, 975,  0,   33, 950,  0,   1,  100,  0,   33, 100,  0,
    1,  0,    0,   33, 0,    0,   1,  0,    0,   17, 30,   0,   33, 0,    0,   1,  0,    0,   33, 0,    0,
    1,  -175, 0,   33, -175, 0,   1,  -100, 0,   17, -40,  0,   33, -100, 0,   1,  30,   0,   17, 25,   0,
    33, 30,   0,   1,  0,    0,   33, 0,    0,   1,  350,  0,   17, 270,  0,   33, 350,  0,   1,  0,    0,
    33, 0,    0,   1,  0,    0,   33, 0,    0,   1,  -250, 0,   17, -195, 0,   33, -250, 0,   1,  0,    0,
    17, -5,   0,   33, 0,    0,   1,  175,  0,   33, 175,  0,   1,  -100, 0,   17, -40,  0,   33, -100, 0,
    1,  -30,  0,   17, -25,  0,   33, -30,  0,   1,  0,    0,   33, 0,    0,   1,  350,  0,   17, 270,  0,
    33, 350,  0,   1,  0,    0,   33, 0,    0,   1,  0,    0,   33, 0,    0,   1,  -250, 0,   17, -195, 0,
    33, -250, 0,   1,  0,    0,   17, 5,    0,   33, 0,    0,   1,  0,    0,   33, 0,    0,   1,  295,  146,
    3,  300,  0,   19, 200,  0,   33, 295,  146, 1,  20,   0,   16, -20,  0,   33, 20,   0,   1,  0,    0,
    33, 0,    0,   1,  80,   298, 5,  100,  0,   21, -30,  0,   33, 80,   298, 1,  18,   60,  3,  20,   0,
    19, -20,  0,   33, 18,   60,  1,  0,    0,   33, 0,    0,   1,  -248, -74, 3,  -250, 0,   19, -200, 0,
    33, -248, -74, 1,  0,    0,   33, 0,    0,   1,  0,    0,   33, 0,    0,   1,  -297, -73, 3,  -300, 0,
    19, -250, 0,   33, -297, -73, 1,  -699, -30, 3,  -700, 0,   19, -685, 0,   33, -699, -30, 1,  0,    0,
    33, 0,    0,   1,  -57,  0,   33, -57,  0,   1,  -98,  -37, 5,  -100, 0,   21, -80,  0,   33, -98,  -37,
    1,  0,    0,   33, 0,    0,   1,  -297, -73, 3,  -300, 0,   19, -250, 0,   33, -297, -73, 1,  699,  31,
    3,  700,  0,   19, 685,  0,   33, 699,  31,  1,  0,    0,   33, 0,    0,   1,  -57,  0,   33, -57,  0,
    1,  98,   37,  5,  100,  0,   21, 80,   0,   33, 98,   37,  1,  0,    0,   33, 0,    0,   1,  0,    0,
    33, 0,    0,   1,  0,    0,   33, 0,    0,   1,  0,    0,   33, 0,    0,   1,  149,  -78, 16, 60,   0,
    32, 150,  0,   33, 149,  -78, 1,  0,    0,   33, 0,    0,   1,  0,    0,   33, 0,    0,   1,  0,    0,
    33, 0,    0,   1,  0,    0,   33, 0,    0
};

static u32 feel_eff_set[] = { 10 };

aNPC_feel_effect_c feel_set[] = { { mNpc_FEEL_SAD, 10, ARRAY_COUNT(feel_eff_set), feel_eff_set } };

aNPC_Animation_c cKF_ba_r_npc_1_wait_ai1 = {
    { cKF_ckcb_r_npc_1_wait_ai1_tbl, cKF_ds_npc_1_wait_ai1_tbl, cKF_kn_npc_1_wait_ai1_tbl, cKF_c_npc_1_wait_ai1_tbl, -1,
      33 },
    1.0f,
    33.0f,
    cKF_FRAMECONTROL_REPEAT,
    -5.0f,
    NULL,
    aNPC_EYE_TEX0,
    4,
    NULL,
    aNPC_MOUTH_TEX2,
    3,
    -1,
    eEC_EFFECT_DOYON,
    feel_set,
    NULL,
};
