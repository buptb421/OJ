#include <stdio.h>

int main()
{
	char a, b, c;
	scanf("%c%c%c", &a, &b, &c);
	if (((a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && c >= 'a' && c <= 'z') || (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z' && c >= 'A' && c <= 'Z')) && ((a - b) == 1 || (a - b) == -1) && ((b - c) == 1 || (b - c) == -1))
		printf ("Yes\n");
	else
		printf ("No\n");
	return 0;
}
