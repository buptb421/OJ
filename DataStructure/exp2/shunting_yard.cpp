#include<iostream>
#include<stack>
#include<string>
#include<iomanip>

#define length 200

using namespace std;

int precedence(char c); // return the precedence of operator
void infix2Postfix(char ch[], string &postfix); // as name
float evalPostfix(string postfix); // as name

int main()
{
	char ch[length];
	string postfix("");
	cin.getline(ch, length);
	infix2Postfix(ch, postfix);
	cout << fixed << setprecision(2) << evalPostfix(postfix) << '\n';
	cout << postfix;
	return 0;
}

/* 0 ~ 2 for override controls like () and string end.
 * 3 ~ 4 for + - * /
 * 5 for numbers
 */ 
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

void infix2Postfix(char ch[], string &postfix)
{
	stack<char>symbol;
	symbol.push('(');

	bool end = false;

	int i = 0, tempPrec;

	while(!end)
	{
		tempPrec = precedence(ch[i]);
		if(tempPrec < 5)
		{
			while(precedence(symbol.top()) >= tempPrec && tempPrec > 0)
			{
				postfix += symbol.top() ;
				postfix += ' ';
				symbol.pop(); 
			}
			if(tempPrec == 2)
			{
				end = true;
			}
			else if(tempPrec == 1)
			{
				symbol.pop();
			}
			else
			{
				symbol.push(ch[i]);
			}
		}
		else // 0~9
		{
			postfix += ch[i];
			postfix += ' ';
		}
		i++;
	}
}

float evalPostfix(string postfix)
{
	float tempRes;
	tempRes =  0;
	stack<float> result;
	for(int i= 0; postfix[i] != '\0'; i++)
	{
		if(postfix[i]!=' ')
		{
			if(postfix[i] <= '9' && postfix[i] >= '0')
			{
				result.push(postfix[i]-'0'); 
			}
			else
			{
				tempRes = result.top();
				result.pop();
				switch (postfix[i])
				{
				case '-':
					result.top() -= tempRes;
					break;
				case '*':
					result.top() *= tempRes;
					break;
				case '/':
					result.top() /= tempRes;
					break;
				default:
					result.top() += tempRes;
					break;
				}
			}
		}
	}
	return result.top() ;
}
