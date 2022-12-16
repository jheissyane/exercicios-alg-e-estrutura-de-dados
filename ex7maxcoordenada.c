#include <stdio.h>
#define MAX_SIZE 3

double modulo(double number)
{
  if (number < 0)
    return number * (-1);
  else
    return number;
}

void calc_print(double *old, double *new)
{
  double ba[3], aux, maior;
  ba[0] = modulo(old[0] - new[0]);
  ba[1] = modulo(old[1] - new[1]);
  ba[2] = modulo(old[2] - new[2]);
  int i, j;
  maior = ba[0];
  if (ba[1] > maior)
    maior = ba[1];
  if (ba[2] > maior)
    maior = ba[2];
  printf("%.2lf\n", maior);
}

int main()
{
  int n;
  double old[MAX_SIZE], new[MAX_SIZE];
  scanf("%d", &n);
  scanf("%lf %lf %lf", &old[0], &old[1], &old[2]);
  while (n > 1)
  {
    scanf("%lf %lf %lf", &new[0], &new[1], &new[2]);
    calc_print(old, new);
    memcpy(old, new, sizeof(new));
    n--;
  }
  return 0;
}