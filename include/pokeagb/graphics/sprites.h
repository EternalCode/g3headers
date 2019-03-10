/**
 * @file
 * @brief Game engine sprites.
 */

#ifndef POKEAGB_GRAPHICS_SPRITES_H_
#define POKEAGB_GRAPHICS_SPRITES_H_

#include <pokeagb/types.h>

POKEAGB_BEGIN_DECL

#define SPRITE_RAM 0x6010000

struct Sprite;

/**
 * Sprite object callback.
 * @param o The object the callback belongs to
 */
typedef void (*SpriteCallback)(struct Sprite* s);

/**
 * 8 bit coordinates
 */
struct Coords8 {
    u8 x;
    u8 y;
};

/**
 * 16 bit coordinates;
 */
struct Coords16 {
    s16 x;
    s16 y;
};

/**
 * Tile animation frame
 */
struct Frame {
    u16 data;
    u16 duration;
};

/**
 * Rotation/Scaling frame
 */
struct RotscaleFrame {
    u16 scale_delta_x;
    u16 scale_delta_y;
    u8 rot_delta;
    u8 duration;
    u16 field_6;
};

/**
 * OAM Structure
 */

struct OamData {
    u32 y : 8;

    /**
     * 0=Normal, 1=Affine, 2=Disable, 3=Double Size
     */
    u32 affine_mode : 2;

    /**
     * 0=Normal, 1=Semi-Transparent, 2=OBJ Window, 3=Prohibited
     */
    u32 obj_mode : 2;

    /**
     * Enable mosaic
     */
    u32 mosaic : 1;

    /**
     * 1=256 colours
     */
    u32 bpp : 1;

    /**
     * 0=Square,1=Horizontal,2=Vertical,3=Prohibited
     */
    u32 shape : 2;

    u32 x : 9;
    u32 matrix_num : 3; // bits 3/4 are h-flip/v-flip if not in affine mode
    u32 h_flip : 1;
    u32 v_flip : 1;
    /**
     * Size  Square   Horizontal  Vertical
     * 0     8x8      16x8        8x16
     * 1     16x16    32x8        8x32
     * 2     32x32    32x16       16x32
     * 3     64x64    64x32       32x64
     */
    u32 size : 2;

    u16 tile_num : 10;

    /**
     * 0-3; 0=Highest
     */
    u16 priority : 2;
    u16 palette_num : 4;
    u16 affine_param;
};

/**
 * Tileset Data
 */

struct CompressedSpriteSheet {
    void* data;// LZ77 compressed pixel data
    u16 size;// Uncompressed size of pixel data
    u16 tag;
};

struct SpritePalette {
    const void* data;
    u16 tag;
};

/**
 * A template for a sprite object
 */
struct Template {
    u16 tiles_tag;
    u16 pal_tag;
    const struct OamData* oam;
    const struct Frame (**animation)[];
    const struct CompressedSpriteSheet* graphics;
    const struct RotscaleFrame (**rotscale)[];
    SpriteCallback callback;
};

/**
 * Sprite object
 */
 struct Subsprite
{
    s8 x; // was u16 in R/S
    s8 y; // was u16 in R/S
    u16 shape:2;
    u16 size:2;
    u16 tileOffset:10;
    u16 priority:2;
};

struct SubspriteTable
{
    u8 subspriteCount;
    const struct Subsprite *subsprites;
};

struct Sprite {
    struct OamData final_oam;
    struct Frame (**animation_table)[];
    struct CompressedSpriteSheet* gfx_table;
    struct RotscaleFrame (**rotscale_table)[];
    struct Template* object_template;
    /*0x18*/ struct SubspriteTable *subspriteTables;

    SpriteCallback callback;
    /*0x20*/ struct Coords16 pos1;
    /*0x24*/ struct Coords16 pos2;
    /*0x28*/ s8 centerToCornerVecX;
    /*0x29*/ s8 centerToCornerVecY;

    /*0x2A*/ u8 animNum;
    /*0x2B*/ u8 animCmdIndex;
    /*0x2C*/ u8 animDelayCounter:6;
             u8 animPaused:1;
             u8 affineAnimPaused:1;
    /*0x2D*/ u8 animLoopCounter;

    // general purpose data fields
    /*0x2E*/ s16 data[8];

    /*0x3E*/ u16 inUse:1;               //1
             u16 coordOffsetEnabled:1;  //2
             u16 invisible:1;           //4
             u16 flags_3:1;             //8
             u16 flags_4:1;             //0x10
             u16 flags_5:1;             //0x20
             u16 flags_6:1;             //0x40
             u16 flags_7:1;             //0x80
    /*0x3F*/ u16 hFlip:1;               //1
             u16 vFlip:1;               //2
             u16 animBeginning:1;       //4
             u16 affineAnimBeginning:1; //8
             u16 animEnded:1;           //0x10
             u16 affineAnimEnded:1;     //0x20
             u16 usingSheet:1;          //0x40
             u16 flags_f:1;             //0x80

    /*0x40*/ u16 sheetTileStart;

    /*0x42*/ u8 subspriteTableNum:6;
             u8 subspriteMode:2;

    /*0x43*/ u8 subpriority;
};

struct OamMatrix
{
    s16 a;
    s16 b;
    s16 c;
    s16 d;
};

// This is used with SWI 0x0F: ObjAffineSet as src
struct ObjAffineSrcData
{
    s16 xScale;
    s16 yScale;
    u16 rotation;
};


/**
 * All the objects
 * @address{BPRE,0202063C}
 */
extern struct Sprite gSprites[64];


/**
 * sin table
 * @address{BPRE,0825E074}
 */
extern const s16 gSineTable[256];

/**
 * Transformation matrix mirror for objects
 * @address{BPRE,02021BCC}
 */
extern struct OamMatrix gOamMatrices[32];


/**
 * @address{BPRE,08231CFC}
 */
extern const struct RotscaleFrame (*rotscale_empty)[];

/**
 * @address{BPRE,08231CF0}
 */
extern const struct Frame (*anim_image_empty)[];

#define SPRITE_NO_ANIMATION (&anim_image_empty)
#define SPRITE_NO_ROTSCALE (&rotscale_empty)

/**
 * @address{BPRE,0800760C}
 */
POKEAGB_EXTERN void oac_nullsub(struct Sprite* o);

/**
* @address{BPRE,08006B10}
*/
POKEAGB_EXTERN void ResetSpriteData(void);

/**
 * @address{BPRE,08006B5C}
 */
POKEAGB_EXTERN void AnimateSprites(void);

/**
* @address{BPRE,08006BA8}
*/
POKEAGB_EXTERN void BuildOAMBuffer(void);

/**
* @address{BPRE,08006F8C}
*/
POKEAGB_EXTERN u8 CreateSprite(const struct Template*,
    u16 x,
    u16 y,
    u8 priority);

/**
* @address{BPRE,08006FE0}
*/
POKEAGB_EXTERN u8 CreateSpriteAtEnd(struct Template*, s16 x, s16 y, u8 height);

/**
* @address{BPRE,080071EC}
*/
POKEAGB_EXTERN u8 CreateSpriteAndAnimate(const struct Template*,
    u16 x,
    u16 y,
    u8 priority);

/**
* Delete and free tiles
* @address{BPRE,08007280}
*/
POKEAGB_EXTERN void DestroySprite(struct Sprite*);

/**
* Reset affine. This doesn't reset the rotscale tables
* @address{BPRE,08007390}
*/
POKEAGB_EXTERN void ResetOamMatrices(void);

/**
 * @address{BPRE,080073BC}
 */
POKEAGB_EXTERN void SetOamMatrix(u8 matrixNum, u16 a, u16 b, u16 c, u16 d);

/**
* @address{BPRE,080073DC}
*/
POKEAGB_EXTERN void obj_delete(struct Sprite *obj);

/**
* @address{BPRE,080073F0}
*/
POKEAGB_EXTERN void CalcCenterToCornerVec(struct Sprite *sprite, u8 shape, u8 size, u8 affineMode);

/**
* reset rotscale entries for all
* @address{BPRE,080077D8}
*/
POKEAGB_EXTERN void FreeSpriteOamMatrix(struct Sprite*);

/**
 * @address{BPRE,08007804}
 */
POKEAGB_EXTERN u8 DestroySpriteAndFreeResources(struct Sprite*);

/**
* Get the gOamMatrices index for a sprite
* @address{BPRE,08007FDC}
*/
POKEAGB_EXTERN void AnimateSprite(struct Sprite*);

/**
* set oam animation start
* @address{BPRE,08007824}
*/
POKEAGB_EXTERN void GetSpriteMatrixNum(struct Sprite*);

/**
* set oam animation start
* @address{BPRE,0800838C}
*/
POKEAGB_EXTERN void StartSpriteAnim(void);

/**
* Resets the rotscale animation for an object and starts the animation from the specified rotscale table index
* @address{BPRE,0800843C}
*/
POKEAGB_EXTERN void StartSpriteAffineAnim(struct Sprite* obj, u8 table_index);

/**
* reset rotscale entries for all
* @address{BPRE,08008560}
*/
POKEAGB_EXTERN void ResetAffineAnimData(void);

/**
* Picks a free oam matrix index and returns the found index
* @address{BPRE,08008560}
*/
POKEAGB_EXTERN u8 AllocOamMatrix(void);

/**
 * @address{BPRE,0800F078}
 */
POKEAGB_EXTERN void LoadCompressedSpritePaletteUsingHeap(struct SpritePalette* pal);

/**
 * @address{BPRE,08008928}
 */
POKEAGB_EXTERN u8 gpu_pal_obj_alloc_tag_and_apply(struct SpritePalette* pal);

/**
 * @address{BPRE,0800F034}
 */
POKEAGB_EXTERN void LoadCompressedSpriteSheetUsingHeap(struct CompressedSpriteSheet* tile);

/**
 * @address{BPRE,080086DC}
 */
POKEAGB_EXTERN void gpu_tile_obj_alloc_tag_and_upload(struct CompressedSpriteSheet* tile);

/**
 * @address{BPRE,08008804}
 */
POKEAGB_EXTERN u16 gpu_tile_obj_tag_range_for_tag(u16 tile_tag);

/**
 * @address{BPRE,08008A30}
 */
POKEAGB_EXTERN u16 FreeSpritePaletteByTag(u16 pal_tag);

/**
 * @address{BPRE,080087C4}
 */
POKEAGB_EXTERN void gpu_tile_obj_tags_reset(void);

/**
 * @address{BPRE,080836B4}
 */
POKEAGB_EXTERN void obj_free(struct Sprite *obj);


/**
 * @address{BPRE,0800874C}
 */
POKEAGB_EXTERN void FreeSpriteTilesByTag(u16 tag);


/**
 * @address{BPRE,0800885C}
 */
POKEAGB_EXTERN u16 GetTileTagBySheet(u16 sheet);

/**
 * Bouncing object. Uses private variables for control.
 * private[0] = 0 - Start object animation before bounce, 1 - Just bounce, other - disable
 * private[1] = Animation to start if private[0] == 0
 * private[2] = Direction: 0 - horizontal, 1 - vertical
 * private[3] = Distance
 * private[4] = Speed
 * private[5] = Phase Shift
 * @address{BPRE,08133904}
 */
POKEAGB_EXTERN void oac_pingpong(struct Sprite*);


/**
 * Sine wave. Used to animate bouncing objects.
 * @param phase The current phase or the x in sin(x)
 * @param scale The amplitude of the wave
 * @address{BPRE,08044E30}
 */
POKEAGB_EXTERN s16 Sin(s16 phase, s16 scale);

/**
 * Cosine wave. Used to animate bouncing objects.
 * @param phase The current phase or the x in Cos(x)
 * @param scale The amplitude of the wave
 * @address{BPRE,08044E4C}
 */
POKEAGB_EXTERN s16 Cos(s16 phase, s16 scale);

/**
 * Sin(x) << 16. With "x" in degrees
 * @address{BPRE,08044E6C}
 */
POKEAGB_EXTERN s16 Sin2(u16 angle);

/**
 * Cos(x) with X in degrees
 * @address{BPRE,08044EB0}
 */
POKEAGB_EXTERN s16 Cos2(u16 angle);

/**
 * apply palfade for transparent objects
 * @address{BPRE,08070588}
 */
POKEAGB_EXTERN void obj_apply_bldpalfade(u32, s16, s16, s16, u32);

/**
 * set oam matrix rotscale manually
 * @address{BPRE,08075858}
 */
POKEAGB_EXTERN void obj_id_set_rotscale(u8 objid, u32 pa, u32 pb, u32 pc, u32 pd);

POKEAGB_END_DECL

#endif /* POKEAGB_GRAPHICS_SPRITES_H_ */
