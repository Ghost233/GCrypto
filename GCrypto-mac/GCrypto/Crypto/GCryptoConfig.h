//
//  GCrypto.h
//  GCrypto
//
//  Created by Ghost on 12-8-20.
//
//

#ifndef GCrypto_GCrypto_h
#define GCrypto_GCrypto_h

#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define LENGTHBYBITS(__keybits__) ((__keybits__)/8)
#define LENGTHPOSITION(__LENGTH__) (__LENGTH__ / 8 - 1)
#define BIT2BYTE 8

struct _crypto_cstring
{
	long length;
    char *context;
}_crypto_cstring;

typedef struct _crypto_cstring crypto_cstring;

#endif
