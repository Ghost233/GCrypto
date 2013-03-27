/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.ghost.GCrypto;

import android.R.integer;
import android.app.Activity;
import android.widget.TextView;
import android.os.Bundle;


public class HelloJni extends Activity
{
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        /* Create a TextView and set its content.
         * the text is retrieved by calling a native
         * function.
         */
        
//        给我看清楚了!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//        AES加密必须用32位字符串!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//        TEA必须用16位字符串!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        
        String tmpString = "abc123def456ghi789F@ck...aaaaaaa1111111";
        String password16String = "1234567890123456";
        String password32String = "12345678901234567890123456789012";
        
        TextView  tv = new TextView(this);
        
        byte[] encryptByte = GCrypto.EncryptWithTEA(tmpString.getBytes(), password16String.getBytes());

        byte[] decryptByte = GCrypto.DecryptWithTEA(encryptByte, password16String.getBytes());
        
        String textString = new String(decryptByte);
        
        tv.setText(textString);
        setContentView(tv);
    }

    /* A native method that is implemented by the
     * 'hello-jni' native library, which is packaged
     * with this application.
     */
//    public native String stringEncryptWithAES(String data, String password);
//    public native String stringDecryptWithAES(String data, String password);
//    public native byte[] stringEncryptWithTEA(byte[] data, byte[] password);
//    public native byte[] stringDecryptWithTEA(byte[] data, byte[] password);

    /* This is another native method declaration that is *not*
     * implemented by 'hello-jni'. This is simply to show that
     * you can declare as many native methods in your Java code
     * as you want, their implementation is searched in 
     * currently loaded native libraries only the first time
     * you call them.
     *
     * Trying to call this function will result in a
     * java.lang.UnsatisfiedLinkError exception !
     */
//    public native String  unimplementedStringFromJNI();
}
