//Bamphiane Annie Phongphouthai
//bp8qg
//November 18, 2017
//huffmanTree.h
#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include "huffmanNode.h"
#include "heap.h"

using namespace std;

class huffmanTree {
public:
  huffmanTree();
  ~huffmanTree();
  heap createhuffmanTree(heap htree);
  huffmanNode* root;
  //huffmanNode* combine(huffmanNode* n1, huffmanNode* n2);
  void printPrefix(huffmanNode* root, string prefix);
  void setPrefix(huffmanNode* root, string prefix);
  
};

#endif
