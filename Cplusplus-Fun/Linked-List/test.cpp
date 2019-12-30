#include <iostream>
#include "list.cpp"

using namespace std;


void dialog();

int main()
{
    int input, value;
    LinkedList l;
    dialog();
    cin>>input;
    while(input != 4)
    {
        if(input == 1)
        {
            cout<<"Enter Value: ";
            cin>>value;
            l.addNode(value);
        }

        if(input == 2)
        {
            cout<<"Enter Value to Remove: ";
            cin>>value;
            l.removeNode(value);
        }

        if(input == 3)
        {
            l.show();
        }
        dialog();
        cin>>input;
    }

    
}

void dialog()
{
    cout<<"[1] - add node\n"
        <<"[2] - remove node\n"
        <<"[3] - show\n"
        <<"[4] - exit\n"
        <<">> ";
}
