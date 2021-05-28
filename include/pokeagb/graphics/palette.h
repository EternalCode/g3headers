/**
 * @file
 * @brief Palettes
 */

#ifndef POKEAGB_GRAPHICS_PALETTE_H_
#define POKEAGB_GRAPHICS_PALETTE_H_

#include "../types.h"

#define PLTT_BUFFER_SIZE 0x200
#define PLTT_BUFFER_ONE_SIZE 0x100
#define PLTT_DECOMP_BUFFER_SIZE (PLTT_BUFFER_SIZE * 2)
#define OBJ_EVENT_PAL_TAG_NONE 0x11FF

// this doesn't structured right at. Bit fields broken between bytes
// and game loads it as though it's a byte. Please review
struct PaletteFadeControl {
    u16 bg_pal_bitfield;
    u16 obj_pal_bitfield;
    u8 delay_counter:6;
    u16 y:5; // blend coefficient
    u16 target_y:5; // target blend coefficient
    u16 blend_color:15;
    u16 active:1;
    u16 multipurpose:6;
    u16 y_dec:1; // whether blend coefficient is decreasing
    u16 buffer_transfer_disabled:1;
    u16 mode:2;
    u16 should_reset_blend_registers:1;
    u16 hardware_fade_finishing:1;
    u16 software_fade_finishing_counter:5;
    u16 software_fade_finishing:1;
    u16 obj_palette_toggle:1;
    u8 delta_y:4; // rate of change of blend coefficient
};

struct ColorComponents {
    u16 r : 5;
    u16 g : 5;
    u16 b : 5;
    u16 unused : 1;
};

union Color {
    struct ColorComponents components;
    u16 packed;
};

struct PairedPalettes {
    u16 tag;
    const u16 *data;
};


/**
 * @address{BPRE,02037AB8}
 */
extern struct PaletteFadeControl gPaletteFade;

/**
 * @address{BPRE,020371F8}
 */
extern u16 gPlttBufferUnfaded[PLTT_BUFFER_SIZE];

/**
 * @address{BPRE,020375F8}
 */
extern u16 gPlttBufferFaded[PLTT_BUFFER_SIZE];

/**
 * @address{BPRE,020377F8}
 */
extern u16 gPlttBufferObjFaded[PLTT_BUFFER_SIZE];

/**
 * @address{BPRE,020373F8}
 */
extern u16 gPlttBufferObjUnFaded[PLTT_BUFFER_SIZE];

/**
 * @address{BPRE,08150408}
 */
POKEAGB_EXTERN u8* stdpal_get(u8 id);

/**
 * @address{BPRE,03003E58}
 */
extern u8* gpu_pal_tag_search_lower_boundary;

/**
 * @address{BPRE,080703EC}
 */
POKEAGB_EXTERN void LoadPalette(void* palette, u16 offset, u16 size);

/**
 * @address{BPRE,080089E8}
 */
POKEAGB_EXTERN u8 IndexOfSpritePaletteTag(u16 tag);

/**
 * @address{BPRE,080703A8}
 */
POKEAGB_EXTERN void LoadPalette_compressed(void* palette, u16 offset, u16 size);

/**
 * @address{BPRE,08070588}
 */
POKEAGB_EXTERN bool BeginNormalPaletteFade(u32 selectedPalettes, s8 delay, u8 startY, u8 targetY, u16 blendColor);

/**
 * fade_and_return_progress_probably
 * @address{BPRE,080704D0}
 */
POKEAGB_EXTERN DEPRECATED void UpdatePaletteFade(void);

/**
 * @address{BPRE,08071510}
 */
POKEAGB_EXTERN void BlendPalettesUnfaded(u32 selectedPalettes, u8 coeff, u16 color);

/**
 * @address{BPRE,08070474}
 */
POKEAGB_EXTERN void TransferPlttBuffer(void);

/**
 * @address{BPRE,08070528}
 */
POKEAGB_EXTERN void pal_fade_control_and_dead_struct_reset(void);

/**
 * @address{BPRE,0807DB38}
 */
POKEAGB_EXTERN void palette_bg_faded_fill_black(void);

/**
 * @address{BPRE,08083598}
 */
POKEAGB_EXTERN void TintPalette_Switch(u8 palIndex);

/**
 * @address{BPRE,080704D0}
 */
POKEAGB_EXTERN void process_palfade(void);

/**
 * @address{BPRE,080088F0}
 */
POKEAGB_EXTERN void FreeAllSpritePalettes(void);

/**
 * @address{BPRE,08008928}
 */
POKEAGB_EXTERN u8 LoadSpritePalette(struct SpritePalette* pal);

/**
 * @address{BPRE,080089B8}
 */
POKEAGB_EXTERN u8 AllocSpritePalette(u16 tag);


/**
 * @address{BPRE,0807DC00}
 */
POKEAGB_EXTERN void pal_fill_black(void);


/**
 * @address{BPRE,083A5158}
 */
extern const struct SpritePalette old_sObjectEventSpritePalettes[];

/**
 * @address{BPRE,03003E58}
 */
extern u8 gReservedSpritePaletteCount;

/**
 * @address{BPRE,083A5208}
 */
extern const struct PairedPalettes gPlayerReflectionPaletteSets[];

/**
 * @address{BPRE,083A5278}
 */
extern const struct PairedPalettes gSpecialObjectReflectionPaletteSets[];

/**
 * @address{BPRE,0835B934}
 */
extern const u8 gReflectionEffectPaletteMap[];

/**
 * @address{BPRE,03000DE8}
 */
extern u16 sSpritePaletteTags[16];


/**
 * @address{BPRE,0805F5A0}
 */
POKEAGB_EXTERN u8 FindObjectEventPaletteIndexByTag(u16 tag);

#endif /* POKEAGB_GRAPHICS_PALETTE_H_ */
