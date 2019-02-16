/**
 * @file
 * @brief Pokedex functions.
 */

#ifndef POKEAGB_POKEMON_POKEDEX_H_
#define POKEAGB_POKEMON_POKEDEX_H_

#include <pokeagb/common.h>
#include <pokeagb/types.h>
#include <pokeagb/pokemon/species.h>

POKEAGB_BEGIN_DECL

enum DexFlagOperation {
    DEX_FLAG_CHECK_SEEN,
    DEX_FLAG_CHECK_CAUGHT,
    DEX_FLAG_SET_SEEN,
    DEX_FLAG_SET_CAUGHT,
    /* TODO: Figure out rest */
};

#define POKEMON_SLOTS_NUMBER 412
#define DEX_FLAGS_NO ((POKEMON_SLOTS_NUMBER / 8) + ((POKEMON_SLOTS_NUMBER % 8) ? 1 : 0))

struct Pokedex {
    /*0x00*/ u8 order;
    /*0x01*/ u8 unknown1;
    /*0x02*/ u8 nationalMagic; // must equal 0xDA in order to have National mode
    /*0x03*/ u8 unknown2;
    /*0x04*/ u32 unownPersonality; // set when you first see Unown
    /*0x08*/ u32 spindaPersonality; // set when you first see Spinda
    /*0x0C*/ u32 unknown3;
    /*0x10*/ u8 owned[DEX_FLAGS_NO];
    /*0x44*/ u8 seen[DEX_FLAGS_NO];
};

/**
 * Check the Pokedex flag given a Pokedex index.
 * @param index The species or Pokedex index
 * @param op The operation to perform
 * @address{BPRE,08088E74}
 */
POKEAGB_EXTERN bool dex_flag_pokedex_index(u16 index, enum DexFlagOperation op);

/**
 * Check the Pokedex flag given an index.
 * @param index The species or Pokedex index
 * @param op The operation to perform
 * @param convert_index If true, the index given is a PokemonSpecies index and will be converted.
 * @address{BPRE,08088E74}
 */
POKEAGB_EXTERN bool dex_flag(u16 index, enum DexFlagOperation op, bool convert_index);

/**
 * Convert a species index to a Pokedex index.
 * @address{BPRE,08043298}
 */
POKEAGB_EXTERN u16 species_to_pokedex_index(u16);

/**
 * Convert a species index to a Pokedex index.
 * @address{BPRE,08043200}
 */
POKEAGB_EXTERN u16 pokedex_index_to_species(u16);

/**
 * @address{BPRE,08251FEE}
 */
extern const u16 pokedex_order[412 - 1];

POKEAGB_END_DECL

#endif /* POKEAGB_POKEMON_POKEDEX_H_ */
