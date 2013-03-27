package com.ghost.GCrypto;

public class GCrypto
{
    private static GCrypto _sharedGCrypto = null;
    
    private static GCrypto shareGCrypto()
    {
        if (_sharedGCrypto == null)
        {
            _sharedGCrypto = new GCrypto();
        }
        return _sharedGCrypto;
    }
    
    public static byte[] EncryptWithTEA(byte[] data, byte[] password)
    {
        byte[] answer = shareGCrypto().JNIEncryptWithTEA(data, password);
        
        return answer;   
    }
    
    public static byte[] DecryptWithTEA(byte[] data, byte[] password)
    {
        byte[] answer = shareGCrypto().JNIDecryptWithTEA(data, password);
        
        return answer;   
    }
    
    public static byte[] EncryptWithAES(byte[] data, byte[] password)
    {
        byte[] answer = shareGCrypto().JNIEncryptWithAES(data, password);
        
        return answer;   
    }
    
    public static byte[] DecryptWithAES(byte[] data, byte[] password)
    {
        byte[] answer = shareGCrypto().JNIDecryptWithAES(data, password);
        
        return answer;   
    }
    
    public native byte[] JNIEncryptWithAES(byte[] data, byte[] password);
    public native byte[] JNIDecryptWithAES(byte[] data, byte[] password);
    public native byte[] JNIEncryptWithTEA(byte[] data, byte[] password);
    public native byte[] JNIDecryptWithTEA(byte[] data, byte[] password);
    
    static {
        System.loadLibrary("GCrypto");
    }
    
}
