//
//  TEAManager.c
//  GCrypto
//
//  Created by Ghost on 12-8-20.
//
//

#include "TEAManager.h"
#include "xxtea.h"

crypto_cstring xxteaEncrypt(const char *data, const unsigned long dataLength, const char* password, unsigned long passwordLength)
{
    assert(passwordLength == XXTEA_KEYBYTE);
    
    int n = 0;
    
    if (dataLength / XXTEA_BLOCKBYTE == dataLength * 1.0 / XXTEA_BLOCKBYTE) n = dataLength / XXTEA_BLOCKBYTE;
    else n = dataLength / XXTEA_BLOCKBYTE + 1;
    
    ++n;
    
    crypto_cstring answer;
    
    answer.length = n * XXTEA_BLOCKBYTE;
    
    answer.context = malloc(sizeof(char) * (answer.length));
    
    memcpy(answer.context, data, sizeof(char) * dataLength);
    
    unsigned long longi;

    for (longi = dataLength ; longi < answer.length ; ++longi) answer.context[longi] = '\0';
    
    ((uint64_t*) answer.context)[LENGTHPOSITION(answer.length)] = (uint64_t) dataLength;
    
    int i;

    for (i = 0 ; i < XXTEA_TURNS; ++i)
    {
        btea((uint32_t*)answer.context, n, (uint32_t*)password);
    }
    return answer;
}

crypto_cstring xxteaDecrypt(const char *data, const unsigned long dataLength, const char* password, unsigned long passwordLength)
{
    assert(passwordLength == XXTEA_KEYBYTE);
    
    int n = 0;
    
    if (dataLength / XXTEA_BLOCKBYTE == dataLength * 1.0 / XXTEA_BLOCKBYTE) n = dataLength / XXTEA_BLOCKBYTE;
    else n = (int) (dataLength / XXTEA_BLOCKBYTE + 1);
    
    crypto_cstring answer;
    
    answer.length = n * XXTEA_BLOCKBYTE;
    
    answer.context = malloc(sizeof(char) * (answer.length));
    
    memcpy(answer.context, data, sizeof(char) * dataLength);
    
    unsigned long longi;

    for (longi = dataLength ; longi < (answer.length) ; ++longi) answer.context[longi] = '\0';
    
    int i;

    for (i = 0 ; i < XXTEA_TURNS; ++i)
    {
        btea((uint32_t*)answer.context, -n, (uint32_t*)password);
    }
    
    answer.length = (uint64_t) ((uint64_t*) answer.context)[LENGTHPOSITION(answer.length)];
    
    for (longi = dataLength - 1 ; longi >= (answer.length) ; --longi) answer.context[longi] = '\0';
    
    return answer;
}
