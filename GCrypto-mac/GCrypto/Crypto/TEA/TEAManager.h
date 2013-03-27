//
//  TEAManager.h
//  GCrypto
//
//  Created by Ghost on 12-8-20.
//
//

#ifndef GCrypto_TEAManager_h
#define GCrypto_TEAManager_h

#include "../GCryptoConfig.h"

#define XXTEA_BLOCKBIT 128
#define XXTEA_KEYBIT 128
#define XXTEA_BLOCKBYTE (XXTEA_BLOCKBIT / BIT2BYTE)
#define XXTEA_KEYBYTE (XXTEA_KEYBIT / BIT2BYTE)
#define XXTEA_TURNS 8

crypto_cstring xxteaEncrypt(const char *data, const unsigned long dataLength, const char* password, unsigned long passwordLength);
crypto_cstring xxteaDecrypt(const char *data, const unsigned long dataLength, const char* password, unsigned long passwordLength);

#endif
