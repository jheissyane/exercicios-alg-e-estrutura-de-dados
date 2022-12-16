#include <stdio.h>

int main()
{
  int n, m, logo[10][10], tela[320][320];
  int i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%d", &logo[i][j]);
    }
  }
  scanf("%d", &m);
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < m; j++)
    {
      scanf("%d", &tela[i][j]);
    }
  }
  static int find = 0;
  int x = 0, y = 0;
  while (1)
  {
    if (x == m)
    {
      y++;
      x = 0;
    }
    if (y == m)
      break;
    int aux1 = 0, aux2 = 0, findd = 1;
    for (i = x; i < x + n; i++)
    {
      aux2 = 0;
      for (j = y; j < y + n; j++)
      {
        if (tela[i][j] != logo[aux1][aux2])
        {
          findd = 0;
        }
        aux2++;
      }
      aux1++;
    }
    if (findd)
      find = 1;
    x++;
  }
  if (find)
    printf("sim\n");
  else
    printf("nao\n");
  return 0;
}