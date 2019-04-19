#include <iostream>
#include <cmath>
#include "RSA.h"

using namespace std;

int main() {


    /*BigInteger test1("2");
    cout<<test1.toString()<<endl;

    BigInteger test2("3C73");
    cout<<test2.toString()<<endl;*/


    BigInteger test1("2");
    BigInteger test2("F4240");
    BigInteger test3("4D");

    BigInteger res;
    BigInteger res2;

    res = RSA::repeatMod(test1,test2,test3);
    cout<<res.toString()<<endl;


    BigInteger test4("7C3");

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

    cout<<RSA::isProbablePrime(test4,1)<<endl;


    return 0;
}