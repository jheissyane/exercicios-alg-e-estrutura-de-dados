#include <stdio.h>

int locais[6][6] = {
    {0, 63, 210, 190, -1, 190},
    {63, 0, 160, 150, 95, 10},
    {210, 160, 0, 10, 1, 10},
    {190, 150, 10, 0, 10, 20},
    {10, 95, 7, 21, 0, 80},
    {190, 2, -1, 41, 80, 0}};
int main()
{
  int n, matriz[101];
  scanf("%d", &n);
  int i, j;
  for (i = 0; i < n; i++)
  {
    scanf("%d", &matriz[i]);
  }
  int sum = 0;
  for (i = 0; i < n - 1; i++)
  {
    if (locais[matriz[i]][matriz[i + 1]] == -1)
    {
      printf("rota invalida!\n");
      return 0;
    }
    sum += locais[matriz[i]][matriz[i + 1]];
  }
  printf("%d\n", sum);
  return 0;
}