//Bamphiane Annie Phongphouthai
//bp8qg
//November 17, 2017
//heap.cpp

// Referenced Code written by Aaron Bloomfield, 2014 binary_heap.cpp
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "heap.h"
#include "huffmanNode.h"

using namespace std;

// default constructor
heap::heap() : heap_size(0), heap_list(101) {
}
vector<huffmanNode*> heap::getVector(){
  return heap_list;
}

// the destructor doesn't need to do much
heap::~heap() {
  //heap_size=0;
  //heap_list.clear();
  makeEmpty();
}

void heap::insert(huffmanNode* nodeH) {
    // a vector push_back will resize as necessary
  while(heap_size == heap_list.size()-1){
    heap_list.resize(heap_list.size()*2);
  }
    // move it up into the right position
    percolateUp(++heap_size, nodeH);
}

void heap::percolateUp(int hole, huffmanNode* hnode) {
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (*hnode < *heap_list[hole/2]); hole /= 2 )
        heap_list[hole] = heap_list[hole/2]; // move the parent down
    // correct position found!  insert at that spot
    heap_list[hole] = hnode;
}

void heap::deleteMin() {
    // make sure the heap is not empty
    if ( heap_size == 0 )
        throw "deleteMin() called on empty heap";
    // move the last inserted position into the root
    heap_list[1] = heap_list[heap_size--];
    // make sure the vector knows that there is one less element
    //heap.pop_back();
    // percolate the root down to the proper position
    percolateDown(1);
    // return the old root node
    //return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    huffmanNode* temp = heap_list[hole];
    // while there is a left child...
    while ( hole*2 <= heap_size ) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ( (child != heap_size) && (*(heap_list[child+1])) < (*(heap_list[child]) ))
            child++;
        // if the child is greater than the node...
        if ( (*heap_list[child]) < (*temp) ) {
            heap_list[hole] = heap_list[child]; // move child up
            hole = child;             // move hole down
        }
	else
            break;
	//hole=child;
    }
    // correct position found!  insert at that spot
    heap_list[hole] = temp;
}

huffmanNode* heap::findMin() {
  if (isEmpty() )
        throw "findMin() called on empty heap";
  else{
    return heap_list[1];
  }
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
  if(!isEmpty()){
    heap_size = 0;
    heap_list.clear();
  }
  else
    throw "Error. Heap empty, nothing to make empty";
}

bool heap::isEmpty() {
  if (heap_size ==0)
    return true;
  else
    return false;
  //return heap_size == 0;
}
