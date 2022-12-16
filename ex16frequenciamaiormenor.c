#include <stdio.h>

int main()
{
  int n, m, matriz[500][500], sum[1000], low, high;
  int i, j;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      scanf("%d", &matriz[i][j]);
      sum[matriz[i][j]]++;
      if (j == 0 && i == 0)
      {
        low = high = matriz[i][j];
      }
      if (matriz[i][j] < low)
        low = matriz[i][j];
      if (matriz[i][j] > high)
      {
        high = matriz[i][j];
      }
    }
  }
  double low_p = (sum[low] * 100.f) / (n * m);
  double high_p = (sum[high] * 100.f) / (n * m);
  printf("%d %.2f%%\n", low, low_p);
  printf("%d %.2f%%\n", high, high_p);
  return 0;
}