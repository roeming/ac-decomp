#include "libforest/gbi_extensions.h"
#include "PR/gbi.h"
#include "evw_anime.h"
#include "c_keyframe.h"
#include "ac_npc.h"

u8 cKF_ckcb_r_obj_s_post_flag_on1_tbl[] = { 56, 0, 7, 0, 0, 7 };

s16 cKF_kn_obj_s_post_flag_on1_tbl[] = { 2, 2, 2, 2, 2, 7, 2, 2, 2 };

s16 cKF_c_obj_s_post_flag_on1_tbl[] = { 0, 0, 0, 0, 450, 0, 0, 0, 0, 0, 450, 0 };

s16 cKF_ds_obj_s_post_flag_on1_tbl[] = { 1,  550,  0, 17, 550, 0, 1,  0,   0, 17, 0,   0, 1,  -450, 0, 17, -450, 0,
                                         1,  0,    0, 17, 0,   0, 1,  0,   0, 17, 0,   0, 1,  0,    0, 8,  900,  6898,
                                         9,  1000, 0, 12, 850, 0, 14, 930, 0, 16, 880, 0, 17, 900,  0, 1,  0,    0,
                                         17, 0,    0, 1,  0,   0, 17, 0,   0, 1,  900, 0, 17, 900,  0 };

cKF_Animation_R_c cKF_ba_r_obj_s_post_flag_on1 = { cKF_ckcb_r_obj_s_post_flag_on1_tbl,
                                                   cKF_ds_obj_s_post_flag_on1_tbl,
                                                   cKF_kn_obj_s_post_flag_on1_tbl,
                                                   cKF_c_obj_s_post_flag_on1_tbl,
                                                   -1,
                                                   17 };
