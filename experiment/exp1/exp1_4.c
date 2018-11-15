#include<stdio.h>

// #define pi 3.14159265
// I hope the system can support more features that can help with debugging.  \(|_|)/

int main()
{
  double pi = 3.14159265;
  double radius, perimeter, area;
  scanf("%lf", &radius);
  perimeter = 2.0 * pi * radius;
  area = pi * radius * radius;
  printf("The perimeter is %.4lf, the area is %.4lf.\n", perimeter, area);
  return 0;
}
