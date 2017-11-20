//Bamphiane Annie Phongphouthai
//bp8qg
//November 18, 2017
//heap.h
// Referenced Code written by Aaron Bloomfield, 2014 binary_heap.h
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <string>
#include "huffmanNode.h"
#include <iostream>
using namespace std;

class heap {
public:
    heap();
    ~heap();

    void insert(huffmanNode* nodeH);
    huffmanNode* findMin();
    void deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    vector<huffmanNode*> getVector();
    unsigned int heap_size;
    vector<huffmanNode*> heap_list;
    void percolateUp(int hole, huffmanNode* hnode);
    void percolateDown(int hole);
};

#endif
