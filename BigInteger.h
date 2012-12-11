#ifndef BIGINTEGER__H__
#define BIGINTEGER__H__

#include <vector>
#include <string>

class BigInteger {
  public:   
    // constructor that takes string as input
    // converts to BigInteger
    BigInteger(string input);
    void add(BigInteger other);
    bool sign;
  private:
    vector<int> nodes;
};

#endif


