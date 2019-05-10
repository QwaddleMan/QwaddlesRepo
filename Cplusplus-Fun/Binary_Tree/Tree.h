#include <iostream>

using namespace std;

#ifndef _Tree_h
#define _Tree_h

//node structure
struct node
{
	int value;
	node * left = NULL;
	node * right = NULL;
};




class Tree{

public:
	Tree();
	void addNode(int value);
	void findSpot(node * current, int value);
	void printValues(node * current);
public:
	node * root;
private:


};

//just set root to null on creation
Tree::Tree()
{
	root = NULL;
}

//addNode
//add a node of value to the tree
void Tree::addNode(int value)
{

	//check if tree is empty
	if(root == NULL)
	{
		root = new node;
		root->value = value;	
	}
	else
	{
		//if tree is not empty find the spot that the new node should be 
		findSpot(root, value);
	}

}

//find spot
//find the spot for the new value
void Tree::findSpot(node * current, int value)
{
	if(value > current->value)//value greater than current value?
	{
		if(current->right == NULL)//if right is null then put the number to the right
		{
			current->right = new node;
			current->right->value = value;
			return;
		}
		findSpot(current->right,value);//if right is not null then continue right
	}
	if(value < current->value)//value less than current value?
	{
		if(current->left == NULL)//if left is null then put the number to the left
		{
			current->left = new node;
			current->left->value = value;
			return;
		}
		findSpot(current->left,value);//if left is not null then continue left
	}
}

//printValues
//print all the values of the tree
void Tree::printValues(node * current)
{

	if(current->left != NULL)
	{
		printValues(current->left);//left value? go left
	}

	cout<<current->value<<endl; // print the current

	if(current->right != NULL)
	{
		printValues(current->right);//right value? go right
	}

	return;//previous node
}



#endif