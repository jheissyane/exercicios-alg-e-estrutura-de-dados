#include <stdio.h>

int have(int src, int *dst)
{
  int i;
  for (i = 0; i < 6; i++)
  {
    if (src == dst[i])
      return 1;
  }
  return 0;
}

int main()
{
  int n, i, j, sena[6];
  scanf("%d", &n);
  int **apostas = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
    apostas[i] = (int *)malloc(6 * sizeof(int));
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < 6; j++)
    {
      scanf("%d", &apostas[i][j]);
    }
  }
  for (j = 0; j < 6; j++)
  {
    scanf("%d", &sena[j]);
  }
  int acertos;
  int ganhadores[3] = {0, 0, 0};
  for (i = 0; i < n; i++)
  {
    acertos = 0;
    for (j = 0; j < 6; j++)
    {
      if (have(apostas[i][j], sena))
      {
        acertos++;
      }
    }
    if (acertos == 6)
      ganhadores[0]++;
    else if (acertos == 5)
      ganhadores[1]++;
    else if (acertos == 4)
      ganhadores[2]++;
  }
  if (ganhadores[0] > 0)
    printf("Houve %d acertador(es) da sena\n", ganhadores[0]);
  else
    printf("Nao houve acertador para sena\n");

  if (ganhadores[1] > 0)
    printf("Houve %d acertador(es) da quina\n", ganhadores[1]);
  else
    printf("Nao houve acertador para quina\n");

  if (ganhadores[2] > 0)
    printf("Houve %d acertador(es) da quadra\n", ganhadores[2]);
  else
    printf("Nao houve acertador para quadra\n");
  for (i = 0; i < n; i++)
  {
    free(apostas[i]);
  }
  free(apostas);

  return 0;
}