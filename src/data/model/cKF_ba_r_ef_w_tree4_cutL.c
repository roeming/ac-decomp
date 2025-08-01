#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

u8 cKF_ckcb_r_ef_w_tree4_cutL_tbl[] = { 0, 7, 7, 3 };

s16 cKF_kn_ef_w_tree4_cutL_tbl[] = { 8, 12, 10, 10, 12, 10, 4, 20 };

s16 cKF_c_ef_w_tree4_cutL_tbl[] = { -750, 0, 0, 0, 0, 900, 0 };

s16 cKF_ds_ef_w_tree4_cutL_tbl[] = {
    1,    0,    0,    9,    0,    14,  22,   123,  472, 32,   285,  445, 34,   309,  165,  38,   294,  -132, 45,   300,
    13,   49,   300,  0,    1,    0,   -476, 5,    -47, -144, 6,    -50, -232, 7,    -63,  -556, 8,    -87,  -556, 9,
    -100, -196, 10,   -100, -8,   32,  -278, -622, 34,  -314, -220, 37,  -300, 203,  45,   -300, -12,  49,   -300, 0,
    1,    0,    722,  3,    43,   389, 5,    55,   264, 8,    95,   264, 11,   102,  57,   32,   287,  389,  35,   312,
    -18,  38,   292,  -167, 45,   300, 16,   49,   300, 0,    1,    0,   0,    11,   0,    17,   32,   528,  2065, 33,
    600,  1752, 34,   645,  675,  36,  623,  -675, 37,  600,  -512, 40,  582,  28,   45,   600,  25,   49,   600,  0,
    1,    0,    476,  5,    47,   144, 6,    50,   232, 7,    63,   556, 8,    87,   556,  9,    100,  204,  10,   101,
    37,   32,   378,  659,  34,   415, 246,  38,   392, -172, 45,   400, 17,   49,   400,  0,    1,    0,    -722, 3,
    -43,  -389, 5,    -55,  -264, 8,   -95,  -264, 11,  -95,  137,  32,  366,  1007, 34,   422,  378,  38,   388,  -275,
    45,   400,  27,   49,   400,  0,   1,    0,    0,   13,   0,    -11, 37,   -150, -11,  49,   -150, 0,    1,    0,
    -836, 2,    -28,  -600, 3,    -40, -41,  6,    11,  450,  7,    20,  70,   10,   -5,   -225, 11,   -10,  5,    13,
    0,    12,   22,   -146, -234, 25,  -150, 0,    32,  -150, 0,    34,  -136, 739,  38,   26,   739,  39,   40,   70,
    42,   -11,  -450, 43,   -20,  -70, 46,   5,    225, 47,   10,   -5,  48,   5,    -150, 49,   0,    -150
};

cKF_Animation_R_c cKF_ba_r_ef_w_tree4_cutL = { cKF_ckcb_r_ef_w_tree4_cutL_tbl,
                                               cKF_ds_ef_w_tree4_cutL_tbl,
                                               cKF_kn_ef_w_tree4_cutL_tbl,
                                               cKF_c_ef_w_tree4_cutL_tbl,
                                               -1,
                                               49 };
