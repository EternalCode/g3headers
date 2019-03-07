/**
 * @file
 * @brief GameFreak BRM and other Menu defines
 */

#ifndef POKEAGB_BRM_MENU_H_
#define POKEAGB_BRM_MENU_H_

POKEAGB_BEGIN_DECL

struct MenuChoiceStruct {
	u8 choiceX;
	u8 choiceY;
	u8 choiceCurrent;
	u8 choiceMin;
	u8 choiceMax;
	u8 choiceRboxId;
	u16 choiceFboxId;
	u16 choiceYStride;
};

ASSERT_SIZEOF(struct MenuChoiceStruct, 10);

/**
 * Choice Structure
 * @address{BPRE,0203ade4}
 */
extern struct MenuChoiceStruct gMenuChoices;

/**
 * Choice Structure
 * @address{BPRE,0203ade4}
 */
extern struct MenuChoiceStruct gMenuChoices;

/**
 * get current choice
 * @address{BPRE,0810f98c}
 */
POKEAGB_EXTERN u8 GetChoiceCurr();

/**
 * add element to a menu
 * @address{BPRE,0806FEC8}
 */
POKEAGB_EXTERN void AppendElement(u8* sequencePtr, u8* cursorPtr, u8 element);

/**
 * update cursor position on multichoice
 * @address{BPRE,0810fa84}
 */
POKEAGB_EXTERN u8 KeypadRepeatChoiceUpdate();

/**
 * update cursor position on multichoice, only sounds on changing cursor
 * @address{BPRE,0810faf0}
 */
POKEAGB_EXTERN u8 KeypadRepeatChoiceUpdateSilent();


POKEAGB_END_DECL

#endif /* POKEAGB_BRM_MENU_H_ */
