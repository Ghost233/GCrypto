#include <string.h>
#include <jni.h>
#include <Crypto/AES/AESManager.h>
#include <Crypto/TEA/TEAManager.h>

JNIEXPORT jbyteArray Java_com_ghost_GCrypto_GCrypto_JNIEncryptWithTEA(JNIEnv* env, jobject obj, jbyteArray dataString, jbyteArray passwordString)
{
	crypto_cstring data;
	data.length  = (*env)->GetArrayLength(env, dataString);
	data.context = (jbyte *)malloc(data.length * sizeof(jbyte));
	(*env)->GetByteArrayRegion(env, dataString,0,data.length,data.context);

	crypto_cstring password;
	password.length  = (*env)->GetArrayLength(env, passwordString);
	password.context = (jbyte *)malloc(password.length * sizeof(jbyte));
	(*env)->GetByteArrayRegion(env, passwordString,0,password.length,password.context);

	crypto_cstring tmp = xxteaEncrypt(data.context, data.length, password.context, password.length);

	jbyte *by = (jbyte*) tmp.context;
	jbyteArray jarray = (*env)->NewByteArray(env, tmp.length);
	(*env)->SetByteArrayRegion(env, jarray, 0, tmp.length, by);

	free(data.context);
	free(password.context);

	return jarray;
}

JNIEXPORT jbyteArray Java_com_ghost_GCrypto_GCrypto_JNIDecryptWithTEA(JNIEnv* env, jobject obj, jbyteArray dataString, jbyteArray passwordString)
{
	crypto_cstring data;
	data.length  = (*env)->GetArrayLength(env, dataString);
	data.context = (jbyte *)malloc(data.length * sizeof(jbyte));
	(*env)->GetByteArrayRegion(env, dataString,0,data.length,data.context);

	crypto_cstring password;
	password.length  = (*env)->GetArrayLength(env, passwordString);
	password.context = (jbyte *)malloc(password.length * sizeof(jbyte));
	(*env)->GetByteArrayRegion(env, passwordString,0,password.length,password.context);

	crypto_cstring tmp = xxteaDecrypt(data.context, data.length, password.context, password.length);

	jbyte *by = (jbyte*) tmp.context;
	jbyteArray jarray = (*env)->NewByteArray(env, tmp.length);
	(*env)->SetByteArrayRegion(env, jarray, 0, tmp.length, by);

	free(data.context);
	free(password.context);

	return jarray;
}

JNIEXPORT jbyteArray Java_com_ghost_GCrypto_GCrypto_JNIEncryptWithAES(JNIEnv* env, jobject obj, jbyteArray dataString, jbyteArray passwordString)
{
	crypto_cstring data;
	data.length  = (*env)->GetArrayLength(env, dataString);
	data.context = (jbyte *)malloc(data.length * sizeof(jbyte));
	(*env)->GetByteArrayRegion(env, dataString,0,data.length,data.context);

	crypto_cstring password;
	password.length  = (*env)->GetArrayLength(env, passwordString);
	password.context = (jbyte *)malloc(password.length * sizeof(jbyte));
	(*env)->GetByteArrayRegion(env, passwordString,0,password.length,password.context);

	crypto_cstring tmp = aesEncrypt(data.context, data.length, password.context, password.length);

	jbyte *by = (jbyte*) tmp.context;
	jbyteArray jarray = (*env)->NewByteArray(env, tmp.length);
	(*env)->SetByteArrayRegion(env, jarray, 0, tmp.length, by);

	free(data.context);
	free(password.context);

	return jarray;
}

JNIEXPORT jbyteArray Java_com_ghost_GCrypto_GCrypto_JNIDecryptWithAES(JNIEnv* env, jobject obj, jbyteArray dataString, jbyteArray passwordString)
{
	crypto_cstring data;
	data.length  = (*env)->GetArrayLength(env, dataString);
	data.context = (jbyte *)malloc(data.length * sizeof(jbyte));
	(*env)->GetByteArrayRegion(env, dataString,0,data.length,data.context);

	crypto_cstring password;
	password.length  = (*env)->GetArrayLength(env, passwordString);
	password.context = (jbyte *)malloc(password.length * sizeof(jbyte));
	(*env)->GetByteArrayRegion(env, passwordString,0,password.length,password.context);

	crypto_cstring tmp = aesDecrypt(data.context, data.length, password.context, password.length);

	jbyte *by = (jbyte*) tmp.context;
	jbyteArray jarray = (*env)->NewByteArray(env, tmp.length);
	(*env)->SetByteArrayRegion(env, jarray, 0, tmp.length, by);

	free(data.context);
	free(password.context);

	return jarray;
}

