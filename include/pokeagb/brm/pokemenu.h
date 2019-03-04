/**
 * @file
 * @brief GameFreak BRM Funcs and Defines.
 */
 
#ifndef POKEAGB_BRM_POKEMENU_H_
#define POKEAGB_BRM_POKEMENU_H_

POKEAGB_BEGIN_DECL


/**
 * BRM address
 * @address{BPRE,0203b0a0}
 */
extern u32 gAddrBRM;

/**
 * BRM data pointer
 * @address{BPRE,0203b09c}
 */
extern u32 gPtrBrmData;


/**
 * Clears and frees the given rboxid, and prepares it for printing.
 * @address{BPRE,08121CE4}
 */
POKEAGB_EXTERN void ClearAndPrepareTextbox(u32* PointerToTextbox);

/**
 * displays a string in the brm given an index
 * @address{BPRE,08121D0C}
 */
POKEAGB_EXTERN void ChoosePokemonStrings(u8 StringIndex);

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
 * do fly
 * @address{BPRE,080c4ef8}
 */
POKEAGB_EXTERN void PerformBRMFly();


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
POKEAGB_EXTERN bool BRMPrepareSoftboiledAndMilkDrink();

/**
 * prepare/check if able to do sweet scent from the pokemenu
 * @address{BPRE,080de0c8}
 */
POKEAGB_EXTERN bool BRMPrepareSweetScent();


/**
 * display a message in the BRM (used in displaying badge error msg)
 * @address{BPRE,081202f8}
 */
POKEAGB_EXTERN void BRMDisplayMessageTask(u32* StringPointer, u8 taskPriority);


/**
 * resolve BRM tasks
 * @address{BPRE,0812492c}
 */
POKEAGB_EXTERN void TaskBRMResolveFromContext(u8 taskId);

/**
 * reset the pokemenu/brm?
 * @address{BPRE,081203b8}
 */
POKEAGB_EXTERN void TaskResetBRM(u8 taskId);


/**
 * fade pal in preparation for task in brm
 * @address{BPRE,0811fa78}
 */
POKEAGB_EXTERN void TaskBRMPalFade(u8 taskId);



/**
 * get selected poke in brm
 * @address{BPRE,0811fb0c}
 */
POKEAGB_EXTERN u8 brmGetPokemonSelection();

/**
 * get selected poke in brm
 * @address{BPRE,08124BB0}
 */
POKEAGB_EXTERN void BRMPrepareOverworldExit(u32* PokeAddr, u8 brmIndex);


/**
 * create task to display a string in BRM - used in teleport BRM func
 * @address{BPRE,081247c4}
 */
POKEAGB_EXTERN void BRMStringBufferTask(u8 taskId);


/**
 * task for milk drink / softboiled
 * @address{BPRE,080e56dc}
 */
POKEAGB_EXTERN void TaskSelectBRMPokeForHeal(u8 taskId);



POKEAGB_END_DECL

#endif /* POKEAGB_CORE_STRING_H_ */


 
 