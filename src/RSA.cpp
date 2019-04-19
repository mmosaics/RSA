//
// Created by OneCarrot on 2019-04-18.
//

#include "RSA.h"
#include "vector"
#include "fstream"



BigInteger RSA::repeatMod(BigInteger base, BigInteger n, BigInteger mod) { //6^5mod11

    BigInteger ZERO("0");
    BigInteger TWO("2");
    BigInteger ONE("1");
    BigInteger b("1");

    base = base % mod;

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
        BigInteger a = BigInteger::generateRangeRand(BigInteger("100"));
        if(try_composite(a))
            return false;
    }

    return true;
}

BigInteger RSA::generatePrime(BigInteger min) {

    BigInteger ONE("1");
    BigInteger TWO("2");
    BigInteger probablePrime("2540BE400");
    srand(time(NULL));
    BigInteger randNum(rand() % 10);
    BigInteger randOne(rand());
    BigInteger randTwo(rand());
    probablePrime = (randOne + randTwo) * randNum + min;
    if(probablePrime.getFirst() % 2 == 0)
        probablePrime = probablePrime + ONE;


    while (isProbablePrime(probablePrime, 3) != 1) {
        probablePrime = probablePrime + TWO;
    }

    return probablePrime;

}

BigInteger RSA::gcd(BigInteger a, BigInteger b) {

    BigInteger ONE("0");
    BigInteger t;
    t = a%b;
    while(t != ONE) {
         a = b;
         b = t;
         t = a%b;
    }

    return b;

}


BigInteger RSA::getInverseElement(BigInteger a, BigInteger mod) {

    BigInteger result("1");
    BigInteger ZERO("0");
    BigInteger ONE("1");
    BigInteger buf1("0");
    BigInteger buf2("0");
    vector<BigInteger> temp;
    while(mod%a != ZERO) {
        BigInteger divideResult = mod / a;
        BigInteger remainder = mod % a;
        temp.push_back(divideResult);
        mod = a;
        a = remainder;
    }
        temp.push_back(ONE);

    for(int i = temp.size()-1; i >= 1; i-- ) {

        buf2 = result;
        result = result * temp[i-1] + buf1;
        buf1 = buf2;


    }

    return result;

}

void RSA::generatePandQ() {

    p = generatePrime(BigInteger("5012BE400"));
    q = generatePrime(BigInteger("2640BE400"));

}

void RSA::initParameter() {

    generatePandQ();
    BigInteger Euler;
    BigInteger ONE("1");
    BigInteger buf1,buf2;
    buf1 = p - ONE;
    buf2 = q - ONE;
    Euler = buf1 * buf2;


    BigInteger e = BigInteger::generateRangeRand(Euler);
    while(gcd(e, Euler) != 1)
        e = BigInteger::generateRangeRand(Euler);

    BigInteger d = RSA::getInverseElement(e, Euler);

    this->d = d;
    this->e = e;
    this->n = p*q;

    p.setName("p");
    q.setName("q");
    n.setName("n");
    this->e.setName("e");
    this->d.setName("d");

}


void RSA::generateKeyFile(string filepath, BigInteger para) {

    ofstream outFile;
    outFile.open(filepath + para.getName() + ".txt");
    outFile<<para.toString();
    outFile.close();

}

void RSA::generateKey(string filepath) {

    initParameter();

    generateKeyFile(filepath,p);
    generateKeyFile(filepath,q);
    generateKeyFile(filepath,n);
    generateKeyFile(filepath,e);
    generateKeyFile(filepath,d);


}

void RSA::setPublicKey(string n, string e) {
    this->n = BigInteger(n);
    this->e = BigInteger(e);
}

void RSA::setPrivateKey(string n, string d) {
    this->d = BigInteger(d);
    this->n = BigInteger(n);
}

string RSA::encrypt(string plaintext) {
    BigInteger cipher;
    BigInteger plain(plaintext);
    cipher = repeatMod(plain,e, n);
    return cipher.toString();
}

string RSA::decrypt(string ciphertext) {
    BigInteger plain;
    BigInteger cipher(ciphertext);
    plain = repeatMod(cipher, d, n);
    return plain.toString();
}

string RSA::getN() {
    return n.toString();
}

string RSA::getE() {
    return e.toString();
}

string RSA::getD() {
    return d.toString();
}