#include<stdio.h>

int main()
{
  char number[3];
  scanf("%c%c%c", &number[0], &number[1], &number[2]);
  if (number[2] == '0')
    printf("The number cannot be changed.\n");
  else
    printf("%c%c%c\n", number[2], number[1], number[0]);
}
