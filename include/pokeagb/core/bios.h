/**
 * @file
 * @brief Game engine bios functions
 */

#ifndef POKEAGB_BIOS_H_
#define POKEAGB_BIOS_H_

#include <pokeagb/types.h>

POKEAGB_BEGIN_DECL


/**
 * @address{BPRE,081E3B6C}
 */
POKEAGB_EXTERN void lz77UnCompVram(void* src, void* dst);

/**
 *
 *
 * @address{BPRE,081E3B64}
 */
POKEAGB_EXTERN void CpuSet(u8 *, void *, void *);

/**
 *
 *
 * @address{BPRE,081E39D8}
 */
POKEAGB_EXTERN void AGBPrintf(const char *pBuf, ...);

/**
 *
 *
 * @address{BPRE,081E391C}
 */
POKEAGB_EXTERN void AGBPutc(const char cChr);

POKEAGB_END_DECL

#endif /* POKEAGB_BIOS_H_ */
