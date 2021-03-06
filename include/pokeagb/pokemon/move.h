/**
 * @file
 * @brief Pokemon attacks/moves.
 */

#ifndef POKEAGB_POKEMON_MOVE_H_
#define POKEAGB_POKEMON_MOVE_H_

#include <pokeagb/common.h>
#include <pokeagb/core/string.h>

POKEAGB_BEGIN_DECL

#define POKEAGB_MOVE_NAME_LENGTH 13

enum Move {
    MOVE_NONE = 0,
    MOVE_POUND,
    MOVE_KARATECHOP,
    MOVE_DOUBLESLAP,
    MOVE_COMETPUNCH,
    MOVE_MEGAPUNCH,
    MOVE_PAYDAY,
    MOVE_FIREPUNCH,
    MOVE_ICEPUNCH,
    MOVE_THUNDERPUNCH,
    MOVE_SCRATCH,
    MOVE_VICEGRIP,
    MOVE_GUILLOTINE,
    MOVE_RAZORWIND,
    MOVE_SWORDSDANCE,
    MOVE_CUT,
    MOVE_GUST,
    MOVE_WINGATTACK,
    MOVE_WHIRLWIND,
    MOVE_FLY,
    MOVE_BIND,
    MOVE_SLAM,
    MOVE_VINEWHIP,
    MOVE_STOMP,
    MOVE_DOUBLEKICK,
    MOVE_MEGAKICK,
    MOVE_JUMPKICK,
    MOVE_ROLLINGKICK,
    MOVE_SANDATTACK,
    MOVE_HEADBUTT,
    MOVE_HORNATTACK,
    MOVE_FURYATTACK,
    MOVE_HORNDRILL,
    MOVE_TACKLE,
    MOVE_BODYSLAM,
    MOVE_WRAP,
    MOVE_TAKEDOWN,
    MOVE_THRASH,
    MOVE_DOUBLEEDGE,
    MOVE_TAILWHIP,
    MOVE_POISONSTING,
    MOVE_TWINEEDLE,
    MOVE_PINMISSILE,
    MOVE_LEER,
    MOVE_BITE,
    MOVE_GROWL,
    MOVE_ROAR,
    MOVE_SING,
    MOVE_SUPERSONIC,
    MOVE_SONICBOOM,
    MOVE_DISABLE,
    MOVE_ACID,
    MOVE_EMBER,
    MOVE_FLAMETHROWER,
    MOVE_MIST,
    MOVE_WATERGUN,
    MOVE_HYDROPUMP,
    MOVE_SURF,
    MOVE_ICEBEAM,
    MOVE_BLIZZARD,
    MOVE_PSYBEAM,
    MOVE_BUBBLEBEAM,
    MOVE_AURORABEAM,
    MOVE_HYPERBEAM,
    MOVE_PECK,
    MOVE_DRILLPECK,
    MOVE_SUBMISSION,
    MOVE_LOWKICK,
    MOVE_COUNTER,
    MOVE_SEISMICTOSS,
    MOVE_STRENGTH,
    MOVE_ABSORB,
    MOVE_MEGADRAIN,
    MOVE_LEECHSEED,
    MOVE_GROWTH,
    MOVE_RAZORLEAF,
    MOVE_SOLARBEAM,
    MOVE_POISONPOWDER,
    MOVE_STUNSPORE,
    MOVE_SLEEPPOWDER,
    MOVE_PETALDANCE,
    MOVE_STRINGSHOT,
    MOVE_DRAGONRAGE,
    MOVE_FIRESPIN,
    MOVE_THUNDERSHOCK,
    MOVE_THUNDERBOLT,
    MOVE_THUNDERWAVE,
    MOVE_THUNDER,
    MOVE_ROCKTHROW,
    MOVE_EARTHQUAKE,
    MOVE_FISSURE,
    MOVE_DIG,
    MOVE_TOXIC,
    MOVE_CONFUSION,
    MOVE_PSYCHIC,
    MOVE_HYPNOSIS,
    MOVE_MEDITATE,
    MOVE_AGILITY,
    MOVE_QUICKATTACK,
    MOVE_RAGE,
    MOVE_TELEPORT,
    MOVE_NIGHTSHADE,
    MOVE_MIMIC,
    MOVE_SCREECH,
    MOVE_DOUBLETEAM,
    MOVE_RECOVER,
    MOVE_HARDEN,
    MOVE_MINIMIZE,
    MOVE_SMOKESCREEN,
    MOVE_CONFUSERAY,
    MOVE_WITHDRAW,
    MOVE_DEFENSECURL,
    MOVE_BARRIER,
    MOVE_LIGHTSCREEN,
    MOVE_HAZE,
    MOVE_REFLECT,
    MOVE_FOCUSENERGY,
    MOVE_BIDE,
    MOVE_METRONOME,
    MOVE_MIRRORMOVE,
    MOVE_SELFDESTRUCT,
    MOVE_EGGBOMB,
    MOVE_LICK,
    MOVE_SMOG,
    MOVE_SLUDGE,
    MOVE_BONECLUB,
    MOVE_FIREBLAST,
    MOVE_WATERFALL,
    MOVE_CLAMP,
    MOVE_SWIFT,
    MOVE_SKULLBASH,
    MOVE_SPIKECANNON,
    MOVE_CONSTRICT,
    MOVE_AMNESIA,
    MOVE_KINESIS,
    MOVE_SOFTBOILED,
    MOVE_HIGHJUMPKICK,
    MOVE_GLARE,
    MOVE_DREAMEATER,
    MOVE_POISONGAS,
    MOVE_BARRAGE,
    MOVE_LEECHLIFE,
    MOVE_LOVELYKISS,
    MOVE_SKYATTACK,
    MOVE_TRANSFORM,
    MOVE_BUBBLE,
    MOVE_DIZZYPUNCH,
    MOVE_SPORE,
    MOVE_FLASH,
    MOVE_PSYWAVE,
    MOVE_SPLASH,
    MOVE_ACIDARMOR,
    MOVE_CRABHAMMER,
    MOVE_EXPLOSION,
    MOVE_FURYSWIPES,
    MOVE_BONEMERANG,
    MOVE_REST,
    MOVE_ROCKSLIDE,
    MOVE_HYPERFANG,
    MOVE_SHARPEN,
    MOVE_CONVERSION,
    MOVE_TRIATTACK,
    MOVE_SUPERFANG,
    MOVE_SLASH,
    MOVE_SUBSTITUTE,
    MOVE_STRUGGLE,
    MOVE_SKETCH,
    MOVE_TRIPLEKICK,
    MOVE_THIEF,
    MOVE_SPIDERWEB,
    MOVE_MINDREADER,
    MOVE_NIGHTMARE,
    MOVE_FLAMEWHEEL,
    MOVE_SNORE,
    MOVE_CURSE,
    MOVE_FLAIL,
    MOVE_CONVERSION2,
    MOVE_AEROBLAST,
    MOVE_COTTONSPORE,
    MOVE_REVERSAL,
    MOVE_SPITE,
    MOVE_POWDERSNOW,
    MOVE_PROTECT,
    MOVE_MACHPUNCH,
    MOVE_SCARYFACE,
    MOVE_FEINTATTACK,
    MOVE_SWEETKISS,
    MOVE_BELLYDRUM,
    MOVE_SLUDGEBOMB,
    MOVE_MUDSLAP,
    MOVE_OCTAZOOKA,
    MOVE_SPIKES,
    MOVE_ZAPCANNON,
    MOVE_FORESIGHT,
    MOVE_DESTINYBOND,
    MOVE_PERISHSONG,
    MOVE_ICYWIND,
    MOVE_DETECT,
    MOVE_BONERUSH,
    MOVE_LOCKON,
    MOVE_OUTRAGE,
    MOVE_SANDSTORM,
    MOVE_GIGADRAIN,
    MOVE_ENDURE,
    MOVE_CHARM,
    MOVE_ROLLOUT,
    MOVE_FALSESWIPE,
    MOVE_SWAGGER,
    MOVE_MILKDRINK,
    MOVE_SPARK,
    MOVE_FURYCUTTER,
    MOVE_STEELWING,
    MOVE_MEANLOOK,
    MOVE_ATTRACT,
    MOVE_SLEEPTALK,
    MOVE_HEALBELL,
    MOVE_RETURN,
    MOVE_PRESENT,
    MOVE_FRUSTRATION,
    MOVE_SAFEGUARD,
    MOVE_PAINSPLIT,
    MOVE_SACREDFIRE,
    MOVE_MAGNITUDE,
    MOVE_DYNAMICPUNCH,
    MOVE_MEGAHORN,
    MOVE_DRAGONBREATH,
    MOVE_BATONPASS,
    MOVE_ENCORE,
    MOVE_PURSUIT,
    MOVE_RAPIDSPIN,
    MOVE_SWEETSCENT,
    MOVE_IRONTAIL,
    MOVE_METALCLAW,
    MOVE_VITALTHROW,
    MOVE_MORNINGSUN,
    MOVE_SYNTHESIS,
    MOVE_MOONLIGHT,
    MOVE_HIDDENPOWER,
    MOVE_CROSSCHOP,
    MOVE_TWISTER,
    MOVE_RAINDANCE,
    MOVE_SUNNYDAY,
    MOVE_CRUNCH,
    MOVE_MIRRORCOAT,
    MOVE_PSYCHUP,
    MOVE_EXTREMESPEED,
    MOVE_ANCIENTPOWER,
    MOVE_SHADOWBALL,
    MOVE_FUTURESIGHT,
    MOVE_ROCKSMASH,
    MOVE_WHIRLPOOL,
    MOVE_BEATUP,
    MOVE_FAKEOUT,
    MOVE_UPROAR,
    MOVE_STOCKPILE,
    MOVE_SPITUP,
    MOVE_SWALLOW,
    MOVE_HEATWAVE,
    MOVE_HAIL,
    MOVE_TORMENT,
    MOVE_FLATTER,
    MOVE_WILLOWISP,
    MOVE_MEMENTO,
    MOVE_FACADE,
    MOVE_FOCUSPUNCH,
    MOVE_SMELLINGSALTS,
    MOVE_FOLLOWME,
    MOVE_NATUREPOWER,
    MOVE_CHARGE,
    MOVE_TAUNT,
    MOVE_HELPINGHAND,
    MOVE_TRICK,
    MOVE_ROLEPLAY,
    MOVE_WISH,
    MOVE_ASSIST,
    MOVE_INGRAIN,
    MOVE_SUPERPOWER,
    MOVE_MAGICCOAT,
    MOVE_RECYCLE,
    MOVE_REVENGE,
    MOVE_BRICKBREAK,
    MOVE_YAWN,
    MOVE_KNOCKOFF,
    MOVE_ENDEAVOR,
    MOVE_ERUPTION,
    MOVE_SKILLSWAP,
    MOVE_IMPRISON,
    MOVE_REFRESH,
    MOVE_GRUDGE,
    MOVE_SNATCH,
    MOVE_SECRETPOWER,
    MOVE_DIVE,
    MOVE_ARMTHRUST,
    MOVE_CAMOUFLAGE,
    MOVE_TAILGLOW,
    MOVE_LUSTERPURGE,
    MOVE_MISTBALL,
    MOVE_FEATHERDANCE,
    MOVE_TEETERDANCE,
    MOVE_BLAZEKICK,
    MOVE_MUDSPORT,
    MOVE_ICEBALL,
    MOVE_NEEDLEARM,
    MOVE_SLACKOFF,
    MOVE_HYPERVOICE,
    MOVE_POISONFANG,
    MOVE_CRUSHCLAW,
    MOVE_BLASTBURN,
    MOVE_HYDROCANNON,
    MOVE_METEORMASH,
    MOVE_ASTONISH,
    MOVE_WEATHERBALL,
    MOVE_AROMATHERAPY,
    MOVE_FAKETEARS,
    MOVE_AIRCUTTER,
    MOVE_OVERHEAT,
    MOVE_ODORSLEUTH,
    MOVE_ROCKTOMB,
    MOVE_SILVERWIND,
    MOVE_METALSOUND,
    MOVE_GRASSWHISTLE,
    MOVE_TICKLE,
    MOVE_COSMICPOWER,
    MOVE_WATERSPOUT,
    MOVE_SIGNALBEAM,
    MOVE_SHADOWPUNCH,
    MOVE_EXTRASENSORY,
    MOVE_SKYUPPERCUT,
    MOVE_SANDTOMB,
    MOVE_SHEERCOLD,
    MOVE_MUDDYWATER,
    MOVE_BULLETSEED,
    MOVE_AERIALACE,
    MOVE_ICICLESPEAR,
    MOVE_IRONDEFENSE,
    MOVE_BLOCK,
    MOVE_HOWL,
    MOVE_DRAGONCLAW,
    MOVE_FRENZYPLANT,
    MOVE_BULKUP,
    MOVE_BOUNCE,
    MOVE_MUDSHOT,
    MOVE_POISONTAIL,
    MOVE_COVET,
    MOVE_VOLTTACKLE,
    MOVE_MAGICALLEAF,
    MOVE_WATERSPORT,
    MOVE_CALMMIND,
    MOVE_LEAFBLADE,
    MOVE_DRAGONDANCE,
    MOVE_ROCKBLAST,
    MOVE_SHOCKWAVE,
    MOVE_WATERPULSE,
    MOVE_DOOMDESIRE,
    MOVE_PSYCHOBOOST,

// new moves start here

    MOVE_ROOST,
    MOVE_GRAVITY,
    MOVE_MIRACLEEYE,
    MOVE_WAKEUPSLAP,
    MOVE_HAMMERARM,
    MOVE_GYROBALL,
    MOVE_HEALINGWISH,
    MOVE_BRINE,
    MOVE_NATURALGIFT,
    MOVE_FEINT,
    MOVE_PLUCK,
    MOVE_TAILWIND,
    MOVE_ACUPRESSURE,
    MOVE_METALBURST,
    MOVE_UTURN,
    MOVE_CLOSECOMBAT,
    MOVE_PAYBACK,
    MOVE_ASSURANCE,
    MOVE_EMBARGO,
    MOVE_FLING,
    MOVE_PSYCHOSHIFT,
    MOVE_TRUMPCARD,
    MOVE_HEALBLOCK,
    MOVE_WRINGOUT,
    MOVE_POWERTRICK,
    MOVE_GASTROACID,
    MOVE_LUCKYCHANT,
    MOVE_MEFIRST,
    MOVE_COPYCAT,
    MOVE_POWERSWAP,
    MOVE_GUARDSWAP,
    MOVE_PUNISHMENT,
    MOVE_LASTRESORT,
    MOVE_WORRYSEED,
    MOVE_SUCKERPUNCH,
    MOVE_TOXICSPIKES,
    //MOVE_HEARTSWAP,
    MOVE_AQUARING,
    MOVE_MAGNETRISE,
    MOVE_FLAREBLITZ,
    MOVE_FORCEPALM,
    MOVE_AURASPHERE,
    MOVE_ROCKPOLISH,
    MOVE_POISONJAB,
    MOVE_DARKPULSE,
    MOVE_NIGHTSLASH,
    MOVE_AQUATAIL,
    MOVE_SEEDBOMB,
    MOVE_AIRSLASH,
    MOVE_XSCISSOR,
    MOVE_BUGBUZZ,
    MOVE_DRAGONPULSE,
    MOVE_DRAGONRUSH,
    MOVE_POWERGEM,
    MOVE_DRAINPUNCH,
    MOVE_VACUUMWAVE,
    MOVE_FOCUSBLAST,
    MOVE_ENERGYBALL,
    MOVE_BRAVEBIRD,
    MOVE_EARTHPOWER,
    MOVE_SWITCHEROO,
    MOVE_GIGAIMPACT,
    MOVE_NASTYPLOT,
    MOVE_BULLETPUNCH,
    MOVE_AVALANCHE,
    MOVE_ICESHARD,
    MOVE_SHADOWCLAW,
    MOVE_THUNDERFANG,
    MOVE_ICEFANG,
    MOVE_FIREFANG,
    MOVE_SHADOWSNEAK,
    MOVE_MUDBOMB,
    MOVE_PSYCHOCUT,
    MOVE_ZENHEADBUTT,
    MOVE_MIRRORSHOT,
    MOVE_FLASHCANNON,
    MOVE_ROCKCLIMB,
    MOVE_DEFOG,
    MOVE_TRICKROOM,
    MOVE_DRACOMETEOR,
    MOVE_DISCHARGE,
    MOVE_LAVAPLUME,
    MOVE_LEAFSTORM,
    MOVE_POWERWHIP,
    MOVE_ROCKWRECKER,
    MOVE_CROSSPOISON,
    MOVE_GUNKSHOT,
    MOVE_IRONHEAD,
    MOVE_MAGNETBOMB,
    MOVE_STONEEDGE,
    MOVE_CAPTIVATE,
    MOVE_STEALTHROCK,
    MOVE_GRASSKNOT,
    //MOVE_CHATTER,
    //MOVE_JUDGMENT,
    MOVE_BUGBITE,
    MOVE_CHARGEBEAM,
    MOVE_WOODHAMMER,
    MOVE_AQUAJET,
    MOVE_ATTACKORDER,
    MOVE_DEFENDORDER,
    MOVE_HEALORDER,
    MOVE_HEADSMASH,
    MOVE_DOUBLEHIT,
    //MOVE_ROAROFTIME,
    //MOVE_SPACIALREND,
    //MOVE_LUNARDANCE,
    //MOVE_CRUSHGRIP,
    MOVE_MAGMASTORM,
    MOVE_DARKVOID,
    //MOVE_SEEDFLARE,
    MOVE_OMINOUSWIND,
    //MOVE_SHADOWFORCE,
    MOVE_HONECLAWS,
    MOVE_WIDEGUARD,
    MOVE_GUARDSPLIT,
    MOVE_POWERSPLIT,
    //MOVE_WONDERROOM,
    MOVE_PSYSHOCK,
    MOVE_VENOSHOCK,
    MOVE_AUTOTOMIZE,
    MOVE_RAGEPOWDER,
    MOVE_TELEKINESIS,
    MOVE_MAGICROOM,
    MOVE_SMACKDOWN,
    MOVE_STORMTHROW,
    MOVE_FLAMEBURST,
    MOVE_SLUDGEWAVE,
    MOVE_QUIVERDANCE,
    MOVE_HEAVYSLAM,
    MOVE_SYNCHRONOISE,
    MOVE_ELECTROBALL,
    MOVE_SOAK,
    MOVE_FLAMECHARGE,
    MOVE_COIL,
    MOVE_LOWSWEEP,
    MOVE_ACIDSPRAY,
    MOVE_FOULPLAY,
    MOVE_SIMPLEBEAM,
    MOVE_ENTRAINMENT,
    MOVE_AFTERYOU,
    MOVE_ROUND,
    MOVE_ECHOEDVOICE,
    MOVE_CHIPAWAY,
    MOVE_CLEARSMOG,
    MOVE_STOREDPOWER,
    MOVE_QUICKGUARD,
    //MOVE_ALLYSWITCH,
    MOVE_SCALD,
    MOVE_SHELLSMASH,
    MOVE_HEALPULSE,
    MOVE_HEX,
    MOVE_SKYDROP,
    //MOVE_SHIFTGEAR,
    MOVE_CIRCLETHROW,
    MOVE_INCINERATE,
    MOVE_QUASH,
    MOVE_ACROBATICS,
    MOVE_REFLECTTYPE,
    MOVE_RETALIATE,
    MOVE_FINALGAMBIT,
    MOVE_BESTOW,
    MOVE_INFERNO,
    // MOVE_WATERPLEDGE,
    // MOVE_FIREPLEDGE,
    // MOVE_GRASSPLEDGE,
    MOVE_VOLTSWITCH,
    MOVE_STRUGGLEBUG,
    MOVE_BULLDOZE,
    MOVE_FROSTBREATH,
    MOVE_DRAGONTAIL,
    MOVE_WORKUP,
    MOVE_ELECTROWEB,
    MOVE_WILDCHARGE,
    MOVE_DRILLRUN,
    MOVE_DUALCHOP,
    //MOVE_HEARTSTAMP,
    MOVE_HORNLEECH,
    MOVE_SACREDSWORD,
    MOVE_RAZORSHELL,
    //MOVE_HEATCRASH,
    MOVE_LEAFTORNADO,
    MOVE_STEAMROLLER,
    MOVE_COTTONGUARD,
    MOVE_NIGHTDAZE,
    MOVE_PSYSTRIKE,
    MOVE_TAILSLAP,
    MOVE_HURRICANE,
    MOVE_HEADCHARGE,
    //MOVE_GEARGRIND,
    //MOVE_SEARINGSHOT,
    //MOVE_TECHNOBLAST,
    // MOVE_RELICSONG,
    // MOVE_SECRETSWORD,
    // MOVE_GLACIATE,
    //MOVE_BOLTSTRIKE,
    //MOVE_BLUEFLARE,
    MOVE_FIERYDANCE,
    //MOVE_FREEZESHOCK,
    //MOVE_ICEBURN,
    //MOVE_SNARL,
    MOVE_ICICLECRASH,
    // MOVE_VCREATE,
    // MOVE_FUSIONFLARE,
    // MOVE_FUSIONBOLT,
    MOVE_FLYINGPRESS,
    //MOVE_MATBLOCK,
    MOVE_BELCH,
    MOVE_ROTOTILLER,
    MOVE_STICKYWEB,
    MOVE_FELLSTINGER,
    MOVE_PHANTOMFORCE,
    //MOVE_TRICKORTREAT,
    MOVE_NOBLEROAR,
    MOVE_IONDELUGE,
    //MOVE_PARABOLICCHARGE,
    //MOVE_FORESTSCURSE,
    MOVE_PETALBLIZZARD,
    MOVE_FREEZEDRY,
    MOVE_DISARMINGVOICE,
    MOVE_PARTINGSHOT,
    MOVE_TOPSYTURVY,
    MOVE_DRAININGKISS,
    //MOVE_CRAFTYSHIELD,
    //MOVE_FLOWERSHIELD,
    MOVE_GRASSYTERRAIN,
    MOVE_MISTYTERRAIN,
    //MOVE_ELECTRIFY,
    MOVE_PLAYROUGH,
    MOVE_FAIRYWIND,
    MOVE_MOONBLAST,
    MOVE_BOOMBURST,
    MOVE_FAIRYLOCK,
    MOVE_KINGSSHIELD,
    MOVE_PLAYNICE,
    //MOVE_CONFIDE,
    // MOVE_DIAMONDSTORM,
    // MOVE_STEAMERUPTION,
    // MOVE_HYPERSPACEHOLE,
    // MOVE_WATERSHURIKEN,
    // MOVE_MYSTICALFIRE,
    MOVE_SPIKYSHIELD,
    MOVE_AROMATICMIST,
    MOVE_EERIEIMPULSE,
    MOVE_VENOMDRENCH,
    MOVE_POWDER,
    //MOVE_GEOMANCY,
    MOVE_MAGNETICFLUX,
    //MOVE_HAPPYHOUR,
    MOVE_ELECTRICTERRAIN,
    MOVE_DAZZLINGGLEAM,
    //MOVE_CELEBRATE,
    MOVE_BABYDOLLEYES,
    MOVE_NUZZLE,
    MOVE_HOLDBACK,
    MOVE_INFESTATION,
    MOVE_POWERUPPUNCH,
    //MOVE_OBLIVIONWING,
    //MOVE_THOUSANDARROWS,
    //MOVE_THOUSANDWAVES,
    // MOVE_HOLDHANDS,
    // MOVE_LANDSWRATH,
    // MOVE_LIGHTOFRUIN,
    // MOVE_ORIGINPULSE,
    // MOVE_PRECIPICEBLADES,
    // MOVE_DRAGONASCENT,
    // MOVE_HYPERSPACEFURY,
    MOVE_SHOREUP,
    //MOVE_FIRSTIMPRESSION,
    // MOVE_BANEFULBUNKER,
    // MOVE_SPIRITSHACKLE,
    // MOVE_DARKESTLARIAT,
    // MOVE_SPARKLINGARIA,
    // MOVE_ICEHAMMER,
    //MOVE_FLORALHEALING,
    MOVE_HIGHHORSEPOWER,
    MOVE_STRENGTHSAP,
    // MOVE_SOLARBLADE,
    // MOVE_LEAFAGE,
    MOVE_SPOTLIGHT,
    MOVE_TOXICTHREAD,
    MOVE_LASERFOCUS,
    //MOVE_GEARUP,
    MOVE_THROATCHOP,
    //MOVE_POLLENPUFF,
    MOVE_ANCHORSHOT,
    MOVE_PSYCHICTERRAIN,
    MOVE_LUNGE,
    //MOVE_FIRELASH,
    MOVE_POWERTRIP,
    MOVE_BURNUP,
    //MOVE_SPEEDSWAP,
    //MOVE_SMARTSTRIKE,
    //MOVE_PURIFY,
    //MOVE_REVELATIONDANCE,
    //MOVE_COREENFORCER,
    MOVE_TROPKICK,
    //MOVE_INSTRUCT,
    //MOVE_BEAKBLAST,
    //MOVE_CLANGINGSCALES,
    MOVE_DRAGONHAMMER,
    MOVE_BRUTALSWING,
    //MOVE_AURORAVEIL,
    MOVE_SHELLTRAP,
    //MOVE_FLEURCANNON,
    MOVE_PSYCHICFANGS,
    MOVE_STOMPINGTANTRUM,
    //MOVE_SHADOWBONE,
    MOVE_ACCELEROCK,
    MOVE_LIQUIDATION,
    //MOVE_PRISMATICLASER,
    //MOVE_SPECTRALTHIEF,
    //MOVE_SUNSTEELSTRIKE,
    //MOVE_MOONGEISTBEAM,
    MOVE_TEARFULLOOK,
    MOVE_ZINGZAP,
    //MOVE_NATURESMADNESS,
    //MOVE_MULTIATTACK,
    MOVE_MAX,
};

ASSERT_SIZEOF(enum Move, 2);

enum MoveTarget {
    MOVE_TARGET_SELECT, /**< Selected target */
    MOVE_TARGET_VARIABLE, /**< Depends on the attack */
    MOVE_TARGET_EVERYONE, /**< Can be everyone? */
    MOVE_TARGET_RANDOM, /**< Random target */
    MOVE_TARGET_BOTH, /**< Both foes */
    MOVE_TARGET_USER, /**< User */
    MOVE_TARGET_OTHERS, /**< Both foes and partner */
    MOVE_TARGET_OPPONENTS, /**< Opponent field */
};

struct MoveDataFlags {
    u8 contact: 1; /**< This moves makes contact with the target. */
    u8 protect: 1; /**< This move is affected by Protect. */
    u8 magic_coat: 1; /**< This move is affected by Magic Coat. */
    u8 snatch: 1; /**< This move is affected by Snatch.
                     @note Mutually-exclusive with magic_coat */
    u8 mirror_move: 1; /**< This move may be used with Mirror Move */
    u8 kings_rock: 1; /**< This move is affected by the effects of Kings Rock. */
};

struct MoveData {
    u8 move_script_id;
    u8 power;
    u8 type;
    u8 accuracy;
    u8 pp;
    u8 effect_accuracy;
    enum MoveTarget target;
    u8 priority;
    struct MoveDataFlags flags;
    u8 padding[3];
};

ASSERT_SIZEOF(struct MoveData, 0xC);

/**
 * Pokemon move data table.
 *
 * @address{BPRE,08250C04}
 */
extern struct MoveData old_pokemon_moves[MOVE_MAX];

/**
 * Pokemon move names table.
 *
 * @address{BPRE,08247094}
 */
extern pchar old_pokemon_move_names[MOVE_MAX][POKEAGB_MOVE_NAME_LENGTH];

struct LearnsetEntry {
    u16 move: 9;
    u16 level: 7;
};

/**
 * Table of moves a Pokemon can learn by levelling up.
 *
 * @address{BPRE,0825D7B4}
 */
extern struct LearnsetEntry* old_pokemon_learnset[412];

ASSERT_SIZEOF(struct LearnsetEntry, 2);


#define EGGMOVE_MAX 8

/**
 * Pokemon egg moves table
 *
 * @address{BPRE,0825EF0C}
 */
extern u16 old_pokemon_eggmoves[0x471];


POKEAGB_END_DECL

#endif /* POKEAGB_POKEMON_MOVE_H_ */
