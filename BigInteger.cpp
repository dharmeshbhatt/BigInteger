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

BigInteger::BigInteger(BigInteger other) {
  sign = other.sign;
  vector<int>::iterator it = other.nodes.begin();

  for(;it != other.nodes.end();it++) {
    nodes.push_back(*it);
  }
}

BigInteger BigInteger::add(BigInteger other) {
  // opposite parity numbers
  // effectively subtraction
  if(sign == true && other.sign == false) {
    BigInteger temp1 = new BigInteger(other);
    temp1.sign = true;
    return subtract(temp1);
  }
  else if(sign == false && other.sign == true) {
    BigInteger temp1 = new BigInteger(this);
    temp1.sign = true;
    return other.subtract(temp1);
  }

  // both numbers have same parity 
  BigInteger ret = new BigInteger();
  ret.sign = sign;

  vector<int>::iterator i1 = nodes.end();
  vector<int>::iterator i2 = other.nodes.end();
  int a = 0, b = 0;
  int temp_sum = 0;
  int carry = 0;
  
  while(true) {
    if(i1 == nodes.begin() && i2 == other.nodes.begin())
      break;

    if(i1 == nodes.begin())
      a = 0;
    else
      a = *i1;

    if(i2 == other.nodes.begin())
      b = 0;
    else
      b = *i2;

    temp_sum = a + b + carry;
    if(temp_sum > 9) {
      carry = 1;
      temp_sum = temp_sum % 10;
    }
    else 
      carry = 0;
    
    ret.nodes.push_back(temp_sum);

    i1--;
    i2--;
  }

  return ret;
}   

static int max(BigInteger a, BigInteger b) {
  if(a.sign != b.sign) {
    return (a.sign == true) ? 0 : 1;
  }
  
  if(b.nodes.size() > a.nodes.size()) { 
    // both numbers are negative
    if(a.sign == false)
      return 0;
    else 
      return 1;
  }
  else if(a.nodes.size() > b.nodes.size()) {
    if(a.sign == false) 
      return 1;
    else
      return 0;
  }

  vector<int>::iterator it1 = a.nodes.begin();
  vector<int>::iterator it2 = b.nodes.begin();

  // the lengths of the two vectors are known
  // to be equal
  while(it1 != a.nodes.end()) {
    if(*it1 > *it2) {
      // a is more negative
      if(a.sign == false)
        return 1;
      else
        return 0;
    }
    else if(*it2 > *it1) {
      // b is more negative
      if(a.sign ==  false)
        return 0;
      else
        return 1;
    }

    it1++;
    it2++;
  }

  // a = b
  return 0;
}



