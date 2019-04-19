#include <iostream>
#include <cmath>
#include "RSA.h"

using namespace std;

int main() {


    /*BigInteger test1("2");
    cout<<test1.toString()<<endl;

    BigInteger test2("3C73");
    cout<<test2.toString()<<endl;*/


    BigInteger test2("23123");
    BigInteger test1("3479289348ABDE");

    BigInteger res;
    BigInteger res2;
    res = test1%test2;
    res2 = test1/test2;
    cout<<res2.toString()<<endl;
    cout<<res.toString()<<endl;

    //BigInteger test4("3A9");

   /* BigInteger test3("B");

    BigInteger res;
    res = test3/test1;
    cout<<res.toString()<<endl;

    BigInteger mod;
    mod = test2%test1;
    cout<<mod.toString()<<endl;

    BigInteger ONE("1");

    BigInteger randBig = BigInteger::generateBigRand();

    BigInteger randBig2 = BigInteger::generateBigRand();
    cout<<randBig.toString()<<endl;
    cout<<randBig2.toString()<<endl;

*/

    //cout<<RSA::isProbablePrime(test4,1)<<endl;


    return 0;
}