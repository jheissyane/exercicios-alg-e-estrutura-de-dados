#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void higger(int size, int max, char *numbers)
{
  int i, already = 0, current = -1;
  char *highnumber;
  highnumber = calloc(max, sizeof(char));
  while (already < max)
  {
    char tmpnumber = '0';
    for (i = current + 1; i < size - (max - already - 1); i++)
    {
      if (numbers[i] > tmpnumber)
      {
        tmpnumber = numbers[i];
        current = i;
      }
    }
    highnumber[already] = tmpnumber;
    already++;
  }
  printf("%s\n", highnumber);
  free(highnumber);
}

int main()
{
  int n, max, i;
  char *numbers;
  char ch;
  do
  {
    scanf("%d %d", &n, &max);
    numbers = calloc(n, sizeof(char));
    for (i = 0; i < n; i++)
    {
      scanf("%c", &ch);
      if (isdigit(ch))
      {
        numbers[i] = ch;
      }
      else
      {
        i--;
      }
    }
    higger(n, max, numbers);
    free(numbers);
  } while (n != 0 && max != 0);
  return 0;
}