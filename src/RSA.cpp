//
// Created by OneCarrot on 2019-04-18.
//

#include "RSA.h"


BigInteger RSA::repeatMod(BigInteger base, BigInteger n, BigInteger mod) { //6^5mod11

    BigInteger ZERO("0");
    BigInteger TWO("2");
    BigInteger ONE("1");
    BigInteger b("1");

    while (n >= ONE) {
        if(n % TWO > ZERO)
            b = (base * b) % mod;
        base = (base * base) % mod;
        n = n / TWO;
    }

    return b;

}

bool RSA::isProbablePrime(BigInteger n, int trial) {

    static BigInteger ONE("1");
    static BigInteger TWO("2");
    static BigInteger ZERO("0");
    BigInteger s("0");
    BigInteger d = n - ONE;

    if(n< BigInteger(2))
        return false;

    if(n== BigInteger(2))
        return true;

    BigInteger judge = n%TWO;

    if(judge == ZERO)
        return false;

    //BigInteger s("0");
    //BigInteger d = n - ONE;
    while(true) {
        BigInteger quotient;
        BigInteger remainder;
        quotient = d/TWO;
        remainder = d%TWO;
        if(remainder == ONE)
            break;
        s = s+ONE;
        d = quotient;
    }

    auto try_composite = [&d, &n, &s](BigInteger a) -> bool {

        BigInteger midRes = repeatMod(a, d, n);
        if(midRes == ONE)
            return false;
        for(BigInteger i("0"); i < s; i = i+ONE) {
            BigInteger twosi = TWO.pow(i);
            BigInteger temp = twosi * d;
            BigInteger comp = repeatMod(a, temp, n);
            if(comp == (n - ONE))
                return false;

        }

        return true;

    };

    for(int i = 0; i < trial; i++) {
        BigInteger a = BigInteger::generateRangeRand(n);
        if(try_composite(a))
            return false;
    }

    return true;
}