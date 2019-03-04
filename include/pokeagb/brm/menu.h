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


POKEAGB_END_DECL

#endif /* POKEAGB_CORE_STRING_H_ */


