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
  
  int multiplier;
  if(sign == other.sign) {
   multiplier = 1;
  }
  else {
    multiplier = -1;
  }

  // v1 will hold the larger number by abs value
  // v2 will hold the smaller number by abs value
  vector<int> v1;
  vector<int> v2;
  if(nodes.size() > other.nodes.size()) {
    v1 = nodes; 
    v2 = other.nodes;
  }
  else if(nodes.size() == other.nodes.size()){
    if(nodes[0] > other.nodes[0]) {
      v1 = nodes;
      v2 = other.nodes;
    }
    else {
      v1 = other.nodes;
      v2 = nodes;
    }
  }
  else {
    v1 = other.nodes;
    v2 = nodes;
  }

  vector::iterator it1;
  vector::iterator it2;
  vector<int> temp;
  int carry = 0;
  int temp_sum = 0;
  int a = 0, b = 0;
  while(true) {
    if(it1 == v1.end() && it2 == v2.end())
      break;
 
    if(it1 != v1.end()) 
      a = *it1;
    else
      a = 0;

    if(it2 != v2.end())
      b = *it2;
    else
      b = 0;
    
    temp_sum = a + b + carry;
    if(temp_sum > 9)
      carry = 1;

    temp.push_back(temp_sum%10);
 }   


  nodes = temp;
  sign = (sign == other.sign);
  return;
}


