/**
 * @file
 * @brief Audio related functions
 */

#ifndef POKEAGB_CORE_AUDIO_H_
#define POKEAGB_CORE_AUDIO_H_

#include "../types.h"
#include "../common.h"
#include "m4a.h"

POKEAGB_BEGIN_DECL

enum Sound {
    MUS_DUMMY = 0,   // MUS_DUMMY
    SE_USE_ITEM = 1,   // SE_KAIFUKU
    SE_PC_LOGIN = 2,   // SE_PC_LOGIN
    SE_PC_OFF = 3,   // SE_PC_OFF
    SE_PC_ON = 4,   // SE_PC_ON
    SE_SELECT = 5,   // SE_SELECT
    SE_WIN_OPEN = 6,   // SE_WIN_OPEN
    SE_WALL_HIT = 7,   // SE_WALL_HIT
    SE_RS_DOOR = 8,   // SE_DOOR
    SE_EXIT = 9,   // SE_KAIDAN
    SE_LEDGE = 10,  // SE_DANSA
    SE_BIKE_BELL = 11,  // SE_JITENSYA
    SE_NOT_EFFECTIVE = 12,  // SE_KOUKA_L
    SE_EFFECTIVE = 13,  // SE_KOUKA_M
    SE_SUPER_EFFECTIVE = 14,  // SE_KOUKA_H
    SE_BALL_OPEN = 15,  // SE_BOWA2
    SE_FAINT = 16,  // SE_POKE_DEAD
    SE_FLEE = 17,  // SE_NIGERU
    SE_SLIDING_DOOR = 18,  // SE_JIDO_DOA
    SE_SHIP = 19,  // SE_NAMINORI
    SE_BANG = 20,  // SE_BAN
    SE_PIN = 21,  // SE_PIN
    SE_BOO = 22,  // SE_BOO
    SE_BALL = 23,  // SE_BOWA
    SE_CONTEST_PLACE = 24,  // SE_JYUNI
    SE_SUCCESS = 25,  // SE_SEIKAI
    SE_FAILURE = 26,  // SE_HAZURE
    SE_EXP = 27,  // SE_EXP
    SE_BIKE_HOP = 28,  // SE_JITE_PYOKO
    SE_SWITCH = 29,  // SE_MU_PACHI
    SE_CLICK = 30,  // SE_TK_KASYA
    SE_FU_ZAKU = 31,  // SE_FU_ZAKU
    SE_CONTEST_CONDITION_LOSE = 32,  // SE_FU_ZAKU2
    SE_LAVARIDGE_FALL_WARP = 33,  // SE_FU_ZUZUZU
    SE_ICE_STAIRS = 34,  // SE_RU_GASHIN
    SE_ICE_BREAK = 35,  // SE_RU_GASYAN
    SE_ICE_CRACK = 36,  // SE_RU_BARI
    SE_FALL = 37,  // SE_RU_HYUU
    SE_UNLOCK = 38,  // SE_KI_GASYAN
    SE_WARP_IN = 39,  // SE_TK_WARPIN
    SE_WARP_OUT = 40,  // SE_TK_WARPOUT
    SE_REPEL = 41,  // SE_TU_SAA
    SE_ROTATING_GATE = 42,  // SE_HI_TURUN
    SE_TRUCK_MOVE = 43,  // SE_TRACK_MOVE
    SE_TRUCK_STOP = 44,  // SE_TRACK_STOP
    SE_TRUCK_UNLOAD = 45,  // SE_TRACK_HAIKI
    SE_TRUCK_DOOR = 46,  // SE_TRACK_DOOR
    SE_BERRY_BLENDER = 47,  // SE_MOTER
    SE_SAVE = 48,  // SE_SAVE
    SE_BALL_BOUNCE_1 = 49,  // SE_KON
    SE_BALL_BOUNCE_2 = 50,  // SE_KON2
    SE_BALL_BOUNCE_3 = 51,  // SE_KON3
    SE_BALL_BOUNCE_4 = 52,  // SE_KON4
    SE_BALL_TRADE = 53,  // SE_SUIKOMU
    SE_BALL_THROW = 54,  // SE_NAGERU
    SE_NOTE_C = 55,  // SE_TOY_C
    SE_NOTE_D = 56,  // SE_TOY_D
    SE_NOTE_E = 57,  // SE_TOY_E
    SE_NOTE_F = 58,  // SE_TOY_F
    SE_NOTE_G = 59,  // SE_TOY_G
    SE_NOTE_A = 60,  // SE_TOY_A
    SE_NOTE_B = 61,  // SE_TOY_B
    SE_NOTE_C_HIGH = 62,  // SE_TOY_C1
    SE_PUDDLE = 63,  // SE_MIZU
    SE_BRIDGE_WALK = 64,  // SE_HASHI
    SE_ITEMFINDER = 65,  // SE_DAUGI
    SE_DING_DONG = 66,  // SE_PINPON
    SE_BALLOON_RED = 67,  // SE_FUUSEN1
    SE_BALLOON_BLUE = 68,  // SE_FUUSEN2
    SE_BALLOON_YELLOW = 69,  // SE_FUUSEN3
    SE_BREAKABLE_DOOR = 70,  // SE_TOY_KABE
    SE_MUD_BALL = 71,  // SE_TOY_DANGO
    SE_FIELD_POISON = 72,  // SE_DOKU
    SE_ESCALATOR = 73,  // SE_ESUKA
    SE_THUNDERSTORM = 74,  // SE_T_AME
    SE_THUNDERSTORM_STOP = 75,  // SE_T_AME_E
    SE_DOWNPOUR = 76,  // SE_T_OOAME
    SE_DOWNPOUR_STOP = 77,  // SE_T_OOAME_E
    SE_RAIN = 78,  // SE_T_KOAME
    SE_RAIN_STOP = 79,  // SE_T_KOAME_E
    SE_THUNDER = 80,  // SE_T_KAMI
    SE_THUNDER2 = 81,  // SE_T_KAMI2
    SE_ELEVATOR = 82,  // SE_ELEBETA
    SE_LOW_HEALTH = 83,  // SE_HINSI
    SE_EXP_MAX = 84,  // SE_EXPMAX
    SE_ROULETTE_BALL = 85,  // SE_TAMAKORO
    SE_ROULETTE_BALL2 = 86,  // SE_TAMAKORO_E
    SE_TAILLOW_WING_FLAP = 87,  // SE_BASABASA
    SE_RS_SHOP = 88,  // SE_REGI
    SE_CONTEST_HEART = 89,  // SE_C_GAJI
    SE_CONTEST_CURTAIN_RISE = 90,  // SE_C_MAKU_U
    SE_CONTEST_CURTAIN_FALL = 91,  // SE_C_MAKU_D
    SE_CONTEST_ICON_CHANGE = 92,  // SE_C_PASI
    SE_CONTEST_ICON_CLEAR = 93,  // SE_C_SYU
    SE_CONTEST_MONS_TURN = 94,  // SE_C_PIKON
    SE_SHINY = 95,  // SE_REAPOKE
    SE_INTRO_BLAST = 96,  // SE_OP_BASYU
    SE_MUGSHOT = 97,  // SE_BT_START
    SE_APPLAUSE = 98,  // SE_DENDOU
    SE_VEND = 99,  // SE_JIHANKI
    SE_ORB = 100, // SE_TAMA
    SE_DEX_SCROLL = 101, // SE_Z_SCROLL
    SE_DEX_PAGE = 102, // SE_Z_PAGE
    SE_POKENAV_ON = 103, // SE_PN_ON
    SE_POKENAV_OFF = 104, // SE_PN_OFF
    SE_DEX_SEARCH = 105, // SE_Z_SEARCH
    SE_EGG_HATCH = 106, // SE_TAMAGO
    SE_BALL_TRAY_ENTER = 107, // SE_TB_START
    SE_BALL_TRAY_BALL = 108, // SE_TB_KON
    SE_BALL_TRAY_EXIT = 109, // SE_TB_KARA
    SE_GLASS_FLUTE = 110, // SE_BIDORO
// Move SFX
    SE_M_THUNDERBOLT = 111, // SE_W085
    SE_M_THUNDERBOLT2 = 112, // SE_W085B
    SE_M_HARDEN = 113, // SE_W231
    SE_M_NIGHTMARE = 114, // SE_W171
    SE_M_VITAL_THROW = 115, // SE_W233
    SE_M_VITAL_THROW2 = 116, // SE_W233B
    SE_M_BUBBLE = 117, // SE_W145
    SE_M_BUBBLE2 = 118, // SE_W145B
    SE_M_BUBBLE3 = 119, // SE_W145C
    SE_M_RAIN_DANCE = 120, // SE_W240
    SE_M_CUT = 121, // SE_W015
    SE_M_STRING_SHOT = 122, // SE_W081
    SE_M_STRING_SHOT2 = 123, // SE_W081B
    SE_M_ROCK_THROW = 124, // SE_W088
    SE_M_GUST = 125, // SE_W016
    SE_M_GUST2 = 126, // SE_W016B
    SE_M_DOUBLE_SLAP = 127, // SE_W003
    SE_M_DOUBLE_TEAM = 128, // SE_W104
    SE_M_RAZOR_WIND = 129, // SE_W013
    SE_M_ICY_WIND = 130, // SE_W196
    SE_M_THUNDER_WAVE = 131, // SE_W086
    SE_M_COMET_PUNCH = 132, // SE_W004
    SE_M_MEGA_KICK = 133, // SE_W025
    SE_M_MEGA_KICK2 = 134, // SE_W025B
    SE_M_CRABHAMMER = 135, // SE_W152
    SE_M_JUMP_KICK = 136, // SE_W026
    SE_M_FLAME_WHEEL = 137, // SE_W172
    SE_M_FLAME_WHEEL2 = 138, // SE_W172B
    SE_M_FLAMETHROWER = 139, // SE_W053
    SE_M_FIRE_PUNCH = 140, // SE_W007
    SE_M_TOXIC = 141, // SE_W092
    SE_M_SACRED_FIRE = 142, // SE_W221
    SE_M_SACRED_FIRE2 = 143, // SE_W221B
    SE_M_EMBER = 144, // SE_W052
    SE_M_TAKE_DOWN = 145, // SE_W036
    SE_M_BLIZZARD = 146, // SE_W059
    SE_M_BLIZZARD2 = 147, // SE_W059B
    SE_M_SCRATCH = 148, // SE_W010
    SE_M_VICEGRIP = 149, // SE_W011
    SE_M_WING_ATTACK = 150, // SE_W017
    SE_M_FLY = 151, // SE_W019
    SE_M_SAND_ATTACK = 152, // SE_W028
    SE_M_RAZOR_WIND2 = 153, // SE_W013B
    SE_M_BITE = 154, // SE_W044
    SE_M_HEADBUTT = 155, // SE_W029
    SE_M_SURF = 156, // SE_W057
    SE_M_HYDRO_PUMP = 157, // SE_W056
    SE_M_WHIRLPOOL = 158, // SE_W250
    SE_M_HORN_ATTACK = 159, // SE_W030
    SE_M_TAIL_WHIP = 160, // SE_W039
    SE_M_MIST = 161, // SE_W054
    SE_M_POISON_POWDER = 162, // SE_W077
    SE_M_BIND = 163, // SE_W020
    SE_M_DRAGON_RAGE = 164, // SE_W082
    SE_M_SING = 165, // SE_W047
    SE_M_PERISH_SONG = 166, // SE_W195
    SE_M_PAY_DAY = 167, // SE_W006
    SE_M_DIG = 168, // SE_W091
    SE_M_DIZZY_PUNCH = 169, // SE_W146
    SE_M_SELF_DESTRUCT = 170, // SE_W120
    SE_M_EXPLOSION = 171, // SE_W153
    SE_M_ABSORB_2 = 172, // SE_W071B
    SE_M_ABSORB = 173, // SE_W071
    SE_M_SCREECH = 174, // SE_W103
    SE_M_BUBBLE_BEAM = 175, // SE_W062
    SE_M_BUBBLE_BEAM2 = 176, // SE_W062B
    SE_M_SUPERSONIC = 177, // SE_W048
    SE_M_BELLY_DRUM = 178, // SE_W187
    SE_M_METRONOME = 179, // SE_W118
    SE_M_BONEMERANG = 180, // SE_W155
    SE_M_LICK = 181, // SE_W122
    SE_M_PSYBEAM = 182, // SE_W060
    SE_M_FAINT_ATTACK = 183, // SE_W185
    SE_M_SWORDS_DANCE = 184, // SE_W014
    SE_M_LEER = 185, // SE_W043
    SE_M_SWAGGER = 186, // SE_W207
    SE_M_SWAGGER2 = 187, // SE_W207B
    SE_M_HEAL_BELL = 188, // SE_W215
    SE_M_CONFUSE_RAY = 189, // SE_W109
    SE_M_SNORE = 190, // SE_W173
    SE_M_BRICK_BREAK = 191, // SE_W280
    SE_M_GIGA_DRAIN = 192, // SE_W202
    SE_M_PSYBEAM2 = 193, // SE_W060B
    SE_M_SOLAR_BEAM = 194, // SE_W076
    SE_M_PETAL_DANCE = 195, // SE_W080
    SE_M_TELEPORT = 196, // SE_W100
    SE_M_MINIMIZE = 197, // SE_W107
    SE_M_SKETCH = 198, // SE_W166
    SE_M_SWIFT = 199, // SE_W129
    SE_M_REFLECT = 200, // SE_W115
    SE_M_BARRIER = 201, // SE_W112
    SE_M_DETECT = 202, // SE_W197
    SE_M_LOCK_ON = 203, // SE_W199
    SE_M_MOONLIGHT = 204, // SE_W236
    SE_M_CHARM = 205, // SE_W204
    SE_M_CHARGE = 206, // SE_W268
    SE_M_STRENGTH = 207, // SE_W070
    SE_M_HYPER_BEAM = 208, // SE_W063
    SE_M_WATERFALL = 209, // SE_W127
    SE_M_REVERSAL = 210, // SE_W179
    SE_M_ACID_ARMOR = 211, // SE_W151
    SE_M_SANDSTORM = 212, // SE_W201
    SE_M_TRI_ATTACK = 213, // SE_W161
    SE_M_TRI_ATTACK2 = 214, // SE_W161B
    SE_M_ENCORE = 215, // SE_W227
    SE_M_ENCORE2 = 216, // SE_W227B
    SE_M_BATON_PASS = 217, // SE_W226
    SE_M_MILK_DRINK = 218, // SE_W208
    SE_M_ATTRACT = 219, // SE_W213
    SE_M_ATTRACT2 = 220, // SE_W213B
    SE_M_MORNING_SUN = 221, // SE_W234
    SE_M_FLATTER = 222, // SE_W260
    SE_M_SAND_TOMB = 223, // SE_W328
    SE_M_GRASSWHISTLE = 224, // SE_W320
    SE_M_SPIT_UP = 225, // SE_W255
    SE_M_DIVE = 226, // SE_W291
    SE_M_EARTHQUAKE = 227, // SE_W089
    SE_M_TWISTER = 228, // SE_W239
    SE_M_SWEET_SCENT = 229, // SE_W230
    SE_M_YAWN = 230, // SE_W281
    SE_M_SKY_UPPERCUT = 231, // SE_W327
    SE_M_STAT_INCREASE = 232, // SE_W287
    SE_M_HEAT_WAVE = 233, // SE_W257
    SE_M_UPROAR = 234, // SE_W253
    SE_M_HAIL = 235, // SE_W258
    SE_M_COSMIC_POWER = 236, // SE_W322
    SE_M_TEETER_DANCE = 237, // SE_W298
    SE_M_STAT_DECREASE = 238, // SE_W287B
    SE_M_HAZE = 239, // SE_W114
    SE_M_HYPER_BEAM2 = 240, // SE_W063B
// New FRLG SFX
    SE_DOOR = 241, // SE_RG_W_DOOR
    SE_CARD_FLIP = 242, // SE_RG_CARD1
    SE_CARD_FLIPPING = 243, // SE_RG_CARD2
    SE_CARD_OPEN = 244, // SE_RG_CARD3
    SE_BAG_CURSOR = 245, // SE_RG_BAG1
    SE_BAG_POCKET = 246, // SE_RG_BAG2
    SE_BALL_CLICK = 247, // SE_RG_GETTING
    SE_SHOP = 248, // SE_RG_SHOP
    SE_SS_ANNE_HORN = 249, // SE_RG_KITEKI
    SE_HELP_OPEN = 250, // SE_RG_HELP_OP
    SE_HELP_CLOSE = 251, // SE_RG_HELP_CL
    SE_HELP_ERROR = 252, // SE_RG_HELP_NG
    SE_DEOXYS_MOVE = 253, // SE_RG_DEOMOV
    SE_POKE_JUMP_SUCCESS = 254, // SE_RG_EXCELLENT
    SE_POKE_JUMP_FAILURE = 255, // SE_RG_NAWAMISS
// Music kept from RS
    MUS_HEAL = 256, // MUS_ME_ASA
    MUS_LEVEL_UP = 257, // MUS_FANFA1
    MUS_OBTAIN_ITEM = 258, // MUS_FANFA4
    MUS_EVOLVED = 259, // MUS_FANFA5
    MUS_OBTAIN_BADGE = 260, // MUS_ME_BACHI
    MUS_OBTAIN_TMHM = 261, // MUS_ME_WAZA
    MUS_OBTAIN_BERRY = 262, // MUS_ME_KINOMI
    MUS_EVOLUTION_INTRO = 263, // MUS_ME_SHINKA
    MUS_EVOLUTION = 264, // MUS_SHINKA
    MUS_RS_VS_GYM_LEADER = 265, // MUS_BATTLE32
    MUS_RS_VS_TRAINER = 266, // MUS_BATTLE20
    MUS_SCHOOL = 267, // MUS_P_SCHOOL
    MUS_SLOTS_JACKPOT = 268, // MUS_ME_B_BIG
    MUS_SLOTS_WIN = 269, // MUS_ME_B_SMALL
    MUS_MOVE_DELETED = 270, // MUS_ME_WASURE
    MUS_TOO_BAD = 271, // MUS_ME_ZANNEN
// New FRLG Music
    MUS_FOLLOW_ME = 272, // MUS_RG_ANNAI
    MUS_GAME_CORNER = 273, // MUS_RG_SLOT
    MUS_ROCKET_HIDEOUT = 274, // MUS_RG_AJITO
    MUS_GYM = 275, // MUS_RG_GYM
    MUS_JIGGLYPUFF = 276, // MUS_RG_PURIN
    MUS_INTRO_FIGHT = 277, // MUS_RG_DEMO
    MUS_TITLE = 278, // MUS_RG_TITLE
    MUS_CINNABAR = 279, // MUS_RG_GUREN
    MUS_LAVENDER = 280, // MUS_RG_SHION
    MUS_HEAL_UNUSED = 281, // MUS_RG_KAIHUKU
    MUS_CYCLING = 282, // MUS_RG_CYCLING
    MUS_ENCOUNTER_ROCKET = 283, // MUS_RG_ROCKET
    MUS_ENCOUNTER_GIRL = 284, // MUS_RG_SHOUJO
    MUS_ENCOUNTER_BOY = 285, // MUS_RG_SHOUNEN
    MUS_HALL_OF_FAME = 286, // MUS_RG_DENDOU
    MUS_VIRIDIAN_FOREST = 287, // MUS_RG_T_MORI
    MUS_MT_MOON = 288, // MUS_RG_OTSUKIMI
    MUS_POKE_MANSION = 289, // MUS_RG_POKEYASHI
    MUS_CREDITS = 290, // MUS_RG_ENDING
    MUS_ROUTE1 = 291, // MUS_RG_LOAD01
    MUS_ROUTE24 = 292, // MUS_RG_OPENING
    MUS_ROUTE3 = 293, // MUS_RG_LOAD02
    MUS_ROUTE11 = 294, // MUS_RG_LOAD03
    MUS_VICTORY_ROAD = 295, // MUS_RG_CHAMP_R
    MUS_VS_GYM_LEADER = 296, // MUS_RG_VS_GYM
    MUS_VS_TRAINER = 297, // MUS_RG_VS_TORE
    MUS_VS_WILD = 298, // MUS_RG_VS_YASEI
    MUS_VS_CHAMPION = 299, // MUS_RG_VS_LAST
    MUS_PALLET = 300, // MUS_RG_MASARA
    MUS_OAK_LAB = 301, // MUS_RG_KENKYU
    MUS_OAK = 302, // MUS_RG_OHKIDO
    MUS_POKE_CENTER = 303, // MUS_RG_POKECEN
    MUS_SS_ANNE = 304, // MUS_RG_SANTOAN
    MUS_SURF = 305, // MUS_RG_NAMINORI
    MUS_POKE_TOWER = 306, // MUS_RG_P_TOWER
    MUS_SILPH = 307, // MUS_RG_SHIRUHU
    MUS_FUCHSIA = 308, // MUS_RG_HANADA
    MUS_CELADON = 309, // MUS_RG_TAMAMUSI
    MUS_VICTORY_TRAINER = 310, // MUS_RG_WIN_TRE
    MUS_VICTORY_WILD = 311, // MUS_RG_WIN_YASEI
    MUS_VICTORY_GYM_LEADER = 312, // MUS_RG_WIN_GYM
    MUS_VERMILLION = 313, // MUS_RG_KUCHIBA
    MUS_PEWTER = 314, // MUS_RG_NIBI
    MUS_ENCOUNTER_RIVAL = 315, // MUS_RG_RIVAL1
    MUS_RIVAL_EXIT = 316, // MUS_RG_RIVAL2
    MUS_DEX_RATING = 317, // MUS_RG_FAN2
    MUS_OBTAIN_KEY_ITEM = 318, // MUS_RG_FAN5
    MUS_CAUGHT_INTRO = 319, // MUS_RG_FAN6
    MUS_PHOTO = 320, // MUS_ME_RG_PHOTO
    MUS_GAME_FREAK = 321, // MUS_RG_TITLEROG
    MUS_CAUGHT = 322, // MUS_RG_GET_YASEI
    MUS_NEW_GAME_INSTRUCT = 323, // MUS_RG_SOUSA
    MUS_NEW_GAME_INTRO = 324, // MUS_RG_SEKAIKAN
    MUS_NEW_GAME_EXIT = 325, // MUS_RG_SEIBETU
    MUS_POKE_JUMP = 326, // MUS_RG_JUMP
    MUS_UNION_ROOM = 327, // MUS_RG_UNION
    MUS_NET_CENTER = 328, // MUS_RG_NETWORK
    MUS_MYSTERY_GIFT = 329, // MUS_RG_OKURIMONO
    MUS_BERRY_PICK = 330, // MUS_RG_KINOMIKUI
    MUS_SEVII_CAVE = 331, // MUS_RG_NANADUNGEON
    MUS_TEACHY_TV_SHOW = 332, // MUS_RG_OSHIE_TV
    MUS_SEVII_ROUTE = 333, // MUS_RG_NANASHIMA
    MUS_SEVII_DUNGEON = 334, // MUS_RG_NANAISEKI
    MUS_SEVII_123 = 335, // MUS_RG_NANA123
    MUS_SEVII_45 = 336, // MUS_RG_NANA45
    MUS_SEVII_67 = 337, // MUS_RG_NANA67
    MUS_POKE_FLUTE = 338, // MUS_RG_POKEFUE
    MUS_VS_DEOXYS = 339, // MUS_RG_VS_DEO
    MUS_VS_MEWTWO = 340, // MUS_RG_VS_MYU2
    MUS_VS_LEGEND = 341, // MUS_RG_VS_DEN
    MUS_ENCOUNTER_GYM_LEADER = 342, // MUS_RG_EXEYE
    MUS_ENCOUNTER_DEOXYS = 343, // MUS_RG_DEOEYE
    MUS_TRAINER_TOWER = 344, // MUS_RG_T_TOWER
    MUS_SLOW_PALLET = 345, // MUS_RG_SLOWMASARA
    MUS_TEACHY_TV_MENU = 346, // MUS_RG_TVNOIZE
};

// enum Sound  {
//     SOUND_RS_BERRY_PICKING_MAYBE = 0x1,
//     SOUND_PC_GO_BACK = 0x3,
//     SOUND_PC_OPEN = 0x4,
//     SOUND_GENERIC_CLINK = 0x5,
//     SE_WIN_OPEN = 0x6,
//     SOUND_WALLRUN = 0x7,
//     SOUND_DOOR_OPEN_MAYBE = 0x8,
//     SOUND_BIKE_CLINK = 0xB,
//     SOUND_NOT_VERY_EFFECTIVE = 0xC,
//     SOUND_NORMAL_DAMAGE = 0xD,
//     SOUND_SUPER_EFFECTIVE = 0xE,
//     SOUND_POKEMON_ENTER_LEAVE = 0xF,
//     SOUND_GOT_AWAY_SAFELY = 0x11,
//     SOUND_TELEPHONE_MAYBE = 0x12,
//     SOUND_FLY_MAYBE = 0x14,
//     SOUND_EXCLAMATION_MARK = 0x15,
//     SOUND_RS_CONTEST_NOT_YOU = 0x16,
//     SOUND_RS_CONTEST_1 = 0x18,
//     SOUND_RS_CONTEST_2 = 0x19,
//     SOUND_RS_CONTEST_3 = 0x1A,
//     SOUND_EXP_GAIN = 0x1B,
//     SOUND_RSE_BERRY_MIX_CLICK = 0x22,
//     SOUND_FALL_THROUGH_ICE = 0x23,
//     SOUND_DAMAGE_ICE_FLOOR = 0x24,
//     SOUND_RSE_ROULETTE_BALL_FALL = 0x25,
//     SOUND_RSE_ROULETTE_BALL_LAND = 0x26,
//     SOUND_SOME_BEEP = 0x28,
//     SOUND_GAME_SAVED = 0x30,
//     SOUND_POKEBALL_BOUNCE1 = 0x31,
//     SOUND_POKEBALL_BOUNCE2 = 0x32,
//     SOUND_POKEBALL_BOUNCE3 = 0x33,
//     SOUND_POKEBALL_BOUNCE4 = 0x34,
//     SOUND_OVERWORLD_POISON = 0x48,
//     SOUND_COUNTINOUS_RAINING_1 = 0x4A,
//     SOUND_RAIN_END = 0x4B,
//     SOUND_COUNTINOUS_RAINING_2 = 0x4C,
//     SOUND_LEVEL_UP = 0x58,
//     SOUND_SUNLIGHT = 0xC3,
//     SOUND_BOULDER_BUMP = 0xCF,
//     SOUND_YAWN_MAYBE = 0xDC,
//     SOUND_RUN_THE_TERMINATOR = 0xE3,
//     SOUND_SOME_AIR_MOVE_1 = 0xE4,
//     SOUND_SWEET_SCENT = 0xE5,
//     SOUND_YAWN_PROBABLY = 0xE6,
//     SOUND_SOME_AIR_MOVE_2 = 0xE7,
//     SOUND_STAT_INCREASE = 0xE8,
//     SOUND_SOME_FIRE_MOVE = 0xE9,
//     SOUND_HEAVENLY = 0xEC,
//     SOUND_WOAH = 0xED,
//     SOUND_STAT_DECREASE = 0xEE,
//     SOUND_WHAT = 0xEF,
//     SOUND_DOOR_OPEN_MAYBE_2 = 0xF1,
//     SOUND_HMM = 0xF2,
//     SOUND_TRAINER_CARD = 0xF4,
//     SOUND_OPEN_START_MENU_MAYBE = 0xF5,
//     SOUND_SCRATCHING = 0xF7,
//     SOUND_THE_STORE_IS_OPEN = 0xF8,
//     SOUND_SOMEONE_ORDER_A_SHIP = 0xF9,
//     SOUND_OPENING_HELP_MENU = 0xFA,
//     SOUND_CLOSING_HELP_MENU = 0xFB,
//     SOUND_CANT_OPEN_HELP_MENU = 0xFC,
//     SOUND_TRIANGLE_QUIZ = 0xFD,
//     SOUND_HEALING = 0xFE,
//     SONG_HEALING_RS = 0x105,
//     SONG_LEVEL_UP = 0x106,
//     SONG_EVOLUTION_START = 0x107,
//     SONG_EVOLUTION_SAFARI = 0x108,
//     SONG_BATTLE_1 = 0x109,
//     SONG_BATTLE_2 = 0x10A,
//     SONG_UNKNOWN_10B = 0x10B,
//     SONG_FANFARE_1 = 0x10C,
//     SONG_FANFARE_2 = 0x10D,
//     SONG_YOU_FAIL_IT = 0x10E,
//     SONG_YOU_FAIL_IT_AGAIN = 0x10F,
//     SONG_FOLLOW_ME = 0x110,
//     SONG_GAME_CORNER = 0x111,
//     SONG_EVIL_LURKS = 0x112,
//     SONG_GYM = 0x113,
//     SONG_JIGGLYPUFFS_SONG = 0x114,
//     SONG_INTRODUCTION = 0x115,
//     SONG_POKEMON_THEME = 0x116,
//     SONG_CINNABAR_ISLAND = 0x117,
//     SONG_LAVENDER_TOWN = 0x118,
//     SONG_HEALING = 0x119,
//     SONG_BICYCLE = 0x11A,
//     SONG_ENCOUNTER_1 = 0x11B,
//     SONG_ENCOUNTER_2 = 0x11C,
//     SONG_ENCOUNTER_3 = 0x11D,
//     SONG_YOURE_IN_THE_HALL_OF_FAME = 0x11E,
//     SONG_VIRIDIAN_FOREST = 0x11F,
//     SONG_MOUNT_MOON = 0x120,
//     SONG_ABANDONED_PLACE = 0x121,
//     SONG_END_CREDITS = 0x122,
//     SONG_ROUTE_THEME_1 = 0x123,
//     SONG_ROUTE_THEME_2 = 0x124,
//     SONG_ROUTE_THEME_3 = 0x125,
//     SONG_ROUTE_THEME_4 = 0x126,
//     SONG_INDIGO_PLATEAU = 0x127,
//     SONG_BATTLE_3 = 0x128,
//     SONG_BATTLE_4 = 0x129,
//     SONG_BATTLE_5 = 0x12A,
//     SONG_BATTLE_6 = 0x12B,
//     SONG_PALLET_TOWN = 0x12C,
//     SONG_OAKS_LAB = 0x12D,
//     SONG_OAKS_THEME = 0x12E,
//     SONG_POKEMON_CENTER = 0x12F,
//     SONG_SS_ANNE = 0x130,
//     SONG_SURFS_UP = 0x131,
//     SONG_POKEMON_TOWER = 0x132,
//     SONG_SILPH_CO = 0x133,
//     SONG_CERULEAN_CITY = 0x134,
//     SONG_CELADON_CITY = 0x135,
//     SONG_VICTORY_1 = 0x136,
//     SONG_VICTORY_2 = 0x137,
//     SONG_VICTORY_3 = 0x138,
//     SONG_VERMILLON_CITY = 0x139,
//     SONG_VIRIDIAN_CITY_AND_PEWTER_CITY = 0x13A,
//     SONG_GARYS_THEME = 0x13B,
//     SONG_GARYS_THEME_BIS = 0x13C,
//     SONG_FANFARE_3 = 0x13D,
//     SONG_FANFARE_4 = 0x13E,
//     SONG_YOU_CAUGHT_A_POKEMON = 0x13F,
//     SONG_TRAINER_CARD_PHOTO = 0x140,
//     SONG_GAME_FREAK = 0x141,
//     SONG_VICTORY_2_BIS = 0x142,
//     SONG_INTRO_MESSAGE_1 = 0x143,
//     SONG_INTRO_MESSAGE_2 = 0x144,
//     SONG_INTRO_MESSAGE_3 = 0x145,
//     SONG_GAME_CORNER_1 = 0x146,
//     SONG_GAME_CORNER_2 = 0x147,
//     SONG_NET_CORNER = 0x148,
//     SONG_MYSTERY_CONNECTION = 0x149,
//     SONG_GAME_CORNER_3 = 0x14A,
//     SONG_MOUNT_EMBER = 0x14B,
//     SONG_FOLLOW_ME_ALT = 0x14C,
//     SONG_WATER_LABYRINTH = 0x14D,
//     SONG_TANOBY_RUINS = 0x14E,
//     SONG_ISLANDS_1_2_3 = 0x14F,
//     SONG_ISLANDS_4_5 = 0x150,
//     SONG_ISLANDS_6_7 = 0x151,
//     SONG_POKE_FLUTE = 0x152,
//     SONG_BATTLE_DEOXYS = 0x153,
//     SONG_BATTLE_5_1 = 0x154,
//     SONG_BATTLE_5_2 = 0x155,
//     SONG_ENCOUNTER_4 = 0x156,
//     SONG_DEOXYS_ENCOUNTER = 0x157,
//     SONG_TRAINER_TOWER = 0x158,
//     SONG_PALLET_TOWN_REMIX = 0x159,
//     SONG_TEACHY_TV = 0x15A,
// };

/**
 * Play a sound effect.
 * @address{BPRE,080722CC}
 */
POKEAGB_EXTERN void PlayBGM(enum Sound sound);

/**
 * Play a sound effect.
 * @address{BPRE,080722CC}
 */
POKEAGB_EXTERN void PlaySE(enum Sound sound);

/**
 * change music for battle.
 * @address{BPRE,08044090}
 */
POKEAGB_EXTERN void PlayMapChosenOrBattleBGM(u16);

/**
 * Check is sound effect is playing
 * @address{BPRE,080723E0}
 */
POKEAGB_EXTERN bool IsSEPlaying(void);

/**
 * Unsure. Need info.
 * @address{BPRE,080722F4}
 */
POKEAGB_EXTERN void PlaySE12WithPanning(u8 sound_effect, u16 sound_another);


POKEAGB_END_DECL

#endif /* POKEAGB_CORE_AUDIO_H_ */
