#include<iostream>
#include<iomanip>

#define LOWEST_PRECEDENCE 0
#define HIGHEST_PRECEDENCE 1

#define NUMBERandVARIABLE 2

#define SCOPE_START 3
#define SCOPE_END 4

#define DELIMITER 5

using namespace std;

int precedence(char op);
float binCalc(float result, float prevRes, char op);
float evaluator(float prevRes, char prevOp);

int main()
{
    // queue<char> output;
    float result;

    result = evaluator(0, '+');
    cout << "result: " << fixed << setprecision(2) << result << endl;
    return 0;
}

int precedence(char op)
{
    switch (op)
    {
    case '+':
        return LOWEST_PRECEDENCE;
    case '-':
        return LOWEST_PRECEDENCE;
    case '*':
        return HIGHEST_PRECEDENCE;
    case '/':
        return HIGHEST_PRECEDENCE;
    case '(':
        return SCOPE_START;
    case ')':
        return SCOPE_END;    
    case '\n':
        return DELIMITER;
    case '\0':
        return DELIMITER;
    default:
        return NUMBERandVARIABLE;
    }
}

float binCalc(float result, float prevRes, char op, bool init) // result = binCalc(result, prevRes, prevOp)
{
    if(!init)
    {
        cout << op << ' ';
    }
    
    switch(op)
    {
        case '+':
            return result + prevRes;
        case '-':
            return result - prevRes;
        case '*':
            return result * prevRes;
        case '/':
            return result / prevRes;
        default:
            cout << "Wrong operator." << endl;
            return 0;
    }
}

float evaluator(float prevRes, char prevOp)
{
    int evaluator_precedence = precedence(prevOp);

    bool init;
    if(evaluator_precedence == LOWEST_PRECEDENCE)
    {
        init = true;
    }

    float result = prevRes, nowRes = 0.0;
    //int nowNum = 0;
    char nowOp, par;
    int peekPrec = precedence(cin.peek());
    while(peekPrec < SCOPE_END && peekPrec >= evaluator_precedence) // peekPrec != DELIMITER && peekPrec != SCOPE_END
    {
        if(peekPrec <= HIGHEST_PRECEDENCE)
        {
            if(peekPrec > evaluator_precedence)
            {
                cin >> nowOp;
                nowRes = evaluator(nowRes, nowOp);
            }
            else
            {
                
            }
            
        }
        else if()
        {
            
        }
        else
        {
            cin >> par;
            nowRes = evaluator(0, '+');
        }
        peekPrec = precedence(cin.peek());
    }

}



