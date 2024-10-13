//
// Created by Yurij on 13.10.2024.
//

#ifndef RC4_H
#define RC4_H
#include <iostream>
#include <cstring>

#define KEY_LENGTH 256

class RC4 {
    unsigned char S[KEY_LENGTH];
    unsigned char K[KEY_LENGTH];
    void initMatrix(const char* key, size_t keyLength);
    void KSA();
    void PRGA(char* output, size_t messageLength);
public:
    void encryptDecrypt(char* input, size_t messageLength, const char* key) {
        initMatrix(key,strlen(key));
        KSA();
        PRGA(input, messageLength);
    }
};
#endif //RC4_H
