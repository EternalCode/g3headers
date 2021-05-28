/**
 * @file
 * @brief movement animation table
 */

#ifndef POKEAGB_MOVEMENT_ANIMATION_H_
#define POKEAGB_MOVEMENT_ANIMATION_H_

#include "../common.h"
#include "../types.h"
#include "npc.h"

/**
 * @address{BPRE,080646FC}
 */
POKEAGB_EXTERN void an_run_any(struct ObjectEvent *ObjectEvent, struct Sprite *sprite, u8 direction, u8 speed);

/**
 * @address{BPRE,08065F60}
 */
POKEAGB_EXTERN void StartRunningAnimSlow(struct ObjectEvent *ObjectEvent, struct Sprite *sprite, u8 direction);

/**
 * @address{BPRE,08064758}
 */
POKEAGB_EXTERN void StartRunningAnim(struct ObjectEvent *ObjectEvent, struct Sprite *sprite, u8 direction);

/**
 * @address{BPRE,08064788}
 */
POKEAGB_EXTERN bool npc_obj_ministep_stop_on_arrival(struct ObjectEvent *ObjectEvent, struct Sprite *sprite);

/**
 * @address{BPRE,080645F4}
 */
POKEAGB_EXTERN void FaceDirection(struct ObjectEvent *ObjectEvent, struct Sprite* s, u8 direction);

/**
 * @address{BPRE,0805FBDC}
 */
POKEAGB_EXTERN void SetObjectEventDirection(struct ObjectEvent *ObjectEvent, u8 direction);

/**
 * @address{BPRE,0805F818}
 */
POKEAGB_EXTERN void ShiftStillObjectEventCoords(struct ObjectEvent *ObjectEvent);

/**
 * @address{BPRE,08063440}
 */
POKEAGB_EXTERN u8 GetMoveDirectionAnimNum(u8 direction);

/**
 * @address{BPRE,0805BF7C}
 */
POKEAGB_EXTERN bool PlayerIsAnimActive(void);

/**
 * @address{BPRE,0806359C}
 */
POKEAGB_EXTERN void obj_npc_animation_step(struct ObjectEvent* ObjectEvent, struct Sprite* sprite, u8 animNum);

/**
 *
 * @address{BPRE,0805BFC4}
 */
POKEAGB_EXTERN void PlayerSetCopyableMovement(u8 copyableMovement);

/**
 *
 * @address{BPRE,08068A5C}
 */
POKEAGB_EXTERN void UnfreezeObjectEvents(void);

/**
 *
 * @address{BPRE,080689F4}
 */
POKEAGB_EXTERN void UnfreezeObjectEvent(struct ObjectEvent *objectEvent);

/**
 *
 * @address{BPRE,08063C70}
 */
POKEAGB_EXTERN bool ObjectEventIsMovementOverridden(struct ObjectEvent *objectEvent);

/**
 *
 * @address{BPRE,08063CA4}
 */
POKEAGB_EXTERN u8 old_ObjectEventSetHeldMovement(struct ObjectEvent *ObjectEvent, u8 movementActionId);

/**
 *
 * @address{BPRE,0806408C}
 */
POKEAGB_EXTERN u8 GetPlayerRunMovementAction(u32);

/**
 *
 * @address{BPRE,08063F84}
 */
POKEAGB_EXTERN u8 GetWalkNormalMovementAction(u32);

/**
 *
 * @address{BPRE,08064008}
 */
POKEAGB_EXTERN u8 GetPlayerBikeMovementAction(u32);

/**
 *
 * @address{BPRE,0805A0B4}
 */
POKEAGB_EXTERN u8 MetatileBehavior_IsNorthBlocked(u8);

/**
 *
 * @address{BPRE,0805A0D0}
 */
POKEAGB_EXTERN u8 MetatileBehavior_IsSouthBlocked(u8);

/**
 *
 * @address{BPRE,0805A07C}
 */
POKEAGB_EXTERN u8 MetatileBehavior_IsEastBlocked(u8);

/**
 *
 * @address{BPRE,0805A098}
 */
POKEAGB_EXTERN u8 MetatileBehavior_IsWestBlocked(u8);



#endif /* POKEAGB_MOVEMENT_ANIMATION_H_ */
