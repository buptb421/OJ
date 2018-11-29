#include<stdio.h>

int payWage(int wage, int denomination)
{
    int number = wage / denomination;
    if(number > 0)
	printf("%d:%d\n", denomination, number);
    return wage % denomination;
}

int main()
{
    int denomination[7] = {100, 50, 20, 10, 5, 2, 1};
    int wage;
    scanf("%d", &wage);
    for(int i = 0; i < 7; i = i + 1)
	wage = payWage(wage, denomination[i]);
    return 0;	
}
