/**
 * @file
 * @brief Overworld characters.
 */

#ifndef POKEAGB_OVERWORLD_NPC_H_
#define POKEAGB_OVERWORLD_NPC_H_

#include <pokeagb/types.h>
#include <pokeagb/common.h>
#include <pokeagb/graphics/sprites.h>

POKEAGB_BEGIN_DECL

/**
 * The player's NPC local ID.
 */
#define NPC_LOCAL_ID_PLAYER 0xFF

/**
 * Invalid NPC state ID.
 */
#define NPC_STATE_ID_MAX 0x10
#define OBJECT_EVENTS_COUNT 0x10


#define MOVEMENT_TYPE_PLAYER 0xB
#define MOVEMENT_TYPE_INVISIBLE 0x4C

/**
 * An NPC in the overworld.
 */
struct ObjectEvent {
    /*0x00*/ u32 active:1;
             u32 singleMovementActive:1;
             u32 triggerGroundEffectsOnMove:1;
             u32 triggerGroundEffectsOnStop:1;
             u32 disableCoveringGroundEffects:1;
             u32 landingJump:1;
             u32 heldMovementActive:1;
             u32 heldMovementFinished:1;
    /*0x01*/ u32 frozen:1;
             u32 facingDirectionLocked:1;
             u32 disableAnim:1;
             u32 enableAnim:1;
             u32 inanimate:1;
             u32 invisible:1;
             u32 offScreen:1;
             u32 trackedByCamera:1;
    /*0x02*/ u32 isPlayer:1;
             u32 hasReflection:1;
             u32 inShortGrass:1;
             u32 inShallowFlowingWater:1;
             u32 inSandPile:1;
             u32 inHotSprings:1;
             u32 hasShadow:1;
             u32 spriteAnimPausedBackup:1;
    /*0x03*/ u32 spriteAffineAnimPausedBackup:1;
             u32 disableJumpLandingGroundEffect:1;
             u32 fixedPriority:1;
             u32 unk3_3:1;
             u32 unused:4;
    /*0x04*/ u8 spriteId;
    /*0x05*/ u8 graphicsId;
    /*0x06*/ u8 movementType;
    /*0x07*/ u8 trainerType;
    /*0x08*/ u8 localId;
    /*0x09*/ u8 mapNum;
    /*0x0A*/ u8 mapGroup;
    /*0x0B*/ u8 currentElevation:4;
             u8 previousElevation:4;
    /*0x0C*/ struct Coords16 initialCoords;
    /*0x10*/ struct Coords16 currentCoords;
    /*0x14*/ struct Coords16 previousCoords;
    /*0x18*/ u8 facingDirection : 4;
    /*0x18*/ u8 movementDirection : 4;


    /*0x19*/ union __attribute__((packed)) {
        u8 as_byte;
        struct __attribute__((packed)) {
            u8 x:4;
            u8 y:4;
        } __attribute__((aligned (1))) as_nybbles;
    } __attribute__((aligned (1))) range;
    /*0x1A*/ u8 fieldEffectSpriteId;
    /*0x1B*/ u8 warpArrowSpriteId;
    /*0x1C*/ u8 movementActionId;
    /*0x1D*/ u8 trainerRange_berryTreeId;
    /*0x1E*/ u8 currentMetatileBehavior;
    /*0x1F*/ u8 previousMetatileBehavior;
    /*0x20*/ u8 previousMovementDirection;
    /*0x21*/ u8 directionSequenceIndex;
    /*0x22*/ u8 playerCopyableMovement;
    /*size = 0x24*/
};

// player running states
enum
{
    NOT_MOVING,
    TURN_DIRECTION, // not the same as turning! turns your avatar without moving. also known as a turn frame in some circles
    MOVING,
};

enum
{
    DIR_NONE = 0,
    DIR_SOUTH, // 1
    DIR_NORTH, // 2
    DIR_WEST, // 3
    DIR_EAST, // 4
    DIR_SOUTHWEST, // 5
    DIR_SOUTHEAST, // 6
    DIR_NORTHWEST, // 7
    DIR_NORTHEAST, // 8
};

// player tile transition states
enum
{
    T_NOT_MOVING,
    T_TILE_TRANSITION,
    T_TILE_CENTER, // player is on a frame in which they are centered on a tile during which the player either stops or keeps their momentum and keeps going, changing direction if necessary.
};

#define PLAYER_AVATAR_FLAG_ON_FOOT    (1 << 0)
#define PLAYER_AVATAR_FLAG_MACH_BIKE  (1 << 1)
#define PLAYER_AVATAR_FLAG_ACRO_BIKE  (1 << 2)
#define PLAYER_AVATAR_FLAG_SURFING    (1 << 3)
#define PLAYER_AVATAR_FLAG_UNDERWATER (1 << 4)
#define PLAYER_AVATAR_FLAG_FIELD_MOVE (1 << 5)
#define PLAYER_AVATAR_FLAG_FISHING    (1 << 6)
#define PLAYER_AVATAR_FLAG_WATERING   (1 << 7)

/**
 * The player's movement state.
 */
 struct PlayerAvatar /* 02037078 */
 {
     /*0x00*/ u8 flags; // & 0x6 means biking(?)
     /*0x01*/ u8 unk1; // used to be named bike, but its definitely not that. seems to be some transition flags
     /*0x02*/ u8 runningState; // this is a static running state. 00 is not moving, 01 is turn direction, 02 is moving.
     /*0x03*/ u8 tileTransitionState; // this is a transition running state: 00 is not moving, 01 is transition between tiles, 02 means you are on the frame in which you have centered on a tile but are about to keep moving, even if changing directions. 2 is also used for a ledge hop, since you are transitioning.
     /*0x04*/ u8 spriteId;
     /*0x05*/ u8 ObjectEventId;
     /*0x06*/ u8 preventStep;
     /*0x07*/ u8 gender;
     /*0x08*/ u8 acroBikeState; // 00 is normal, 01 is turning, 02 is standing wheelie, 03 is hopping wheelie
     /*0x09*/ u8 newDirBackup; // during bike movement, the new direction as opposed to player's direction is backed up here.
     /*0x0A*/ u8 bikeFrameCounter; // on the mach bike, when this value is 1, the bike is moving but not accelerating yet for 1 tile. on the acro bike, this acts as a timer for acro bike.
     /*0x0B*/ u8 bikeSpeed;
 	// acro bike only
     /*0x0C*/ u32 directionHistory; // up/down/left/right history is stored in each nybble, but using the field directions and not the io inputs.
     /*0x10*/ u32 abStartSelectHistory; // same as above but for A + B + start + select only
 	// these two are timer history arrays which [0] is the active timer for acro bike. every element is backed up to the next element upon update.
     /*0x14*/ u8 dirTimerHistory[8];
     /*0x1C*/ u8 abStartSelectTimerHistory[8];
 };

/**
 * An NPC in the ROM.
 */
struct ObjectEventTemplate {
    u8 localId;
    u8 graphicsId;
    u8 rival;
    u8 field3;
    u16 x;
    u16 y;
    u8 elevation;
    u8 movementType;
    u8 movement_area;
    u8 fieldB;
    u8 trainer_or_mapnumber;
    u8 fieldD;
    u8 sight_distance_or_mapbank;
    u8* script;
    u16 flagId;
    u16 field16;
};


/**
 * The player's movement state.
 *
 * @address{BPRE,02037078}
 */
extern struct PlayerAvatar gPlayerAvatar;

/**
 * Currently loaded NPCs.
 *
 * @address{BPRE,02036E38}
 */
extern struct ObjectEvent gObjectEvents[16];

struct ObjectEventGraphicsInfo {
    /*0x00*/ u16 tileTag;
    /*0x02*/ u16 paletteTag;
    /*0x04*/ u16 bridgeReflectionPaletteTag;
    /*0x06*/ u16 size;
    /*0x08*/ s16 width;
    /*0x0A*/ s16 height;
    /*0x0C*/ u8 paletteSlot:4;
             u8 shadowSize:2;
             u8 inanimate:1;
             u8 disableReflectionPaletteLoad:1;
    /*0x0D*/ u8 tracks;
    /*0x10*/ const struct OamData *oam;
    /*0x14*/ const struct SubspriteTable *subspriteTables;
    /*0x18*/ const union AnimCmd *const *anims;
    /*0x1C*/ const struct SpriteFrameImage *images;
    /*0x20*/ const struct RotscaleFrame (**rotscale_table)[];
};


/**
* Graphics info for all npcs
* @address{BPRE,0839FDB0}
*/
extern const struct ObjectEventGraphicsInfo *const gObjectEventGraphicsInfoPointers[];

/**
 * @address{BPRE,080DAE40}
 */
POKEAGB_EXTERN s16 GetReflectionVerticalOffset(struct ObjectEvent * objectEvent);

/**
 * @address{BPRE,0805F2C8}
 */
POKEAGB_EXTERN struct ObjectEventGraphicsInfo *GetObjectEventGraphicsInfo(u8);

/**
 * @address{BPRE,0806E5A4}
 */
POKEAGB_EXTERN u8 VarGetObjectEventGraphicsId(u8 idx);


/**
 * @address{BPRE,080DAF50}
 */
POKEAGB_EXTERN void UpdateObjectReflectionSprite(struct Sprite * reflectionSprite);

/**
 * Reset NPC state with no checks.
 *
 * @address{BPRE,08063D34}
 */
POKEAGB_EXTERN u8 npc_half_reset_no_checks(struct ObjectEvent* npc);

/**
 *
 * @address{BPRE,0805F4B0}
 */
POKEAGB_EXTERN void LoadObjectEventPalette(u16 paletteTag);

/**
 *
 * @address{BPRE,08063AD4}
 */
POKEAGB_EXTERN void sub_8063AD4(s16 x, s16 y, s16 *destX, s16 *destY);

/**
 *
 * @address{BPRE,080679F8}
 */
POKEAGB_EXTERN void UpdateObjectEventVisibility(struct ObjectEvent *, struct Sprite *);


/**
 * @address{BPRE,0805BEB8}
 */
POKEAGB_EXTERN void npc_apply_direction(struct ObjectEvent *ObjectEvent, struct Sprite *sprite, u8 direction, u8 speed);

/**
 * @address{BPRE,08063554}
 */
POKEAGB_EXTERN void npc_apply_anim_looping(struct ObjectEvent *ObjectEvent, struct Sprite *sprite, u8 direction);

/**
 * @address{BPRE,0806DB84}
 */
POKEAGB_EXTERN u8 IsStaircase(u8 behavior, u8 direction);

/**
 *
 * @address{BPRE,0805BEB8}
 */
POKEAGB_EXTERN void sub_805BEB8(void);

/**
 * Reset NPC when state->bitfield & 0x40
 *
 * @address{BPRE,08063D1C}
 */
POKEAGB_EXTERN void npc_half_reset(struct ObjectEvent* npc);

/**
 * Set the NPC to have the given state (applymovement values) and apply associated animation.
 *
 * @address{BPRE,08063CA4}
 */
POKEAGB_EXTERN int npc_set_state_2(struct ObjectEvent* npc, u8 state);

/**
 * Reset the NPC when state->bitfield & 0x80 (set by some tile behaviors)
 *
 * @address{BPRE,08063D7C}
 */
POKEAGB_EXTERN u8 npc_half_reset_when_bit7_is_set(struct ObjectEvent* npc);

/**
 * Find an NPC given their local ID on a given map and bank.
 *
 * @address{BPRE,0805FD5C}
 */
POKEAGB_EXTERN struct ObjectEventTemplate* GetObjectEventTemplateByLocalIdAndMap(u8 local_id, u8 map, u8 bank);

/**
 * Find an NPC given their local ID on a given map and bank.
 *
 * @address{BPRE,0805E898}
 */
POKEAGB_EXTERN u8 TrySpawnObjectEvent(u8 localId, u8 num, u8 bank);

/**
 *
 * @address{BPRE,0805F7C4}
 */
POKEAGB_EXTERN void TryMoveObjectEventToMapCoords(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y);

/**
 * Spawn a new NPC.
 *
 * @address{BPRE,0805E72C}
 */
POKEAGB_EXTERN u8 TrySpawnObjectEventTemplate(struct ObjectEventTemplate*,
                                              u8 map,
                                              u8 bank,
                                              s16 x_shift,
                                              s16 y_shift);

/**
 * Change the NPC's sprite.
 *
 * @address{BPRE,0805F060}
 */
POKEAGB_EXTERN void npc_change_sprite(struct ObjectEvent* npc, u8 sprite);

/**
 * Make the NPC face a given direction.
 *
 * @address{BPRE,0805F218}
 */
POKEAGB_EXTERN void ObjectEventTurn(struct ObjectEvent* npc, u8 direction);

/**
 * Exclamation mark animation over npc.
 *
 * @address{BPRE,08066920}
 */
POKEAGB_EXTERN void an_exclamation_mark(struct ObjectEvent* npc, struct Sprite* obj);

/**
 * Translate a local ID to an NPC state ID.
 * Map and bank are ignored if local_id != NPC_LOCAL_ID_PLAYER.
 *
 * @param local_id A local ID (e.g. from applymovement).
 * @param map From this map number.
 * @param bank From this map bank number.
 * @return The NPC state id or NPC_STATE_ID_MAX on failure.
 *
 * @address{BPRE,0805DF60}
 */
POKEAGB_EXTERN u8 npc_id_by_local_id(u8 local_id, u8 map, u8 bank);

/**
 * set a direction an NPC will turn
 *
 * @address{BPRE,0805FBDC}
 */
POKEAGB_EXTERN void FieldObjectSetDirection(struct ObjectEvent* npc, u8 direction);

/**
 * Stop NPCs from moving around
 *
 * @address{BPRE,08068974}
 */
POKEAGB_EXTERN void FreezeObjectEvents();

/**
 * Stop Player from moving
 *
 * @address{BPRE,0805C780}
 */
POKEAGB_EXTERN void StopPlayerAvatar();

/**
 * Reset animation pauses
 *
 * @address{BPRE,0805B4B0}
 */
POKEAGB_EXTERN void npc_clear_strange_bits(struct ObjectEvent *objEvent);

/**
 * Reset animation pauses
 *
 * @address{BPRE,08063D34}
 */
POKEAGB_EXTERN void ObjectEventClearHeldMovement(struct ObjectEvent *objEvent);

/**
 * set x and y coords given a direction to move
 *
 * @address{BPRE,08063A20}
 */
POKEAGB_EXTERN void MoveCoords(u8 direction, s16 *x, s16 *y);

/**
 * @address{BPRE,0805C1AC}
 */
POKEAGB_EXTERN void PlayerNotOnBikeCollide(u8 direction);

/**
 * @address{BPRE,0806835C}
 */
POKEAGB_EXTERN bool AreZCoordsCompatible(u8 a, u8 b);

/**
 * @address{BPRE,0805F02C}
 */
POKEAGB_EXTERN void SetPlayerAvatarObjectEventIdAndObjectId(u8 objectEventId, u8 spriteId);

/**
 * @address{BPRE,080DB0C4}
 */
POKEAGB_EXTERN u8 CreateWarpArrowSprite();

/**
 * @address{BPRE,08063430}
 */
POKEAGB_EXTERN u8 GetFaceDirectionAnimNum(u8);

/**
 * @address{BPRE,0805EFF4}
 */
POKEAGB_EXTERN void sub_805EFF4(struct ObjectEvent *);

/**
 * @address{BPRE,0805F5E8}
 */
POKEAGB_EXTERN void LoadPlayerObjectReflectionPalette(u16, u8);

/**
 * @address{BPRE,0805F658}
 */
POKEAGB_EXTERN void LoadSpecialObjectReflectionPalette(u16, u8);

/**
 * @address{BPRE,0805E940}
 */
POKEAGB_EXTERN void MakeObjectTemplateFromObjectEventGraphicsInfoWithCallbackIndex(u16 graphicsId, u16 callbackIndex, struct Template *spriteTemplate, const struct SubspriteTable **subspriteTables);

/**
 * @address{BPRE,080682F8}
 */
POKEAGB_EXTERN void SetObjectSubpriorityByZCoord(u8 z, struct Sprite * sprite, u8 offset);

/**
 * @address{BPRE,0805E080}
 */
POKEAGB_EXTERN u8 InitObjectEventStateFromTemplate(struct ObjectEventTemplate* temp, u8 mapNum, u8 mapGroup);

/**
* @address{BPRE,0806883C}
*/
POKEAGB_EXTERN void DoGroundEffects_OnBeginStep(struct ObjectEvent*, struct Sprite*);

/**
 * @address{BPRE,08068890}
 */
POKEAGB_EXTERN void DoGroundEffects_OnFinishStep(struct ObjectEvent*, struct Sprite*);

/**
 * @address{BPRE,080687F0}
 */
POKEAGB_EXTERN void DoGroundEffects_OnSpawn(struct ObjectEvent*, struct Sprite*);


/**
 * Translate a local ID to an NPC state ID.
 * Map and bank are ignored if local_id != NPC_LOCAL_ID_PLAYER.
 *
 * @param local_id A local ID (e.g. from applymovement).
 * @param map From this map number.
 * @param bank From this map bank number.
 * @param id Pointer to store the result at.
 * @return true if the lookup failed.
 *
 * @address{BPRE,0805DF84}
 */
POKEAGB_EXTERN bool npc_id_by_local_id_and_map_ret_success(u8 local_id, u8 map, u8 bank, u8* id);

/**
 * @address{BPRE,080DAE54}
 */
POKEAGB_EXTERN void LoadObjectReflectionPalette(struct ObjectEvent* objevent, struct Sprite * sprite);

POKEAGB_END_DECL

#endif /* POKEAGB_OVERWORLD_NPC_H_ */
