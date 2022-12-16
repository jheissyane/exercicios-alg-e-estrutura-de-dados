#include <stdio.h>

int main()
{
  int n, matriz[101][101];
  int i, j;
  scanf("%d", &n);
  for (i = 0; i < n + 1; i++)
  {
    for (j = 0; j < n + 1; j++)
    {
      scanf("%d", &matriz[i][j]);
    }
  }
  int x = 0, y = 0, count = 0;
  while (1)
  {
    count = 0;
    if (x >= n)
    {
      x = 0;
      y++;
      printf("\n");
    }
    if (y >= n)
      break;
    for (i = y; i < y + 2; i++)
    {
      for (j = x; j < x + 2; j++)
      {
        if (matriz[i][j] == 1)
        {
          count++;
        }
      }
    }
    x++;
    if (count >= 2)
      printf("S");
    else
      printf("U");
  }
  return 0;
}