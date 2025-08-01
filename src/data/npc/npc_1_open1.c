#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"
#include "ef_effect_control.h"

u8 cKF_ckcb_r_npc_1_open1_tbl[] = { 56, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 7, 0, 7, 7, 0, 7, 7, 7, 7, 0, 7, 0, 0 };

s16 cKF_kn_npc_1_open1_tbl[] = { 6, 4,  6, 6, 5,  4,  13, 11, 12, 2, 12, 2, 2, 18, 15, 13, 18, 13,
                                 2, 18, 2, 2, 16, 13, 2,  5,  7,  2, 5,  7, 5, 6,  4,  4,  4,  5,
                                 2, 7,  2, 4, 7,  7,  2,  7,  2,  2, 2,  2, 6, 6,  7,  2,  2,  2 };

s16 cKF_c_npc_1_open1_tbl[] = { 0,    0, 900, 0,   0, 1800, 0, 0, 1800, 0, 900, 0, 0,   0,
                                -900, 0, 0,   900, 0, -900, 0, 0, 0,    0, 0,   0, -900 };

s16 cKF_ds_npc_1_open1_tbl[] = {
    1,  0,     0,     8,  800,  4401,  17, 1550,  0,     39, 1000,  -1600,  44, 550,  -4126, 51, 0,    0,
    1,  1000,  0,     8,  1100, 0,     42, 1100,  0,     51, 1000,  0,      1,  0,    0,     10, -750, -5521,
    20, -2300, 0,     33, 200,  9358,  42, 3000,  9627,  51, 5000,  1962,   1,  0,    0,     8,  470,  0,
    16, 0,     -1854, 24, -300, -939,  47, -1500, -1862, 51, -1650, 0,      1,  0,    0,     8,  -50,  0,
    19, 55,    443,   34, 150,  0,     51, 0,     0,     1,  0,     0,      23, 0,    0,     34, 150,  0,
    51, 0,     0,     1,  -175, 0,     8,  -227,  0,     11, -140,  962,    17, 26,   435,   20, 40,   124,
    24, 154,   2686,  25, 260,  0,     27, 154,   -3482, 29, -107,  -3171,  36, -420, 0,     39, 0,    6820,
    41, 350,   2582,  51, 600,  0,     1,  -100,  0,     8,  105,   0,      12, -19,  -1578, 14, -115, -119,
    20, -110,  444,   23, 129,  3300,  27, 371,   1032,  29, 423,   0,      36, -112, -2185, 43, -400, -451,
    51, -300,  0,     1,  25,   0,     8,  264,   0,     12, -12,   -2423,  17, -135, 500,   20, 18,   1807,
    24, 260,   1777,  25, 291,  0,     27, 217,   -1525, 36, 92,    0,      37, -29,  -3273, 44, -400, -386,
    51, -300,  0,     1,  0,    0,     51, 0,     0,     1,  200,   0,      8,  0,    0,     12, 249,  3437,
    13, 290,   391,   14, 285,  -366,  17, 0,     0,     23, 74,    1125,   25, 274,  4472,  27, 462,  276,
    29, 430,   -1140, 36, 0,    0,     51, 0,     0,     1,  0,     0,      51, 0,    0,     1,  0,    0,
    51, 0,     0,     1,  -100, 0,     8,  85,    0,     11, -191,  -3067,  12, -259, 0,     16, 58,   4969,
    17, 156,   610,   20, 168,  -411,  21, 96,    -2380, 24, -154,  -2458,  25, -218, 0,     27, -75,  4052,
    29, 203,   199,   32, 101,  0,     35, 210,   0,     38, 104,   0,      40, 302,  3867,  41, 345,  0,
    51, 200,   0,     1,  -5,   0,     8,  -275,  0,     11, -117,  2696,   13, 83,   2020,  16, 145,  -157,
    18, 87,    -2225, 22, -185, -1819, 25, -283,  -199,  27, -115,  2564,   29, 0,    0,     32, -86,  -1107,
    36, -218,  0,     37, -56,  3014,  40, 50,    0,     51, 50,    0,      1,  175,  0,     8,  700,  0,
    12, 500,   -1544, 15, 364,  -556,  18, 315,   -479,  20, 285,   -467,   30, -100, 0,     32, 99,   0,
    33, 28,    -700,  34, 55,   2700,  35, 330,   1259,  45, 709,   936,    51, 800,  0,     1,  -100, 0,
    7,  210,   0,     8,  215,  2009,  12, 397,   153,   15, 321,   -1848,  17, 140,  -3701, 18, 9,    -4242,
    20, -162,  0,     22, 1,    0,     28, -400,  0,     30, -350,  0,      32, -529, -2013, 33, -550, 0,
    34, -472,  1203,  36, -420, 703,   40, -193,  2029,  45, 310,   1645,   51, 400,  0,     1,  -25,  0,
    8,  -392,  0,     12, -45,  0,     15, -155,  -1011, 18, -210,  -35,    20, -174, 2014,  29, 153,  -272,
    32, -138,  -5105, 34, -443, -4456, 35, -553,  0,     40, -384,  2338,   45, -47,  798,   51, 0,    0,
    1,  0,     0,     51, 0,    0,     1,  200,   0,     8,  0,     0,      12, 239,  1853,  15, 190,  -3086,
    17, 86,    0,     18, 174,  3799,  19, 319,   3819,  20, 416,   512,    22, 440,  221,   26, 150,  -2144,
    30, 0,     0,     32, 519,  5401,  33, 574,   -241,  34, 372,   -11382, 36, 0,    0,     40, 542,  1061,
    45, 501,   -1422, 51, 0,    0,     1,  0,     0,     51, 0,     0,      1,  0,    0,     51, 0,    0,
    1,  -100,  0,     8,  380,  0,     12, -186,  -2461, 15, -179,  1343,   17, -50,  984,   19, -78,  -1512,
    22, -355,  0,     29, 280,  0,     32, -68,   -2706, 33, -106,  0,      34, 0,    8261,  35, 330,  4742,
    36, 400,   0,     40, -308, -2501, 45, -320,  1583,  51, 0,     0,      1,  5,    0,     7,  225,  0,
    8,  225,   674,   15, 305,  0,     17, 226,   -2212, 22, -59,   -688,   29, -220, -679,  30, -240, 0,
    32, -124,  3536,  34, 234,  605,   35, 234,   -237,  40, 155,   -541,   51, 140,  0,     1,  0,    0,
    51, 0,     0,     1,  60,   0,     15, 200,   0,     29, -150,  0,      39, -50,  734,   51, 200,  0,
    1,  0,     0,     8,  210,  253,   15, 250,   0,     23, -250,  0,      35, 300,  1691,  43, 450,  0,
    51, 450,   0,     1,  0,    0,     51, 0,     0,     1,  82,    0,      17, 200,  0,     27, 110,  -822,
    38, -300,  0,     51, 200,  0,     1,  0,     0,     8,  210,   253,    17, 250,  0,     25, -250, 0,
    29, 150,   2560,  38, 450,  0,     51, 450,   0,     1,  0,     0,      8,  100,  0,     21, -115, -872,
    34, -300,  -228,  51, -400, 0,     1,  0,     0,     8,  10,    0,      18, 30,   0,     27, -80,  0,
    37, 100,   0,     51, 0,    0,     1,  0,     0,     21, 0,     0,      37, -245, 0,     51, 0,    0,
    1,  0,     0,     8,  350,  0,     31, 80,    -311,  51, 0,     0,      1,  58,   316,   8,  -80,  0,
    30, 450,   0,     51, 60,   0,     1,  -564,  240,   8,  -300,  0,      22, -450, 0,     30, -200, 0,
    51, -410,  0,     1,  0,    0,     51, 0,     0,     1,  -55,   0,      8,  -230, -783,  11, -380, -2772,
    17, -700,  0,     26, -310, 1715,  35, -55,   0,     51, -55,   0,      1,  0,    0,     51, 0,    0,
    1,  0,     0,     24, 0,    0,     39, 400,   759,   51, 570,   0,      1,  58,   0,     15, -300, 0,
    22, -150,  749,   29, -200, -1465, 34, -480,  -1038, 39, -550,  0,      51, -550, 0,     1,  564,  0,
    12, -180,  0,     20, 50,   1486,  24, 150,   0,     29, 20,    -1861,  34, -200, 0,     51, -200, 0,
    1,  0,     0,     51, 0,    0,     1,  -60,   0,     7,  -350,  0,      12, -100, 0,     18, -250, 0,
    31, -100,  509,   40, 0,    0,     51, -35,   0,     1,  0,     0,      51, 0,    0,     1,  0,    0,
    51, 0,     0,     1,  0,    0,     51, 0,     0,     1,  0,     0,      51, 0,    0,     1,  0,    0,
    8,  -400,  0,     20, 25,   0,     32, -300,  -1093, 39, -450,  0,      51, -300, 0,     1,  0,    0,
    20, 0,     0,     32, 50,   -93,   39, -35,   -256,  44, -48,   122,    51, 0,    0,     1,  0,    0,
    8,  0,     0,     20, -30,  -60,   32, 15,    472,   39, 135,   215,    44, 110,  -468,  51, 0,    0,
    1,  0,     0,     51, 0,    0,     1,  0,     0,     51, 0,     0,      1,  0,    0,     51, 0,    0
};

aNPC_Animation_c cKF_ba_r_npc_1_open1 = {
    { cKF_ckcb_r_npc_1_open1_tbl, cKF_ds_npc_1_open1_tbl, cKF_kn_npc_1_open1_tbl, cKF_c_npc_1_open1_tbl, -1, 51 },
    1.0f,
    51.0f,
    cKF_FRAMECONTROL_STOP,
    -10.0f,
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
