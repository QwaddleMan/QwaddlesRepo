#include <iostream>
#include "Tree.h"


using namespace std;


int main()
{
	Tree tree;


	//show what is being added
	cout<<"4\n";
	cout<<"6\n";
	cout<<"3\n";
	cout<<"12\n";
	cout<<"1\n";
	cout<<"100\n\n";

	//add them to the tree
	tree.addNode(4);
	tree.addNode(6);
	tree.addNode(3);
	tree.addNode(12);
	tree.addNode(1);
	tree.addNode(100);
	

	//print the tree
	tree.printValues(tree.root);

	return 0;
}



