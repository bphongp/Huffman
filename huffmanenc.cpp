
//Bamphiane Annie Phongphouthai
//bp8qg
//November 18, 2017
//huffmanenc.cpp
//reference Aaron Bloomfield fileio.cpp and binary_heap.cpp
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "heap.h"
#include "huffmanTree.h"
#include "huffmanNode.h"
#include <vector>
using namespace std;

// we want to use parameters
int main (int argc, char *argv[]) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file.  FILE is a type desgined to
    // hold file pointers.  The first parameter to fopen() is the
    // filename.  The second parameter is the mode -- "r" means it
    // will read from the file.
    FILE *fp = fopen(argv[1], "r");
    // if the file wasn't found, output and error message and exit
    if ( fp == NULL ) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }
    int distinctChar =0;
    char g;
    int chars=0;
    
    //frequencies=0
    int freq[128];
    for(int i =0; i<128; i++){
      freq[i] =0;
    }
    int asciiValue;
    //increment the number of characters read in while not end of file
    //ascii values between 31 and 128
    while ( (g = fgetc(fp)) != EOF ){
      asciiValue= (int) g;
      if(asciiValue>31 && asciiValue<128){
	freq[asciiValue]++;
	chars++;
      }
    }

    //insert chars into heap huffmanNode(0,'0');
    heap myheap;
    
    for(int i=1; i<128; i++){
      if(freq[i]>0){
	  huffmanNode* temp = new huffmanNode(freq[i], (char) i);
	  myheap.insert(temp);
	  distinctChar++;
      }
    }

    //create tree
    huffmanTree* mytree= new huffmanTree();
    heap treeheap=mytree->createhuffmanTree(myheap);
    mytree->printPrefix(treeheap.findMin(),"");
    mytree->setPrefix(treeheap.findMin(),"");

    cout << "----------------------------------------" << endl;

    //rewind file pointer, read file at beginning
    rewind(fp);

    //calculate compress value
    vector<huffmanNode*> huffVec=myheap.getVector();

    int compressed=0;
    int uncompressed=0;

    // use the vector created from myheeap. the nodes and prefix are sorted and assigned
    while((g = fgetc(fp)) != EOF){
      for(int i=1; i<=myheap.size(); i++){
	if (g==huffVec[i]->getLetter()){
	  cout<<huffVec[i]->getPrefix()<<" ";
	  compressed+= huffVec[i]->getPrefix().size();
	}
      }
    }
    cout<<endl;
    cout<<"----------------------------------------" << endl;

    uncompressed = chars*8;
    double ratio =(double)uncompressed/compressed;
    double cost = (double)compressed/chars;

    cout<<"There are a total of "<<chars<<" symbols that are encoded."<<endl;
    cout<<"There are a total of "<<distinctChar<<" distinct symbols used."<<endl;
    cout<<"There were "<<uncompressed<<" bits in the original file."<<endl;
    cout<<"There are "<<compressed<<" bits in the compressed file."<<endl;
    cout<<"This gives a compression ratio of "<<ratio<<"."<<endl;
    cout<<"The cost of the Huffman Tree is "<<cost<<" bits per character"<<endl;

    fclose(fp);
    return 0;
}
