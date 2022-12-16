#include <stdio.h>

int main()
{
  int i, j, k, m[6][6];
  for (i = 0; i < 6; i++)
  {
    for (j = 0; j < 6; j++)
    {
      scanf("%d", &m[i][j]);
    }
  }
  int x = 0, y = 0, aux, max;
  static int initialized = 0;
  while (1)
  {
    aux = 0;
    if (x > 3)
    {
      y++;
      x = 0;
    }
    if (y > 3)
      break;
    aux += m[y][x];
    aux += m[y][x + 1];
    aux += m[y][x + 2];
    aux += m[y + 1][x + 1];
    aux += m[y + 2][x];
    aux += m[y + 2][x + 1];
    aux += m[y + 2][x + 2];
    if (!initialized)
    {
      max = aux;
      initialized = 1;
    }
    else if (aux > max)
      max = aux;
    x++;
  }
  printf("%d\n", max);
  return 0;
}