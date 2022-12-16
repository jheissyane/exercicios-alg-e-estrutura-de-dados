#include <stdio.h>

  int main(){
    int m, n, i, j, linha, coluna, aux, cont;
    scanf("%d %d", &m, &n);
    int mat_linha[m][n], mat_coluna[m][n];
      for(i=0; i<m; i++){
        for(j=0; j<n; j++){
          scanf("%d %d", &mat_linha[i][j], &mat_coluna[i][j]);
        }
      }
      scanf("%d %d", &linha, &coluna);
          for(cont=0; cont<(m*n); cont++){
          aux=linha;
          linha=mat_linha[linha][coluna];
          coluna=mat_coluna[aux][coluna];
            if(linha==0 && coluna==0){
              printf("VENCE\n");
              break;
            }
        }
        if(cont==(m*n)){
          printf("PRESO\n");
        }
  }