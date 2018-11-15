#include<stdio.h>

#define pi 3.14159265

int main()
{
  double radius, perimeter, area;
  scanf("%lf", &radius);
  perimeter = 2.0 * pi * radius;
  area = pi * radius * radius;
  printf("The perimeter is %lf, the area is %lf.\n", perimetr, area);
  return 0;
}
