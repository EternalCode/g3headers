/**
 * @file
 * @brief GameFreak BRM Funcs and Defines.
 */
 
#ifndef POKEAGB_BRM_POKEMENU_H_
#define POKEAGB_BRM_POKEMENU_H_

POKEAGB_BEGIN_DECL


/**
 * BRM data structure
 * struct is larger than this, rest is unknown though
 */
struct gBrmData {
	/*0x00*/ u32 brmCallback;
	/*0x04*/ u16 field4;
	/*0x06*/ u16 field6;
	/*0x08*/ u16 field8;
	/*0x0A*/ u16 fieldA;
	/*0x0C*/ u8 optsBoxId;   // box that holds brm options
	/*0x0D*/ u8 actionBoxId;  // box in bottom left that tells you what to do
	/*0x0E*/ u8 fieldMoveHelpboxId;	// lists what field move does
	/*0x0F*/ u8 brmSequence[8];	// sequence of brm Ids
	/*0x17*/ u8 numBrmOpts;		// number of brm options
};

ASSERT_SIZEOF(struct gBrmData, 0x18);

/**
 * BRM address
 * @address{BPRE,0203b0a0}
 */
extern u32 gAddrBRM;

/**
 * BRM data pointer
 * @address{BPRE,0203b09c}
 */
extern struct gBrmData* gPtrBrmData;


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


/**
 * task for summary screen from BRM
 * @address{BPRE,08122d4c}
 */
POKEAGB_EXTERN void brmLaunchSummary(u8 taskId);

/**
 * task for switching pokes in BRM
 * @address{BPRE,08122E00}
 */
POKEAGB_EXTERN void brmLaunchSwitch(u8 taskId);

/**
 * task for canceling BRM
 * @address{BPRE,08123640}
 */
POKEAGB_EXTERN void brmLaunchCancel(u8 taskId);

/**
 * task for making sub brm menu for Item
 * @address{BPRE,081236A0}
 */
POKEAGB_EXTERN void brmLaunchItemMenu(u8 taskId);

/**
 * task for giving item from BRM
 * @address{BPRE,08123704}
 */
POKEAGB_EXTERN void brmLaunchGiveItem(u8 taskId);

/**
 * task for taking item from BRM
 * @address{BPRE,08123C38}
 */
POKEAGB_EXTERN void brmLaunchTakeItem(u8 taskId);

/**
 * task for making Mail sub menu in BRM
 * @address{BPRE,08123CF4}
 */
POKEAGB_EXTERN void brmLaunchMailMenu(u8 taskId);

/**
 * task for taking mail in BRM
 * @address{BPRE,08123E0C}
 */
POKEAGB_EXTERN void brmLaunchTakeMail(u8 taskId);

/**
 * task for reading mail in BRM
 * @address{BPRE,08123D58}
 */
POKEAGB_EXTERN void brmLaunchReadMail(u8 taskId);

/**
 * task for cancel sub menu in BRM
 * @address{BPRE,08124064}
 */
POKEAGB_EXTERN void brmLaunchCancelSubBrmMenu(u8 taskId);

/**
 * task for shifting/sending out poke
 * @address{BPRE,081240F4}
 */
POKEAGB_EXTERN void brmLaunchShiftOrSendOut(u8 taskId);

/**
 * task for entering poke in something
 * @address{BPRE,08124154}
 */
POKEAGB_EXTERN void brmLaunchEnter(u8 taskId);

/**
 * task for being unable to enter poke in something
 * @address{BPRE,08124278}
 */
POKEAGB_EXTERN void brmLaunchNoEntry(u8 taskId);

/**
 * task for storing pokemon from BRM
 * @address{BPRE,08124354}
 */
POKEAGB_EXTERN void brmLaunchStore(u8 taskId);

/**
 * task for registering pokemon from BRM
 * @address{BPRE,08124384}
 */
POKEAGB_EXTERN void brmLaunchRegister(u8 taskId);

/**
 * task for trading pokemon from BRM
 * @address{BPRE,08124490}
 */
POKEAGB_EXTERN void brmLaunchTrade(u8 taskId);

/**
 * extra trade func in BRM... does nothing
 * @address{BPRE,081245A0}
 */
POKEAGB_EXTERN void brmLaunchNull(u8 taskId);

/**
 * launch field move from BRM
 * @address{BPRE,081245A4}
 */
POKEAGB_EXTERN void brmLaunchFieldMove(u8 taskId);



POKEAGB_END_DECL

#endif /* POKEAGB_CORE_STRING_H_ */


 
 