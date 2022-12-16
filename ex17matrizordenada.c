#include <stdio.h>

int main()
{
  int n, i, j;
  scanf("%d", &n);
  int **matriz = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
    matriz[i] = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%d", &matriz[i][j]);
    }
  }
  int aux, t;
  for (t = 1; t < (n * n); t++)
  {
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n - 1; j++)
      {
        if (matriz[j][i] > matriz[j + 1][i])
        {
          aux = matriz[j][i];
          matriz[j][i] = matriz[j + 1][i];
          matriz[j + 1][i] = aux;
        }
      }
    }
  }
  for (i = 0; i < n; i++)
  {
    printf("%d", matriz[i][0]);
    for (j = 1; j < n; j++)
    {
      printf(" %d", matriz[i][j]);
    }
    printf("\n");
  }
  for (i = 0; i < n; i++)
  {
    free(matriz[i]);
  }
  free(matriz);
  return 0;
}