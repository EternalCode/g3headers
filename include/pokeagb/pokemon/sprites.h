/**
 * @file
 * @brief Pokemon sprites
 */

#ifndef POKEAGB_POKEMON_SPRITES_H_
#define POKEAGB_POKEMON_SPRITES_H_

#include "base.h"
#include "../graphics.h"

/**
 * @address{BPRE,082350AC}
 */
struct Graphics pokemon_graphics_front[POKEAGB_POKEMON_SLOTS];

/**
 * @address{BPRE,0823654C}
 */
struct Graphics pokemon_graphics_back[POKEAGB_POKEMON_SLOTS];

/**
 * @address{BPRE,0823730C}
 */
struct SpritePalette pokemon_palette_normal[POKEAGB_POKEMON_SLOTS];

/**
 * @address{BPRE,082380CC}
 */
struct SpritePalette pokemon_palette_shiny[POKEAGB_POKEMON_SLOTS];

#endif /* POKEAGB_POKEMON_SPRITES_H_ */