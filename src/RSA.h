//
// Created by OneCarrot on 2019-04-18.
//

#include "BigInteger.h"

class RSA {

private:

    BigInteger p;
    BigInteger q;
    BigInteger n;
    BigInteger e;
    BigInteger d;

    string plainFilePath;
    string cipherFilePath;


public:

    static BigInteger repeatMod(BigInteger base, BigInteger n, BigInteger mod);
    static bool isProbablePrime(BigInteger n, int trial);
    static BigInteger generatePrime(BigInteger min);
    static BigInteger gcd(BigInteger a, BigInteger b);
    static BigInteger getInverseElement(BigInteger a, BigInteger mod);
    void generatePandQ();
    void initParameter();
    void generateKey(string filepath, BigInteger para);
    void outputInfo(string filepath);
    void encrypt(BigInteger plaintext);
    void decrypt(BigInteger ciphertext);

    void test();







};
