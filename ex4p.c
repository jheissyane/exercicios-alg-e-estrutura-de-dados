#include <stdio.h>

  int main(){
    int m, n, i, j, linha, coluna, aux, contador;
    scanf("%d %d", &m, &n);
    int matrizl[m][n], matrizc[m][n];
      for(i=0; i<m; i++){
        for(j=0; j<n; j++){
          scanf("%d %d", &matrizl[i][j], &matrizc[i][j]);
        }
      }
      scanf("%d %d", &linha, &coluna);
          for(contador=0; contador<(m*n); contador++){
          aux=linha;
          linha=matrizl[linha][coluna];
          coluna=matrizc[aux][coluna];
            if(linha==0 && coluna==0){
              printf("VENCE\n");
              break;
            }
        }
        if(contador==(m*n)){
          printf("PRESO\n");
        }
  }