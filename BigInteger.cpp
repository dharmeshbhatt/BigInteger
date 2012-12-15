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
  
  // numbers of opposite parity being added
  // effectively subtraction 
  if(sign != other.sign) {
    return subtract(other);
  }

  vector<int>::iterator it1 = nodes.begin();
  vector<int>::iterator it2 = other.nodes.begin();
  vector<int> temp;
  int temp_sum = 0;
  int carry = 0;

  while(true) {
    temp_sum = *it1 + *it2 + carry;
    if(temp_sum > 9) { 
      carry = 1;
      temp_sum = temp_sum % 10;
    }
    else 
      carry = 0;
  
    temp.push_back(temp_sum);
  }

  // the parity of the number will not have changed
  // no alteration to the sign

  nodes = temp;
  return;
}




