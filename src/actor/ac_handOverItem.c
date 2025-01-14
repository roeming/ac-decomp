#include "ac_handOverItem.h"

#include "libultra/libultra.h"
#include "m_common_data.h"
#include "m_demo.h"
#include "m_msg.h"
#include "m_name_table.h"
#include "m_player_lib.h"
#include "m_rcp.h"
#include "sys_matrix.h"

enum {
  aHOI_ITEM_TYPE_ITEM,
  aHOI_ITEM_TYPE_FISH,
  aHOI_ITEM_TYPE_MAIL,

  aHOI_ITEM_TYPE_NUM
};

static void aHOI_actor_ct(ACTOR*, GAME*);
static void aHOI_actor_dt(ACTOR*, GAME*);
static void aHOI_actor_move(ACTOR*, GAME*);
static void aHOI_actor_draw(ACTOR*, GAME*);

ACTOR_PROFILE HandOverItem_Profile = {
  mAc_PROFILE_HANDOVERITEM,
  ACTOR_PART_BG,
  ACTOR_STATE_CAN_MOVE_IN_DEMO_SCENES | ACTOR_STATE_NO_DRAW_WHILE_CULLED | ACTOR_STATE_NO_MOVE_WHILE_CULLED,
  EMPTY_NO,
  ACTOR_OBJ_BANK_KEEP,
  sizeof(HANDOVERITEM_ACTOR),
  &aHOI_actor_ct,
  &aHOI_actor_dt,
  &aHOI_actor_move,
  &aHOI_actor_draw,
  NULL
};

static aHOI_Clip_c aHOI_clip;

#include "../src/actor/ac_gyoei_model.c_inc"

extern Gfx apple_DL_mode[];
extern Gfx orange_DL_mode[];
extern Gfx peach_DL_mode[];
extern Gfx pear_DL_mode[];
extern Gfx nuts_DL_mode[];
extern Gfx matutake_DL_mode[];
extern Gfx kabu_DL_mode[];
extern Gfx fish_DL_mode[];
extern Gfx bag_DL_mode[];
extern Gfx leaf_DL_mode[];
extern Gfx obj_rollT_mat_model[];
extern Gfx box_DL_mode[];
extern Gfx pack_DL_mode[];
extern Gfx present_DL_mode[];
extern Gfx seed_DL_mode[];
extern Gfx obj_haniwaT_mat_model[];
extern Gfx obj_boxT_mat_model[];
extern Gfx obj_cageT_mat_model[];
extern Gfx obj_toolT_mat_model[];
extern Gfx obj_fossilT_mat_model[];
extern Gfx obj_trashT_mat_model[];
extern Gfx obj_letterT_mat_model[];
extern Gfx obj_otosiT_mat_model[];
extern Gfx obj_item_shellAT_mat_model[];
extern Gfx obj_item_shellBT_mat_model[];
extern Gfx obj_item_shellCT_mat_model[];
extern Gfx obj_shop_candy_mat_modelT[];
extern Gfx obj_item_cocoT_mat_model[];
extern Gfx obj_item_omikuji_mat_model[];
extern Gfx obj_item_clothT_mat_model[];
extern Gfx obj_item_carpetT_mat_model[];
extern Gfx obj_item_wallT_mat_model[];
extern Gfx obj_item_axeT_mat_model[];
extern Gfx obj_item_netT_mat_model[];
extern Gfx obj_item_rodT_mat_model[];
extern Gfx obj_item_shovelT_mat_model[];
extern Gfx obj_item_axe2T_mat_model[];
extern Gfx obj_item_net2T_mat_model[];
extern Gfx obj_item_rod2T_mat_model[];
extern Gfx obj_item_shovel2T_mat_model[];
extern Gfx obj_item_umbrellaT_mat_model[];
extern Gfx obj_item_kazaT_mat_model[];
extern Gfx obj_item_utiwaT_mat_model[];
extern Gfx obj_item_paperT_mat_model[];
extern Gfx obj_item_seedT_mat_model[];
extern Gfx obj_item_fukuT_mat_model[];
extern Gfx obj_item_taisouT_mat_model[];
extern Gfx obj_mdT_mat_model[];
extern Gfx obj_item_ticketT_mat_model[];
extern Gfx obj_item_boneT_mat_model[];
extern Gfx obj_item_diaryT_mat_model[];
extern Gfx obj_item_fork_onT_mat_model[];

static Gfx* mode_DL_table[mNT_ITEM_TYPE_NUM] = {
  NULL,  
  apple_DL_mode,
  orange_DL_mode,
  peach_DL_mode,
  pear_DL_mode,
  nuts_DL_mode,
  matutake_DL_mode,
  kabu_DL_mode,
  fish_DL_mode,
  bag_DL_mode,
  leaf_DL_mode,
  obj_rollT_mat_model,
  box_DL_mode,
  pack_DL_mode,
  present_DL_mode,
  seed_DL_mode,
  obj_haniwaT_mat_model,
  obj_boxT_mat_model,
  obj_cageT_mat_model,
  obj_toolT_mat_model,
  obj_fossilT_mat_model,
  obj_trashT_mat_model,
  obj_letterT_mat_model,
  obj_otosiT_mat_model,
  obj_item_shellAT_mat_model,
  obj_item_shellBT_mat_model,
  obj_item_shellCT_mat_model,
  obj_shop_candy_mat_modelT,
  obj_item_cocoT_mat_model,
  obj_item_omikuji_mat_model,
  obj_item_clothT_mat_model,
  obj_item_carpetT_mat_model,
  obj_item_wallT_mat_model,
  obj_item_axeT_mat_model,
  obj_item_netT_mat_model,
  obj_item_rodT_mat_model,
  obj_item_shovelT_mat_model,
  obj_item_axe2T_mat_model,
  obj_item_net2T_mat_model,
  obj_item_rod2T_mat_model,
  obj_item_shovel2T_mat_model,
  obj_item_umbrellaT_mat_model,
  obj_item_kazaT_mat_model,
  obj_item_utiwaT_mat_model,
  obj_item_paperT_mat_model,
  obj_item_seedT_mat_model,
  obj_item_fukuT_mat_model,
  obj_item_taisouT_mat_model,
  obj_mdT_mat_model,
  obj_item_ticketT_mat_model,
  obj_item_boneT_mat_model,
  obj_item_diaryT_mat_model,
  obj_item_fork_onT_mat_model
};

extern Gfx apple_DL_vtx[];
extern Gfx orange_DL_vtx[];
extern Gfx peach_DL_vtx[];
extern Gfx pear_DL_vtx[];
extern Gfx nuts_DL_vtx[];
extern Gfx matutake_DL_vtx[];
extern Gfx kabu_DL_vtx[];
extern Gfx fish_DL_vtx[];
extern Gfx bag_DL_vtx[];
extern Gfx leaf_DL_vtx[];
extern Gfx obj_rollT_gfx_model[];
extern Gfx box_DL_vtx[];
extern Gfx pack_DL_vtx[];
extern Gfx present_DL_vtx[];
extern Gfx seed_DL_vtx[];
extern Gfx obj_haniwaT_gfx_model[];
extern Gfx obj_boxT_gfx_model[];
extern Gfx obj_cageT_gfx_model[];
extern Gfx obj_toolT_gfx_model[];
extern Gfx obj_fossilT_gfx_model[];
extern Gfx obj_trashT_gfx_model[];
extern Gfx obj_letterT_gfx_model[];
extern Gfx obj_otosiT_gfx_model[];
extern Gfx obj_item_shellAT_gfx_model[];
extern Gfx obj_item_shellBT_gfx_model[];
extern Gfx obj_item_shellCT_gfx_model[];
extern Gfx obj_shop_candy_gfx_modelT[];
extern Gfx obj_item_cocoT_gfx_model[];
extern Gfx obj_item_omikuji_gfx_model[];
extern Gfx obj_item_clothT_gfx_model[];
extern Gfx obj_item_carpetT_gfx_model[];
extern Gfx obj_item_wallT_gfx_model[];
extern Gfx obj_item_axeT_gfx_model[];
extern Gfx obj_item_netT_gfx_model[];
extern Gfx obj_item_rodT_gfx_model[];
extern Gfx obj_item_shovelT_gfx_model[];
extern Gfx obj_item_axe2T_gfx_model[];
extern Gfx obj_item_net2T_gfx_model[];
extern Gfx obj_item_rod2T_gfx_model[];
extern Gfx obj_item_shovel2T_gfx_model[];
extern Gfx obj_item_umbrellaT_gfx_model[];
extern Gfx obj_item_kazaT_gfx_model[];
extern Gfx obj_item_utiwaT_gfx_model[];
extern Gfx obj_item_paperT_gfx_model[];
extern Gfx obj_item_seedT_gfx_model[];
extern Gfx obj_item_fukuT_gfx_model[];
extern Gfx obj_item_taisouT_gfx_model[];
extern Gfx obj_mdT_gfx_model[];
extern Gfx obj_item_ticketT_gfx_model[];
extern Gfx obj_item_boneT_gfx_model[];
extern Gfx obj_item_diaryT_gfx_model[];
extern Gfx obj_item_fork_onT_gfx_model[];

static Gfx* vtx_DL_table[mNT_ITEM_TYPE_NUM] = {
  NULL, 
  apple_DL_vtx,
  orange_DL_vtx,
  peach_DL_vtx,
  pear_DL_vtx,
  nuts_DL_vtx,
  matutake_DL_vtx,
  kabu_DL_vtx,
  fish_DL_vtx,
  bag_DL_vtx,
  leaf_DL_vtx,
  obj_rollT_gfx_model,
  box_DL_vtx,
  pack_DL_vtx,
  present_DL_vtx,
  seed_DL_vtx,
  obj_haniwaT_gfx_model,
  obj_boxT_gfx_model,
  obj_cageT_gfx_model,
  obj_toolT_gfx_model,
  obj_fossilT_gfx_model,
  obj_trashT_gfx_model,
  obj_letterT_gfx_model,
  obj_otosiT_gfx_model,
  obj_item_shellAT_gfx_model,
  obj_item_shellBT_gfx_model,
  obj_item_shellCT_gfx_model,
  obj_shop_candy_gfx_modelT,
  obj_item_cocoT_gfx_model,
  obj_item_omikuji_gfx_model,
  obj_item_clothT_gfx_model,
  obj_item_carpetT_gfx_model,
  obj_item_wallT_gfx_model,
  obj_item_axeT_gfx_model,
  obj_item_netT_gfx_model,
  obj_item_rodT_gfx_model,
  obj_item_shovelT_gfx_model,
  obj_item_axe2T_gfx_model,
  obj_item_net2T_gfx_model,
  obj_item_rod2T_gfx_model,
  obj_item_shovel2T_gfx_model,
  obj_item_umbrellaT_gfx_model,
  obj_item_kazaT_gfx_model,
  obj_item_utiwaT_gfx_model,
  obj_item_paperT_gfx_model,
  obj_item_seedT_gfx_model,
  obj_item_fukuT_gfx_model,
  obj_item_taisouT_gfx_model,
  obj_mdT_gfx_model,
  obj_item_ticketT_gfx_model,
  obj_item_boneT_gfx_model,
  obj_item_diaryT_gfx_model,
  obj_item_fork_onT_gfx_model
};

/* Clip */
#include "../src/actor/ac_handOverItem_clip.c_inc"

/* Move */
#include "../src/actor/ac_handOverItem_move.c_inc"

/* Draw */
#include "../src/actor/ac_handOverItem_draw.c_inc"

static void aHOI_actor_ct(ACTOR* actorx, GAME* game) {
  aHOI_init_clip_area(actorx, game);
}

static void aHOI_actor_dt(ACTOR* actorx, GAME* game) {
  aHOI_free_clip_area();
}
