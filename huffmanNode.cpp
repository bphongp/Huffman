//Bamphiane Annie Phongphouthai
//bp8qg
//November 18, 2017
//huffmanNode.cpp

#include <iostream>
#include "huffmanNode.h"
using namespace std;

//default constructor
huffmanNode::huffmanNode(int freq, char c){
  left = NULL;
  right = NULL;
  letter = c;
  fq = freq;
  prefix="";
}

//destructor
huffmanNode:: ~huffmanNode(){
  delete left;
  delete right;
}

//frequency
unsigned int huffmanNode::getFreq() const{
  return fq;
}

string huffmanNode::getPrefix(){
  return prefix;
}

char huffmanNode::getLetter(){
  return letter;
}
//override < operator
bool huffmanNode::operator<(const huffmanNode &n) const{
  return(this->getFreq() < n.getFreq());
}
