/**
 * @file
 * @brief Items.
 */

#ifndef POKEAGB_OVERWORLD_ITEM_H_
#define POKEAGB_OVERWORLD_ITEM_H_

#include <pokeagb/common.h>
#include <pokeagb/version.h>
#include <pokeagb/core/string.h>
#include <pokeagb/core/task.h>

POKEAGB_BEGIN_DECL

#define POKEAGB_ITEM_NAME_LENGTH 14
//
// u16 {
//     ITEM_NONE = 0x0,
//     ITEM_MASTERBALL = 0x1,
//     ITEM_ULTRABALL = 0x2,
//     ITEM_GREATBALL = 0x3,
//     ITEM_POKEBALL = 0x4,
//     ITEM_SAFARIBALL = 0x5,
//     ITEM_NETBALL = 0x6,
//     ITEM_DIVEBALL = 0x7,
//     ITEM_NESTBALL = 0x8,
//     ITEM_REPEATBALL = 0x9,
//     ITEM_TIMERBALL = 0xA,
//     ITEM_LUXURYBALL = 0xB,
//     ITEM_PREMIERBALL = 0xC,
//     ITEM_POTION = 0xD,
//     ITEM_ANTIDOTE = 0xE,
//     ITEM_BURNHEAL = 0xF,
//     ITEM_ICEHEAL = 0x10,
//     ITEM_AWAKENING = 0x11,
//     ITEM_PARLYZHEAL = 0x12,
//     ITEM_FULLRESTORE = 0x13,
//     ITEM_MAXPOTION = 0x14,
//     ITEM_HYPERPOTION = 0x15,
//     ITEM_SUPERPOTION = 0x16,
//     ITEM_FULLHEAL = 0x17,
//     ITEM_REVIVE = 0x18,
//     ITEM_MAXREVIVE = 0x19,
//     ITEM_FRESHWATER = 0x1A,
//     ITEM_SODAPOP = 0x1B,
//     ITEM_LEMONADE = 0x1C,
//     ITEM_MOOMOOMILK = 0x1D,
//     ITEM_ENERGYPOWDER = 0x1E,
//     ITEM_ENERGYROOT = 0x1F,
//     ITEM_HEALPOWDER = 0x20,
//     ITEM_REVIVALHERB = 0x21,
//     ITEM_ETHER = 0x22,
//     ITEM_MAXETHER = 0x23,
//     ITEM_ELIXIR = 0x24,
//     ITEM_MAXELIXIR = 0x25,
//     ITEM_LAVACOOKIE = 0x26,
//     ITEM_BLUEFLUTE = 0x27,
//     ITEM_YELLOWFLUTE = 0x28,
//     ITEM_REDFLUTE = 0x29,
//     ITEM_BLACKFLUTE = 0x2A,
//     ITEM_WHITEFLUTE = 0x2B,
//     ITEM_BERRYJUICE = 0x2C,
//     ITEM_SACREDASH = 0x2D,
//     ITEM_SHOALSALT = 0x2E,
//     ITEM_SHOALSHELL = 0x2F,
//     ITEM_REDSHARD = 0x30,
//     ITEM_BLUESHARD = 0x31,
//     ITEM_YELLOWSHARD = 0x32,
//     ITEM_GREENSHARD = 0x33,
//     ITEM_HPUP = 0x3F,
//     ITEM_PROTEIN = 0x40,
//     ITEM_IRON = 0x41,
//     ITEM_CARBOS = 0x42,
//     ITEM_CALCIUM = 0x43,
//     ITEM_RARECANDY = 0x44,
//     ITEM_PPUP = 0x45,
//     ITEM_ZINC = 0x46,
//     ITEM_PPMAX = 0x47,
//     ITEM_GUARDSPEC = 0x49,
//     ITEM_DIREHIT = 0x4A,
//     ITEM_XATTACK = 0x4B,
//     ITEM_XDEFEND = 0x4C,
//     ITEM_XSPEED = 0x4D,
//     ITEM_XACCURACY = 0x4E,
//     ITEM_XSPECIAL = 0x4F,
//     ITEM_POKEDOLL = 0x50,
//     ITEM_FLUFFYTAIL = 0x51,
//     ITEM_SUPERREPEL = 0x53,
//     ITEM_MAXREPEL = 0x54,
//     ITEM_ESCAPEROPE = 0x55,
//     ITEM_REPEL = 0x56,
//     ITEM_SUNSTONE = 0x5D,
//     ITEM_MOONSTONE = 0x5E,
//     ITEM_FIRESTONE = 0x5F,
//     ITEM_THUNDERSTONE = 0x60,
//     ITEM_WATERSTONE = 0x61,
//     ITEM_LEAFSTONE = 0x62,
//     ITEM_TINYMUSHROOM = 0x67,
//     ITEM_BIGMUSHROOM = 0x68,
//     ITEM_PEARL = 0x6A,
//     ITEM_BIGPEARL = 0x6B,
//     ITEM_STARDUST = 0x6C,
//     ITEM_STARPIECE = 0x6D,
//     ITEM_NUGGET = 0x6E,
//     ITEM_HEARTSCALE = 0x6F,
//     ITEM_PURPLEJUICE = 0x71,
//     ITEM_REDJUICE = 0x72,
//     ITEM_GREENJUICE = 0x73,
//     ITEM_PINKJUICE = 0x74,
//     ITEM_YELLOWJUICE = 0x75,
//     ITEM_AWFULJUICE = 0x76,
//     ITEM_SUPERJUICE = 0x77,
//     ITEM_ORANGEMAIL = 0x79,
//     ITEM_HARBORMAIL = 0x7A,
//     ITEM_GLITTERMAIL = 0x7B,
//     ITEM_MECHMAIL = 0x7C,
//     ITEM_WOODMAIL = 0x7D,
//     ITEM_WAVEMAIL = 0x7E,
//     ITEM_BEADMAIL = 0x7F,
//     ITEM_SHADOWMAIL = 0x80,
//     ITEM_TROPICMAIL = 0x81,
//     ITEM_DREAMMAIL = 0x82,
//     ITEM_FABMAIL = 0x83,
//     ITEM_RETROMAIL = 0x84,
//     ITEM_CHERIBERRY = 0x85,
//     ITEM_CHESTOBERRY = 0x86,
//     ITEM_PECHABERRY = 0x87,
//     ITEM_RAWSTBERRY = 0x88,
//     ITEM_ASPEARBERRY = 0x89,
//     ITEM_LEPPABERRY = 0x8A,
//     ITEM_ORANBERRY = 0x8B,
//     ITEM_PERSIMBERRY = 0x8C,
//     ITEM_LUMBERRY = 0x8D,
//     ITEM_SITRUSBERRY = 0x8E,
//     ITEM_FIGYBERRY = 0x8F,
//     ITEM_WIKIBERRY = 0x90,
//     ITEM_MAGOBERRY = 0x91,
//     ITEM_AGUAVBERRY = 0x92,
//     ITEM_IAPAPABERRY = 0x93,
//     ITEM_RAZZBERRY = 0x94,
//     ITEM_BLUKBERRY = 0x95,
//     ITEM_NANABBERRY = 0x96,
//     ITEM_WEPEARBERRY = 0x97,
//     ITEM_PINAPBERRY = 0x98,
//     ITEM_POMEGBERRY = 0x99,
//     ITEM_KELPSYBERRY = 0x9A,
//     ITEM_QUALOTBERRY = 0x9B,
//     ITEM_HONDEWBERRY = 0x9C,
//     ITEM_GREPABERRY = 0x9D,
//     ITEM_TAMATOBERRY = 0x9E,
//     ITEM_CORNNBERRY = 0x9F,
//     ITEM_MAGOSTBERRY = 0xA0,
//     ITEM_RABUTABERRY = 0xA1,
//     ITEM_NOMELBERRY = 0xA2,
//     ITEM_SPELONBERRY = 0xA3,
//     ITEM_PAMTREBERRY = 0xA4,
//     ITEM_WATMELBERRY = 0xA5,
//     ITEM_DURINBERRY = 0xA6,
//     ITEM_BELUEBERRY = 0xA7,
//     ITEM_LIECHIBERRY = 0xA8,
//     ITEM_GANLONBERRY = 0xA9,
//     ITEM_SALACBERRY = 0xAA,
//     ITEM_PETAYABERRY = 0xAB,
//     ITEM_APICOTBERRY = 0xAC,
//     ITEM_LANSATBERRY = 0xAD,
//     ITEM_STARFBERRY = 0xAE,
//     ITEM_ENIGMABERRY = 0xAF,
//     ITEM_BRIGHTPOWDER = 0xB3,
//     ITEM_WHITEHERB = 0xB4,
//     ITEM_MACHOBRACE = 0xB5,
//     ITEM_EXPSHARE = 0xB6,
//     ITEM_QUICKCLAW = 0xB7,
//     ITEM_SOOTHEBELL = 0xB8,
//     ITEM_MENTALHERB = 0xB9,
//     ITEM_CHOICEBAND = 0xBA,
//     ITEM_KINGSROCK = 0xBB,
//     ITEM_SILVERPOWDER = 0xBC,
//     ITEM_AMULETCOIN = 0xBD,
//     ITEM_CLEANSETAG = 0xBE,
//     ITEM_SOULDEW = 0xBF,
//     ITEM_DEEPSEATOOTH = 0xC0,
//     ITEM_DEEPSEASCALE = 0xC1,
//     ITEM_SMOKEBALL = 0xC2,
//     ITEM_EVERSTONE = 0xC3,
//     ITEM_FOCUSBAND = 0xC4,
//     ITEM_LUCKYEGG = 0xC5,
//     ITEM_SCOPELENS = 0xC6,
//     ITEM_METALCOAT = 0xC7,
//     ITEM_LEFTOVERS = 0xC8,
//     ITEM_DRAGONSCALE = 0xC9,
//     ITEM_LIGHTBALL = 0xCA,
//     ITEM_SOFTSAND = 0xCB,
//     ITEM_HARDSTONE = 0xCC,
//     ITEM_MIRACLESEED = 0xCD,
//     ITEM_BLACKGLASSES = 0xCE,
//     ITEM_BLACKBELT = 0xCF,
//     ITEM_MAGNET = 0xD0,
//     ITEM_MYSTICWATER = 0xD1,
//     ITEM_SHARPBEAK = 0xD2,
//     ITEM_POISONBARB = 0xD3,
//     ITEM_NEVERMELTICE = 0xD4,
//     ITEM_SPELLTAG = 0xD5,
//     ITEM_TWISTEDSPOON = 0xD6,
//     ITEM_CHARCOAL = 0xD7,
//     ITEM_DRAGONFANG = 0xD8,
//     ITEM_SILKSCARF = 0xD9,
//     ITEM_UPGRADE = 0xDA,
//     ITEM_SHELLBELL = 0xDB,
//     ITEM_SEAINCENSE = 0xDC,
//     ITEM_LAXINCENSE = 0xDD,
//     ITEM_LUCKYPUNCH = 0xDE,
//     ITEM_METALPOWDER = 0xDF,
//     ITEM_THICKCLUB = 0xE0,
//     ITEM_STICK = 0xE1,
//     ITEM_MYSTERYTM01 = 0xE2,
//     ITEM_MYSTERYTM02 = 0xE3,
//     ITEM_MYSTERYTM03 = 0xE4,
//     ITEM_MYSTERYTM04 = 0xE5,
//     ITEM_MYSTERYTM05 = 0xE6,
//     ITEM_MYSTERYTM06 = 0xE7,
//     ITEM_MYSTERYTM07 = 0xE8,
//     ITEM_MYSTERYTM08 = 0xE9,
//     ITEM_MYSTERYTM09 = 0xEA,
//     ITEM_MYSTERYTM10 = 0xEB,
//     ITEM_MYSTERYTM11 = 0xEC,
//     ITEM_MYSTERYTM12 = 0xED,
//     ITEM_MYSTERYTM13 = 0xEE,
//     ITEM_REDSCARF = 0xFE,
//     ITEM_BLUESCARF = 0xFF,
//     ITEM_PINKSCARF = 0x100,
//     ITEM_GREENSCARF = 0x101,
//     ITEM_YELLOWSCARF = 0x102,
//     ITEM_MACHBIKE = 0x103,
//     ITEM_COINCASE = 0x104,
//     ITEM_ITEMFINDER = 0x105,
//     ITEM_OLDROD = 0x106,
//     ITEM_GOODROD = 0x107,
//     ITEM_SUPERROD = 0x108,
//     ITEM_SSTICKET = 0x109,
//     ITEM_CONTESTPASS = 0x10A,
//     ITEM_WAILMERPAIL = 0x10C,
//     ITEM_DEVONGOODS = 0x10D,
//     ITEM_SOOTSACK = 0x10E,
//     ITEM_BASEMENTKEY = 0x10F,
//     ITEM_ACROBIKE = 0x110,
//     ITEM_POKEBLOCKCASE = 0x111,
//     ITEM_LETTER = 0x112,
//     ITEM_EONTICKET = 0x113,
//     ITEM_REDORB = 0x114,
//     ITEM_BLUEORB = 0x115,
//     ITEM_SCANNER = 0x116,
//     ITEM_GOGOGGLES = 0x117,
//     ITEM_METEORITE = 0x118,
//     ITEM_RM1KEY = 0x119,
//     ITEM_RM2KEY = 0x11A,
//     ITEM_RM4KEY = 0x11B,
//     ITEM_RM6KEY = 0x11C,
//     ITEM_STORAGEKEY = 0x11D,
//     ITEM_ROOTFOSSIL = 0x11E,
//     ITEM_CLAWFOSSIL = 0x11F,
//     ITEM_DEVONSCOPE = 0x120,
//     ITEM_TM01 = 0x121,
//     ITEM_TM02 = 0x122,
//     ITEM_TM03 = 0x123,
//     ITEM_TM04 = 0x124,
//     ITEM_TM05 = 0x125,
//     ITEM_TM06 = 0x126,
//     ITEM_TM07 = 0x127,
//     ITEM_TM08 = 0x128,
//     ITEM_TM09 = 0x129,
//     ITEM_TM10 = 0x12A,
//     ITEM_TM11 = 0x12B,
//     ITEM_TM12 = 0x12C,
//     ITEM_TM13 = 0x12D,
//     ITEM_TM14 = 0x12E,
//     ITEM_TM15 = 0x12F,
//     ITEM_TM16 = 0x130,
//     ITEM_TM17 = 0x131,
//     ITEM_TM18 = 0x132,
//     ITEM_TM19 = 0x133,
//     ITEM_TM20 = 0x134,
//     ITEM_TM21 = 0x135,
//     ITEM_TM22 = 0x136,
//     ITEM_TM23 = 0x137,
//     ITEM_TM24 = 0x138,
//     ITEM_TM25 = 0x139,
//     ITEM_TM26 = 0x13A,
//     ITEM_TM27 = 0x13B,
//     ITEM_TM28 = 0x13C,
//     ITEM_TM29 = 0x13D,
//     ITEM_TM30 = 0x13E,
//     ITEM_TM31 = 0x13F,
//     ITEM_TM32 = 0x140,
//     ITEM_TM33 = 0x141,
//     ITEM_TM34 = 0x142,
//     ITEM_TM35 = 0x143,
//     ITEM_TM36 = 0x144,
//     ITEM_TM37 = 0x145,
//     ITEM_TM38 = 0x146,
//     ITEM_TM39 = 0x147,
//     ITEM_TM40 = 0x148,
//     ITEM_TM41 = 0x149,
//     ITEM_TM42 = 0x14A,
//     ITEM_TM43 = 0x14B,
//     ITEM_TM44 = 0x14C,
//     ITEM_TM45 = 0x14D,
//     ITEM_TM46 = 0x14E,
//     ITEM_TM47 = 0x14F,
//     ITEM_TM48 = 0x150,
//     ITEM_TM49 = 0x151,
//     ITEM_TM50 = 0x152,
//     ITEM_HM01 = 0x153,
//     ITEM_HM02 = 0x154,
//     ITEM_HM03 = 0x155,
//     ITEM_HM04 = 0x156,
//     ITEM_HM05 = 0x157,
//     ITEM_HM06 = 0x158,
//     ITEM_HM07 = 0x159,
//     ITEM_HM08 = 0x15A,
//     ITEM_TM51 = 0x15B,
//     ITEM_OAKSPARCEL = 0x15D,
//     ITEM_POKEFLUTE = 0x15E,
//     ITEM_SECRETKEY = 0x15F,
//     ITEM_BIKEVOUCHER = 0x160,
//     ITEM_GOLDTEETH = 0x161,
//     ITEM_OLDAMBER = 0x162,
//     ITEM_CARDKEY = 0x163,
//     ITEM_LIFTKEY = 0x164,
//     ITEM_HELIXFOSSIL = 0x165,
//     ITEM_DOMEFOSSIL = 0x166,
//     ITEM_SILPHSCOPE = 0x167,
//     ITEM_BICYCLE = 0x168,
//     ITEM_TOWNMAP = 0x169,
//     ITEM_VSSEEKER = 0x16A,
//     ITEM_FAMECHECKER = 0x16B,
//     ITEM_TMCASE = 0x16C,
//     ITEM_BERRYPOUCH = 0x16D,
//     ITEM_TEACHYTV = 0x16E,
//     ITEM_TRIPASS = 0x16F,
//     ITEM_RAINBOWPASS = 0x170,
//     ITEM_TEA = 0x171,
//     ITEM_MYSTICTICKET = 0x172,
//     ITEM_AURORATICKET = 0x173,
//     ITEM_POWDERJAR = 0x174,
//     ITEM_RUBY = 0x175,
//     ITEM_SAPPHIRE = 0x176,
// #ifdef VERSION_EMERALD
//     ITEM_MAGMAEMBLEM = 0x177,
//     ITEM_OLDSEAMAP = 0x178,
// #endif
//     ITEM_MAX
// };
//
// ASSERT_SIZEOF(u16, 2);
//
// u16Pocket {
//     ITEM_POCKET_NONE,
//     ITEM_POCKET_KEY_ITEMS,
//     ITEM_POCKET_ITEMS,
//     ITEM_POCKET_BALL,
//     ITEM_POCKET_BERRIES,
//     ITEM_POCKET_TMHM,
// };
//
// ASSERT_SIZEOF(u16Pocket, 1);
//
// u16GenericType {
//     /**> Mail */
//     ITEM_TYPE_GENERIC_MAIL,
//
//     /**> Items which can be used out-of-battle. */
//     ITEM_TYPE_GENERIC_OVERWORLD,
//
//     /**> Items which can be assigned to select */
//     ITEM_TYPE_GENERIC_REGISTER,
//
//     /**> Only the Pokéblock case is of this type. */
//     ITEM_TYPE_GENERIC_POKEBLOCK_CASE,
//
//     /**> Items which cannot be used out-of-battle. */
//     ITEM_TYPE_GENERIC_BATTLE,
// };
//
// ASSERT_SIZEOF(u16GenericType, 1);
//
// u16BallType {
//     ITEM_TYPE_BALL_MASTER,
//     ITEM_TYPE_BALL_ULTRA,
//     ITEM_TYPE_BALL_GREAT,
//     ITEM_TYPE_BALL_POKE,
//     ITEM_TYPE_BALL_SAFARI,
//     ITEM_TYPE_BALL_NET,
//     ITEM_TYPE_BALL_DIVE,
//     ITEM_TYPE_BALL_NEST,
//     ITEM_TYPE_BALL_REPEAT,
//     ITEM_TYPE_BALL_TIMER,
//     ITEM_TYPE_BALL_LUXURY,
//     ITEM_TYPE_BALL_PREMIER,
// };
//
// ASSERT_SIZEOF(u16BallType, 1);
//
// union ItemType {
//     u16GenericType item;
//     u16BallType ball;
// };
//
// ASSERT_SIZEOF(union ItemType, 1);
//
// struct ItemData {
//     pchar name[POKEAGB_ITEM_NAME_LENGTH];
//     u16 index;
//     u16 market_price;
//     u8 hold_effect;
//     u8 quality;
//     pchar* description;
//     bool is_unique;
//     u8 field_19;
//     u16Pocket pocket;
//     union ItemType type;
//     TaskCallback overworld_routine;
//     u8 usage;
//     u8 field_21;
//     u16 field_22;
//     TaskCallback battle_routine;
//     u32 field_28;
// };
//
// ASSERT_SIZEOF(struct ItemData, 0x2C);
//
// /**
//  * Table of item data
//  * @address{BPRE,083DB028}
//  */
// extern struct ItemData items[ITEM_MAX];
//
// /**
//  * Textbox id for the normal textbox that appears on error during the bag
//  * @address{BPRE,0203AD39}
//  */
// extern u8* gBagNormalTextboxId;
//
// /**
//  * C2 that is set when exiting the bag from battle
//  * @address{BPRE,0203AD10}
//  */
// extern u32* gBagCallback2OnExit;
//
// /**
//  * C2 that is set if the main one isn't. Seems to be a backup.
//  * @address{BPRE,0203ACFC}
//  */
// extern u32* gBagCallback2OnExit_backup;
//
// /**
//  * Returns the quantity of the given item in the player's bag. Returns
//  * 0 if > 999.
//  * @address{BPRE,0809A7DC}
//  */
// POKEAGB_EXTERN u16 BagGetQuantityByItemId(u16 item);
//
// /**
//  * Returns true if the quantity of the item in the player's bag is at
//  * least the specified amount.
//  * @address{BPRE,08099F40}
//  */
// POKEAGB_EXTERN bool check_item(u16 item, u8 quantity);
//
// /**
//  * Returns true if the quantity of the item in the player's bag is at
//  * least the specified amount.
//  * @address{BPRE,0809A1D8}
//  */
// POKEAGB_EXTERN bool BagRemoveItem(u16 item, u8 quantity);
//
// /**
//  * The animation made by collapsing mindows when exiting the bag
//  * @address{BPRE,08108CB4}
//  */
// POKEAGB_EXTERN void BagClosingAnimation(void);
//
// /**
//  * Task which exits the bag
//  * @address{BPRE,08108B50}
//  */
// POKEAGB_EXTERN void TaskExitBag(u8 taskId);
//
// /**
//  * Function to open the bag
//  * @address{BPRE,08107DB4}
//  */
// POKEAGB_EXTERN void GoToBagMenu(u8 mode, u8 pocketId, MainCallback postExitMenuMainCallback2);
//
// /**
//  * check if hold item is type Mail
//  * @address{BPRE,080980F8}
//  */
// POKEAGB_EXTERN bool ItemIdIsMail(u16 itemId);


POKEAGB_END_DECL

#endif /* POKEAGB_OVERWORLD_ITEM_H_ */
