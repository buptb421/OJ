#include<iostream>
#include<iomanip>

using namespace std;

int precedence(char op);
float binCalc(float result, float prevRes, char op);
float evaluator(float prevRes, char prevOp);

int main()
{
    float result;

    result = evaluator(0, '+');
    cout << "result: " << fixed << setprecision(2) << result << endl;
    return 0;
}

int precedence(char c)
{
	switch(c)
	{
		case '(':
			return 0;
		case ')':
			return 1;
		case '\0':
			return 2;
		case '\n':
			return 2;

		case '+' :
			return 3;
		case '-' :
			return 3;
		case '*' :
			return 4;
		case '/' :
			return 4;
		
		default :
			return 5; 
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



