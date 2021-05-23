#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <cstring>
#include "BinaryHeap.h"
using namespace std;

class BinaryTree
{
 public:
  BinaryTree *parent;
  BinaryTree *leftChild;
  BinaryTree *rightChild;
  int frequency;
  char character;
//  char code [256];
  BinaryTree(char pchar='\0', int pfreq=0)
  {
	frequency = pfreq;
	character = pchar;
	leftChild = NULL;
	rightChild = NULL;
  //      code[0] = ' ';
}
BinaryTree(BinaryTree *  ptr1, BinaryTree * ptr2){
	 leftChild = ptr1;
	 rightChild = ptr2;
	 frequency = ptr1->frequency + ptr2->frequency;
	 character = '\0';
//	code[0] = ' ';
}


//Print out Huffmann encoding of each character in the message
void printTree(char * code ){

  if(leftChild)
  {
    strcat(code,"0");
    leftChild->printTree(code);
  }
   if(character != '\0')
  {
  	int i;
  	cout<<character<<" "<<frequency<<" "<<code<<endl;
  	//now remove last character in code, and go back up.
  	int length = strlen(code) - 1;
	for( i=0;i<length;i++)  {
  	}
 	code[i] = '\0';

  }
   if(rightChild)
   {
		strcat(code,"1");
		rightChild->printTree(code);
   }
   if (character == '\0'){
	int length = strlen(code) - 1;
        int i;
	for( i=0;i<length;i++)  {
        }
        code[i] = '\0';
   }
}


};
class BinaryTreePtr{
	public:
		BinaryTree *ptr;
		BinaryTreePtr(BinaryTree *p){
			ptr = p;
		}
		BinaryTreePtr(){
			ptr = NULL;
		}
		bool operator <  (const BinaryTreePtr & rhs) const{
			return ptr->frequency < rhs.ptr->frequency;
		}
		BinaryTreePtr(BinaryTreePtr & small, BinaryTreePtr & big){
			BinaryTree* temp = new BinaryTree(small.ptr, big.ptr);
			ptr = temp;
		}

};
#endif

