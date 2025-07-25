#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

u8 cKF_ckcb_r_npc_1_keitai_on1_tbl[] = {
    56, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 7, 7, 0, 7, 0, 0
};

s16 cKF_kn_npc_1_keitai_on1_tbl[] = { 2, 5,  2, 4, 5, 6, 2, 2, 2, 2,  2,  2, 2, 2,  2,  2,  2,  2,
                                      2, 2,  2, 2, 2, 2, 2, 2, 2, 2,  2,  2, 9, 7,  13, 11, 11, 11,
                                      2, 11, 6, 7, 7, 7, 3, 7, 8, 12, 12, 7, 9, 12, 13, 2,  2,  2 };

s16 cKF_c_npc_1_keitai_on1_tbl[] = { 0,    0, 900, 0,   0, 1800, 0, 0, 1800, 0, 900, 0, 0,   0,
                                     -900, 0, 0,   900, 0, -900, 0, 0, 0,    0, 0,   0, -900 };

s16 cKF_ds_npc_1_keitai_on1_tbl[] = {
    1,  -1000, 0,    68, -1000, 0,    1,  1000, 0,     11, 1500, 0,     52, 1500, 0,     64, 2000, 0,    68, 2000, 0,
    1,  6000,  0,    68, 6000,  0,    1,  -450, 0,     11, -250, 0,     21, -450, 0,     68, -450, 0,    1,  0,    0,
    52, 0,     0,    56, 20,    82,   62, 20,   -82,   68, 0,    0,     1,  0,    0,     11, 0,    0,    52, 0,    0,
    56, 20,    84,   62, 20,    -81,  68, 0,    0,     1,  -175, 0,     68, -175, 0,     1,  -100, 0,    68, -100, 0,
    1,  25,    0,    68, 25,    0,    1,  0,    0,     68, 0,    0,     1,  200,  0,     68, 200,  0,    1,  0,    0,
    68, 0,     0,    1,  0,     0,    68, 0,    0,     1,  -100, 0,     68, -100, 0,     1,  0,    0,    68, 0,    0,
    1,  175,   0,    68, 175,   0,    1,  -100, 0,     68, -100, 0,     1,  -25,  0,     68, -25,  0,    1,  0,    0,
    68, 0,     0,    1,  200,   0,    68, 200,  0,     1,  0,    0,     68, 0,    0,     1,  0,    0,    68, 0,    0,
    1,  -100,  0,    68, -100,  0,    1,  0,    0,     68, 0,    0,     1,  0,    0,     68, 0,    0,    1,  60,   0,
    68, 60,    0,    1,  0,     0,    68, 0,    0,     1,  0,    0,     68, 0,    0,     1,  82,   0,    68, 82,   0,
    1,  0,     0,    68, 0,     0,    1,  0,    0,     6,  250,  693,   11, 300,  0,     17, 250,  -637, 23, 30,   -475,
    29, 0,     0,    52, 0,     0,    64, -80,  0,     68, -80,  0,     1,  2,    0,     11, -300, 0,    19, -150, 0,
    28, -200,  0,    52, -230,  0,    64, 50,   0,     68, 50,   0,     1,  0,    0,     11, -150, 0,    17, -110, 462,
    23, -50,   68,   29, -50,   0,    33, -70,  0,     36, -50,  0,     40, -70,  0,     44, -50,  0,    48, -70,  0,
    52, -50,   0,    64, -100,  0,    68, -100, 0,     1,  0,    0,     11, 0,    0,     29, 150,  991,  33, 280,  0,
    36, 150,   0,    40, 280,   0,    44, 150,  0,     48, 280,  0,     52, 150,  0,     64, 0,    0,    68, 0,    0,
    1,  58,    0,    11, 50,    0,    29, -580, -1062, 33, -650, 0,     36, -710, 0,     40, -760, 0,    44, -650, 0,
    48, -710,  0,    52, -580,  0,    64, 50,   0,     68, 50,   0,     1,  -564, -235,  11, -650, 0,    29, -550, 0,
    33, -680,  0,    36, -550,  0,    40, -680, 0,     44, -550, 0,     48, -680, 0,     52, -550, 0,    64, -650, 0,
    68, -650,  0,    1,  0,     0,    68, 0,    0,     1,  -57,  0,     11, -250, 0,     29, -500, 0,    33, -370, 0,
    36, -500,  0,    40, -370,  0,    44, -500, 0,     48, -370, 0,     52, -500, 0,     64, -250, 0,    68, -250, 0,
    1,  0,     0,    11, 0,     0,    29, -250, 0,     52, -250, 0,     64, 0,    0,     68, 0,    0,    1,  0,    0,
    11, -500,  0,    18, -50,   0,    33, -300, 0,     53, -300, 0,     64, 600,  0,     68, 600,  0,    1,  58,   0,
    11, -750,  0,    18, -700,  508,  33, -500, 0,     53, -500, 0,     64, -200, 0,     68, -200, 0,    1,  564,  0,
    11, 1050,  0,    18, 400,   0,    33, 650,  0,     53, 650,  0,     64, -100, 0,     68, -100, 0,    1,  0,    0,
    64, 0,     0,    68, 0,     0,    1,  -57,  0,     11, -250, 0,     22, -280, -298,  33, -500, 0,    53, -500, 0,
    64, -350,  0,    68, -350,  0,    1,  0,    0,     11, 350,  0,     18, 320,  -434,  26, 200,  0,    33, 250,  0,
    53, 250,   0,    64, 0,     0,    68, 0,    0,     1,  0,    0,     11, 0,    0,     21, -250, 0,    31, -230, 0,
    37, -250,  0,    41, -230,  0,    45, -250, 0,     49, -230, 0,     53, -250, 0,     58, 100,  1478, 66, 150,  -728,
    68, 150,   0,    1,  0,     0,    11, 900,  0,     21, 0,    -3194, 26, -300, 0,     31, -285, 0,    37, -275, 0,
    41, -285,  0,    45, -275,  0,    49, -285, 0,     53, -275, 0,     58, -50,  1461,  68, 100,  0,    1,  0,    0,
    11, 0,     0,    21, 350,   1002, 31, 500,  0,     53, 500,  0,     58, 220,  -1548, 68, 50,   0,    1,  0,    0,
    6,  220,   1243, 11, 300,   0,    20, 50,   -531,  29, 0,    0,     52, 0,    0,     59, -30,  -217, 66, -50,  0,
    68, -50,   0,    1,  0,     0,    11, -50,  0,     20, 50,   0,     29, -100, -277,  33, -120, 0,    36, -100, 0,
    40, -120,  0,    44, -100,  0,    48, -120, 0,     52, -100, 205,   59, -60,  375,   68, 50,   0,    1,  0,    0,
    11, -50,   0,    20, -20,   129,  29, 0,    0,     33, 20,   0,     36, 0,    0,     40, 20,   0,    44, 0,    0,
    48, 20,    0,    52, 0,     0,    59, 50,   148,   66, 50,   0,     68, 50,   0,     1,  0,    0,    68, 0,    0,
    1,  0,     0,    68, 0,     0,    1,  0,    0,     68, 0,    0
};

aNPC_Animation_c cKF_ba_r_npc_1_keitai_on1 = {
    { cKF_ckcb_r_npc_1_keitai_on1_tbl, cKF_ds_npc_1_keitai_on1_tbl, cKF_kn_npc_1_keitai_on1_tbl,
      cKF_c_npc_1_keitai_on1_tbl, -1, 68 },
    1.0f,
    68.0f,
    cKF_FRAMECONTROL_STOP,
    -5.0f,
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
