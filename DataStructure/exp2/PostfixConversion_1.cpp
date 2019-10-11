#include<iostream>
#include<iomanip>

using namespace std;

float product(float prevRes, char prevOp);
float sum(float prevRes, char prevOp);

int main()
{
    // queue<char> output;
    float result;

    result = sum(0, '+');
    cout << endl << "result: " << fixed << setprecision(2) << result << endl;
    return 0;
}

float sum(float prevRes, char prevOp)
{
    bool init = true;
    float result = prevRes;
    float nowRes = 0;
    int nowNum = 0;
    char nowOp, par;

    char peek = cin.peek();

    while(peek != '\n' && peek != ')')
    {
        if(isdigit(peek))
        {
            cin >> nowNum;
            cout << nowNum << ' ';
            nowRes = nowNum;
        }
        else if(peek == '+' || peek == '-')
        {
            cin >> nowOp;
            if(prevOp == '+')
            {
                result += nowRes;
            }
            else
            {
                result -= nowRes;
            }
            if(!init)
            {
                cout << prevOp << ' ';
            }
            else
            {
                init = false;
            }
            
            
            prevOp = nowOp;
        }
        else if(peek == '*' || peek == '/')
        {
            cin >> nowOp;
            nowRes = product(nowRes, nowOp);
        }
        else if(peek == '(')
        {
            cin >> par;
            nowRes = sum(0, '+');
        }
        else
        {
            cout << "Wrong character [" << peek << "]" << endl;
        }
        peek = cin.peek();
    }
    if(peek == ')')
    {
        cin >> par;
    }
    if(prevOp == '+')
    {
        result += nowRes;
    }
    else
    {
        result -= nowRes;
    }
    cout << prevOp << ' ';
    return result;
}

float product(float prevRes, char prevOp)
{
    float result = prevRes;
    float nowRes;
    int nowNum;

    char nowOp, par;
    char peek = cin.peek();
    while(peek != '\n' && peek != ')' && peek != '+' && peek != '-')
    {
        if(isdigit(peek))
        {
           cin >> nowNum;
           cout << nowNum << ' ';
           nowRes = nowNum;
        }
        else if(peek == '*' || peek == '/')
        {
            cin >> nowOp;
            if(prevOp == '*')
            {
                result *= nowRes;
            }
            else
            {
                result /= nowRes;
            }
            cout << prevOp << ' ';
            prevOp = nowOp;
        }
        else if(peek == '(')
        {
            cin >> par;
            nowRes = sum(0, '+');
        }
        else
        {
            cout << "Wrong character [" << peek << "]" << endl;
        }
        peek = cin.peek();
    }
    if(peek == ')')
    {
        cin >> par;
    }
    if(prevOp == '*')
    {
        result *= nowRes;
    }
    else
    {
        result /= nowRes;
    }
    cout << prevOp << ' ';
    return result;
}

// 1-(12+3)*7*2+13-23-12*234/(1+5)

