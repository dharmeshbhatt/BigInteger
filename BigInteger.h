#ifndef BIGINTEGER__H__
#define BIGINTEGER__H__

#include <vector>
#include <string>

class BigInteger {
  public:   
    // constructor that takes string as input
    // converts to BigInteger
    BigInteger(string input);
    BigInteger add(BigInteger other);
    BigInteger subtract(BigInteger other);
    // return 0 if first param is greater
    // 1 otherwise
    static int max(BigInteger, BigInteger);
    // false means negative;
    bool sign;
    vector <int> nodes;
};

#endif


