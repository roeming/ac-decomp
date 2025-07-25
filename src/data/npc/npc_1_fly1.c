#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

u8 cKF_ckcb_r_npc_1_fly1_tbl[] = { 56, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 7, 7, 0, 7, 0, 0 };

s16 cKF_kn_npc_1_fly1_tbl[] = { 2, 2, 2, 4, 5, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                2, 2, 2, 4, 5, 3, 2, 5, 9, 2, 2, 6, 2, 5, 9, 2, 2, 6, 2, 2, 2, 2, 5, 2, 2, 2, 2 };

s16 cKF_c_npc_1_fly1_tbl[] = { 3600, 0, 900, 0,   0, 1800, 0, 0, 1800, 0, 900, 0, 0,   0,
                               -900, 0, 0,   900, 0, -900, 0, 0, 0,    0, 0,   0, -900 };

s16 cKF_ds_npc_1_fly1_tbl[] = {
    1,  0,    0,     17, 0,    0,     1,  1000, 0,    17, 1000, 0,   1,  0,    0,     17, 0,    0,    1,  0,    441,
    5,  60,   0,     13, -60,  0,     17, 0,    457,  1,  -220, 0,   5,  -270, 0,     9,  -220, 0,    13, -270, 0,
    17, -220, 0,     1,  -70,  0,     9,  70,   0,    17, -70,  0,   1,  -100, 0,     17, -100, 0,    1,  100,  0,
    17, 100,  0,     1,  100,  0,     17, 100,  0,    1,  0,    0,   17, 0,    0,     1,  250,  0,    17, 250,  0,
    1,  0,    0,     17, 0,    0,     1,  0,    0,    17, 0,    0,   1,  200,  0,     17, 200,  0,    1,  0,    0,
    17, 0,    0,     1,  100,  0,     17, 100,  0,    1,  100,  0,   17, 100,  0,     1,  -100, 0,    17, -100, 0,
    1,  0,    0,     17, 0,    0,     1,  250,  0,    17, 250,  0,   1,  0,    0,     17, 0,    0,    1,  0,    0,
    17, 0,    0,     1,  200,  0,     17, 200,  0,    1,  0,    0,   17, 0,    0,     1,  0,    0,    17, 0,    0,
    1,  60,   0,     17, 60,   0,     1,  0,    0,    17, 0,    0,   1,  0,    0,     17, 0,    0,    1,  82,   0,
    17, 80,   0,     1,  0,    0,     17, 0,    0,    1,  0,    480, 5,  -60,  0,     13, 60,   0,    17, 0,    0,
    1,  -40,  0,     5,  60,   0,     9,  -40,  0,    13, 60,   0,   17, -40,  0,     1,  50,   0,    9,  -50,  0,
    17, 50,   0,     1,  -100, 0,     17, -100, 0,    1,  -100, 0,   5,  100,  0,     9,  -100, 0,    13, 100,  0,
    17, -100, 0,     1,  -600, 0,     3,  -300, 6843, 5,  300,  0,   7,  -50,  -7497, 9,  -600, 0,    11, -300, 6843,
    13, 300,  0,     15, -50,  -7497, 17, -600, 0,    1,  0,    0,   17, 0,    0,     1,  -57,  0,    17, -57,  0,
    1,  0,    -5163, 3,  -300, 0,     6,  600,  0,    11, -300, 0,   14, 600,  0,     17, 0,    0,    1,  100,  0,
    17, 100,  0,     1,  -100, 0,     5,  100,  0,    9,  -100, 0,   13, 100,  0,     17, -100, 0,    1,  600,  0,
    3,  300,  -7363, 5,  -300, 0,     7,  50,   6314, 9,  600,  0,   11, 300,  -7363, 13, -300, 0,    15, 50,   6314,
    17, 600,  0,     1,  0,    0,     17, 0,    0,    1,  -57,  0,   17, -57,  0,     1,  0,    6004, 3,  300,  0,
    6,  -600, 0,     11, 300,  0,     14, -600, 0,    17, 0,    0,   1,  0,    0,     17, 0,    0,    1,  0,    0,
    17, 0,    0,     1,  0,    0,     17, 0,    0,    1,  0,    0,   17, 0,    0,     1,  60,   0,    5,  110,  0,
    9,  60,   0,     13, 110,  0,     17, 60,   0,    1,  0,    0,   17, 0,    0,     1,  0,    0,    17, 0,    0,
    1,  0,    0,     17, 0,    0,     1,  0,    0,    17, 0,    0
};

static int other_se_chk_pat[] = { 5, 13 };

static aNPC_other_se_data_c other_se_dt[] = { { { ARRAY_COUNT(other_se_chk_pat), other_se_chk_pat }, 290 } };

static aNPC_se_data_table_c se_dt_tbl[] = { { NULL, NULL, aNPC_OTHER_SE_TYPE1, other_se_dt } };

aNPC_Animation_c cKF_ba_r_npc_1_fly1 = {
    { cKF_ckcb_r_npc_1_fly1_tbl, cKF_ds_npc_1_fly1_tbl, cKF_kn_npc_1_fly1_tbl, cKF_c_npc_1_fly1_tbl, -1, 17 },
    1.0f,
    17.0f,
    cKF_FRAMECONTROL_REPEAT,
    -5.0f,
    NULL,
    aNPC_EYE_TEX1,
    -1,
    NULL,
    aNPC_MOUTH_TEX0,
    0,
    -1,
    -1,
    NULL,
    se_dt_tbl,
};
