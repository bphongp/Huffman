//Bamphiane Annie Phongphouthai
//bp8qg
//November 18, 2017
//huffmandec.cpp

// This program is the skeleton code for the lab 10 in-lab.  It uses
// C++ streams for the file input, and just prints out the data when
// read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include "huffmanNode.h"

using namespace std;

void makeTree(huffmanNode* root, char c, string prefix){
  if(prefix.length()==0)
    root->letter = c;
  else{
    if(root==NULL)
      root= new huffmanNode(0,'\0');
    if(prefix[0]=='0'){
      if(root->left==NULL){
	root->left = new huffmanNode(0, '\0');
      }
      makeTree(root->left,c, prefix.substr(1, prefix.length()-1));
    }
    else if(prefix[0]=='1'){
      if(root->right==NULL){
	root->right = new huffmanNode(0, '\0');
      }
      makeTree(root->right,c,prefix.substr(1, prefix.length()-1));
    }
  }
}
// main(): we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    char ascii[256];
    huffmanNode *first = new huffmanNode(0,'\0');
    // read in the first section of the file: the prefix codes
    while ( true ) {
        string character;
        // read in the first token on the line
        file >> character;
	//new line cases
        if ( (character[0] == '\r') || (character[0]=='\r') )
            continue;
	 // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) ){
	  file.getline(ascii, 255, '\n');
            break;
	}
        // check for space
        if ( character == "space" )
            character = " ";
        // do something with the prefix code
        string binary =string(ascii);
	file>>binary;
	makeTree(first, character[0], binary);
	
    }
    // read in the second section of the file: the encoded message
    char bitVal;
    huffmanNode* temp = first;
    while ((bitVal=file.get())!='-' ){
      if((bitVal!='0') && (bitVal!='1'))
	continue;
      if((bitVal== '0') && temp->left!=NULL)
	temp=temp->left;
      else if((bitVal=='1')&& temp->right!=NULL)
	temp=temp->right;
      if(temp->left==NULL && temp->right ==NULL){
	cout<<temp->getLetter();
	temp= first;
      }
    }
    // at this point, all the bits are in the 'allbits' string
    cout<< endl;
    // close the file before exiting
    file.close();
    return 0;
}
