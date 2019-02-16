/**
 * @file
 * @brief Flash memory functions for saving.
 */

#ifndef POKEAGB_SAVE_FLASH_H_
#define POKEAGB_SAVE_FLASH_H_

POKEAGB_BEGIN_DECL

// Each 4 KiB flash sector contains 3968 bytes of actual data followed by a 128 byte footer
#define SECTOR_DATA_SIZE 0xFF0
#define SECTOR_FOOTER_SIZE 128
#define NUM_SECTORS_PER_SAVE_SLOT 14
#define FILE_SIGNATURE 0x08012025
#define gSaveBlockParasite 0x0203B174
#define parasiteSize 0xEC4
#define FLASH_SECTORS 32

enum SaveType {
    SAVE_NORMAL = 0,
    SAVE_LINK,
    SAVE_EREADER,
    SAVE_HALL_OF_FAME,
    SAVE_OVERWRITE_DIFFERENT_FILE,
    SAVE_HALL_OF_FAME_ERASE_BEFORE, // unused
};

struct SaveSection {
    u8 data[0xFF4];
    u16 id;
    u16 checksum;
    u32 signature;
    u32 counter;
}; // size is 0x1000


/**
 * Reads a sector from flash memory into a buffer.
 * @param sector A number less than FLASH_SECTORS
 * @param buffer A buffer of at least FLASH_SECTOR_SIZE bytes
 * @return Always 1
 * @address{BPRE,080DA190}
 */
POKEAGB_EXTERN int DoReadFlashWholeSection(u16 sector, void* buffer);

/**
 * Attempt to write data from buffer into a sector.
 * @param sector A number less than FLASH_SECTORS
 * @param buffer A buffer of at least FLASH_SECTOR_SIZE bytes
 * @address{BPRE,080D99D8}
 */
POKEAGB_EXTERN u8 TryWriteSector(u16 sector, void* buffer);

/**
 * Calculates a checksum for saving.
 * @address{BPRE,080DA1A8}
 */
POKEAGB_EXTERN u16 CalculateChecksum(void* data, u16 size);

/**
 * The number of times the game has been saved.
 * @address{BPRE,03005390}
 */
extern u32 save_count;

/**
 * Move the saveblocks around.
 * @address{BPRE,0804C058}
 */
POKEAGB_EXTERN void saveblock_randomize_position(void);

/**
 * Reset globals used for tracking save failure and count.
 * @address{BPRE,080D9750}
 */
POKEAGB_EXTERN void flash_reset_globals(void);

/**
 * Read the saved game.
 * @address{BPRE,080DA4FC}
 */
POKEAGB_EXTERN void flash_read(u8 mode);

/**
 * Updates gRamSaveSectionLocations, for sectors 0-14.
 * @address{BPRE,080DA1D4}
 */
POKEAGB_EXTERN void UpdateSaveAddresses(void);

/**
 * Save the game.
 * @address{BPRE,0804C300}
 */
POKEAGB_EXTERN void SaveSerializedGame(void);

/**
 * Write save game, given a mode/chunk ID and gRamSaveSectionLocations.
 * @address{BPRE,080D97D0}
 */
POKEAGB_EXTERN u8 save_write_to_flash(u16 chunkId, const struct SaveBlockChunk *chunks);

/**
 * The result of reading the save.
 * @address{BPRE,030053A0}
 */
extern u16 save_load_result;

/**
 * Holds amount of times saved so far. Used to figure out backup with %2.
 * @address{BPRE,03005390}
 */
extern u32* gSaveCounter;

/**
 * Holds the sector number, of save ID 0.
 * @address{BPRE,03005380}
 */
extern u16* gFirstSaveSector;

/**
 * A buffer of read save data.
 * @address{BPRE,03005394}
 */
extern struct SaveSection* gFastSaveSection;

POKEAGB_END_DECL

#endif /* POKEAGB_SAVE_FLASH_H_ */
