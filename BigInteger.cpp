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
  int a = 0, b = 0;
  int temp_sum = 0;
  int carry = 0;

  while(true) {
   
    if(it1 == nodes.end() && it2 == other.nodes.end()) 
      break;

    if(it1 == nodes.end()) 
      a = 0;
    else
      a - *it1;

    if(it2 == other.nodes.end()) 
      b = 0;
    else
      b = *it2;
      
    temp_sum = a + b + carry;
    if(temp_sum > 9) { 
      carry = 1;
      temp_sum = temp_sum % 10;
    }
    else 
      carry = 0;
  
    temp.push_back(temp_sum);
    it1++;
    it2++;
  }

  // the parity of the number will not have changed
  // no alteration to the sign

  nodes = temp;
  return;
}

static int max(BigInteger a, BigInteger b) {
  if(a.sign != b.sign) {
    return (a.sign == true) ? 0 : 1;
  }
  
  if(b.nodes.size() > a.nodes.size()) 
    return 1;
  else
    return 0;

  vector<int>::iterator it1 = a.nodes.begin();
  vector<int>::iterator it2 = b.nodes.begin();

  // the lengths of the two vectors are known
  // to be equal
  while(it1 != a.nodes.end()) {
    if(*it1 > *it2) 
      return 0;
    else if(*it2 > *it1) 
      return 1;

    it1++;
  }

  // a = b
  return 0;
}

void BigInteger::subtract(BigInteger other) {
   
}



