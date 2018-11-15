#include<stdio.h>

int getDays(int year, int month);

int main()
{
    int year, month;
    scanf("%d%d", &year, &month);
    printf("There are %d days in month %d year %d.\n", getDays(year, month), month, year);
}

int getDays(int year, int month)
{
    switch(month)
    {
    case 1:
	return 31;
    case 2:
	if(
	    (year % 4) == 0 &&
	    (year % 100) != 0 ||
	    (year % 400) == 0)
	    return 29;
	else
	    return 28;
    case 3:
	return 31;
    case 4:
	return 30;
    case 5:
	return 31;
    case 6:
	return 30;
    case 7:
	return 31;
    case 8:
	return 31;
    case 9:
	return 30;
    case 10:
	return 31;
    case 11:
	return 30;
    case 12:
	return 31;
    }
}
