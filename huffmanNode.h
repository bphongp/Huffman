//Bamphiane Annie Phongphouthai
//bp8qg
//November 18, 2017
//huffmanNode.h
#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <iostream>
using namespace std;

class huffmanNode {
public:
  huffmanNode(int freq, char c);
  ~huffmanNode();
  string getPrefix();
  char getLetter();
  unsigned int getFreq() const;
  bool operator<(const huffmanNode &n) const;
  huffmanNode *left, *right;
  int fq;
  string prefix;
  char letter;
};

#endif
