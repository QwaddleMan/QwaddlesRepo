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
            void removeNode(int val);
            void removeAllValues(int val);
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

//removes the first node with the value of val
void LinkedList::removeNode(int val)
{
    current = head;
    node * temp = NULL;
    while(current != NULL)
    {
        if(current->value == val)
        {
            temp = current->left;
            current = current->right;
            delete current->left;
            temp->right = current;
            current->left = temp;
            break;
        }
        current = current->right;
    }
}

//removes all occurences of value
void LinkedList::removeAllValues(int val)
{
    
    current = head;
    node * temp = NULL;
    while(current != NULL)
    {
        if(current->value == val)
        {
            temp = current->left;
            current = current->right;
            delete current->left;
            temp->right = current;
            current->left = temp;
        }
        current = current->right;
    }
}
