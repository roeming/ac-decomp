#include "jaudio_NES/game64_cpp.h"
#include "m_name_table.h"

#include "../src/static/jaudio_NES/game/OSAttention.c"
#include "jaudio_NES/audiowork.h"
#include "jaudio_NES/sub_sys.h"
#include "jaudio_NES/staff.h"
#include "jaudio_NES/kappa.h"
#include "jaudio_NES/rhythm.h"
#include "jaudio_NES/melody.h"
#include "jaudio_NES/dummyrom.h"
#include "jaudio_NES/dvdthread.h"
#include "jaudio_NES/verysimple.h"
#include "jaudio_NES/neosthread.h"

typedef struct SOU_LEV_ONGEN_DATA {
    u8 _00;
    u8 _01;
    u8 _02;
    u8 _03;
    u32 _04;
    u8 _08;
    u8 _09;
    f32 _0C;
    f32 _10;
} SOU_LEV_ONGEN_DATA;

typedef struct SOU_LS_STACK {
    u8 _0;
    u8 _1;
    u8 _2;
    u8 _3;
    u8 _4;
    u8 _5;
    u8 _6;
    u8 _7;
} SOU_LS_STACK;

typedef struct SOU_LEV_SE {
    u8 _00;
    u8 _01;
    u8 _02;
    u8 _03;
    u8 _04;
    u8 _05;
    u8 _06;
    u8 _07;
    f32 _08;
    f32 _0C;
    u8 _10;
    u8 _11;
    u8 _12;
    u8 _13;
} SOU_LEV_SE;

typedef struct SOU_ONGEN_ENTRY {
    u32 _00;
    u8 _04;
    u16 _06;
    u8 _08;
    u8 _09;
    u8 _0A;
    f32 _0C;
} SOU_ONGEN_ENTRY;

typedef struct SOU_TRG_SE {
    u16 _00;
    u32 _04;
    f32 _08;
    f32 _0C;
    f32 _10;
    f32 _14;
    u8 _18;
    u8 _19;
    u8 _1A;
    u8 _1B;
    u8 _1C;
    u8 _1D;
} SOU_TRG_SE;

typedef struct SOU_SE_FADE {
    u16 _0;
    u16 _2;
    u16 _4;
    u16 _6;
    f32 _8;
} SOU_SE_FADE;

typedef struct SOU_VOICE_SE {
    u8 _00;
    u32 _04;
    f32 _08;
    f32 _0C;
    f32 _10;
    f32 _14;
    f32 _18;
    f32 _1C;
    u8 _20;
    u8 _21;
} SOU_VOICE_SE;

typedef struct SOU_ROOM_INS {
    u32 _00;
    u8 _04;
    u8 _05;
    u8 _06;
    u8 _07;
} SOU_ROOM_INS;

typedef struct SOU_SYS_LEV {
    u8 _0;
    u8 _1;
    u8 _2;
} SOU_SYS_LEV;

// clang-format off
static const u8 SEQ_TABLE[256] = {
    247,  81,  82,  83,
    84,  85,  86,  87,
    88,  89,  90,  91,
    92,  93,  94,  95,
    96,  97,  98,  99,
    100, 101, 102, 103,
    104, 176, 178, 218,
    219, 220, 222, 223,
    224, 225, 226, 227,
    229, 169, 170, 171,
    68, 166,  60,  59,
    168, 177,  74,  62,
    63,  64,  65,  66,
    67, 214, 215, 216,
    217, 228,  57, 231,
    221, 230, 167,  70,
    71,  73,  75,  78,
    79, 105,  58,  69,
    72, 232, 233, 234,
    235, 179,  76, 172,
    173, 174, 175, 247,
    247, 247, 247, 247,
    180, 181, 182, 183,
    184, 185, 186, 187,
    188, 189, 190, 191,
    192, 193, 194, 195,
    196, 197, 198, 199,
    200, 201, 202, 203,
    204, 205, 206, 207,
    208, 209, 210, 211,
    212, 213,  77,  61,
    77,  80, 247, 247,
    111, 112, 113, 114,
    115, 116, 117, 118,
    119, 120, 121, 122,
    123, 124, 125, 126,
    127, 128, 129, 130,
    131, 132, 133, 134,
    135, 136, 137, 138,
    139, 140, 141, 142,
    143, 144, 145, 146,
    147, 148, 149, 150,
    151, 152, 153, 154,
    155, 156, 157, 158,
    159, 160, 161, 162,
    163, 164, 165, 247,
    247, 247, 247, 247,
    247, 247, 247, 247,
    0,   1,   2,   3,
    4,   5,   6,   7,
    8,   9,  10,  11,
    12,  13,  14,  15,
    16,  17,  18,  19,
    20,  21,  22,  23,
    24,  25,  26,  27,
    28,  29,  30,  31,
    32,  33,  34,  35,
    36,  37,  38,  39,
    40,  41,  42,  43,
    44,  45,  46,  47,
    48,  49,  50,  51,
    52,  53,  54,  55,
    56,  57, 236, 237,
    241, 238, 240, 239
};

static const u16 SE_FLOOR_DATA[FLOOR_ALL_NUM] ATTRIBUTE_ALIGN(2) = {
    27, 27, 32, 31,
    28, 32, 31, 27,
    27, 28, 29, 29,
    27, 31, 28, 30,
    33, 27, 30, 27,
    32, 32, 31, 28,
    32, 27, 35, 32,
    32, 32, 27, 29,
    31, 32, 28, 28,
    28, 27, 28, 28,
    27, 31, 36, 32,
    28, 27, 33, 27,
    35, 28, 32, 32,
    28, 28, 32, 29,
    28, 33, 27, 32,
    33, 27, 32, 32,
    28, 32, 32, 34,
    32, 32, 27, 32,
    28, 27, 29, 27,
    28, 28, 27, 31,
    28, 31, 28, 32,
    28, 32, 32, 32,
    32, 32, 32, 32,
    32, 32, 32
};

// ATTRIBUTE_ALIGN(4)
static const u16 SE_ROOM_INS_DATA[] ATTRIBUTE_ALIGN(2) = {
    0x505, 0x509, 0x50D, 0x511,
    0x515, 0x519, 0x51D, 0x521,
    0x525, 0x529, 0x501, 0x52D,
    0x531, 0x535, 0x539, 0x53D,
    0
};

static const u16 SE_ROOM_INS_RANDOM_OFFSET[] = {
    11, 11, 11, 10,
    10, 10, 12, 100,
    20, 100, 45, 10,
    4, 9, 2, 1,
    0
};

static const u8 SHIIN2BOIN[] = {
    0,   1,   2,   3,
    4,   5,   1,   2,
    3,   4,   5,   1,
    2,   3,   4,   5,
    1,   2,   3,   4,
    5,   1,   2,   3,
    4,   5,   1,   2,
    3,   4,   5,   1,
    2,   3,   4,   5,
    1,   3,   5,   1,
    2,   3,   4,   5,
    1,  45,   1,   2,
    3,   4,   5,   1,
    2,   3,   4,   5,
    1,   4,   5,   1,
    2,   3,   4,   5,
    1,   2,   3,   4,
    5,   1,   2,   3,
    4,   5,   3,   1,
    3,   5,   0,   0,
    0,   0,   0,   0,
    0,   0
};

static const u8 TRGPRIO[] = {
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  50,  50,  50,
    50,  60,  60,  60,
    60,  60,  60,  60,
    60,  70,  70,  70,
    70,  70,  70,  70,
    70,  70,  70,  70,
    70,  70,  70,  70,
    70,  70,  70,  70,
    70,  70,  70,  70
};

static const SOU_TRG_SE sou_trg_se_init = {
   0,
   0,
   1.f,
   1.f,
   1.f,
   1.f,
   0x3f,
   0,
   0,
   0,
   0,
   0,
};

static const SOU_VOICE_SE sou_voice_se_init = {
    0,
    0,
    1.f,
    1.f,
    1.f,
    1.f,
    1.f,
    1.f,
    0x3f,
    0,
};

static const SOU_LEV_SE sou_lev_se_init = {
    0,0,0,0,
    0,0,0,0,
    0.f,
    1.f,
    0x3f,
    0,0,0
};

static const SOU_LEV_ONGEN_DATA sou_lev_ongen_data_init = {
    0,0,0,0,
    0,
    0,0,
    9999.f,
    9999.f
};

static const SOU_ONGEN_ENTRY sou_ongen_entry_init = {
    0,
    0,
    0,
    0x3f,
    0,
    0, 
    9999.f
};

static const SOU_SE_FADE sou_se_fade_init = {
    0,
    0,
    0,
    0,
    1.f
};

const SOU_LS_STACK sou_ls_stack_init = {
    0,0,0,0,
    0,0,0,0
};

const SOU_SYS_LEV sou_sys_lev_init = {
    0,0,0
};

const SOU_ROOM_INS sou_room_ins_init = {
    0,
    0,0,0,0
};

// unused
f32 OCTAVETABLE[] = {
    1.0, 
    1.059463, 
    1.122462, 
    1.189207,
    1.259921,
    1.33484,
    1.414214,
    1.498307,
    1.587401,
    1.681793,
    1.781797,
    1.887749,
};

u16 BGM_MUTE_TABLE_FINE[] = { 
    0x01e0, 0x0d80, 0x3800, 0x0500, 0x00e0, 0x01c0, 0x05e0, 0x3dc0,
    0x0d80, 0x0d80, 0x1800, 0x1d00, 0x1d80, 0x1d80, 0x01f0, 0x00f8,
    0x0d80, 0x7c00, 0xf200, 0x1d00, 0x1d00, 0x05e0, 0x0d80, 0x0dfc 
};

u16 BGM_MUTE_TABLE_SNOW[] = { 
    0x0302, 0x0c23, 0x216e, 0x040c, 0x0006, 0x0006, 0x0406, 0x381b,
    0x0803, 0x0c64, 0x1020, 0x1083, 0x1c02, 0x104f, 0x070e, 0x06c0,
    0x081d, 0x001b, 0x2023, 0x1017, 0x1803, 0x0006, 0x0c16, 0x0d82 
};


u16 BGM_MUTE_TABLE_SAKURA[] = { 
    0x00e2, 0x00a7, 0x116e, 0x001c, 0x0006, 0x0106, 0x018e, 0x01db,
    0x0107, 0x00ff, 0x0024, 0x0087, 0x0007, 0x0c4f, 0x00be, 0x0418,
    0x045f, 0x001b, 0xca07, 0x0517, 0x0107, 0x0106, 0x019f, 0x007b 
};

// clang-format on

// sou_ls_stack;

SOU_LS_STACK sou_ls_stack[6];
SOU_TRG_SE sou_trg_se[6];
SOU_VOICE_SE sou_voice_se[2];
SOU_LEV_SE sou_lev_se[6];
SOU_LEV_ONGEN_DATA sou_lev_ongen_data[4];
SOU_ONGEN_ENTRY sou_ongen_entry[50];
SOU_ROOM_INS sou_room_ins[50];
SOU_SE_FADE sou_se_fade[16];
SOU_SYS_LEV sou_sys_lev[2];

u8 sou_tenki;
f32 sou_bgm1_vol_now;
f32 sou_bgm2_vol_now;
bool sou_now_bgm_fadeout;
u8 sou_now_bgm_num;
f32 sou_kazaguruma_speed;
u8 sou_now_bgm_handle = 1;
u8 sou_out_mode;
u8 sou_message_speed;

void Sou_lev_ongen_data_struct_clear() {
    u8 i = 0;
    for (i = 0; i < ARRAY_COUNT(sou_lev_ongen_data); i++) {
        sou_lev_ongen_data[i]._00 = 0;
        sou_lev_ongen_data[i]._01 = 0;
        sou_lev_ongen_data[i]._02 = 0;
        sou_lev_ongen_data[i]._03 = 0;
        sou_lev_ongen_data[i]._04 = 0;
        sou_lev_ongen_data[i]._08 = 0;
        sou_lev_ongen_data[i]._09 = 0;
        sou_lev_ongen_data[i]._0C = 9999.f;
        sou_lev_ongen_data[i]._10 = 9999.f;
    }
    for (i = 0; i < ARRAY_COUNT(sou_ls_stack); i++) {
        sou_ls_stack[i]._0 = 0;
        sou_ls_stack[i]._1 = 0;
        sou_ls_stack[i]._2 = 0;
        sou_ls_stack[i]._3 = 0;
        sou_ls_stack[i]._4 = 0;
        sou_ls_stack[i]._5 = 0;
        sou_ls_stack[i]._6 = 0;
        sou_ls_stack[i]._7 = 0;
    }
    for (i = 0; i < ARRAY_COUNT(sou_lev_se); i++) {
        sou_lev_se[i]._00 = 0;
        sou_lev_se[i]._01 = 0;
        sou_lev_se[i]._02 = 0;
        sou_lev_se[i]._03 = 0;
        sou_lev_se[i]._04 = 0;
        sou_lev_se[i]._05 = 0;
        sou_lev_se[i]._06 = 0;
        sou_lev_se[i]._07 = 0;
        sou_lev_se[i]._08 = 0.f;
        sou_lev_se[i]._0C = 1.f;
        sou_lev_se[i]._10 = 0x3f;
        sou_lev_se[i]._11 = 0;
        sou_lev_se[i]._12 = 0;
        sou_lev_se[i]._13 = 0;
    }
    for (i = 0; i < ARRAY_COUNT(sou_ongen_entry); i++) {
        sou_ongen_entry[i]._00 = 0;
        sou_ongen_entry[i]._04 = 0;
        sou_ongen_entry[i]._06 = 0;
        sou_ongen_entry[i]._08 = 63;
        sou_ongen_entry[i]._09 = 0;
        sou_ongen_entry[i]._0A = 0;
        sou_ongen_entry[i]._0C = 9999.0f;
    }
}

void Sou_BgmFadeoutEndCheck() {
    if (sou_now_bgm_fadeout && !AG.groups[1].flags.enabled && !AG.groups[3].flags.enabled) {
        sou_now_bgm_num = 0;
        sou_now_bgm_fadeout = false;
    }
}

u8 Sou_BgmTenkiConv(u8 v) {
    Na_BgmMuteClear();
    if (v >= 1 && v <= 24) {
        switch (sou_tenki) {
            case 0: {
                Nap_SetU16(NA_MAKE_COMMAND(0x90, sou_now_bgm_handle, 0, 0), BGM_MUTE_TABLE_FINE[v - 1]);
                Nap_SetS8(NA_MAKE_COMMAND(8, sou_now_bgm_handle, 0xff, 0), 1);
            } break;
            case 1: {
                v = 0x45;
            } break;
            case 2: {
                Nap_SetU16(NA_MAKE_COMMAND(0x90, sou_now_bgm_handle, 0, 0), BGM_MUTE_TABLE_SNOW[v - 1]);
                Nap_SetS8(NA_MAKE_COMMAND(8, sou_now_bgm_handle, 0xff, 0), 1);
            } break;
            case 3: {
                Nap_SetU16(NA_MAKE_COMMAND(0x90, sou_now_bgm_handle, 0, 0), BGM_MUTE_TABLE_SAKURA[v - 1]);
                Nap_SetS8(NA_MAKE_COMMAND(8, sou_now_bgm_handle, 0xff, 0), 1);
            } break;
            case 4:
            default:
                break;
        }
    }
    return v;
}

void Sou_GroupControl(u8 a, u8 b, f32 c) {
    u8 i = 0;
    if (c > 1.f) {
        c = 1.f;
    }
    Nap_SetF32(NA_MAKE_COMMAND(0x41, a, 0, 0), c);
    if (a == 1) {
        sou_bgm1_vol_now = c;
    }
    if (a == 3) {
        sou_bgm2_vol_now = c;
    }
    for (i = 0; i < 16; i++) {
        Nap_SetS8(NA_MAKE_COMMAND(0x3, a, i, 0), b);
    }
}

void Sou_GroupControl_MD(u8 a, u8 b, f32 c) {
    u8 i = 0;
    if (c > 2.25f) {
        c = 2.25f;
    }
    Nap_SetF32(NA_MAKE_COMMAND(0x41, a, 0, 0), c);
    if (a == 1) {
        sou_bgm1_vol_now = c;
    }
    if (a == 3) {
        sou_bgm2_vol_now = c;
    }
    for (i = 0; i < 16; i++) {
        Nap_SetS8(NA_MAKE_COMMAND(0x3, a, i, 0), b);
    }
}

u8 pan_kochou(u8 a, f32 b) {
    s16 v = 0;
    switch (sou_out_mode) {
        case 0: {
            b = b * 1.6f;
        } break;
        case 2: {
            b = b * 0.75f;
        }; break;
        case 1: {
            return a;
        };
    }
    v = (s16)((a - 0x40) * b);
    if (v > 0x3f) {
        v = 0x3f;
    }
    if (v < -0x40) {
        v = -0x40;
    }
    return 0x40 + v;
}

u8 angle2pan(u16 angle, f32 dist) {
    u8 a = 0;
    f32 v = 1.f;
    angle >>= 8;
    if (angle >= 0x40 && angle <= 0xc0) {
        a = 0x80 - (angle - 0x40);
        if (a == 0x80) {
            a = 0x7f;
        }
    } else if (angle >= 0xc1) {
        a = angle - 0xc0;
    } else {
        a = angle + 0x40;
    }
    a = pan_kochou(a, v);
    return a;
}

f32 SOU_ONGEN_AREA1 = 540.f;
f32 SOU_ONGEN_AREA2 = 533.f;
f32 distance2vol(f32 distance) {
    f32 ret = 0.f;
    if (distance > SOU_ONGEN_AREA1) {
        return 0.f;
    }

    ret = 1.15f - (1.15f / SQ(SOU_ONGEN_AREA1)) * SQ(distance);
    if (ret > 1.5f) {
        if (ret > 1.5f) {
            ret = 1.5f;
        }
        ret = 1.5f;
    }
    return ret;
}

f32 distance2vol4KITEKI(f32 v) {
    f32 v2 = 0.f;
    if (v > 320.f) {
        v2 = 1.15f;
    }
    if (v < 0.f) {
        v2 = 0.f;
    }
    // idk about this constant
    v2 = 1.15f - (1.f / (5287.f - 0.0435f)) * (v - 320.f);
    return v2;
}

f32 distance2vol4MD(f32 v) {
    f32 v2 = 0.f;
    if (v > SOU_ONGEN_AREA2) {
        v2 = 0.f;
    } else {
        v2 = 1.15f - (1.15f / SQ(SOU_ONGEN_AREA2)) * SQ(v);
    }
    if (v2 > 0.8f) {
        v2 = 0.8f;
    }
    if (v2 < 0.2f) {
        v2 = 0.2f;
    }
    return v2;
}

void Sou_VoiceStart(u8 a, u8 b) {
    Nap_SetS8(NA_MAKE_COMMAND(6, 4, a, 0), b);
}

void Sou_TrgStart(u16 r29, f32 f29, f32 f30, f32 f31, u8 r17, u8 r28, f32 stack_8) {
    u8 r31 = 0;
    u8 r22 = 0;
    u8 r30 = 0;
    u32 r27 = 0;
    u8 r26 = 0;
    u8 r23 = 0;
    u8 r24 = 0;
    u16 r25 = 0;
    u8 r21 = 0;
    u8 r20 = 0;
    u8 r19 = 0;
    u8 r18 = 0;
    switch (r29) {
        case 0x61:
        case 0x63:
        case 0x65:
        case 0x67:
        case 0x11e:
        case 0x4028: {
            r27 = Nap_GetRandom();
            r29 = r29 + (r27 & 1);
        } break;
        case 0x3b:
        case 0x13f:
        case 0x43f:
        case 0x501:
        case 0x505:
        case 0x509:
        case 0x50d:
        case 0x511:
        case 0x515:
        case 0x519:
        case 0x51d:
        case 0x521:
        case 0x525:
        case 0x529:
        case 0x531:
        case 0x539:
        case 0x53d: {
            r27 = Nap_GetRandom();
            r29 = r29 + (r27 & 3);
        } break;
    }
    r26 = r29;
    r25 = r29 & 0xf000;
    r24 = r25 >> 12;
    r25 = r29 & 0xf00;
    r23 = r25 >> 8;
    r21 = r24 & 1;
    r19 = r24 & 2;
    r18 = r24 & 4;
    r20 = r24 & 8;

    if (r21) {
        Nap_SetF32(NA_MAKE_COMMAND(4, 0, 0xe, 0), f31);
        Nap_SetS8(NA_MAKE_COMMAND(3, 0, 0xe, 0), r17);
        Nap_SetS8(NA_MAKE_COMMAND(5, 0, 0xe, 0), r28);
        Nap_SetS8(NA_MAKE_COMMAND(6, 0, 0xe, 0), r26);
        Nap_SetS8(NA_MAKE_COMMAND(6, 0, 0xe, 1), r23);
        return;
    }

    if (r20) {
        for (r30 = 0; r30 < 6; r30++) {
            if (r29 == sou_trg_se[r30]._00) {
                return;
            }
        }
    }

    for (r30 = 0; r30 < 6; r30++) {
        if (!sou_trg_se[r30]._00) {
            r31 = r30;
            r30 = 6;
            r22 = 1;
        }
    }

    if (r22 == 1) {
        sou_trg_se[r31]._00 = r29;
        sou_trg_se[r31]._1C = TRGPRIO[r26];
        sou_trg_se[r31]._04 = 1;
        sou_trg_se[r31]._08 = f29;
        sou_trg_se[r31]._0C = f30;
        sou_trg_se[r31]._14 = f31;
        sou_trg_se[r31]._18 = r17;
        if (r28) {
            sou_trg_se[r31]._19 = r28;
        } else {
            if (r19) {
                r25 = (u16)(stack_8);
                r28 = r25 >> 3;
                if (r28 > 0x32) {
                    r28 = 0x32;
                }
            }
            if (r18 && sou_trg_se[r31]._1B) {
                r28 = 0x28;
            } else {
                r28 = 0;
            }
            sou_trg_se[r31]._19 = r28;
        }
        Nap_SetS8(NA_MAKE_COMMAND(6, 0, r31, 0), r26);
        Nap_SetS8(NA_MAKE_COMMAND(6, 0, r31, 1), r23);
        return;
    }
    r27 = 0;
    for (r30 = 0; r30 < 6; r30++) {
        if (sou_trg_se[r30]._04 > r27) {
            r27 = sou_trg_se[r30]._04;
            r31 = r30;
        }
    }
    if (TRGPRIO[r26] >= sou_trg_se[r31]._1C) {
        sou_trg_se[r31]._00 = r29;
        sou_trg_se[r31]._1C = TRGPRIO[r26];
        sou_trg_se[r31]._04 = 1;
        sou_trg_se[r31]._08 = f29;
        sou_trg_se[r31]._0C = f30;
        sou_trg_se[r31]._14 = f31;
        sou_trg_se[r31]._18 = r17;
        Nap_SetS8(NA_MAKE_COMMAND(6, 0, r31, 0), r26);
        Nap_SetS8(NA_MAKE_COMMAND(6, 0, r31, 1), r23);
    }
}

u16 sou_kiteki_counter;
u16 sou_kiteki_random;
void Sou_SpecialRoutine00() {
    u16 r = 0;
    if (sou_kiteki_counter) {
        if (sou_kiteki_counter == 1) {
            r = Nap_GetRandom();
            r >>= 8;
            sou_kiteki_random = r + 0x40;
        }
        if (sou_kiteki_counter == sou_kiteki_random) {
            Na_SysTrgStart(0x4028);
            r = Nap_GetRandom();
            r >>= 7;
            sou_kiteki_random = r + 0x80;
            sou_kiteki_counter = 2;
        }
        sou_kiteki_counter++;
    }
}

u8 sou_SE_SENTAKU_KETTEI_timer;
void Sou_SpecialRoutine02() {
    if (sou_SE_SENTAKU_KETTEI_timer) {
        sou_SE_SENTAKU_KETTEI_timer++;
    }
    if (sou_SE_SENTAKU_KETTEI_timer == 0x1e) {
        sou_SE_SENTAKU_KETTEI_timer = 0;
    }
}

u8 sou_SE_ami_hit_water_timer;
void Sou_SpecialRoutine03() {
    if (sou_SE_ami_hit_water_timer) {
        sou_SE_ami_hit_water_timer++;
    }
    if (sou_SE_ami_hit_water_timer == 10) {
        sou_SE_ami_hit_water_timer = 0;
    }
}

void Sou_TrgEndCheck() {
    u8 i = 0;
    // unused
    u8 j = 0;
    for (i = 0; i < 6; i++) {
        if (sou_trg_se[i]._00) {
            sou_trg_se[i]._04++;
            if (!Nap_ReadSubPort(0, i, 5) && sou_trg_se[i]._1D) {
                sou_trg_se[i]._00 = 0;
                sou_trg_se[i]._04 = 0;
            }
        }
        sou_trg_se[i]._1D = Nap_ReadSubPort(0, i, 5);
    }
}

void Sou_LevStart(u8 a, u8 b) {
    if (b == sou_lev_se[a]._00 || b == sou_lev_se[a]._01 || b == sou_lev_se[a]._02 || b == sou_lev_se[a]._03 ||
        b == sou_lev_se[a]._04 || b == sou_lev_se[a]._05 || b == sou_lev_se[a]._06 || b == sou_lev_se[a]._07) {
        return;
    }

    if (sou_ls_stack[a]._0) {
        if (sou_ls_stack[a]._1) {
            if (sou_ls_stack[a]._2) {
                if (sou_ls_stack[a]._3) {
                } else {
                    sou_ls_stack[a]._3 = b;
                }
            } else {
                sou_ls_stack[a]._2 = b;
            }
        } else {
            sou_ls_stack[a]._1 = b;
        }
    } else {
        sou_ls_stack[a]._0 = b;
    }
}

void Sou_LevStop(u8 a, u8 b) {
    u8 v = 0;
    if (b == sou_ls_stack[a]._0) {
        sou_ls_stack[a]._0 = 0;
        if (sou_ls_stack[a]._1) {
            sou_ls_stack[a]._0 = sou_ls_stack[a]._1;
            sou_ls_stack[a]._1 = sou_ls_stack[a]._2;
            sou_ls_stack[a]._2 = sou_ls_stack[a]._3;
            sou_ls_stack[a]._3 = 0;
        }
    }

    if (b == sou_ls_stack[a]._1) {
        sou_ls_stack[a]._1 = 0;
        if (sou_ls_stack[a]._2) {
            sou_ls_stack[a]._1 = sou_ls_stack[a]._2;
            sou_ls_stack[a]._2 = sou_ls_stack[a]._3;
            sou_ls_stack[a]._3 = 0;
        }
    }

    if (b == sou_ls_stack[a]._2) {
        sou_ls_stack[a]._2 = 0;
        if (sou_ls_stack[a]._3) {
            sou_ls_stack[a]._2 = sou_ls_stack[a]._3;
            sou_ls_stack[a]._3 = 0;
        }
    }

    if (b == sou_ls_stack[a]._3) {
        sou_ls_stack[a]._3 = 0;
    }

    if (b == sou_lev_se[a]._00) {
        sou_lev_se[a]._00 = sou_lev_se[a]._01;
        sou_lev_se[a]._01 = sou_lev_se[a]._02;
        sou_lev_se[a]._02 = sou_lev_se[a]._03;
        sou_lev_se[a]._03 = sou_lev_se[a]._04;
        sou_lev_se[a]._04 = sou_lev_se[a]._05;
        sou_lev_se[a]._05 = sou_lev_se[a]._06;
        sou_lev_se[a]._06 = sou_lev_se[a]._07;
        sou_lev_se[a]._07 = 0;
        Nap_SetS8(NA_MAKE_COMMAND(6, 0, a + 8, 5), -1);
        if (sou_lev_se[a]._00) {
            v = sou_lev_se[a]._00;
            sou_lev_se[a]._00 = 0;
            Sou_LevStart(a, v);
        }
        return;
    }

    if (b == sou_lev_se[a]._01) {
        sou_lev_se[a]._01 = sou_lev_se[a]._02;
        sou_lev_se[a]._02 = sou_lev_se[a]._03;
        sou_lev_se[a]._03 = sou_lev_se[a]._04;
        sou_lev_se[a]._04 = sou_lev_se[a]._05;
        sou_lev_se[a]._05 = sou_lev_se[a]._06;
        sou_lev_se[a]._06 = sou_lev_se[a]._07;
        sou_lev_se[a]._07 = 0;
        return;
    }

    if (b == sou_lev_se[a]._02) {
        sou_lev_se[a]._02 = sou_lev_se[a]._03;
        sou_lev_se[a]._03 = sou_lev_se[a]._04;
        sou_lev_se[a]._04 = sou_lev_se[a]._05;
        sou_lev_se[a]._05 = sou_lev_se[a]._06;
        sou_lev_se[a]._06 = sou_lev_se[a]._07;
        sou_lev_se[a]._07 = 0;
        return;
    }

    if (b == sou_lev_se[a]._03) {
        sou_lev_se[a]._03 = sou_lev_se[a]._04;
        sou_lev_se[a]._04 = sou_lev_se[a]._05;
        sou_lev_se[a]._05 = sou_lev_se[a]._06;
        sou_lev_se[a]._06 = sou_lev_se[a]._07;
        sou_lev_se[a]._07 = 0;
        return;
    }

    if (b == sou_lev_se[a]._04) {
        sou_lev_se[a]._04 = sou_lev_se[a]._05;
        sou_lev_se[a]._05 = sou_lev_se[a]._06;
        sou_lev_se[a]._06 = sou_lev_se[a]._07;
        sou_lev_se[a]._07 = 0;
        return;
    }

    if (b == sou_lev_se[a]._05) {
        sou_lev_se[a]._05 = sou_lev_se[a]._06;
        sou_lev_se[a]._06 = sou_lev_se[a]._07;
        sou_lev_se[a]._07 = 0;
        return;
    }

    if (b == sou_lev_se[a]._06) {
        sou_lev_se[a]._06 = sou_lev_se[a]._07;
        sou_lev_se[a]._07 = 0;
        return;
    }

    if (b == sou_lev_se[a]._07) {
        sou_lev_se[a]._07 = 0;
        return;
    }
}

u8 sou_se_fadeout_flag;
void Sou_TrgMake(u8 a) {
    f32 v = 0.f;
    sou_trg_se[a]._10 = sou_trg_se[a]._08 * sou_trg_se[a]._0C;
    v = sou_trg_se[a]._10;
    if (sou_se_fadeout_flag) {
        v *= sou_se_fade[a]._8;
    }
    Nap_SetF32(NA_MAKE_COMMAND(1, 0, a, 0), v);
    Nap_SetF32(NA_MAKE_COMMAND(4, 0, a, 0), sou_trg_se[a]._14);
    Nap_SetS8(NA_MAKE_COMMAND(3, 0, a, 0), sou_trg_se[a]._18);
    Nap_SetS8(NA_MAKE_COMMAND(5, 0, a, 0), sou_trg_se[a]._19);
}

void Sou_VoiceMake(u8 a) {
    sou_voice_se[a]._10 = sou_voice_se[a]._08 * sou_voice_se[a]._0C;
    sou_voice_se[a]._1C = sou_voice_se[a]._14 * sou_voice_se[a]._18;
    Nap_SetF32(NA_MAKE_COMMAND(1, 4, a, 0), sou_voice_se[a]._10);
    Nap_SetF32(NA_MAKE_COMMAND(4, 4, a, 0), sou_voice_se[a]._1C);
    Nap_SetS8(NA_MAKE_COMMAND(3, 4, a, 0), sou_voice_se[a]._20);
    Nap_SetS8(NA_MAKE_COMMAND(5, 4, a, 0), sou_voice_se[a]._21);
}

u8 sou_pause_flag;
u8 sou_scene_mode;
void Sou_LevMake(u8 a) {
    u8 unused = 0;
    f32 v = 0.f;
    if (sou_pause_flag == 1) {
        Nap_SetF32(NA_MAKE_COMMAND(1, 0, a + 8, 0), 0.5f * sou_lev_se[a]._08);
        return;
    }
    v = sou_lev_se[a]._08;
    if (sou_se_fadeout_flag) {
        v *= sou_se_fade[a + 8]._8;
    }
    if (sou_lev_se[a]._00 == 77) {
        v *= sou_kazaguruma_speed;
    }
    Nap_SetF32(NA_MAKE_COMMAND(1, 0, a + 8, 0), v);
    Nap_SetS8(NA_MAKE_COMMAND(3, 0, a + 8, 0), sou_lev_se[a]._10);
    if (sou_lev_se[a]._13 && sou_lev_se[a]._12) {
        if (sou_scene_mode == 0xf) {
            sou_lev_se[a]._11 = 0;
        } else {
            sou_lev_se[a]._11 = 0x28;
        }
    } else {
        sou_lev_se[a]._11 = 0;
    }
    Nap_SetS8(NA_MAKE_COMMAND(5, 0, a + 8, 0), sou_lev_se[a]._11);
}

f32 sou_chime_volume;
void Sou_ChimeMake() {
    if (sou_se_fade[7]._0 || sou_se_fade[7]._4) {
        sou_chime_volume *= sou_se_fade[7]._8;
    }
    Nap_SetF32(NA_MAKE_COMMAND(1, 0, 7, 0), sou_chime_volume);
}

void Sou_LevSet(u8 a) {
    u8 v1 = 0, v2 = 0;
    if (!sou_ls_stack[a]._0) {
        return;
    }
    v1 = sou_ls_stack[a]._0;
    if (!sou_lev_se[a]._00) {
        sou_lev_se[a]._00 = v1;
    } else if (!sou_lev_se[a]._01) {
        sou_lev_se[a]._01 = sou_lev_se[a]._00;
        sou_lev_se[a]._00 = v1;
    } else if (!sou_lev_se[a]._02) {
        sou_lev_se[a]._02 = sou_lev_se[a]._01;
        sou_lev_se[a]._01 = sou_lev_se[a]._00;
        sou_lev_se[a]._00 = v1;
    } else if (!sou_lev_se[a]._03) {
        sou_lev_se[a]._03 = sou_lev_se[a]._02;
        sou_lev_se[a]._02 = sou_lev_se[a]._01;
        sou_lev_se[a]._01 = sou_lev_se[a]._00;
        sou_lev_se[a]._00 = v1;
    } else if (!sou_lev_se[a]._04) {
        sou_lev_se[a]._04 = sou_lev_se[a]._03;
        sou_lev_se[a]._03 = sou_lev_se[a]._02;
        sou_lev_se[a]._02 = sou_lev_se[a]._01;
        sou_lev_se[a]._01 = sou_lev_se[a]._00;
        sou_lev_se[a]._00 = v1;
    } else if (!sou_lev_se[a]._05) {
        sou_lev_se[a]._05 = sou_lev_se[a]._04;
        sou_lev_se[a]._04 = sou_lev_se[a]._03;
        sou_lev_se[a]._03 = sou_lev_se[a]._02;
        sou_lev_se[a]._02 = sou_lev_se[a]._01;
        sou_lev_se[a]._01 = sou_lev_se[a]._00;
        sou_lev_se[a]._00 = v1;
    } else if (!sou_lev_se[a]._06) {
        sou_lev_se[a]._06 = sou_lev_se[a]._05;
        sou_lev_se[a]._05 = sou_lev_se[a]._04;
        sou_lev_se[a]._04 = sou_lev_se[a]._03;
        sou_lev_se[a]._03 = sou_lev_se[a]._02;
        sou_lev_se[a]._02 = sou_lev_se[a]._01;
        sou_lev_se[a]._01 = sou_lev_se[a]._00;
        sou_lev_se[a]._00 = v1;
    } else if (!sou_lev_se[a]._07) {
        sou_lev_se[a]._07 = sou_lev_se[a]._06;
        sou_lev_se[a]._06 = sou_lev_se[a]._05;
        sou_lev_se[a]._05 = sou_lev_se[a]._04;
        sou_lev_se[a]._04 = sou_lev_se[a]._03;
        sou_lev_se[a]._03 = sou_lev_se[a]._02;
        sou_lev_se[a]._02 = sou_lev_se[a]._01;
        sou_lev_se[a]._01 = sou_lev_se[a]._00;
        sou_lev_se[a]._00 = v1;
    }
    v2 = v1 & 0x80;
    sou_lev_se[a]._12 = v2;
    v1 &= 0x7f;
    Nap_SetS8(NA_MAKE_COMMAND(6, 0, a + 8, 0), v1);
    sou_ls_stack[a]._0 = sou_ls_stack[a]._1;
    sou_ls_stack[a]._1 = sou_ls_stack[a]._2;
    sou_ls_stack[a]._2 = sou_ls_stack[a]._3;
    sou_ls_stack[a]._3 = 0;
}

void Sou_Insect_Lev_Cont() {
    u8 i = 0;
    for (i = 0; i < 50; i++) {
        if (sou_room_ins[i]._04 == sou_room_ins[i]._05) {
            sou_room_ins[i]._00 = 0;
            sou_room_ins[i]._04 = 0;
            sou_room_ins[i]._05 = 0;
            sou_room_ins[i]._06 = 0;
            sou_room_ins[i]._07 = 0;
        } else {
            sou_room_ins[i]._05 = sou_room_ins[i]._04;
        }
    }
}

void Sou_Ongen_Lev_Cont() {
    u8 i = 0;
    u8 j = 0;
    u8 k = 0;
    bool found = false;
    u8 foundIndex = 0;
    u8 old04 = 0;
    u8 old09 = 0;

    for (i = 0; i < ARRAY_COUNT(sou_ongen_entry); i++) {
        if (sou_ongen_entry[i]._00) {
            for (j = 0; j < ARRAY_COUNT(sou_lev_ongen_data); j++) {
                if (sou_ongen_entry[i]._00 == sou_lev_ongen_data[j]._04) {
                    found = true;
                }
            }

            if (!found) {
                for (j = 0; j < ARRAY_COUNT(sou_lev_ongen_data); j++) {
                    if (!sou_lev_ongen_data[j]._04) {
                        sou_lev_ongen_data[j]._09 = sou_ongen_entry[i]._04;
                        sou_lev_ongen_data[j]._04 = sou_ongen_entry[i]._00;
                        sou_lev_ongen_data[j]._08 = sou_ongen_entry[i]._06;
                        sou_lev_ongen_data[j]._0C = sou_ongen_entry[i]._0C;
                        sou_lev_se[j]._10 = sou_ongen_entry[i]._08;

                        sou_lev_ongen_data[j]._00 = 1;
                        sou_lev_ongen_data[j]._01 = 0;
                        sou_lev_ongen_data[j]._10 = 9999.f;
                        sou_lev_ongen_data[j]._03 = 0;
                        sou_lev_ongen_data[j]._02 = 0;

                        // exit early
                        j = ARRAY_COUNT(sou_lev_ongen_data);
                    }
                }
            }
        }
    }

    for (i = 0; i < ARRAY_COUNT(sou_ongen_entry); i++) {
        if (sou_ongen_entry[i]._00) {
            if (sou_ongen_entry[i]._09 == sou_ongen_entry[i]._0A) {
                for (j = 0; j < ARRAY_COUNT(sou_lev_ongen_data); j++) {
                    if (sou_lev_ongen_data[j]._04 == sou_ongen_entry[i]._00) {

                        // extern void Sou_LevStop(u8, u8);

                        // matches the asm here, but messes up the rest of the file
                        // Sou_LevStop((u8)j, sou_lev_ongen_data[j]._08);

                        // matches the rest of the file before this point
                        Sou_LevStop((int)j, sou_lev_ongen_data[j]._08);

                        old09 = sou_lev_ongen_data[j]._09;
                        sou_lev_ongen_data[j]._09 = 0;
                        sou_lev_ongen_data[j]._00 = 0;
                        sou_lev_ongen_data[j]._01 = 0;
                        sou_lev_ongen_data[j]._02 = 0;
                        sou_lev_ongen_data[j]._03 = 0;
                        sou_lev_ongen_data[j]._04 = 0;
                        sou_lev_ongen_data[j]._08 = 0;
                        sou_lev_ongen_data[j]._0C = 9999.f;
                        sou_lev_ongen_data[j]._10 = 9999.f;
                        for (k = 0; k < ARRAY_COUNT(sou_lev_ongen_data); k++) {
                            if (sou_lev_ongen_data[k]._09 > old09) {
                                sou_lev_ongen_data[k]._09--;
                            }
                        }

                        // exit early
                        j = ARRAY_COUNT(sou_lev_ongen_data);
                    }
                }
                old04 = sou_ongen_entry[i]._04;
                sou_ongen_entry[i]._04 = 0;
                sou_ongen_entry[i]._00 = 0;
                sou_ongen_entry[i]._06 = 0;
                sou_ongen_entry[i]._08 = 0;
                sou_ongen_entry[i]._09 = 0;
                sou_ongen_entry[i]._0A = 0;
                sou_ongen_entry[i]._0C = 9999.f;

                for (j = 0; j < ARRAY_COUNT(sou_ongen_entry); j++) {
                    if (sou_ongen_entry[j]._04 > old04) {
                        sou_ongen_entry[j]._04--;
                    }
                }
                return;
            }

            if (sou_ongen_entry[i]._04 < 5 && sou_ongen_entry[i]._04) {
                for (j = 0; j < ARRAY_COUNT(sou_lev_ongen_data); j++) {
                    if (sou_lev_ongen_data[j]._04 == sou_ongen_entry[i]._00) {
                        foundIndex = j;

                        // exit early
                        j = ARRAY_COUNT(sou_lev_ongen_data);
                    }
                }
                sou_lev_ongen_data[foundIndex]._0C = sou_ongen_entry[i]._0C;
                sou_lev_se[foundIndex]._10 = sou_ongen_entry[i]._08;
                sou_lev_ongen_data[foundIndex]._00++;
            }

            sou_ongen_entry[i]._0A = sou_ongen_entry[i]._09;
        }
    }
}

void Sou_Ongen_Lev_Prog(u8 param_1) {
    u8 unused = 0;
    u8 i = 0;
    u8 t = 0;
    if (sou_pause_flag != 1) {
        if (sou_lev_ongen_data[param_1]._04 == 0) {
            sou_lev_ongen_data[param_1]._02 = 0xff;
        }
        if (sou_lev_ongen_data[param_1]._00 == sou_lev_ongen_data[param_1]._01) {
            if (sou_lev_ongen_data[param_1]._02 == 2) {
                sou_lev_ongen_data[param_1]._02 = 3;
            }
        } else {
            if (sou_lev_ongen_data[param_1]._02 == 0) {
                sou_lev_ongen_data[param_1]._02 = 1;
            }
            if (sou_lev_ongen_data[param_1]._02 >= 3 && (sou_lev_ongen_data[param_1]._02 <= 6)) {
                sou_lev_ongen_data[param_1]._02 = 2;
            }
        }

        sou_lev_ongen_data[param_1]._01 = sou_lev_ongen_data[param_1]._00;
        if ((sou_lev_ongen_data[param_1]._10 <= SOU_ONGEN_AREA1) &&
            (sou_lev_ongen_data[param_1]._0C > SOU_ONGEN_AREA1)) {
            sou_lev_ongen_data[param_1]._03 = 0;
        }

        if (sou_lev_ongen_data[param_1]._10 > SOU_ONGEN_AREA1) {
            if (sou_lev_ongen_data[param_1]._0C <= SOU_ONGEN_AREA1) {
                sou_lev_ongen_data[param_1]._03 = 1;
            }
        }

        sou_lev_ongen_data[param_1]._10 = sou_lev_ongen_data[param_1]._0C;
        if ((sou_lev_ongen_data[param_1]._02 >= 3) && (sou_lev_ongen_data[param_1]._02 <= 6)) {
            sou_lev_ongen_data[param_1]._02++;
        }

        if ((sou_lev_ongen_data[param_1]._02 == 1) && (sou_lev_ongen_data[param_1]._03 == 1)) {
            Sou_LevStart((int)param_1, sou_lev_ongen_data[param_1]._08);
            sou_lev_ongen_data[param_1]._02 = 2;
        }

        if (sou_lev_ongen_data[param_1]._02 == 7 || sou_lev_ongen_data[param_1]._02 == 0xff) {
            Sou_LevStop((int)param_1, sou_lev_ongen_data[param_1]._08);
            t = sou_lev_ongen_data[param_1]._09;
            sou_lev_ongen_data[param_1]._09 = 0;
            sou_lev_ongen_data[param_1]._00 = 0;
            sou_lev_ongen_data[param_1]._01 = 0;
            sou_lev_ongen_data[param_1]._02 = 0;
            sou_lev_ongen_data[param_1]._03 = 0;
            sou_lev_ongen_data[param_1]._04 = 0;
            sou_lev_ongen_data[param_1]._08 = 0;
            sou_lev_ongen_data[param_1]._0C = 9999.f;
            sou_lev_ongen_data[param_1]._10 = 9999.f;
            for (i = 0; i < 4; i++) {
                if (sou_lev_ongen_data[i]._09 > t) {
                    sou_lev_ongen_data[i]._09--;
                }
            }
        }

        if (sou_lev_ongen_data[param_1]._02 != 0) {
            switch (sou_lev_ongen_data[param_1]._08) {
                default:
                    sou_lev_se[param_1]._08 = distance2vol4MD(sou_lev_ongen_data[param_1]._0C);
                    break;
                case 78:
                    sou_lev_se[param_1]._08 = distance2vol4MD(sou_lev_ongen_data[param_1]._0C);
                    break;
            }
        }
    }
    return;
}

void Sou_BgmStart(u8 a, u16 b) {
    sou_now_bgm_num = a;
    if (a == 0) {
        Nap_SetS32(NA_MAKE_COMMAND(0x83, 1, 0, 0), 0);
        Nap_SetS32(NA_MAKE_COMMAND(0x83, 3, 0, 0), 0);
        return;
    }
    u16 oldBGMHandle = sou_now_bgm_handle;
    sou_now_bgm_handle = (sou_now_bgm_handle == 1) ? 3 : 1;
    if (a >= 0x70 && a <= 0x79) {
        Nap_SetS8(NA_MAKE_COMMAND(0x46, oldBGMHandle, 0, 0), sou_now_bgm_handle);
        Nap_SetS8(NA_MAKE_COMMAND(0x46, oldBGMHandle, 0, 1), SEQ_TABLE[a]);
        Na_BgmMuteClear();
    } else if (a >= 0x53 && a <= 0x57) {
        int bb = (u8)(a - 0x53);
        Na_SysTrgStart(bb + 0x16f);
    } else {
        Nap_SetS32(NA_MAKE_COMMAND(0x83, oldBGMHandle, 0, 0), b);
        Nap_SetS32(NA_MAKE_COMMAND(0x83, sou_now_bgm_handle, 0, 0), 0);
        a = Sou_BgmTenkiConv(a);
        Nap_SetS32(NA_MAKE_COMMAND(0x82, sou_now_bgm_handle, SEQ_TABLE[a], 0), b);
        Na_StaffRollStart(SEQ_TABLE[a]);
        Na_SetKappaSeqHandle(sou_now_bgm_handle);
    }
}

u16 sou_bgm_vol_time;
u16 sou_bgm_vol_move_counter;
u16 sou_bgm_vol_move_time;
f32 sou_bgm_vol_move_target;
f32 sou_bgm_vol_move_delta;
void Sou_BGMVolMove() {
    f32 v = 0.f;
    f32 unused = 0.f;
    if (sou_bgm_vol_time) {
        switch (sou_now_bgm_handle) {
            case 1: {
                if (sou_bgm_vol_move_counter == 0) {
                    sou_bgm_vol_move_time = 0;
                    v = sou_bgm_vol_move_target;
                } else {
                    if (sou_bgm_vol_move_counter == sou_bgm_vol_move_time && sou_bgm_vol_move_time) {
                        if (sou_bgm_vol_move_target - sou_bgm1_vol_now == 0) {
                            sou_bgm_vol_move_delta = 0.f;
                            sou_bgm_vol_move_counter = 1;
                        } else {
                            sou_bgm_vol_move_delta =
                                (sou_bgm_vol_move_target - sou_bgm1_vol_now) / (int)sou_bgm_vol_move_time;
                        }
                    }
                    v = sou_bgm_vol_move_target + (-(sou_bgm_vol_move_delta * (int)sou_bgm_vol_move_counter));
                    sou_bgm_vol_move_counter--;
                    if (v > 1.f) {
                        v = 1.f;
                    }
                }
                if (v > 1.f) {
                    v = 1.f;
                }
                if (v < 0.f) {
                    v = 0.f;
                }
                sou_bgm1_vol_now = v;
                Nap_SetF32(NA_MAKE_COMMAND(0x41, 1, 0, 0), v);
            } break;
            case 3: {
                if (sou_bgm_vol_move_counter == 0) {
                    sou_bgm_vol_move_time = 0;
                    v = sou_bgm_vol_move_target;
                } else {
                    if (sou_bgm_vol_move_counter == sou_bgm_vol_move_time && sou_bgm_vol_move_time) {
                        if (sou_bgm_vol_move_target - sou_bgm1_vol_now == 0) {
                            sou_bgm_vol_move_delta = 0.f;
                            sou_bgm_vol_move_counter = 1;
                        } else {
                            sou_bgm_vol_move_delta =
                                (sou_bgm_vol_move_target - sou_bgm1_vol_now) / (int)sou_bgm_vol_move_time;
                        }
                    }
                    v = sou_bgm_vol_move_target + (-(sou_bgm_vol_move_delta * (int)sou_bgm_vol_move_counter));
                    sou_bgm_vol_move_counter--;
                    if (v > 1.f) {
                        v = 1.f;
                    }
                }
                if (v > 1.f) {
                    v = 1.f;
                }
                if (v < 0.f) {
                    v = 0.f;
                }
                sou_bgm1_vol_now = v;
                Nap_SetF32(NA_MAKE_COMMAND(0x41, 3, 0, 0), v);
            } break;
        }
    }
}

void Sou_Na_BgmStart(u8 a) {
    u16 v = 0;
    Sou_BgmStart(a, v);
    if (a >= 0x80 && a <= 0xb6) {
        Sou_GroupControl(1, 0x3f, 0.f);
        Sou_GroupControl(3, 0x3f, 0.f);
    }
}

void Sou_Na_BgmStop(u16 a) {
    sou_now_bgm_fadeout = 1;
    a &= 0xfff;
    if (sou_now_bgm_handle == 1) {
        Nap_SetS32(NA_MAKE_COMMAND(0x83, 1, 0, 0), a);
    } else {
        Nap_SetS32(NA_MAKE_COMMAND(0x83, 3, 0, 0), a);
    }
}

u8 sou_bgm_call_buffer;
u8 sou_bgm_call_buffer_u8;
u16 sou_bgm_call_buffer_u16;
void Sou_SpecialRoutine06() {
    u8 v = 0;
    switch (sou_bgm_call_buffer) {
        case 1: {
            Sou_Na_BgmStart(sou_bgm_call_buffer_u8);
        } break;
        case 2: {
            if (sou_now_bgm_handle == 1) {
                sou_now_bgm_handle = 3;
                Nap_SetS32(NA_MAKE_COMMAND(0x83, 1, 0, 0), 700);
                v = Sou_BgmTenkiConv(sou_bgm_call_buffer_u8);
                Nap_SetS32(NA_MAKE_COMMAND(0x82, 3, SEQ_TABLE[v], 0), 700);
            } else {
                sou_now_bgm_handle = 1;
                Nap_SetS32(NA_MAKE_COMMAND(0x83, 3, 0, 0), 700);
                v = Sou_BgmTenkiConv(sou_bgm_call_buffer_u8);
                Nap_SetS32(NA_MAKE_COMMAND(0x82, 1, SEQ_TABLE[v], 0), 700);
            }
        } break;
        case 3: {
            Sou_Na_BgmStop(sou_bgm_call_buffer_u16);
        }
    }
}

void Sou_SpecialRoutine07() {
    sou_bgm_call_buffer = 0;
    sou_bgm_call_buffer_u8 = 0;
    sou_bgm_call_buffer_u16 = 0;
}

void Sou_SeFadeoutRoutine() {
    u8 i = 0;
    f32 v1 = 0.f;
    f32 v2 = 0.f;
    for (i = 0; i < ARRAY_COUNT(sou_se_fade); i++) {
        if (sou_se_fade[i]._0 == 0xffff) {
            sou_se_fade[i]._8 = 0.f;
            sou_se_fade[i]._0 = 0;
            if (i >= 8 && i <= 14) {
                sou_lev_se[i]._08 = 0.f;
            }
        } else if (sou_se_fade[i]._0 != 0) {
            if (sou_se_fade[i]._0 == sou_se_fade[i]._2) {
                sou_se_fade[i]._8 = 0.f;
                sou_se_fade[i]._0 = 0xffff;
            } else {
                v1 = sou_se_fade[i]._2 - sou_se_fade[i]._0;
                v2 = sou_se_fade[i]._2;
                sou_se_fade[i]._8 = v1 / v2;
                sou_se_fade[i]._0++;
            }
        }
    }
}

void Sou_SeFadeinRoutine() {
    u8 i = 0;
    f32 v1 = 0.f;
    f32 v2 = 0.f;
    for (i = 0; i < ARRAY_COUNT(sou_se_fade); i++) {
        if (sou_se_fade[i]._4 == 0xffff) {
            sou_se_fade[i]._8 = 1.f;
            sou_se_fade[i]._4 = 0;
            if (i >= 8 && i <= 14) {
                sou_lev_se[i]._08 = 1.f;
            }
        } else if (sou_se_fade[i]._4 != 0) {
            if (sou_se_fade[i]._4 == sou_se_fade[i]._6) {
                sou_se_fade[i]._8 = 1.f;
                sou_se_fade[i]._4 = 0xffff;
            } else {
                v1 = sou_se_fade[i]._6 - sou_se_fade[i]._4;
                v2 = sou_se_fade[i]._6;
                sou_se_fade[i]._8 = v1 / v2;
                sou_se_fade[i]._4++;
            }
        }
    }
}

void Sou_SeVolumeReset() {
    u8 i = 0;
    for (i = 0; i < ARRAY_COUNT(sou_lev_se); i++) {
        sou_se_fade[i + 8]._0 = 0;
        sou_se_fade[i + 8]._4 = 0;
        sou_lev_se[i]._08 = 0.f;
        sou_lev_se[i]._0C = 1.f;
    }
}

void Sou_SeTrFadeout(u8 a, u16 b) {
    sou_se_fade[a]._0 = 1;
    sou_se_fade[a]._2 = b;
}

void Sou_SeFadeout(u16 a) {
    u8 i = 0;
    sou_se_fadeout_flag = 1;
    for (i = 0; i < ARRAY_COUNT(sou_lev_se); i++) {
        Sou_SeTrFadeout(i + 8, a);
    }
}

u16 sou_ongenpos_kill_countdown;
void Sou_SpecialRoutine08() {
    if (sou_ongenpos_kill_countdown != 0 && sou_ongenpos_kill_countdown != 1) {
        sou_ongenpos_kill_countdown--;
    }
}
u8 sou_Na_VoiceSeFlag;
u8 sou_num2_request;
s16 sou_num2_animal_id;
u8 sou_num2_scale;
void Sou_SpecialRoutine10() {
    if (sou_Na_VoiceSeFlag == 1) {
        sou_Na_VoiceSeFlag = 0;
    } else if (sou_num2_request) {
        Na_VoiceSe(sou_num2_request, 0, 0, sou_num2_animal_id, sou_num2_scale, 2);
        sou_num2_request = 0;
    }
}

u32 sou_now_spec;
u8 sou_chime_status;
u8 sou_last_kokoro_counter;
u8 sou_game_frame_counter;
u8 sou_kokoro_toguru;
u16 sou_last_sys_trg_num;
u8 sou_sub_game_flag;

u8 sou_walk_flag;
u8 sou_last_walk_l;
u8 sou_last_walk_r;
u8 sou_player_dash;
f32 sou_player_speed;
u8 sou_voice_se_toguru;

u8 sou_message_status;
u8 sou_last_voice;
u8 sou_voice_effect;
u8 sou_voice_effect_counter;

u8 sou_metranome_counter;
u16 sou_last_period;
u16 sou_last_uchiwa;

u8 sou_voice_mode;

f32 sou_camera2ground;
u8 sou_now_boin;
u8 sou_now_voice_seq;
u8 sou_nobasu_count;

u16 sou_kisha_angle;
f32 sou_kisha_distance;
u16 sou_kisha_angle2;
f32 sou_kisha_distance2;
u16 sou_kisha_status;
u16 sou_shu_count;
u16 sou_tonton_count;
u8 sou_voice_type;

u8 sou_se_handle_ready;
u8 sou_voice_handle_ready;

u8 sou_filter_status;
u8 sou_room_type;
u8 sou_museum_type;

f32 sou_md_bgm_boost_pasent = 1.f;
u8 sou_internal_filter_status;

u8 sou_voice_sad_toguru;
u8 sou_last_voice_toguru;
u8 sou_voice_se_skip;

u8 sou_last_num;
u8 sou_last_num2;
u8 sou_num_org;
u8 sou_num2_org;
u8 sou_num3_org;

void Sou_InitAudio() {
    int i;
    sou_now_spec = 0;
    sou_scene_mode = 0;
    sou_now_bgm_handle = 1;
    sou_chime_status = 0;
    sou_last_kokoro_counter = 0;
    sou_game_frame_counter = 0;
    sou_kokoro_toguru = 0;
    sou_last_sys_trg_num = 0;
    sou_sub_game_flag = 0;
    sou_kazaguruma_speed = 0.f;
    sou_walk_flag = 0;
    sou_last_walk_l = 0;
    sou_last_walk_r = 0;
    sou_player_dash = 0;
    sou_player_speed = 0.f;
    sou_voice_se_toguru = 0;
    sou_message_speed = 0;
    sou_message_status = 0;
    sou_last_voice = 0;
    sou_voice_effect = 0;
    sou_voice_effect_counter = 0;
    sou_pause_flag = 0;
    sou_metranome_counter = 0;
    sou_last_period = 0;
    sou_last_uchiwa = 0;
    sou_out_mode = 0;
    sou_voice_mode = 0;
    sou_kiteki_random = 0;
    sou_kiteki_counter = 0;
    sou_camera2ground = 0.f;
    sou_now_boin = 0;
    sou_now_voice_seq = 0;
    sou_nobasu_count = 0;
    sou_now_bgm_num = 0;
    sou_bgm_vol_move_target = 0.f;
    sou_bgm_vol_move_delta = 0.f;
    sou_bgm1_vol_now = 0.f;
    sou_bgm2_vol_now = 0.f;
    sou_bgm_vol_move_time = 0;
    sou_bgm_vol_move_counter = 0;
    sou_kisha_angle = 0;
    sou_kisha_distance = 0.f;
    sou_kisha_angle2 = 0;
    sou_kisha_distance2 = 0.f;
    sou_kisha_status = 0;
    sou_shu_count = 0;
    sou_tonton_count = 0;
    sou_voice_type = 0;
    sou_SE_SENTAKU_KETTEI_timer = 0;
    sou_SE_ami_hit_water_timer = 0;
    sou_tenki = 0;
    sou_now_bgm_fadeout = 0;
    sou_se_handle_ready = 0;
    sou_voice_handle_ready = 0;
    sou_bgm_call_buffer = 0;
    sou_bgm_call_buffer_u8 = 0;
    sou_bgm_call_buffer_u16 = 0;
    sou_ongenpos_kill_countdown = 0;
    sou_chime_volume = 0.f;
    sou_filter_status = 0;
    sou_room_type = 0;
    sou_museum_type = 0;
    SOU_ONGEN_AREA1 = 540.f;
    SOU_ONGEN_AREA2 = 533.f;
    sou_md_bgm_boost_pasent = 1.f;
    sou_internal_filter_status = 0;
    sou_se_fadeout_flag = 0;
    sou_voice_sad_toguru = 0;
    sou_last_voice_toguru = 0;
    sou_voice_se_skip = 0;
    sou_num2_request = 0;
    sou_Na_VoiceSeFlag = 0;
    sou_num2_animal_id = 0;
    sou_num2_scale = 0;
    sou_last_num = 0;
    sou_last_num2 = 0;
    sou_num_org = 0;
    sou_num2_org = 0;
    sou_num3_org = 0;
    for (i = 0; i < ARRAY_COUNT(sou_trg_se); i++) {
        sou_trg_se[i] = sou_trg_se_init;
    }
    for (i = 0; i < ARRAY_COUNT(sou_voice_se); i++) {
        sou_voice_se[i] = sou_voice_se_init;
    }
    for (i = 0; i < ARRAY_COUNT(sou_lev_se); i++) {
        sou_lev_se[i] = sou_lev_se_init;
        sou_ls_stack[i] = sou_ls_stack_init;
    }
    for (i = 0; i < ARRAY_COUNT(sou_lev_ongen_data); i++) {
        sou_lev_ongen_data[i] = sou_lev_ongen_data_init;
    }
    for (i = 0; i < ARRAY_COUNT(sou_ongen_entry); i++) {
        sou_ongen_entry[i] = sou_ongen_entry_init;
    }
    for (i = 0; i < ARRAY_COUNT(sou_sys_lev); i++) {
        sou_sys_lev[i] = sou_sys_lev_init;
    }
    for (i = 0; i < ARRAY_COUNT(sou_room_ins); i++) {
        sou_room_ins[i] = sou_room_ins_init;
    }
    for (i = 0; i < ARRAY_COUNT(sou_se_fade); i++) {
        sou_se_fade[i] = sou_se_fade_init;
    }
    Nap_SetS32(NA_MAKE_COMMAND(0x82, 0, 0xf2, 0), 0);
    Nap_SetF32(NA_MAKE_COMMAND(0x41, 0, 0, 0), 1.15f);
    Nap_SetF32(NA_MAKE_COMMAND(0x41, 1, 0, 0), 1.f);
    sou_bgm1_vol_now = 1.f;
    Nap_SetF32(NA_MAKE_COMMAND(0x41, 3, 0, 0), 1.f);
    sou_bgm2_vol_now = 1.f;
    Nap_SetF32(NA_MAKE_COMMAND(0x41, 2, 0, 0), 1.f);
    Na_Pause(0);
    Na_BGMVolume(1.f, 2);
    Na_RhythmInit();
    Na_MelodyInit();
    Na_StaffRollInit();
}

void (*fatalErrorCallback)();

void Sou_DVD_Error(char*, u8*) {
    fatalErrorCallback();
}

void BootSound(u32, u32) {
}

u8 sou_NeosBootCheck_ok;
u8 audiomemory[0x90000];
void Na_InitAudio(void (*fatal_callback)(), u8* load_addr, size_t load_size, u8* bootsound, size_t bootsound_size,
                  BOOL cut_flag) {
    u32 v = 0x810000;
    fatalErrorCallback = fatal_callback;
    u32 unused = SetPreCopy_NeosRom(load_addr, load_size, cut_flag);
    Jac_RegisterDVDErrorCallback(Sou_DVD_Error);
    Jac_Start(audiomemory, sizeof(audiomemory), v);
    BootSound((u32)bootsound, bootsound_size);
    sou_NeosBootCheck_ok = 1;
}

void Na_GameFrame() {
    u8 i = 0;
    sou_game_frame_counter++;
    switch (sou_NeosBootCheck_ok) {
        case 1: {
            if (!Neos_CheckBoot()) {
                return;
            }
            sou_NeosBootCheck_ok = 2;
        }
        // fallthrough
        case 2: {
            Sou_InitAudio();
            sou_NeosBootCheck_ok = 3;
        } break;
        case 3: {
            Sou_BGMVolMove();
            Sou_SeFadeoutRoutine();
            Sou_SeFadeinRoutine();
            Sou_TrgEndCheck();
            for (i = 0; i < ARRAY_COUNT(sou_trg_se); i++) {
                Sou_TrgMake(i);
            }
            for (i = 0; i < ARRAY_COUNT(sou_voice_se); i++) {
                Sou_VoiceMake(i);
            }
            for (i = 0; i < ARRAY_COUNT(sou_lev_se); i++) {
                Sou_LevSet(i);
                Sou_LevMake(i);
            }
            Sou_ChimeMake();
            Sou_Ongen_Lev_Cont();
            Sou_Insect_Lev_Cont();
            for (i = 0; i < ARRAY_COUNT(sou_lev_ongen_data); i++) {
                Sou_Ongen_Lev_Prog(i);
            }
            Sou_BgmFadeoutEndCheck();
            Sou_SpecialRoutine00();
            Sou_SpecialRoutine02();
            Sou_SpecialRoutine03();
            Sou_SpecialRoutine06();
            Sou_SpecialRoutine07();
            Sou_SpecialRoutine08();
            Sou_SpecialRoutine10();
            int unused = Nap_SendStart();
        } break;
        case 0:
        case 4:
        default:
            break;
    }
}

void Na_Reset() {
    int unused = Nap_StartReset();
}

void Na_SoftReset() {
    u8 i = 0;
    sou_pause_flag = 0;
    sou_scene_mode = 0;
    for (i = 0; i < ARRAY_COUNT(sou_sys_lev); i++) {
        sou_sys_lev[i]._0 = 0;
        sou_sys_lev[i]._1 = 0;
    }
    for (i = 0; i < ARRAY_COUNT(sou_ls_stack); i++) {
        sou_ls_stack[i]._0 = 0;
        sou_ls_stack[i]._1 = 0;
        sou_ls_stack[i]._2 = 0;
        sou_ls_stack[i]._3 = 0;
        sou_ls_stack[i]._4 = 0;
        sou_ls_stack[i]._5 = 0;
        sou_ls_stack[i]._6 = 0;
        sou_ls_stack[i]._7 = 0;
    }
    for (i = 0; i < ARRAY_COUNT(sou_lev_se); i++) {
        sou_lev_se[i]._00 = 0;
        sou_lev_se[i]._01 = 0;
        sou_lev_se[i]._02 = 0;
        sou_lev_se[i]._03 = 0;
        sou_lev_se[i]._04 = 0;
        sou_lev_se[i]._05 = 0;
        sou_lev_se[i]._06 = 0;
        sou_lev_se[i]._07 = 0;
    }
    Na_Pause(0);
    Nap_SetS32(NA_MAKE_COMMAND(0x83, 0, 0, 0), 180);
    Na_BgmStart(180);
    Nap_SetS32(NA_MAKE_COMMAND(0x83, 2, 0, 0), 180);
    Nap_SetS32(NA_MAKE_COMMAND(0x83, 4, 0, 0), 180);
    Na_BGMVolume(1.f, 2);
    Nap_SetS32(NA_MAKE_COMMAND(0x82, 0, 0xf2, 0), 0);
    int unused = Nap_SendStart();
}

void Na_Tenki(u8 a) {
    if (a != sou_tenki) {
        sou_tenki = a;
    }
}

void Na_BgmStart(u8 a) {
    u16 unused = 0;

    sou_bgm_call_buffer_u8 = a;
    sou_bgm_call_buffer = 1;
}

void Na_BgmCrossfadeStart(u8 a) {
    sou_bgm_call_buffer_u8 = a;
    sou_bgm_call_buffer = 2;
}

void Na_BgmStop(u16 a) {
    sou_bgm_call_buffer_u16 = a;
    sou_bgm_call_buffer = 3;
}

void Na_SysTrgStart(u16 a) {
    bool v = false;
    u8 j = 0x3f;
    u8 k = 0;
    u8 unused = 0;
    f32 f31 = 1.f;
    f32 f30 = 1.f;
    f32 f29 = 1.f;
    f32 f28 = 0.f;
    if (a == 0x54 && sou_last_sys_trg_num == 0x54) {
        if (sou_kokoro_toguru == 0) {
            sou_kokoro_toguru = 1;
            if (sou_last_kokoro_counter - sou_game_frame_counter == 1) {
                return;
            }
        } else {
            sou_kokoro_toguru = 0;
        }
    }

    sou_last_kokoro_counter = sou_game_frame_counter;
    sou_kokoro_toguru = 0;
    sou_last_sys_trg_num = a;
    switch (a) {
        case 0x424: {
            if (sou_scene_mode != 1) {
                a = 0x16e;
            }
        } break;
        case 0xd: {
            sou_SE_SENTAKU_KETTEI_timer = 1;
        } break;
        case 0x8005: {
            if (sou_scene_mode != 0) {
                v = true;
            }
        } break;
    }

    if (!v) {
        Sou_TrgStart(a, f31, f30, f29, j, k, f28);
    }
}

void Sou_WalkSe(u16 a, u16 b, f32 c, u8 d, f32 e) {
    u8 r29 = 0x3f;
    u8 unused = 0;
    u16 v = 0;
    f32 f29 = 1.f;
    f32 f30 = 1.;

    if (a == 0 || c > SOU_ONGEN_AREA1) {
        // needed to match, probably stripped assert;
        (void)0;
        return;
    }

    r29 = angle2pan(b, c);
    f30 = distance2vol(c);
    v = Nap_GetRandom();
    v >>= 0xe;
    if (sou_player_dash == 3) {
        a = a + 40;
    }
    if ((sou_walk_flag & 1) == 1) {
        if (v == 3 && sou_last_walk_l == 0 && sou_last_walk_r == 0) {
            a = a + 0x1e;
            sou_last_walk_l = 1;
        } else {
            a = a + 0xa;
            sou_last_walk_l = 0;
        }
    } else if (v == 3 && sou_last_walk_l == 0 && sou_last_walk_r == 0) {
        a = a + 0x14;
        sou_last_walk_r = 1;
    } else {
        sou_last_walk_r = 0;
    }
    sou_walk_flag++;
    Sou_TrgStart(a, f30, e, f29, r29, d, c);
}

void Na_PlyWalkSe(u16 a, u16 b, f32 c) {
    u8 j = 0;
    f32 v = 1.f;
    if (sou_scene_mode) {
        switch (sou_player_dash) {
            case 1: {
                v = 0.6f;
            } break;
            case 2: {
                v = 0.8f;
            } break;
            case 3: {
                v = 1.0f;
            } break;
        }

        Sou_WalkSe(a, b, c, j, v);
    }
}

void Na_PlyWalkSeRoom(u8 a, u16 b, f32 c) {
    u16 r30 = 0;
    u8 r31 = 0;
    f32 f31 = 1.f;
    if (sou_scene_mode) {
        switch (sou_player_dash) {
            case 0xf: {
                r31 = 0x32;
            } break;
            case 0x10: {
                r31 = 0x32;
            } break;
            default: {
                r31 = 5;
            } break;
        }
        if (a == 0xff) {
            r30 = 0x4204;
        } else {
            r30 = SE_FLOOR_DATA[a] + 0x42e6;
        }
        switch (sou_player_dash) {
            case 1: {
                f31 = 0.54f;
            } break;
            case 2: {
                f31 = 0.71999997f;
            } break;
            case 3: {
                f31 = 0.9f;
            } break;
        }
        Sou_WalkSe(r30, b, c, r31, f31);
    }
}

void Na_NpcWalkSe(u16 a, u16 b, f32 c) {
    u8 r31 = 0;
    f32 f31 = 0.68f;
    if (sou_scene_mode == 0 || sou_scene_mode == 0xc) {
        (void)0;
        return;
    }
    Sou_WalkSe(a, b, c, r31, f31);
}

void Na_NpcWalkSeRoom(u8 a, u16 b, f32 c) {
    u16 r30 = 0;
    u8 r31 = 0;
    f32 f31 = 0.612f;
    if (sou_scene_mode == 0 || sou_scene_mode == 0xe) {
        (void)0;
        return;
    }
    switch (sou_scene_mode) {
        case 0xf: {
            r31 = 0x32;
        } break;
        case 0x10: {
            r31 = 0x32;
        } break;
        default: {
            r31 = 5;
        } break;
    }
    r30 = SE_FLOOR_DATA[a] + 0x42e6;
    Sou_WalkSe(r30, b, c, r31, f31);
}

void Na_PlayerStatusLevel(f32 a, int b) {
    sou_player_dash = b;
    sou_player_speed = a;
}

u8 Sou_TanboinHenkan(u8 a, u8 b) {
    switch (a) {
        case 0x5d:
            return 0x01;
        case 0x65:
            return 0x14;
        case 0x71:
            return 0x29;
        case 0x61:
            return 0x0a;
        case 0x6b:
            return 0x1d;
        case 0x6a:
            return 0x1b;
        case 0x53:
            return 0x32;
        case 0x54:
            return 0x33;
        case 0x55:
            return 0x26;
        case 0x56:
            return 0x27;
        case 0x57:
            return 0x34;
        case 0x58:
            return 0x35;
        case 0x59:
            return 0x36;
        case 0x5a:
            return 0x37;
        case 0x5b:
            return 0x10;
        case 0x5c:
            return 0x38;
        case 0x5e:
            return 7;
        case 0x5f: {
            switch (b) {
                case 0x65:
                case 0x61:
                    return 0x23;
                default:
                    return 0x18;
            }
        }
        case 0x60:
            return 0x09;
        case 0x62:
            return 0x11;
        case 0x63:
            return 0x12;
        case 0x64:
            return 0x00;
        case 0x66:
            return 0x17;
        case 0x67:
            return 0x18;
        case 0x68:
            return 0x19;
        case 0x69:
            return 0x1a;
        case 0x6c:
            return 0x21;
        case 0x6d:
            return 0x18;
        case 0x6e:
            return 0x22;
        case 0x6f:
            return 0x23;
        case 0x70:
            return 0x26;
        case 0x72:
            return 0x2d;
        case 0x73:
            return 0x2e;
        case 0x74:
            return 0x31;
        case 0x75:
            return 0x15;
        case 0x76:
            return 0x30;
    }
}

u8 Sou_ChouboinHenkan(u8 a, u8 b) {
    switch (a) {
        case 0x5d:
            return 0x02;
        case 0x65:
            return 0x15;
        case 0x71:
            return 0x2a;
        case 0x61:
            return 0x0e;
        case 0x6b:
            return 0x1e;
        case 0x6a:
            return 0x1b;
        case 0x53:
            return 0x32;
        case 0x54:
            return 0x33;
        case 0x55:
            return 0x26;
        case 0x56:
            return 0x27;
        case 0x57:
            return 0x34;
        case 0x58:
            return 0x35;
        case 0x59:
            return 0x36;
        case 0x5a:
            return 0x37;
        case 0x5b:
            return 0x10;
        case 0x5c:
            return 0x38;
        case 0x5e:
            return 7;
        case 0x5f: {
            switch (b) {
                case 0x65:
                case 0x61:
                    return 0x23;
                default:
                    return 0x18;
            }
        }
        case 0x60:
            return 0x09;
        case 0x62:
            return 0x11;
        case 0x63:
            return 0x12;
        case 0x64:
            return 0x00;
        case 0x66:
            return 0x17;
        case 0x67:
            return 0x18;
        case 0x68:
            return 0x19;
        case 0x69:
            return 0x1a;
        case 0x6c:
            return 0x21;
        case 0x6d:
            return 0x18;
        case 0x6e:
            return 0x22;
        case 0x6f:
            return 0x23;
        case 0x70:
            return 0x26;
        case 0x72:
            return 0x2d;
        case 0x73:
            return 0x2e;
        case 0x74:
            return 0x31;
        case 0x75:
            return 0x15;
        case 0x76:
            return 0x30;
    }
}

void Sou_ConnectCheck(u8, u8, u8) {
}

void Sou_BoinShiinCheck(u8) {
}
void Na_VoiceSe(u8, u8, u8, s16, u8, u8) {
}
void Na_MessageStatus(u8) {
}
void Na_MessageSpeed(u8 v) {
    sou_message_speed = v;
}
u8 Na_MessageSpeedGet() {
    return sou_message_speed;
}
void Na_OngenPos(u32, u8, u16, f32) {
}
void Sou_PosTrgStart(u16, u16, f32, u8, f32) {
}
extern void Na_OngenTrgStartSpeed(u16, u16, f32, f32) {
}
extern void Na_OngenTrgStart(u16, u16, f32) {
}
extern void Na_SetOutMode(u8) {
}
extern void Na_SetVoiceMode(u8) {
}
extern void Na_FloorTrgStart(u8, u16, f32) {
}
extern void Na_SysLevStart(u8) {
}
extern void Na_SysLevStop(u8) {
}
extern void Na_Pause(u8) {
}
extern void Na_RhythmPos(u32, u8, u16, f32) {
}
extern void Na_SpecChange(int) {
}
extern void Na_MDPlayerPos(u16, u16, u16, int, f32) {
}
extern void Na_BGMVolume(f32, u16) {
}
extern void Na_RestartPrepare() {
}
extern u8 Na_CheckRestartReady() {
}
extern void Na_Restart() {
}
extern u8 Na_SubGameOK() {
}
extern void Na_KishaStatusTrg(u8) {
}
extern void Na_KishaStatusLevel(f32 speed, u32 ongenNum1, u16 angle1, f32 distance1, u32 ongenNum2, u16 angle2,
                                f32 distance2) {
}
extern void Na_TTKK_ARM(u8) {
}
extern void Na_BgmMuteClear() {
}
extern void Na_BgmFadeoutCheck() {
}
extern void Na_SeFadeoutCheck() {
}
extern void Na_BgmTrOn() {
}
extern void Na_BgmTrOff() {
}
extern void Na_SubGameStart() {
}
extern void Na_SubGameEnd() {
}
extern void Na_SceneMode(u8) {
}
extern u8 Na_RoomIncectPos(int, u16, u16, f32) {
}
extern void Na_FurnitureInstPos(int, u16, f32) {
}
extern void Na_TrgSeEcho(u8) {
}
extern void Na_LevSeEcho(u8) {
}
extern void Na_BGMFilter() {
}
extern void Na_RoomType(u8) {
}
extern u8 Na_CheckNeosBoot() {
}
extern void Na_Museum(u8) {
}
extern int Na_GetSoundFrameCounter() {
}
extern void Na_kazagurumaLevel(f32 v) {
    sou_kazaguruma_speed = v;
}

#pragma force_active on

// force data pooling
FORCESTRIP static int __REMOVE_TEMP() {
    int a = SEQ_TABLE[55];
    int b = SE_FLOOR_DATA[3];
    int c = SE_ROOM_INS_DATA[6];

    return a * b * c;
}
#pragma force_active reset
