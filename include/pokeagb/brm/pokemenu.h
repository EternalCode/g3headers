/**
 * @file
 * @brief GameFreak BRM Funcs and Defines.
 */
 
#ifndef POKEAGB_BRM_POKEMENU_H_
#define POKEAGB_BRM_POKEMENU_H_

POKEAGB_BEGIN_DECL

/**
 * Clears and frees the given rboxid, and prepares it for printing.
 * @address{BPRE,08121CE4}
 */
POKEAGB_EXTERN void ClearAndPrepareTextbox(u32* PointerToTextbox);

/**
 * Chooses a String to display in the BRM given table index (eg. fly is 0xD)
 * @address{BPRE,08121D0C}
 */
POKEAGB_EXTERN void ChoosePokemonStrings(u8 StringIndex); 

/**
 * perform flash from the brm pokemenu
 * @address{BPRE,08124954}
 */
POKEAGB_EXTERN void BRMDoHMFlash(); 

/**
 * perform surf from the brm pokemenu
 * @address{BPRE,08124A0C}
 */
POKEAGB_EXTERN void BRMDoHMSurf(); 

/**
 * exit to overworld from brm menu (default opt)
 * @address{BPRE,0812475c}
 */
POKEAGB_EXTERN void BRMExitToOverworld(u8 task_id, u8 brm_index);

/**
 * do fly from brm menu
 * @address{BPRE,0812474c}
 */
POKEAGB_EXTERN void BRMDoHMFly(u8 task_id);

/**
 * do teleport from brm menu
 * @address{BPRE,081246b4}
 */
POKEAGB_EXTERN void BRMDoHMTeleport(u8 task_id, u8 brm_index);

/**
 * do dig from brm menu
 * @address{BPRE,081246f0}
 */
POKEAGB_EXTERN void BRMDoHMDig(u8 task_id, u8 brm_index);

/**
 * do milk drink from brm menu
 * @address{BPRE,081246ac}
 */
POKEAGB_EXTERN void BRMDoMilkDrink(u8 task_id);

/**
 * prepare to do flash from the pokemenu
 * @address{BPRE,080c9b2c}
 */
POKEAGB_EXTERN bool BRMPrepareFlash();

/**
 * prepare/check if able to do cut from the pokemenu
 * @address{BPRE,08097898}
 */
POKEAGB_EXTERN bool BRMPrepareCut();

/**
 * prepare/check if able to do fly from the pokemenu
 * @address{BPRE,08124a8c}
 */
POKEAGB_EXTERN bool BRMPrepareFly();

/**
 * prepare/check if able to do strength from the pokemenu
 * @address{BPRE,080d07ec}
 */
POKEAGB_EXTERN bool BRMPrepareStrength();

/**
 * prepare/check if able to do surf from the pokemenu
 * @address{BPRE,08124998}
 */
POKEAGB_EXTERN bool BRMPrepareSurf();

/**
 * prepare/check if able to do rock smash from the pokemenu
 * @address{BPRE,080c99d8}
 */
POKEAGB_EXTERN bool BRMPrepareRockSmash();

/**
 * prepare/check if able to do waterfall from the pokemenu
 * @address{BPRE,08124af8}
 */
POKEAGB_EXTERN bool BRMPrepareWaterfall();

/**
 * prepare/check if able to do teleport from the pokemenu
 * @address{BPRE,080f66f0}
 */
POKEAGB_EXTERN bool BRMPrepareTeleport();

/**
 * prepare/check if able to do dig from the pokemenu
 * @address{BPRE,080c9a78}
 */
POKEAGB_EXTERN bool BRMPrepareDig();

/**
 * prepare/check if able to do softboiled/milk drink from the pokemenu
 * @address{BPRE,080e5684}
 */
POKEAGB_EXTERN bool BRMPrepareSoftboiled_MilkDrink();

/**
 * prepare/check if able to do sweet scent from the pokemenu
 * @address{BPRE,080de0c8}
 */
POKEAGB_EXTERN bool BRMPrepareSweetScent();



#define TaskBRMResolveFromContext 0x0812492c



POKEAGB_END_DECL

#endif /* POKEAGB_CORE_STRING_H_ */


 
 