#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

u8 cKF_ckcb_r_npc_1_komari_i1_tbl[] = { 56, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 7, 7, 0, 7, 0, 0 };

s16 cKF_kn_npc_1_komari_i1_tbl[] = { 2, 3, 3, 2, 3, 2, 3, 3, 3, 2, 3, 2, 2, 3, 3, 3, 3, 3, 2, 3, 2, 2, 3, 3, 2, 5, 2,
                                     2, 6, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 4, 2, 2, 2 };

s16 cKF_c_npc_1_komari_i1_tbl[] = { 0,    0, 900, 0,   0, 1800, 0, 0, 1800, 0, 900, 0, 0,   0,
                                    -900, 0, 0,   900, 0, -900, 0, 0, 0,    0, 0,   0, -900 };

s16 cKF_ds_npc_1_komari_i1_tbl[] = {
    1,  0,    0, 33, 0,    0, 1,  975,  0,    17, 1000, 0, 33, 975,  0,   1,  0,    0, 17, 75,   0, 33, 0,    0,
    1,  0,    0, 33, 0,    0, 1,  60,   0,    17, 40,   0, 33, 60,   0,   1,  90,   0, 33, 90,   0, 1,  -185, 0,
    17, -184, 0, 33, -185, 0, 1,  40,   0,    17, 84,   0, 33, 40,   0,   1,  -85,  0, 17, -91,  0, 33, -85,  0,
    1,  0,    0, 33, 0,    0, 1,  40,   0,    17, 0,    0, 33, 40,   0,   1,  0,    0, 33, 0,    0, 1,  0,    0,
    33, 0,    0, 1,  -15,  0, 17, -13,  0,    33, -15,  0, 1,  0,    0,   17, -3,   0, 33, 0,    0, 1,  180,  0,
    17, 174,  0, 33, 180,  0, 1,  -260, 0,    17, -194, 0, 33, -260, 0,   1,  -145, 0, 17, -134, 0, 33, -145, 0,
    1,  0,    0, 33, 0,    0, 1,  560,  0,    17, 493,  0, 33, 560,  0,   1,  0,    0, 33, 0,    0, 1,  0,    0,
    33, 0,    0, 1,  -240, 0, 17, -261, 0,    33, -240, 0, 1,  -40,  0,   17, -31,  0, 33, -40,  0, 1,  0,    0,
    33, 0,    0, 1,  60,   0, 9,  0,    0,    17, 60,   0, 25, 0,    0,   33, 60,   0, 1,  0,    0, 33, 0,    0,
    1,  0,    0, 33, 0,    0, 1,  82,   285,  4,  100,  0, 11, 40,   0,   19, 100,  0, 27, 40,   0, 33, 85,   285,
    1,  0,    0, 33, 0,    0, 1,  0,    0,    33, 0,    0, 1,  100,  -93, 2,  99,   0, 18, 149,  0, 33, 101,  -78,
    1,  -90,  0, 33, -90,  0, 1,  0,    0,    33, 0,    0, 1,  -300, 0,   33, -300, 0, 1,  -500, 0, 33, -500, 0,
    1,  0,    0, 33, 0,    0, 1,  -600, 0,    33, -600, 0, 1,  0,    0,   33, 0,    0, 1,  0,    0, 33, 0,    0,
    1,  -300, 0, 33, -301, 0, 1,  503,  0,    33, 503,  0, 1,  0,    0,   33, 0,    0, 1,  -600, 0, 33, -600, 0,
    1,  0,    0, 33, 0,    0, 1,  0,    0,    33, 0,    0, 1,  0,    0,   33, 0,    0, 1,  0,    0, 33, 0,    0,
    1,  0,    0, 33, 0,    0, 1,  -200, 0,    9,  -170, 0, 17, -200, 0,   25, -170, 0, 33, -200, 0, 1,  -10,  -149,
    9,  -30,  0, 25, 10,   0, 33, -10,  -116, 1,  0,    0, 33, 0,    0,   1,  0,    0, 33, 0,    0, 1,  0,    0,
    33, 0,    0
};

aNPC_Animation_c cKF_ba_r_npc_1_komari_i1 = {
    { cKF_ckcb_r_npc_1_komari_i1_tbl, cKF_ds_npc_1_komari_i1_tbl, cKF_kn_npc_1_komari_i1_tbl, cKF_c_npc_1_komari_i1_tbl,
      -1, 33 },
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
    -1,
    NULL,
    NULL,
};
