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
 * Check if the player has an active animation already
 * @address{BPRE,0805BF7C}
 */
POKEAGB_EXTERN bool PlayerIsAnimActive(void);

/**
 *
 * @address{BPRE,0805BFC4}
 */
POKEAGB_EXTERN void PlayerSetCopyableMovement(u8 copyableMovement);

/**
 *
 * @address{BPRE,08063CA4}
 */
POKEAGB_EXTERN u8 EventObjectSetHeldMovement(struct EventObject *eventObject, u8 movementActionId);

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



#endif /* POKEAGB_MOVEMENT_ANIMATION_H_ */
