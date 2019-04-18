#include <iostream>
#include <cmath>
#include "BigInteger.h"

using namespace std;

int main() {

    BigInteger test1("123");
    BigInteger test2("45");
    BigInteger res = test1*test2;
    cout<<res.toString();

    return 0;
}