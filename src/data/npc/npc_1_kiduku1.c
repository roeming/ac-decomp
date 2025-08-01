#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

u8 cKF_ckcb_r_npc_1_kiduku1_tbl[] = { 56, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 7, 7, 0, 7, 0, 0 };

s16 cKF_kn_npc_1_kiduku1_tbl[] = { 5, 11, 5, 3, 6,  5, 4, 12, 9, 2, 12, 2, 2,  11, 2, 5, 12, 9,
                                   2, 12, 2, 2, 11, 2, 2, 8,  4, 2, 7,  4, 8,  11, 5, 7, 9,  9,
                                   2, 7,  6, 7, 10, 9, 2, 8,  7, 2, 2,  2, 11, 11, 8, 5, 7,  5 };

s16 cKF_c_npc_1_kiduku1_tbl[] = { 0,    0, 900, 0,   0, 1800, 0, 0, 1800, 0, 900, 0, 0,   0,
                                  -900, 0, 0,   900, 0, -900, 0, 0, 0,    0, 0,   0, -900 };

s16 cKF_ds_npc_1_kiduku1_tbl[] = {
    1,  0,    0,     38, 0,    0,    41, 50,   0,     47, -50,  0,     50, 0,    746,  1,  1000, 0,    4,  1025, 0,
    8,  1025, 0,     13, 1000, 0,    21, 1025, 0,     27, 1000, 0,     36, 1025, 0,    41, 975,  0,    44, 1000, 0,
    47, 975,  0,     50, 1000, 0,    1,  0,    0,     4,  -100, 0,     8,  -100, 0,    13, 0,    0,    50, 0,    0,
    1,  0,    0,     38, 0,    0,    50, -80,  0,     1,  0,    0,     2,  -50,  0,    4,  5,    622,  8,  30,   0,
    13, 0,    0,     50, 0,    0,    1,  0,    0,     38, 0,    0,     41, -50,  0,    47, 50,   0,    50, 0,    -701,
    1,  -175, 0,     44, -175, 0,    47, -150, 0,     50, -175, 0,     1,  -100, 0,    2,  -150, 0,    4,  -60,  0,
    8,  -60,  0,     13, -100, 0,    21, 0,    0,     27, -100, 0,     36, 0,    0,    41, -200, 0,    44, -100, 0,
    47, -450, 0,     50, -100, 0,    1,  25,   0,     13, 25,   0,     21, 0,    0,    27, 25,   0,    36, 0,    0,
    41, 75,   0,     44, 25,   0,    47, 150,  0,     50, 25,   0,     1,  0,    0,    50, 0,    0,    1,  200,  0,
    2,  300,  0,     4,  100,  0,    8,  100,  0,     13, 200,  0,     21, 0,    0,    27, 200,  0,    36, 0,    0,
    41, 400,  0,     44, 200,  0,    47, 950,  0,     50, 200,  0,     1,  0,    0,    50, 0,    0,    1,  0,    0,
    50, 0,    0,     1,  -100, 0,    2,  -200, 0,     4,  -100, 0,     13, -100, 0,    21, 0,    0,    27, -100, 0,
    36, 0,    0,     41, -200, 0,    44, -100, 0,     47, -300, 0,     50, -100, 0,    1,  0,    0,    50, 0,    0,
    1,  175,  0,     36, 175,  0,    41, 150,  0,     44, 175,  0,     50, 175,  0,    1,  -100, 0,    2,  -150, 0,
    4,  -60,  0,     8,  -60,  0,    13, -100, 0,     21, 0,    0,     27, -100, 0,    36, 0,    0,    41, -450, 0,
    44, -100, 0,     47, -200, 0,    50, -100, 0,     1,  -25,  0,     13, -25,  0,    21, 0,    0,    27, -25,  0,
    36, 0,    0,     41, -150, 0,    44, -25,  0,     47, -75,  0,     50, -25,  0,    1,  0,    0,    50, 0,    0,
    1,  200,  0,     2,  300,  0,    4,  100,  0,     8,  100,  0,     13, 200,  0,    21, 0,    0,    27, 200,  0,
    36, 0,    0,     41, 950,  0,    44, 200,  0,     47, 400,  0,     50, 200,  0,    1,  0,    0,    50, 0,    0,
    1,  0,    0,     50, 0,    0,    1,  -100, 0,     2,  -200, 0,     4,  -100, 0,    13, -100, 0,    21, 0,    0,
    27, -100, 0,     36, 0,    0,    41, -300, 0,     44, -100, 0,     47, -200, 0,    50, -100, 0,    1,  0,    0,
    50, 0,    0,     1,  0,    0,    50, 0,    0,     1,  60,   0,     4,  -300, 0,    6,  -200, 0,    8,  -260, -404,
    13, 60,   0,     37, 60,   0,    47, -200, 0,     50, 0,    0,     1,  0,    0,    37, 0,    0,    41, 20,   0,
    50, -38,  499,   1,  0,    0,    50, 0,    0,     1,  82,   0,     4,  -50,  0,    6,  50,   0,    8,  20,   -511,
    13, 82,   0,     37, 82,   0,    50, -178, 1563,  1,  0,    0,     37, 0,    0,    43, 20,   0,    50, -68,  346,
    1,  0,    0,     13, 0,    0,    19, -80,  0,     22, -70,  302,   33, 80,   0,    36, 70,   -198, 47, -80,  0,
    50, 0,    1527,  1,  2,    0,    5,  50,   0,     8,  50,   -101,  13, 2,    0,    19, 30,   0,    22, 30,   0,
    27, 0,    0,     33, 30,   0,    36, 30,   0,     47, 125,  0,     50, 100,  -751, 1,  0,    0,    36, 0,    0,
    41, 50,   0,     47, -50,  0,    50, 0,    739,   1,  0,    0,     3,  0,    0,    5,  -200, 0,    8,  -200, 0,
    13, 0,    0,     38, 0,    0,    50, -560, -2692, 1,  58,   0,     3,  -150, 0,    5,  -100, 0,    8,  -100, 0,
    13, 58,   0,     19, 30,   0,    33, 100,  0,     38, 58,   -619,  50, -355, 153,  1,  -564, 0,    3,  -650, 0,
    5,  -600, 0,     8,  -600, 0,    19, -530, 0,     27, -560, 0,     33, -530, 0,    38, -564, 240,  50, 175,  3728,
    1,  0,    0,     50, 0,    0,    1,  -57,  0,     5,  -160, 0,     8,  -110, 539,  13, -57,  0,    21, -20,  0,
    35, -100, 0,     50, -450, 0,    1,  0,    0,     13, 0,    0,     21, 30,   0,    27, 0,    0,    35, 30,   0,
    50, 0,    0,     1,  0,    0,    3,  0,    0,     5,  200,  0,     8,  200,  0,    13, 0,    0,    38, 0,    0,
    50, 390,  -2640, 1,  58,   0,    3,  -150, 0,     5,  -100, 0,     8,  -100, 0,    13, 58,   421,  19, 90,   0,
    27, 60,   -178,  33, 30,   0,    38, 58,   317,   50, -395, -120,  1,  564,  -272, 3,  650,  0,    5,  600,  0,
    8,  600,  0,     19, 530,  0,    27, 560,  0,     33, 530,  0,     38, 564,  -272, 50, 75,   3811, 1,  0,    0,
    50, 0,    0,     1,  -57,  0,    5,  -160, 0,     8,  -110, 518,   13, -57,  0,    20, -100, 0,    27, -60,  279,
    34, -20,  0,     50, -450, 0,    1,  0,    0,     8,  0,    0,     13, 0,    0,    20, -30,  0,    27, 0,    0,
    34, -30,  0,     50, 0,    0,    1,  0,    0,     50, 0,    0,     1,  0,    0,    50, 0,    0,    1,  0,    0,
    50, 0,    0,     1,  0,    0,    8,  0,    0,     13, 0,    -3079, 17, -320, 0,    19, -300, 0,    22, -300, 0,
    27, 0,    3177,  31, 320,  0,    33, 300,  0,     37, 300,  0,     50, 0,    0,    1,  0,    0,    3,  -50,  0,
    6,  50,   0,     8,  30,   -436, 13, 0,    0,     22, 0,    0,     27, -20,  0,    31, 0,    0,    38, 0,    0,
    47, 150,  0,     50, 150,  0,    1,  0,    0,     13, 0,    0,     17, 50,   0,    22, 50,   0,    27, 0,    -751,
    31, -50,  0,     37, -50,  0,    50, 0,    0,     1,  0,    0,     6,  0,    0,    8,  0,    0,    37, 0,    0,
    50, 0,    0,     1,  0,    0,    3,  0,    0,     6,  -150, 0,     8,  -150, 0,    26, -125, 0,    37, -150, 0,
    50, -150, 0,     1,  0,    0,    6,  0,    0,     8,  0,    0,     37, 0,    0,    50, 0,    0
};

u8 npc_1_kiduku10_tex_index[] = { 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                                  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 };

u8 npc_1_kiduku11_tex_index[] = { 0, 1, 2, 2, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
                                  6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 };

aNPC_Animation_c cKF_ba_r_npc_1_kiduku1 = {
    { cKF_ckcb_r_npc_1_kiduku1_tbl, cKF_ds_npc_1_kiduku1_tbl, cKF_kn_npc_1_kiduku1_tbl, cKF_c_npc_1_kiduku1_tbl, -1,
      50 },
    1.0f,
    50.0f,
    cKF_FRAMECONTROL_STOP,
    -5.0f,
    npc_1_kiduku11_tex_index,
    aNPC_EYE_TEX0,
    -1,
    npc_1_kiduku10_tex_index,
    aNPC_MOUTH_TEX0,
    -1,
    6,
    eEC_EFFECT_SHOCK,
    NULL,
    NULL,
};
