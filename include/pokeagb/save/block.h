/**
 * @file
 * @brief Game save data.
 */

#ifndef POKEAGB_SAVE_BLOCK_H_
#define POKEAGB_SAVE_BLOCK_H_

#include <pokeagb/types.h>
#include <pokeagb/common.h>
#include <pokeagb/version.h>
#include <pokeagb/core/string.h>
#include <pokeagb/overworld/npc.h>
#include <pokeagb/overworld/map.h>
#include <pokeagb/pokemon/data.h>
#include <pokeagb/pokemon/pokedex.h>
#include <pokeagb/graphics/sprites.h>

POKEAGB_BEGIN_DECL

#define PLAYER_NAME_LENGTH 8
#define MAP_OBJECTS_COUNT  16
#define BERRY_TREES_COUNT  128
#define FLAGS_COUNT        288 // 300
#define VARS_COUNT         256
#define MAIL_COUNT         16
#define NUM_EASY_CHAT_EXTRA_PHRASES 33
#define EASY_CHAT_EXTRA_PHRASES_SIZE ((NUM_EASY_CHAT_EXTRA_PHRASES >> 3) + (NUM_EASY_CHAT_EXTRA_PHRASES % 8 ? 1 : 0))
#define OT_NAME_LENGTH 7
#define PC_ITEMS_COUNT      30
#define BAG_ITEMS_COUNT     42
#define BAG_KEYITEMS_COUNT  30
#define BAG_POKEBALLS_COUNT 13
#define BAG_TMHM_COUNT      58
#define BAG_BERRIES_COUNT   43
#define NUM_GAME_STATS      64

#define ADDED_FLAGS         0xFFF
#define ADDED_VARS          0x1FF

struct SaveBlockChunk {
    u8* data;
    u16 size;
};

struct SaveSectionOffset {
    u16 toAdd; // offset really
    u16 size;
};


/* Save block 1 structs */
struct ItemSlot {
    u16 itemId;
    u16 quantity;
};

// An entry in the log for the "previously on your quest" feature.
struct QuestLogNPCData {
    u32 x:8;
    u32 negx:1;
    u32 y:8;
    u32 negy:1;
    u32 elevation:6;
    u32 movementType:8;
};

struct QuestLog {
    /*0x0000*/ u8 unk_000;
    /*0x0001*/ s8 unk_001;
    /*0x0002*/ s8 unk_002;
    /*0x0003*/ s8 unk_003;
    /*0x0004*/ s16 unk_004;
    /*0x0006*/ s16 unk_006;
    /*0x0008*/ u8 filler_008[0x140];

    // These arrays hold the game state for
    // playing back the quest log
    /*0x0148*/ u8 flags[0x120];
    /*0x02c8*/ u16 vars[0x100];
    /*0x0468*/ struct QuestLogNPCData npcData[64];
    /*0x0568*/ u16 unk_568[128];
    /*0x0668*/ u16 end[0];
};

struct MailStruct {
    /*0x00*/ u16 words[9];
    /*0x12*/ u8 playerName[8];
    /*0x1A*/ u8 trainerId[4];
    /*0x1E*/ u16 species;
    /*0x20*/ u16 itemId;
};

struct EasyChatPair {
    u16 unk0_0:7;
    u16 unk0_7:7;
    u16 unk1_6:1;
    u16 unk2;
    u16 words[2];
}; /*size = 0x8*/

struct DaycareMiscMon {
    struct MailStruct mail;
    u8 OT_name[OT_NAME_LENGTH + 1];
    u8 monName[POKEMON_NAME_LENGTH + 1];
    u8 gameLanguage:4;
    u8 monLanguage:4;
};

struct DaycareMon {
    struct BoxPokemon mon;
    struct DaycareMiscMon misc;
    u32 steps;
};

#define DAYCARE_MON_COUNT   2
struct DayCare {
    struct DaycareMon mons[DAYCARE_MON_COUNT];
    u16 unk_118;
    u8 unk_11A;
};

struct UnkMauvilleOldManStruct
{
    u8 unk_2D94;
    u8 unk_2D95;
    /*0x2D96*/ u16 mauvilleOldMan_ecArray[6];
    /*0x2DA2*/ u16 mauvilleOldMan_ecArray2[6];
    /*0x2DAE*/ u8 playerName[8];
    /*0x2DB6*/ u8 filler_2DB6[0x3];
    /*0x2DB9*/ u8 playerTrainerId[4];
    u8 unk_2DBD;
}; /*size = 0x2C*/

struct UnkMauvilleOldManStruct2
{
    u8 filler0;
    u8 unk1;
    u8 unk2;
    u16 mauvilleOldMan_ecArray[10];
    u8 mauvilleOldMan_ecArray2[12];
    u8 fillerF[0x2];
}; /*size = 0x2C*/

struct MauvilleOldManTrader
{
    u8 unk0;
    u8 unk1[4];
    u8 unk5[4][11];
    u8 unk31;
};

typedef union OldMan
{
    struct UnkMauvilleOldManStruct oldMan1;
    struct UnkMauvilleOldManStruct2 oldMan2;
    struct MauvilleOldManTrader trader;
    u8 filler[0x40];
} OldMan;

struct Roamer {
    /*0x00*/ u32 ivs;
    /*0x04*/ u32 personality;
    /*0x08*/ u16 species;
    /*0x0A*/ u16 hp;
    /*0x0C*/ u8 level;
    /*0x0D*/ u8 status;
    /*0x0E*/ u8 cool;
    /*0x0F*/ u8 beauty;
    /*0x10*/ u8 cute;
    /*0x11*/ u8 smart;
    /*0x12*/ u8 tough;
    /*0x13*/ bool active;
    /*0x14*/ u8 filler[0x8];
};

#define BERRY_NAME_COUNT 7
#define BERRY_ITEM_EFFECT_COUNT 18
struct Berry2 {
    u8 name[BERRY_NAME_COUNT];
    u8 firmness;
    u16 size;
    u8 maxYield;
    u8 minYield;
    u8 *description1;
    u8 *description2;
    u8 stageDuration;
    u8 spicy;
    u8 dry;
    u8 sweet;
    u8 bitter;
    u8 sour;
    u8 smoothness;
};

struct EnigmaBerry {
    struct Berry2 berry;
    u8 itemEffect[BERRY_ITEM_EFFECT_COUNT];
    u8 holdEffect;
    u8 holdEffectParam;
    u32 checksum;
};

struct MEventBuffer_3120_Sub {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04[40];
    u8 unk_2C[10][40];
};

struct MEventBuffer_3120 {
    u32 crc;
    struct MEventBuffer_3120_Sub data;
};

struct MEventBuffer_32E0_Sub
{
    u16 unk_00;
    u16 unk_02;
    u32 unk_04;
    u8 unk_08_0:2;
    u8 unk_08_2:4;
    u8 unk_08_6:2;
    u8 unk_09;
    u8 unk_0A[40];
    u8 unk_32[40];
    u8 unk_5A[4][40];
    u8 unk_FA[40];
    u8 unk_122[40];
};

struct MEventBuffer_32E0 {
    u32 crc;
    struct MEventBuffer_32E0_Sub data;
};

struct MEventBuffer_3430_Sub {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08[2][7];
};

struct MEventBuffer_3430 {
    u32 crc;
    struct MEventBuffer_3430_Sub data;
};

struct MysteryEventStruct
{
    u8 unk_0_0:2;
    u8 unk_0_2:3;
    u8 unk_0_5:3;
    u8 unk_1;
};

struct MEventBuffers {
    /*0x000 0x3120*/ struct MEventBuffer_3120 buffer_000;
    /*0x1c0 0x32e0*/ struct MEventBuffer_32E0 buffer_1c0;
    /*0x310 0x3430*/ struct MEventBuffer_3430 buffer_310;
    /*0x338 0x3458*/ u16 unk_338[4];
    /*0x340 0x3460*/ struct MysteryEventStruct unk_340;
    /*0x344 0x3464*/ u32 unk_344[2][5];
}; // 0x36C 0x348C

struct RamScriptData
{
    u8 magic;
    u8 mapGroup;
    u8 mapNum;
    u8 objectId;
    u8 script[995];
};

struct RamScript
{
    u32 checksum;
    struct RamScriptData data;
};

struct FameCheckerSaveData
{
    /*3a54*/ u16 pickState:2;
    u16 flavorTextFlags:12;
    u16 unk_0_E:2;
};

enum {
    FAMECHECKER_OAK,
    FAMECHECKER_DAISY,
    FAMECHECKER_BROCK,
    FAMECHECKER_MISTY,
    FAMECHECKER_LTSURGE,
    FAMECHECKER_ERIKA,
    FAMECHECKER_KOGA,
    FAMECHECKER_SABRINA,
    FAMECHECKER_BLAINE,
    FAMECHECKER_LORELEI,
    FAMECHECKER_BRUNO,
    FAMECHECKER_AGATHA,
    FAMECHECKER_LANCE,
    FAMECHECKER_BILL,
    FAMECHECKER_MRFUJI,
    FAMECHECKER_GIOVANNI,
    NUM_FAMECHECKER_PERSONS
};

struct TrainerTowerLog
{
    u32 unk0;
    u32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA_0:1;
    u8 unkA_1:1;
    u8 unkA_2:1;
    u8 unkA_3:1;
    u8 unkA_4:1;
    u8 unkA_5:1;
    u8 unkA_6:2;
};


/**
 * Main save game data.
 */
struct SaveBlock1 {
    /*0x0000*/ struct Coords16 pos;
    /*0x0004*/ struct WarpData location;
    /*0x000C*/ struct WarpData warp1;
    /*0x0014*/ struct WarpData warp2;
    /*0x001C*/ struct WarpData lastHealLocation;
    /*0x0024*/ struct WarpData warp4;
    /*0x002C*/ u16 savedMusic;
    /*0x002E*/ u8 weather;
    /*0x002F*/ u8 filler_2F;
    /*0x0030*/ u8 flashLevel;
    /*0x0031*/ u8 filler_31;
    /*0x0032*/ u16 mapDataId;
    /*0x0034*/ u8 playerPartyCount;
    /*0x0038*/ struct Pokemon playerParty[POKEMON_PARTY_SIZE];
    /*0x0290*/ u32 money;
    /*0x0294*/ u16 coins;
    /*0x0296*/ u16 registeredItem; // registered for use with SELECT button
    /*0x0298*/ struct ItemSlot pcItems[PC_ITEMS_COUNT];
    /*0x0310*/ struct ItemSlot bagPocket_Items[BAG_ITEMS_COUNT];
    /*0x03b8*/ struct ItemSlot bagPocket_KeyItems[BAG_KEYITEMS_COUNT];
    /*0x0430*/ struct ItemSlot bagPocket_PokeBalls[BAG_POKEBALLS_COUNT];
    /*0x0464*/ struct ItemSlot bagPocket_TMHM[BAG_TMHM_COUNT];
    /*0x054c*/ struct ItemSlot bagPocket_Berries[BAG_BERRIES_COUNT];
    /*0x05F8*/ u8 seen1[DEX_FLAGS_NO];
    /*0x062C*/ u16 berryBlenderRecords[3]; // unused
    /*0x0632*/ u8 field_632[6]; // unused?
    /*0x0638*/ u8 trainerRematchStepCounter;
    /*0x063A*/ u8 ALIGNED(2) trainerRematches[100];
    /*0x06A0*/ struct ObjectEvent ObjectEvents[16];
    /*0x08E0*/ struct ObjectEventTemplate ObjectEventTemplates[64];
    /*0x0EE0*/ u8 flags[FLAGS_COUNT];
    /*0x1000*/ u16 vars[VARS_COUNT];
    /*0x1200*/ u32 gameStats[NUM_GAME_STATS];
    /*0x1300*/ struct QuestLog questLog[4];
    /*0x2CA0*/ u16 unk2CA0[6];
    /*0x2CAC*/ u16 unk2CAC[6];
    /*0x2CB8*/ u16 unk2CB8[6];
    /*0x2CC4*/ u16 unk2CC4[6];
    /*0x2CD0*/ struct MailStruct mail[MAIL_COUNT];
    /*0x2F10*/ u8 additionalPhrases[EASY_CHAT_EXTRA_PHRASES_SIZE];
    /*0x2F18*/ OldMan oldMan; // unused
    /*0x2F54*/ struct EasyChatPair easyChatPairs[5]; // unused
    /*0x2F80*/ struct DayCare daycare;
    /*0x309C*/ u8 giftRibbons[52];
    /*0x30D0*/ struct Roamer roamer;
    /*0x30EC*/ struct EnigmaBerry enigmaBerry;
    /*0x3120*/ struct MEventBuffers unk_3120;
    /*0x348C*/ u8 filler_348C[400];
    /*0x361C*/ struct RamScript ramScript;
    /*0x3A08*/ u8 filler3A08[12];
    /*0x3A14*/ u8 seen2[DEX_FLAGS_NO];
    /*0x3A48*/ u8 filler_3a48[4];
    /*0x3A4C*/ u8 rivalName[PLAYER_NAME_LENGTH];
    /*0x3A54*/ struct FameCheckerSaveData fameChecker[NUM_FAMECHECKER_PERSONS];
    /*0x3A94*/ u8 filler3A94[0x2A0];
    /*0x3D34*/ u32 unkArrayIdx;
    /*0x3D38*/ struct TrainerTowerLog unkArray[4];
    };

enum Gender {
    GENDER_MALE,
    GENDER_FEMALE,
};

struct Time {
    /*0x00*/ s16 days;
    /*0x02*/ s8 hours;
    /*0x03*/ s8 minutes;
    /*0x04*/ s8 seconds;
};

struct UnkSaveBlock2Substruct_55C
{
    /* 0x000:0x55C */ u8 unk_00_0:1;
    u8 unk_00_1:1;
    /* 0x001:0x55D */ u8 unk_01;
    /* 0x002:0x55E */ u8 unk_02[2];
    /* 0x004:0x560 */ u16 unk_04[2];
    /* 0x008:0x564 */ u16 unk_08[2];
    /* 0x00C:0x568 */ u16 unk_0C[2];
    /* 0x010:0x56C */ u8 unk_10;
    /* 0x011:0x56D */ u8 unk_11[3];
    /* 0x014:0x570 */ u16 unk_14;
    /* 0x016:0x572 */ u8 unk_16;
}; // size: 0x018

#define LINK_B_RECORDS_COUNT 5

struct LinkBattleRecord {
    u8 name[PLAYER_NAME_LENGTH];
    u16 trainerId;
    u16 wins;
    u16 losses;
    u16 draws;
};

struct LinkBattleRecords {
    struct LinkBattleRecord entries[LINK_B_RECORDS_COUNT];
    u8 languages[LINK_B_RECORDS_COUNT];
};

struct BerryCrush {
    u16 berryCrushResults[4];
    u32 berryPowderAmount;
    u32 unk;
};

/**
 * Trainer and miscellaneous save data.
 */
 struct SaveBlock2
 {
     /*0x000*/ u8 playerName[PLAYER_NAME_LENGTH];
     /*0x008*/ u8 playerGender; // MALE, FEMALE
     /*0x009*/ u8 specialSaveWarp;
     /*0x00A*/ u8 playerTrainerId[4];
     /*0x00E*/ u16 playTimeHours;
     /*0x010*/ u8 playTimeMinutes;
     /*0x011*/ u8 playTimeSeconds;
     /*0x012*/ u8 playTimeVBlanks;
     /*0x013*/ u8 optionsButtonMode;  // OPTIONS_BUTTON_MODE_[NORMAL/LR/L_EQUALS_A]
     /*0x014*/ u16 optionsTextSpeed:3; // OPTIONS_TEXT_SPEED_[SLOW/MID/FAST]
     u16 optionsWindowFrameType:5; // Specifies one of the 20 decorative borders for text boxes
     u16 optionsSound:1; // OPTIONS_SOUND_[MONO/STEREO]
     u16 optionsBattleStyle:1; // OPTIONS_BATTLE_STYLE_[SHIFT/SET]
     u16 optionsBattleSceneOff:1; // whether battle animations are disabled
     u16 regionMapZoom:1; // whether the map is zoomed in
     /*0x018*/ struct Pokedex pokedex;
     /*0x090*/ u8 filler_90[0x8];
     /*0x098*/ struct Time localTimeOffset;
     /*0x0A0*/ struct Time lastBerryTreeUpdate;
     /*0x0A8*/ u32 field_A8;
     /*0x0AC*/ u8 filler_AC[0x3F4];
     /*0x4A0*/ u32 unk_4A0[0x2F];
     /*0x55c*/ struct UnkSaveBlock2Substruct_55C unk_55C;
     /*0x574*/ u8 filler_574[0x324];
     /*0x898*/ u16 mapView[0x100];
     /*0xA98*/ struct LinkBattleRecords linkBattleRecords;
     /*0xAF0*/ struct BerryCrush berryCrush;
     /*0xB00*/ u8 filler_B00[0x420];
     /*0xF20*/ u32 encryptionKey;
 };

ASSERT_SIZEOF(struct SaveBlock2, 0xF20);

/**
 * Pokemon storage related save data.
 */
struct SaveBlock3 {
  u8 preferred_box;
  u8 gap_1[3];
  struct BoxPokemon bills_pc[420];
  pchar box_names[14][9];
};

ASSERT_SIZEOF(struct SaveBlock3, 0x83C2);

/**
 * @address{BPRE,03005008}
 */
extern struct SaveBlock1* gSaveBlock1Ptr;

/**
 * @address{BPRE,0300500C}
 */
extern struct SaveBlock2* gSaveBlock2Ptr;

/**
 * @address{BPRE,03005010}
 */
extern struct SaveBlock3* saveblock3;

/**
 * @address{BPRE,030053B0}
 */
extern struct SaveBlockChunk gRamSaveSectionLocations[0xE];

POKEAGB_END_DECL

#endif /* POKEAGB_SAVE_BLOCKH_ */
