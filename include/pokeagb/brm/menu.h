/**
 * @file
 * @brief GameFreak BRM and other Menu defines
 */
 
#ifndef POKEAGB_BRM_MENU_H_
#define POKEAGB_BRM_MENU_H_

POKEAGB_BEGIN_DECL

struct MenuChoiceStruct {
	u8 ChoiceX;
	u8 ChoiceY;
	u8 ChoiceCurrent;
	u8 ChoiceMin;
	u8 ChoiceMax;
	u8 ChoiceRboxId;
	u16 ChoiceFboxId;
	u16 ChoiceYStride;
};

ASSERT_SIZEOF(struct MenuChoiceStruct, 10);

/**
 * Choice Structure
 * @address{BPRE,0203ade4}
 */
extern struct MenuChoiceStruct MenuChoices;


POKEAGB_END_DECL

#endif /* POKEAGB_CORE_STRING_H_ */


