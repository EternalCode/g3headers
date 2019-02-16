/**
 * @file
 * @brief Game engine callbacks.
 */

#ifndef POKEAGB_CORE_CALLBACK_H_
#define POKEAGB_CORE_CALLBACK_H_

#include <pokeagb/types.h>
#include <pokeagb/common.h>
#include <pokeagb/graphics/sprites.h>

POKEAGB_BEGIN_DECL

typedef void (*MainCallback)(void);
typedef void (*IntrCallback)(void);
typedef void (*IntrFunc)(void);
typedef void (*EraseFlash)(u16);

/**
 * Bits for the keypad;
 */
enum Keypad {
    KEY_A = (1 << 0),
    KEY_B = (1 << 1),
    KEY_SELECT = (1 << 2),
    KEY_START = (1 << 3),
    KEY_RIGHT = (1 << 4),
    KEY_LEFT = (1 << 5),
    KEY_UP = (1 << 6),
    KEY_DOWN = (1 << 7),
    KEY_L = (1 << 8),
    KEY_R = (1 << 9),

    /** Directional pad mask */
    KEY_DPAD = (KEY_UP | KEY_DOWN | KEY_LEFT | KEY_RIGHT),
};

struct Main
{
    /*0x000*/ MainCallback callback1;
    /*0x004*/ MainCallback callback2;

    /*0x008*/ MainCallback savedCallback;

    /*0x00C*/ IntrCallback vblankCallback;
    /*0x010*/ IntrCallback hblankCallback;
    /*0x014*/ IntrCallback vcountCallback;
    /*0x018*/ IntrCallback serialCallback;

    /*0x01C*/ vu16 intrCheck;

    /*0x020*/ u32 *vblankCounter1;
    /*0x024*/ u32 vblankCounter2;

    /*0x028*/ enum Keypad heldKeysRaw;           // held keys without L=A remapping
    /*0x02A*/ enum Keypad newKeysRaw;            // newly pressed keys without L=A remapping
    /*0x02C*/ enum Keypad heldKeys;              // held keys with L=A remapping
    /*0x02E*/ enum Keypad newKeys;               // newly pressed keys with L=A remapping
    /*0x030*/ enum Keypad newAndRepeatedKeys;    // newly pressed keys plus key repeat
    /*0x032*/ enum Keypad keyRepeatCounter;      // counts down to 0, triggering key repeat
    /*0x034*/ u16 watchedKeysPressed; // whether one of the watched keys was pressed
    /*0x036*/ u16 watchedKeysMask;       // bit mask for watched keys

    /*0x038*/ struct OamData oamBuffer[128];

    /*0x438*/ u8 state;

    /*0x439*/ u8 oamLoadDisabled:1;
    /*0x439*/ u8 inBattle:1;
    /*0x439*/ u8 field_439_x4:1;
};


struct FieldInput
{
    u8 pressedAButton:1;
    u8 checkStandardWildEncounter:1;
    u8 pressedStartButton:1;
    u8 pressedSelectButton:1;
    u8 heldDirection:1;
    u8 heldDirection2:1;
    u8 tookStep:1;
    u8 pressedBButton:1;
    u8 input_field_1_0:1;
    u8 input_field_1_1:1;
    u8 input_field_1_2:1;
    u8 input_field_1_3:1;
    u8 input_field_1_4:1;
    u8 input_field_1_5:1;
    u8 input_field_1_6:1;
    u8 input_field_1_7:1;
    u8 dpadDirection;
};

/**
 * Set a primary per-frame callback.
 *
 * @address{BPRE,0806C888}
 */
POKEAGB_EXTERN void ptr_andeq_xFF00E000(struct FieldInput* in);


/**
 * Set a primary per-frame callback.
 *
 * @address{BPRE,080565E0}
 */
POKEAGB_EXTERN void SetMainCallback(MainCallback func);


/**
 * Set a secondary per-frame callback.
 *
 * @address{BPRE,08000544}
 */
POKEAGB_EXTERN void SetMainCallback2(MainCallback func);

/**
 *
 *
 * @address{BPRE,080006F4}
 */
POKEAGB_EXTERN void SetVBlankCallback(MainCallback func);

/**
 *
 *
 * @address{BPRE,08000700}
 */
POKEAGB_EXTERN void SetHBlankCallback(MainCallback func);

/**
 *
 *
 * @address{BPRE,0800070C}
 */
POKEAGB_EXTERN void SetVCountCallback(MainCallback func);

/**
 *
 *
 * @address{BPRE,08000718}
 */
POKEAGB_EXTERN void SetSerialCallback(MainCallback func);


/**
 *
 *
 * @address{BPRE,080567DC}
 */
POKEAGB_EXTERN void c2_exit_to_overworld_2_switch(void);

/**
 *
 *
 * @address{BPRE,08056938}
 */
POKEAGB_EXTERN void C2MapLoadFresh(void);

/**
 *
 *
 * @address{BPRE,080982EC}
 */
POKEAGB_EXTERN void HideMapPopUpWindow(void);


/**
 *
 *
 * @address{BPRE,0805B3E0}
 */
POKEAGB_EXTERN u8 player_step(u8 dir, u8 newKeys, u8 heldKeys);

/**
 *
 *
 * @address{BPRE,0806F258}
 */
POKEAGB_EXTERN void ShowStartMenu(void);

/**
 *
 *
 * @address{BPRE,0810AD10}
 */
POKEAGB_EXTERN bool UseRegisteredKeyItemOnField(void);


/**
 * Global game state.
 *
 * @address{BPRE,030030F0}
 */
extern struct Main gMain;

POKEAGB_END_DECL

#endif /* POKEAGB_CORE_CALLBACK_H_ */
