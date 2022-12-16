#include <stdio.h>

int check(int *sena, int *numeros)
{
  int i, j, acertos = 0;
  for (i = 0; i < 6; i++)
  {
    for (j = 0; j < 6; j++)
    {
      if (numeros[j] == sena[i])
        acertos++;
    }
  }
  return acertos;
}

void print(int acertos, char *complemento)
{
  if (acertos > 0)
    printf("Houve %d acertador(es) da %s\n", acertos, complemento);
  else
    printf("Nao houve acertador para %s\n", complemento);
}

int main()
{
  int sena[6], i, n, numeros[6], ganhadores[3];
  memset(ganhadores, 0, sizeof(ganhadores));
  for (i = 0; i < 6; i++)
    scanf("%d", &sena[i]);
  scanf("%d", &n);
  while (n > 0)
  {
    for (i = 0; i < 6; i++)
      scanf("%d", &numeros[i]);
    int acertos = check(sena, numeros);
    if (acertos == 6)
      ganhadores[0]++;
    else if (acertos == 5)
      ganhadores[1]++;
    else if (acertos == 4)
      ganhadores[2]++;
    n--;
  }
  print(ganhadores[0], "sena");
  print(ganhadores[1], "quina");
  print(ganhadores[2], "quadra");
  return 0;
}