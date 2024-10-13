//
// Created by Yurij on 13.10.2024.
//

#include "RC4.h"
#include "RC4.h"
void swap(unsigned char & a, unsigned char & b) {
    unsigned char t = a;
    a = b;
    b = t;
}
void RC4::initMatrix(const char *key, size_t keyLength) {
    for (int i = 0; i < KEY_LENGTH; ++i) {
        S[i] = i;
        K[i] = key[i % keyLength];
    }
}
void RC4::KSA()  {
    unsigned char j = 0;
    for (int i = 0; i < KEY_LENGTH; ++i) {
        j = (j + S[i] + K[i]) % KEY_LENGTH;
        swap(S[i], S[j]);
    }
}
void RC4::PRGA(char *output, size_t messageLength) {
    unsigned int i = 0, j = 0;
    for (size_t l = 0; l < messageLength; ++l) {
        i = (i + 1) % KEY_LENGTH;
        j = (j + S[i]) % KEY_LENGTH;
        swap(S[i], S[j]);
        unsigned char k = S[(S[i] + S[j]) % KEY_LENGTH];
        output[l] ^= k;
    }
}
