//
//  AESManager.c
//  GCrypto
//
//  Created by Ghost on 12-8-22.
//
//

#include "AESManager.h"
#include "rijndael.h"

crypto_cstring aesEncrypt(const char *data, const unsigned long dataLength, const char* password, unsigned long passwordLength)
{
    assert(passwordLength == AES_KEYBYTE);
    
    int n = 0;
    
    if (dataLength / AES_BLOCKBYTE == dataLength * 1.0 / AES_BLOCKBYTE) n = dataLength / AES_BLOCKBYTE;
    else n = dataLength / AES_BLOCKBYTE + 1;
    
    ++n;
    
    crypto_cstring answer;
    
    answer.length = n * AES_BLOCKBYTE;
    
    answer.context = malloc(sizeof(char) * (answer.length) + 100);
    
    memcpy(answer.context, data, sizeof(char) * dataLength);

    unsigned long longi;
    
    for (longi = dataLength ; longi < (answer.length) ; ++longi) answer.context[longi] = '\0';
    
    ((uint64_t*) answer.context)[LENGTHPOSITION(answer.length)] = (uint64_t) dataLength;
    
    int i;

    unsigned long rk[RKLENGTH(AES_KEYBIT)];
	unsigned char key[KEYLENGTH(AES_KEYBIT)];
    
	for (i = 0; i < passwordLength; i++)
		key[i] = password != 0 ? *password++ : 0;
	
	int nrounds = rijndaelSetupEncrypt(rk, key, AES_KEYBIT);
	
    int index = 0;
    int lastIndex;

	
	while (1)
	{
        lastIndex = index;
		unsigned char plaintext[32];
		unsigned char ciphertext[32];
		int j;
		for (j = 0; j < 16; j++)
		{
			if (index >= answer.length)
				break;
			
			plaintext[j] = answer.context[index++];
		}
		if (j == 0)
			break;
		for (; j < sizeof(plaintext); j++)
			plaintext[j] = '\0';
		
		rijndaelEncrypt(rk, nrounds, plaintext, ciphertext);
        memcpy(answer.context + lastIndex, ciphertext, AES_BLOCKBYTE);
	}
    
    return answer;
}

crypto_cstring aesDecrypt(const char *data, const unsigned long dataLength, const char* password, unsigned long passwordLength)
{
    assert(passwordLength == AES_KEYBYTE);
    
    int n = 0;
    
    if (dataLength / AES_BLOCKBYTE == dataLength * 1.0 / AES_BLOCKBYTE) n = dataLength / AES_BLOCKBYTE;
    else n = dataLength / AES_BLOCKBYTE + 1;
    
    crypto_cstring answer;
    
    answer.length = n * AES_BLOCKBYTE;
    
    answer.context = malloc(sizeof(char) * (answer.length) + 100);
    
    memcpy(answer.context, data, sizeof(char) * dataLength);
    
    unsigned long longi;

    for (longi = dataLength ; longi < (answer.length) ; ++longi) answer.context[longi] = '\0';
    
    unsigned long rk[RKLENGTH(AES_KEYBIT)];
	unsigned char key[KEYLENGTH(AES_KEYBIT)];
    
    int i = 0;
	for (i = 0; i < sizeof(key); i++) key[i] = password != 0 ? *password++ : 0;
	
	int nrounds = rijndaelSetupDecrypt(rk, key, AES_KEYBIT);
	
    int index = 0;
    int lastIndex;
	
	while (1)
	{
        lastIndex = index;
		unsigned char plaintext[32];
		unsigned char ciphertext[32];
		int j;
		for (j = 0; j < 16; j++)
		{
			if (index >= answer.length)
				break;
			
			plaintext[j] = answer.context[index++];
		}
		if (j == 0)
			break;
		for (; j < sizeof(plaintext); j++)
			plaintext[j] = '\0';
        
		rijndaelDecrypt(rk, nrounds, plaintext, ciphertext);
        memcpy(answer.context + lastIndex, ciphertext, AES_BLOCKBYTE);
        
	}
    
    answer.length = ((uint64_t*) answer.context)[LENGTHPOSITION(answer.length)];
    
    for (longi = dataLength - 1 ; i >= (answer.length) ; --i) answer.context[i] = '\0';
    
    return answer;
}
