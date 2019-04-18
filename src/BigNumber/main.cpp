#include <iostream>
#include <cmath>
#include "BigInteger.h"

using namespace std;

int main() {

    BigInteger test1("100");
    BigInteger test2("25");
    BigInteger res1 = test1.pow(2);
    BigInteger res2 = test1 * test2;
    BigInteger res3 = test1/test2;
    BigInteger res4 = test1%test2;
    cout<<res1.toString()<<endl;
    cout<<res2.toString()<<endl;
    cout<<res3.toString()<<endl;
    cout<<res4.toString()<<endl;
    return 0;
}