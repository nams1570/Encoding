
#include <fstream>
#include "BinaryTree.h"
#include "BinaryHeap.h"
using namespace std;

int main(int argc, char* argv[])
{
	fstream infile;
	int characters[256];
	char cread;
//Initializing characters to all 0
	for(int i=0;i<256;i++)
	{
	characters[i] = 0;
	}
//filename should be read from command line.
	infile.open(argv[1]);

//Reading characters from file
	while(infile.get(cread))
	{
 		characters[cread]++;
	}
//Above loop stores frequency of each character
	infile.close();
	BinaryTreePtr a[256];
	BinaryTree b[256];
  //Making the characters into nodes, then inserting them into heap
	BinaryHeap <BinaryTreePtr> heapobj(256);
	for (int i = 0; i < 256; i++){
		if(characters[i] > 0){
			b[i] = BinaryTree(i, characters[i]);
			a[i] =  BinaryTreePtr(&b[i]);
			heapobj.insert(a[i]);
		}
	}

	BinaryTreePtr temp1 (NULL);
	BinaryTreePtr temp2 (NULL);
	BinaryTreePtr merge (NULL);
	BinaryTreePtr c[256];
                int j = 0;
//Loop to build tries from heap until only one trie is left in heap
	while(!heapobj.isEmpty() )
	{
 		temp1 =heapobj.findMin();
		heapobj.deleteMin();
		if(heapobj.isEmpty()){
			break;
		}
		temp2 = heapobj.findMin();
		heapobj.deleteMin();
		 c[j] = BinaryTreePtr(temp1,temp2);
		heapobj.insert(c[j]);
		j++;
	}
//repurposing temp1 to act as storage of last trie
	char code [256] = "";
	temp1.ptr->printTree(code);
}


