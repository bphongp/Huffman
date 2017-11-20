//Bamphiane Annie Phongphouthai
//bp8qg
//November 18, 2017
//huffmanTree.cpp
#include <iostream>
#include "huffmanTree.h"
#include "huffmanNode.h"
#include "heap.h"
#include <string>

using namespace std;

//constructor
huffmanTree:: huffmanTree(){
  root=NULL;
}
//destructor
huffmanTree::~huffmanTree(){
  delete root;
}

//prints huffman nodes prefix
void huffmanTree::printPrefix(huffmanNode *root, string prefix){
  if (root->left==NULL && root->right==NULL){ //if leaf node
    if(root->letter == ' '){
      cout<<"space"<<" "<<prefix<<endl;
    }
    else{
      cout<< root->letter<<" "<<prefix<<endl;
    }
  }
  else{
    if(root->left){
      printPrefix(root->left, prefix+ "0");
    }
    if(root->right){
      printPrefix(root->right,prefix+"1");
    }
  }
}

//sets the prefix
void huffmanTree::setPrefix(huffmanNode *root, string temp){
  if (root->left==NULL && root->right==NULL){ //if leaf node
    root->prefix=temp;
  }
  else{
    if(root->left){
      setPrefix(root->left, temp+ "0");
    }
    if(root->right){
      setPrefix(root->right, temp+"1");
    }
  }
}
heap huffmanTree::createhuffmanTree(heap htree){
  while(htree.size()>=2){
    huffmanNode* pop1 = htree.findMin();//store first pop as node
    htree.deleteMin();//delete it from heap
    huffmanNode* pop2 = htree.findMin();//store next pop as node
    htree.deleteMin();//delete it from heap
    //need to combine the two
    int combineFreq =0;//combining frequencies
    combineFreq = (pop1->getFreq())+ (pop2->getFreq());
    huffmanNode* combineNode = new huffmanNode( combineFreq, '/');
    //filler character is /
    combineNode->left = pop1;
    combineNode->right = pop2;
    htree.insert(combineNode);//inseart new combined node into heap
  }
  return htree;
}
