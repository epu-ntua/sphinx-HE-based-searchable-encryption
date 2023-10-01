
#ifndef KEY_DEF
#define KEY_DEF
#include<stdio.h>
#include<iostream>
#include"openssl/sha.h"
#include"openssl/hmac.h"
#include "openssl/bn.h"
#include<string.h>
#include <sstream>
#include<fstream>

using namespace std;
class ECCKey{
    public:
    SHA512_CTX ctx;
    BN_CTX* bnctx;
    BIGNUM*    p;
    BIGNUM*    a;   
    string     k1;
    string     k2;
    string     AES_k;
    string     AES_iv;
};
#endif
