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



public:

    static BigInteger repeatMod(BigInteger base, BigInteger n, BigInteger mod);
    static bool isProbablePrime(BigInteger n, int trial);







};
