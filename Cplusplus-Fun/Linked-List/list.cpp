#pragma once
#include <iostream>

using namespace std;

struct node{
    int value;
    node * left;
    node * right;
};


class LinkedList{

    public:
            LinkedList();
            void addNode(int val);
            void show();
    private:
            node * head;
            node * current;
            node * tail;

};

LinkedList::LinkedList()
{
    current = NULL;
    head = NULL;
    tail = NULL;
}

void LinkedList::addNode(int val)
{

    if(tail == NULL)
    {
        head = new node;
        tail = head;
        tail->left = NULL;
        tail->right = NULL;
    }
    else
    {
        current = tail;
        tail->right = new node;
        tail = tail->right;
        tail->right = NULL;
        tail->left = current;
    }
    tail->value = val;

}

void LinkedList::show()
{
    current = head;
    while(current != NULL)
    {
        cout<<current->value<<endl;
        current = current->right;
    }

}
