/**
 * @file
 * @brief Background graphics
 */

#ifndef POKEAGB_GRAPHICS_BACKGROUND_H_
#define POKEAGB_GRAPHICS_BACKGROUND_H_

#include "../types.h"

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 160

#define BG_ATTR_WRAPAROUND 6
#define BG_ATTR_PRIORITY 7

struct BgConfig {
	u32 bgid : 2;
	u32 character_base : 2;
	u32 map_base : 5;
	u32 size : 2;
	u32 palette : 1;
	u32 priority : 2;
	u32 basetile : 10;
};

struct BgConfig2 {
    u16 target_tile;
	u16 padding;
    u8 *tilemap;
    s32 x;
    s32 y;
};

struct mapblock_16color {
    u16 tile_offset : 8;
    u16 disable : 2; // not sure, could possible be part of tile offset
    u16 h_flip : 1;
    u16 v_flip : 1;
    u16 pal_slot : 4;
};

/**
 * @address{BPRE,0203AB58}
 */
extern void* sTempTileDataBuffers[0x20];

/**
 * @address{BPRE,0203AB5C}
 */
extern u8 sTempTileDataBufferCursor;

/**
 * @address{BPRE,0300501C}
 */
extern u16* gBGTilemapBuffers3;

/**
 * @address{BPRE,03005014}
 */
extern u16* gBGTilemapBuffers2;

/**
 * @address{BPRE,03005018}
 */
extern u16* gBGTilemapBuffers1;

/**
 * @address{BPRE,030008E8}
 */
extern struct BgConfig2 sGpuBgConfigs2[4];

/**
 * @address{BPRE,030008D0}
 */
extern struct BgConfig sGpuBgConfigs[4];

/**
 * @address{BPRE,0800139C}
 */
POKEAGB_EXTERN void HideBgInternal(u8 bg);

/**
 * @address{BPRE,08001320}
 */
POKEAGB_EXTERN void ShowBgInternal(u8 bg);

/**
 * @address{BPRE,08001618}
 */
POKEAGB_EXTERN void gpu_tile_bg_drop_all_sets(u8);


/**
 * @address{BPRE,0800108C}
 */
POKEAGB_EXTERN void gpu_sGpuBgConfigs_set_by_serialized(u8);


/**
 * @address{BPRE,080010B8}
 */
POKEAGB_EXTERN void SetBgControlAttributes(u8 bg, u8 charBaseIndex, u8 mapBaseIndex, u8 screenSize, u8 paletteMode, u8 priority, u8 mosaic, u8 wraparound);

/**
 * @address{BPRE,080019E4}
 */
POKEAGB_EXTERN void SetBgControlAttribute(u8 bg, u8 attributeId, u8 value);

/**
 * @address{BPRE,080011E4}
 */
POKEAGB_EXTERN u16 GetBgControlAttribute(u8 bg, u8 attributeId);

/**
 * @address{BPRE,080F67B8}
 */
POKEAGB_EXTERN void DoScheduledBgTilemapCopiesToVram(void);

/**
 * @address{BPRE,08002008}
 */
POKEAGB_EXTERN void* GetBgTilemapBuffer(u8 bgid);

/**
 * @address{BPRE,0812D594}
 */
POKEAGB_EXTERN void bg_positions_reset(void);

/**
 * @address{BPRE,080F4E24}
 */
POKEAGB_EXTERN void callback_clear_and_init(void);

/**
 * @address{BPRE,08001FD4}
 */
POKEAGB_EXTERN void bgid_nullify_tilemap(u8);

/**
 * @address{BPRE,080017D0}
 */
POKEAGB_EXTERN u16 LoadBgTiles(u8 bgid, u8* tiles, u16 size, u16 destOffset);

/**
 * @address{BPRE,08002040}
 */
POKEAGB_EXTERN void CopyToBgTilemapBuffer(u8 bgid, u8* map, u16 size_or_null, u16 offset);

/**
 * @address{BPRE,080020BC}
 */
POKEAGB_EXTERN void CopyBgTilemapBufferToVram(u8 bgid);

/**
 * @address{BPRE,08001FA0}
 */
POKEAGB_EXTERN void SetBgTilemapBuffer(u8 bgid, u8* space);

/**
 * @address{BPRE,08001888}
 */
POKEAGB_EXTERN u16 LoadBgTilemap(u8 bg, const void *src, u16 size, u16 destOffset);

/**
 * @address{BPRE,08001658}
 */
POKEAGB_EXTERN void bg_vram_setup(u8 bgid, const struct BgConfig* config, u8 layers);

/**
 * @address{BPRE,08001658}
 */
POKEAGB_EXTERN void bg_vram_set(u8 mode, u32 *setup_array, u8 array_size);

/**
 * @address{BPRE,080F6878}
 */
POKEAGB_EXTERN void* decompress_with_fallback_maybe(u8 layer,
                                                    u8* tiles,
                                                    u16 size,
                                                    u16 offset,
                                                    u8 mode);

/**
 * @address{BPRE,080019BC}
 */
POKEAGB_EXTERN void ShowBg(u8 layer);

/**
 * @address{BPRE,080019D0}
 */
POKEAGB_EXTERN void HideBg(u8 layer);

/**
 * @address{BPRE,08007320}
 */
POKEAGB_EXTERN void LoadOam(void);

/**
 * @address{BPRE,08007610}
 */
POKEAGB_EXTERN void ProcessSpriteCopyRequests(void);

/**
 * @address{BPRE,080563F0}
 */
POKEAGB_EXTERN void overworld_free_bgmaps(void);

/**
 * @address{BPRE,08001D08}
 */
POKEAGB_EXTERN void ChangeBgY(u8 bgid, s32 delta, u8 dir);

/**
 * @address{BPRE,08001B90}
 */
POKEAGB_EXTERN void ChangeBgX(u8 bgid, s32 delta, u8 dir);

/**
 * @address{BPRE,08001CCC}
 */
POKEAGB_EXTERN s32 GetBgX(u8 bgid);

/**
 * @address{BPRE,08001E44}
 */
POKEAGB_EXTERN s32 GetBgY(u8 bgid);

struct REG_BGCNT {
	u16 priority : 2;
	u16 char_index : 2; // 0x6000000 + char_index * 0x4000
	u16 padding : 2;
	u16 mosiac : 1;
	u16 color : 1; // 256 or 16
	u16 map_index : 5;
	u16 screen_over : 1;
	u16 size : 2;
	/*
	For "text" backgrounds:
	  00 : 256x256 (32x32 tiles)
	  01 : 512x256 (64x32 tiles)
	  10 : 256x512 (32x64 tiles)
	  11 : 512x512 (64x64 tiles)

	  For rotational backgrounds:
	  00 : 128x128 (16x16 tiles)
	  01 : 256x256 (32x32 tiles)
	  10 : 512x512 (64x64 tiles)
	  11 : 1024x1024 (128x128 tiles)

	*/
};

/**
 * BGCNT
 *
 * @address{BPRE,04000008}
 */
extern struct REG_BGCNT BG_CNT[4];

/**
 * @address{BPRE,080F6790}
 */
POKEAGB_EXTERN void ClearScheduledBgCopiesToVram(void);

/**
 * @address{BPRE,080F6808}
 */
POKEAGB_EXTERN void ResetTempTileDataBuffers(void);

/**
 * @address{BPRE,080F67A4}
 */
POKEAGB_EXTERN void ScheduleBgCopyTilemapToVram(u8 bgid);

/**
 * @address{BPRE,08087F54}
 */
POKEAGB_EXTERN void ScanlineEffect_InitHBlankDmaTransfer(void);

/**
 * @address{BPRE,0805A5F4}
 */
POKEAGB_EXTERN void FieldUpdateBgTilemapScroll(void);

/**
 * @address{BPRE,0805A5F4}
 */
POKEAGB_EXTERN void FieldUpdateBgTilemapScroll(void);

/**
 * @address{BPRE,0806FF54}
 */
POKEAGB_EXTERN void TransferTilesetAnimsBuffer(void);

/**
 * @address{BPRE,080563F0}
 */
POKEAGB_EXTERN void CleanupOverworldTextboxesAndTilemaps(void);

/**
 * BG Rotscale maybe
 * @address{BPRE,08001E80}
 */
POKEAGB_EXTERN void SetBgAffine(u8 bg, u32 srcCenterX, u32 srcCenterY, s16 dispCenterX, s16 dispCenterY, s16 scaleX, s16 scaleY, u16 rotationAngle);


#endif /* POKEAGB_GRAPHICS_BACKGROUND_H_ */
