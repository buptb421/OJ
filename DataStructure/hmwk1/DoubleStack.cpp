#include<iostream>
#include"DoubleStack.hpp"

using namespace std;

int main()
{
    int pageHandler = 1;
    int stackID = 1;
    ElemType e;

    twStack s;
    InitStack(s);

    if(isStackExist(s))
    {
        cout << "Please enter your operation:" << endl << "  0. quit" << endl << "  1. push" << endl << "  2. pop" << endl << "  3. show length" << endl; 
        cin >> pageHandler;
        while(pageHandler != 0)
        {
            cout << "Please enter the stack you want to operate(1/2):";
            cin >> stackID;
            
            switch (pageHandler)
            {
            case 1:
                cin.ignore(INT_MAX, '\n');
                cout << "Please enter the element:";
                cin >> e;
                push(s, stackID, e);
                break;
            case 2:
                cout << "Pop at " << stackLength(s, stackID) << "th position, it is ";
                Display_ElemType(pop(s, stackID));
                cout << '.' << endl;
                break;
            case 3:
                cout << "The Length of the stack is " << stackLength(s, stackID) << '.' << endl;
                break;
            default:
                cout << "Input erreo." << endl;
                break;
            }
            cout << "Please enter your operation:" << endl << "  0. quit" << endl << "  1. push" << endl << "  2. pop" << endl << "  3. show length" << endl; 
            cin >> pageHandler;
        }

        for(int i = 1; i <=2; i++)
        {
            cout << "The " << i << "th stack of " << stackLength(s, i) << " elements:" << endl;
            while(stackLength(s, i) > 0)
            {
                cout << '{' << stackLength(s, i) << ':';
				e = pop(s, i);
                Display_ElemType(e);
                cout << '}';
            }
            cout << "<<------BOTTOM" << endl;
        }
        
        return 0;
    }
    else
    {
        return 1;
    }
}
