#include<stdio.h>

int main()
{
  char gender;
  int age;
  float height;
  scanf("%c %d %f", &gender, &age, &height);
  printf("The sex is %c, the age is %d, and the height is %f.\n", gender, age, height);
  return 0;
}
