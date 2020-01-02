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
    while(input != 5)
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
            cout<<"Enter Value to Remove: ";
            cin>>value;
            l.removeAllValues(value);
        }

        if(input == 4)
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
        <<"[3] - remove all occurences of Value\n"
        <<"[4] - show\n"
        <<"[5] - exit\n"
        <<">> ";
}
