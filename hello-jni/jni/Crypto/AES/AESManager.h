//
//  AESManager.h
//  GCrypto
//
//  Created by Ghost on 12-8-22.
//
//

#ifndef GCrypto_AESManager_h
#define GCrypto_AESManager_h

#include "../GCryptoConfig.h"

#define AES_BLOCKBIT 128
#define AES_KEYBIT 256
#define AES_BLOCKBYTE (AES_BLOCKBIT / BIT2BYTE)
#define AES_KEYBYTE (AES_KEYBIT / BIT2BYTE)

crypto_cstring aesEncrypt(const char *data, const unsigned long dataLength, const char* password, unsigned long passwordLength);
crypto_cstring aesDecrypt(const char *data, const unsigned long dataLength, const char* password, unsigned long passwordLength);

#endif
