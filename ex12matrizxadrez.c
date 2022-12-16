#include <stdio.h>

int main()
{
  int n, m, i, j, matriz[10][10], count = 1;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      if (j > 0)
        printf(" ");
      if (!(j % 2))
      {
        if (!(i % 2) || i == 0)
        {
          printf("0");
        }
        else
        {
          printf("%d", count);
          count++;
        }
      }
      else
      {
        if (!(i % 2) || i == 0)
        {
          printf("%d", count);
          count++;
        }
        else
        {
          printf("0");
        }
      }
    }
    printf("\n");
  }
  return 0;
}