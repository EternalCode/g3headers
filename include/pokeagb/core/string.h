/**
 * @file
 * @brief GameFreak strings.
 */

#ifndef POKEAGB_CORE_STRING_H_
#define POKEAGB_CORE_STRING_H_

#include <pokeagb/types.h>
#include "task.h"

POKEAGB_BEGIN_DECL

typedef u8 pchar;
struct Textbox {
    u8 bg_id;
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    u8 pal_id;
    u16 charbase;
    u8* pixels;
};

struct TextboxTemplate {
    u8 bg_id;
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    u8 pal_id;
    u16 charbase;
};

struct TextColor {
    u8 background;
    u8 foreground;
    u8 shadow;
};

ASSERT_SIZEOF(struct Textbox, 12);
ASSERT_OFFSETOF(struct Textbox, bg_id, 0);
ASSERT_OFFSETOF(struct Textbox, x, 1);
ASSERT_OFFSETOF(struct Textbox, y, 2);
ASSERT_OFFSETOF(struct Textbox, width, 3);
ASSERT_OFFSETOF(struct Textbox, height, 4);
ASSERT_OFFSETOF(struct Textbox, charbase, 6);
ASSERT_OFFSETOF(struct Textbox, pixels, 8);

/**
 * @address{BPRE,020204B4}
 */
extern struct Textbox rboxes[32];


/**
 * @address{BPRE,0x0203709C}
 */
extern u8 box_status_and_type;

/**
 * Clear a textbox.
 *
 * @address{BPRE,0800445C}
 */
POKEAGB_EXTERN void rboxid_clear_pixels(u8 id, u8 offset);

/**
 * Update a textbox.
 *
 * @param mode 3 == Update tileset & tilemap, 2 == update tileset, 1 == update tilemap
 * @address{BPRE,08003F20}
 */
POKEAGB_EXTERN void rboxid_update(u8 id, u8 mode);


struct ScrollArrows {
    struct Arrow {
        /* TODO: Enum direction */
        u8 orientation;
        u8 x;
        u8 y;
    } positions[2];

    /**
     * Arrow IDs. A pointer to the arrow ID function can be passed in
     * to the spawning function. If the value at that pointer is equal
     * to the ID in this array, then the arrow is visible. There are
     * two slots for the two arrows.
     */
    u16 ids[2];

    /**
     * The tiles tag or 0xFFFF.
     */
    u16 tiles_tag;

    /**
     * The palette tag or 0xFFFF.
     */
    u16 palette_tag;

    /**
     * The palette slot index to start copying the arrow palette to.
     */
    u8 palette_index;
};

ASSERT_SIZEOF(struct ScrollArrows, 16);
ASSERT_OFFSETOF(struct ScrollArrows, positions, 0);
ASSERT_OFFSETOF(struct ScrollArrows, ids, 6);
ASSERT_OFFSETOF(struct ScrollArrows, tiles_tag, 10);
ASSERT_OFFSETOF(struct ScrollArrows, palette_tag, 12);
ASSERT_OFFSETOF(struct ScrollArrows, palette_index, 14);

struct ScrollArrowTaskState {
    u8 starts_zero;
    u16* current_arrow_id;
    u16 arrow_ids[2];
    u16 unknown;
    u16 tiles_tag;
    u16 palette_tag;
};

/**
 * Draw a pair of red arrows to indicate scrolling. This creates a
 * task with the private state layout seen in ScrollArrowTaskState
 *
 * @param data The box that the arrows must be drawn around.
 * @param arrows Pointer to a byte which controls which arrows ID to activate.
 * @returns Task ID
 * @address{BPRE,08133A20}
 */
POKEAGB_EXTERN u8 textbox_spawn_scroll_arrows(const struct ScrollArrows* data, u16* arrows);

/**
 * Clean up the scroll arrows and delete the task. Set the task
 * function for the task returned from textbox_spawn_scroll_arrows to
 * this to clean up.
 *
 * @address{BPRE,08133C30}
 */
POKEAGB_EXTERN void textbox_task_delete_scroll_arrows(u8 task_id);

#define FCODE_BUFFER_SIZE 20
#define STRING_BUFFER_SIZE 1000

/**
 * Generic buffer for strings.
 * @address{BPRE,02021CD0}
 */
extern pchar gFcodeBuffer2[FCODE_BUFFER_SIZE];

/**
 * Generic buffer for strings.
 * @address{BPRE,02021CF0}
 */
extern pchar gFcodeBuffer3[FCODE_BUFFER_SIZE];

/**
 * Generic buffer for strings.
 * @address{BPRE,02021D04}
 */
extern pchar gFcodeBuffer4[FCODE_BUFFER_SIZE];

/**
 * Generic buffer also used for strings
 * @address{BPRE,02021D18}
 */
extern pchar gStringBuffer[STRING_BUFFER_SIZE];

/**
 * Copies the 0xFF terminated string from source to desination.
 * @address{BPRE,08008D84}
 */
POKEAGB_EXTERN pchar* pstrcpy(pchar* dst, const pchar* src);

/**
 * Appends a copy of the source to the end of the 0xFF terminated string at destination.
 * @address{BPRE,08008DA4}
 */
POKEAGB_EXTERN pchar* pstrcat(pchar* dst, const pchar* src);

/**
 * Returns the length of the 0xFF terminated string.
 * @address{BPRE,08008E08}
 */
POKEAGB_EXTERN u16 pstrlen(pchar* s);

/**
 * Converts int to pstring. Maybe more. Padding_x may just be the Space char.
 * @address{BPRE,08008E78}
 */
POKEAGB_EXTERN pchar* fmt_int_10(pchar* dst, u32 num, u8 padding_x, u8);

/**
 * @address{BPRE,08002C28}
 */
POKEAGB_EXTERN void remo_reset_acknowledgement_flags(void);

/**
 * @address{BPRE,08003ECC}
 */
POKEAGB_EXTERN void rboxes_free(void);

/**
 * @address{BPRE,08002DE8}
 */
POKEAGB_EXTERN void RunTextPrinters();

/**
 * creates new rbox using string. Rbox tiles address returned, and
 * rboxid written to buffer.
 * @address{BPRE,0804A648}
 */
POKEAGB_EXTERN u32 write_to_rbox(pchar* string, u8 unk, u8 unk2, u8* rboxid_buffer);


/**
 * @address{BPRE,0804A6E8}
 */
POKEAGB_EXTERN u8 rbox_to_vram(void* vram_addr, void* src_pixels, u8 tiles_to_copy_maybe);



/**
 * Allocates a textbox and returns its ID.
 * @address{BPRE,08002C48}
 */
POKEAGB_EXTERN u8 rboxid_draw_text(u8 id, u8 font, const pchar* s, u8 x, u8 y, u8 speed,
                                   void* callback);

/**
 * @address{BPRE,0812E51C}
 */
POKEAGB_EXTERN u8 rboxid_print(u8 id, u8 font, u8 x, u8 y, struct TextColor* color,
                               u8 speed, const pchar* s);
							   
/**
 * outline a textbox
 * @address{BPRE,0810F2E8}
 */
POKEAGB_EXTERN void rbox_outline(u8 box_id, u8, u8, u8);

/**
 * Get the width in pixels of a string.
 * @address{BPRE,08005ED4}
 */
POKEAGB_EXTERN u32 font_get_width_of_string(u8 font, const pchar* s, u16);

/**
 * @address{BPRE,080F6CD0}
 */
POKEAGB_EXTERN void box_related_one(u8, u8, pchar *, u8, u8, u8, u8, u8);

/**
 * @address{BPRE,080F6CD0}
 */
POKEAGB_EXTERN void box_related_one(u8, u8, pchar *, u8, u8, u8, u8, u8);

/**
 * Allocates a textbox and returns its ID.
 * @address{BPRE,08003FA0}
 */
POKEAGB_EXTERN u8 rboxid_tilemap_update(u8 id);

/**
 * Clean a textbox. Should be called before rboxid_free.
 * @address{BPRE,0810F4D8}
 */
POKEAGB_EXTERN u8 rboxid_clean(u8 id, bool update);

/**
 * Free a textbox.
 * @address{BPRE,08003E3C}
 */
POKEAGB_EXTERN u8 rboxid_free(u8 id);

/**
 *
 * @address{BPRE,080F7768}
 */
POKEAGB_EXTERN void box_curved(u8 rboxid, u8 player_closed);


/**
 *
 * @address{BPRE,080D87BC}
 */
POKEAGB_EXTERN void ShowBattleMessage(pchar* str, u8 unk);


/**
 *
 * @address{BPRE,080694C8}
 */
POKEAGB_EXTERN void textbox_fdecode_auto_and_task_add(pchar* str);

/**
 *
 * @address{BPRE,080694F4}
 */
POKEAGB_EXTERN void textbox_close(void);

/**
 * Rbox init, but for a special battle box
 * @address{BPRE,08003B24}
 */
POKEAGB_EXTERN void rbox_init_from_templates(struct TextboxTemplate* templates);

/**
 *
 * @address{BPRE,0800F380}
 */
POKEAGB_EXTERN void battlebox_mark_usable(void);

/**
 * If A is pressed and Dialog has reached it's end, returns 0 to mark completion
 * @address{BPRE,08002E64}
 */
POKEAGB_EXTERN bool dialogid_was_acknowledged(u8);

/**
 * string substitution based on assigned buffer ids
 * @address{BPRE,08008FCC}
 */
POKEAGB_EXTERN pchar* fdecoder(pchar* dst, pchar* src);


/**
 * @address{BPRE,08004950}
 */
POKEAGB_EXTERN u32 rboxid_get_field(u8 rid, u8 field);


/**
 * string substitution based on assigned buffer ids
 * @address{BPRE,0812E5A4}
 */
POKEAGB_EXTERN void rboxid_add_812E5A4(u8, u8, u8, u8, u8, u8, u32*, u8, pchar*);


/**
 * Sets up a choice box cursor
 * @address{BPRE,0810F7D8}
 */
POKEAGB_EXTERN void choice_setup_simple(u8 rid, u8 fboxid, u8 x, u8 y, u8 y_stride, u8 num_choices, u8 preselected_choice);


/**
 * enables choice selection on a multichoice box. Additionally, returns a value on resolution
 * -1 = B pressed, -2 = waiting for response, 0+ choice picked
 * @address{BPRE,0810FA04}
 */
POKEAGB_EXTERN s8 rbox_choice_update(void);

/**
 * Draws an outline around a text box
 * @address{BPRE,0810F2E8}
 */
POKEAGB_EXTERN u32 outline_box(u8 rid, bool trigger_a, u16 tilemap_set_something_idk, u8 pal_slot);

/**
 * Updates tilemap and tileset of given box, preserving order of execution
 * @param id Textbox ID according to TextboxTemplate configuration
 * @address{BPRE,0812DFE4}
 */
POKEAGB_EXTERN void rboxid_update_tilemap_and_tileset(u8 id);
/**
 * Allocates a single textbox and returns its ID.
 * @returns Textbox ID or 255 on failure.
 * @address{BPRE,08003CE4}
 */
POKEAGB_EXTERN u8 rboxid_init(struct TextboxTemplate* textbox);
/**
 * Gets the game textspeed after modification by the options menu
 * @address{BPRE,080F78A8}
 */
POKEAGB_EXTERN u8 sav2_get_text_speed(void);

/**
 * Callback, prints text for bag
 * @address{BPRE,0810A1F8}
 */
POKEAGB_EXTERN void bag_print(u8 taskid);

/**
 * Callback, prints text for bag with SOUND_GENERIC_CLINK on A press
 * @address{BPRE,0810A1D0}
 */
POKEAGB_EXTERN void bag_print_and_click_sound(u8 taskid);

/**
 * Callback, prints text for bag
 * @address{BPRE,08108E70}
 */
POKEAGB_EXTERN void PrintErrorMsgBag(u8 taskid, u8 fboxid, pchar* str, TaskCallback textHandler);


POKEAGB_END_DECL

#endif /* POKEAGB_CORE_STRING_H_ */
