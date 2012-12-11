#include "BigInteger.h"

BigInteger::BigInteger(string input) {
  
  if(input[0].compare("-") == 0) 
    sign = false;
  else
    sign = true;
  
  for(int i=0;i<input.length();i++) {
    nodes.push_back(atoi(input[i]));
  }
}

void BigInteger::add(BigInteger other) {
  int carry = 0;
  vector<int> temp;
  
  int multiplier;
  if(sign == other.sign) {
    )
  }
}
