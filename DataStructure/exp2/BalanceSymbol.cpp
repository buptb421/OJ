#include<iostream>
#include<stack>

using namespace std;

void BalanceDetect(char expression[], int n);

int main()
{
    char expression[51];
    cin.getline(expression, 51);

    BalanceDetect(expression, 51);
    
    return 0;
}

void BalanceDetect(char expression[], int n)
{
    int nError = 0;
    stack<int> symbol;
    for(int i = 0; i < n && expression[i] != '\0'; i++)
    {
        if(expression[i] == '(')
        {
            symbol.push(1);
        }
        else if(expression[i] == ')')
        {
            if(!symbol.empty() && symbol.top() == 1)
            {
                symbol.pop();
            }
            else
            {
                nError++;
                cout << 1 << ',';
            }
        }
        else if(expression[i] == '[')
        {
            symbol.push(2);
        }
        else if (expression[i] == ']')
        {
            if(!symbol.empty() && symbol.top() == 2)
            {
                symbol.pop();
            }
            else
            {
                nError++;
                cout << 2 << ',';
            }
        }
        else if(expression[i] == '{')
        {
            symbol.push(3);
        }
        else if(expression[i] == '}')
        {
            if(!symbol.empty() && symbol.top() == 3)
            {
                symbol.pop();
            }
            else
            {
                nError++;
                cout << 3 << ',';
            }
        }
    }

    nError += symbol.size();
    if(nError == 0)
    {
        cout << '0';
    }
    else
    {
        while(!symbol.empty())
        {
            cout << symbol.top() << ',';
            symbol.pop();
        }
    }
}
