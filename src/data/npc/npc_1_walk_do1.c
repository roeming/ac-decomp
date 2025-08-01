#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

u8 cKF_ckcb_r_npc_1_walk_do1_tbl[] = { 56, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 7, 7, 0, 7, 0, 0 };

s16 cKF_kn_npc_1_walk_do1_tbl[] = { 2, 7, 2, 5, 7, 5, 7, 6, 7, 2, 7, 2, 2, 8, 5, 7, 6, 7, 2, 8, 2, 2, 8, 6, 2, 7, 2,
                                    2, 7, 2, 6, 6, 6, 2, 9, 7, 2, 5, 2, 2, 9, 7, 2, 5, 2, 2, 2, 2, 2, 9, 2, 3, 3, 3 };

s16 cKF_c_npc_1_walk_do1_tbl[] = { 0,    0, 900, 0,   0, 1800, 0, 0, 1800, 0, 900, 0, 0,   0,
                                   -900, 0, 0,   900, 0, -900, 0, 0, 0,    0, 0,   0, -900 };

s16 cKF_ds_npc_1_walk_do1_tbl[] = {
    1,  0,    0,     17, 0,    0,     1,  913,  0,     5,  1000, 0,     7,  988,  -596,  9,  913,  0,
    13, 1000, 0,     15, 988,  -633,  17, 913,  0,     1,  0,    0,     17, 0,    0,     1,  0,    0,
    5,  50,   0,     9,  0,    0,     13, -50,  0,     17, 0,    0,     1,  0,    0,     5,  115,  0,
    7,  85,   -1035, 9,  0,    0,     13, 115,  0,     15, 85,   -1051, 17, 0,    0,     1,  0,    0,
    5,  -60,  0,     9,  0,    0,     13, 60,   0,     17, 0,    0,     1,  -175, 0,     5,  -100, 751,
    9,  -50,  0,     11, -100, -2279, 13, -310, -2405, 15, -380, 0,     17, -175, 0,     1,  -350, 0,
    5,  50,   3514,  9,  300,  -1136, 13, -500, -4004, 15, -600, 990,   17, -350, 0,     1,  100,  0,
    5,  150,  0,     9,  15,   0,     11, 50,   2228,  13, 260,  2425,  15, 330,  0,     17, 100,  0,
    1,  0,    0,     17, 0,    0,     1,  450,  0,     3,  500,  1997,  5,  650,  0,     8,  500,  0,
    11, 650,  0,     14, 300,  0,     17, 450,  0,     1,  0,    0,     17, 0,    0,     1,  0,    0,
    17, 0,    0,     1,  -100, 0,     3,  -200, -2974, 5,  -375, 0,     8,  -275, 0,     11, -380, 0,
    13, -100, 3774,  15, 0,    0,     17, -100, 0,     1,  0,    0,     5,  -125, -1749, 8,  -275, 0,
    13, 0,    0,     17, 0,    0,     1,  50,   0,     3,  100,  2216,  5,  310,  2393,  7,  380,  0,
    9,  175,  0,     13, 100,  -750,  17, 50,   0,     1,  250,  -1136, 5,  -500, -4038, 7,  -600, 998,
    9,  -350, 0,     13, 50,   3509,  17, 300,  -1118, 1,  -15,  0,     3,  -50,  -1882, 5,  -260, -2384,
    7,  -330, 0,     9,  -100, 0,     13, -150, 0,     17, -15,  0,     1,  0,    0,     17, 0,    0,
    1,  550,  2259,  3,  650,  0,     6,  300,  0,     9,  450,  0,     11, 500,  2010,  13, 650,  0,
    16, 500,  0,     17, 550,  2252,  1,  0,    0,     17, 0,    0,     1,  0,    0,     17, 0,    0,
    1,  -275, 0,     3,  -375, 0,     5,  -100, 3793,  7,  0,    0,     9,  -100, 0,     11, -180, -2197,
    14, -375, 0,     17, -275, 0,     1,  250,  -1502, 5,  0,    0,     9,  0,    0,     13, 125,  1323,
    16, 275,  0,     17, 250,  -1496, 1,  0,    0,     17, 0,    0,     1,  -250, -1521, 3,  -350, 0,
    6,  -150, 0,     9,  -250, -1502, 11, -350, 0,     14, -150, 0,     17, -250, -1512, 1,  0,    0,
    17, 0,    0,     1,  0,    0,     17, 0,    0,     1,  30,   -1624, 4,  -50,  0,     7,  100,  0,
    9,  30,   -1572, 12, -50,  0,     15, 100,  0,     17, 30,   -1563, 1,  0,    0,     17, 0,    0,
    1,  8,    -430,  2,  0,    0,     6,  -50,  0,     10, 0,    0,     14, 50,   0,     17, 8,    -430,
    1,  -193, -423,  2,  -200, 0,     6,  -150, 0,     10, -200, 0,     14, -150, 0,     17, -193, -423,
    1,  -12,  665,   2,  0,    0,     6,  80,   0,     10, 0,    0,     14, -80,  0,     17, -12,  665,
    1,  450,  0,     17, 450,  0,     1,  0,    -1022, 3,  30,   1309,  5,  150,  752,   7,  120,  -1355,
    9,  0,    -765,  11, 30,   1306,  13, 150,  751,   15, 120,  -1338, 17, 0,    -1022, 1,  -450, 0,
    4,  -250, 1454,  7,  -280, -1988, 9,  -450, 0,     12, -250, 1474,  15, -280, -1997, 17, -450, 0,
    1,  0,    0,     17, 0,    0,     1,  -450, 0,     5,  -550, 0,     9,  -450, 0,     13, -550, 0,
    17, -450, 0,     1,  0,    0,     17, 0,    0,     1,  -450, 0,     17, -450, 0,     1,  0,    -1022,
    3,  30,   1309,  5,  150,  752,   7,  120,  -1355, 9,  0,    -765,  11, 30,   1306,  13, 150,  751,
    15, 120,  -1338, 17, 0,    -1022, 1,  450,  0,     4,  250,  -1523, 7,  280,  2003,  9,  450,  0,
    12, 250,  -1494, 15, 280,  2034,  17, 450,  0,     1,  0,    0,     17, 0,    0,     1,  -450, 0,
    5,  -550, 0,     9,  -450, 0,     13, -550, 0,     17, -450, 0,     1,  0,    0,     17, 0,    0,
    1,  1800, 0,     17, 1800, 0,     1,  150,  0,     17, 150,  0,     1,  0,    0,     17, 0,    0,
    1,  0,    0,     17, 0,    0,     1,  150,  0,     3,  30,   -1204, 5,  0,    0,     7,  80,   2100,
    9,  150,  0,     11, 30,   -1208, 13, 0,    0,     15, 80,   2102,  17, 150,  0,     1,  0,    0,
    17, 0,    0,     1,  0,    0,     9,  0,    0,     17, 0,    0,     1,  0,    0,     9,  0,    0,
    17, 0,    0,     1,  0,    0,     9,  0,    0,     17, 0,    0
};

static u32 feel_eff_set[] = { 20 };

static aNPC_feel_effect_c feel_eff[] = { { mNpc_FEEL_ANGRY, 20, ARRAY_COUNT(feel_eff_set), feel_eff_set } };

static int lfoot_se_chk_pat[] = { 1 };

static aNPC_se_data_c lfoot_se_dt[] = { { ARRAY_COUNT(lfoot_se_chk_pat), lfoot_se_chk_pat } };

static int rfoot_se_chk_pat[] = { 9 };

static aNPC_se_data_c rfoot_se_dt[] = { { ARRAY_COUNT(rfoot_se_chk_pat), rfoot_se_chk_pat } };

static aNPC_se_data_table_c se_dt_tbl[] = { { lfoot_se_dt, rfoot_se_dt, aNPC_OTHER_SE_TYPE_NONE, NULL } };

aNPC_Animation_c cKF_ba_r_npc_1_walk_do1 = {
    { cKF_ckcb_r_npc_1_walk_do1_tbl, cKF_ds_npc_1_walk_do1_tbl, cKF_kn_npc_1_walk_do1_tbl, cKF_c_npc_1_walk_do1_tbl, -1,
      17 },
    1.0f,
    17.0f,
    cKF_FRAMECONTROL_REPEAT,
    -5.0f,
    NULL,
    aNPC_EYE_TEX0,
    3,
    NULL,
    aNPC_MOUTH_TEX0,
    3,
    -1,
    eEC_EFFECT_PUN_YUGE,
    feel_eff,
    se_dt_tbl,
};
