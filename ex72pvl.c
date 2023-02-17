#include <stdio.h>

  int main(){
    int t, n, k, i, j, l, maxl=0;
    scanf("%d", &t);
      for(t; t>0; t--){
        scanf("%d %d", &n, &k);
        getchar();
        char mat[n][n];
        for(i=0; i<n; i++){
          for(j=0; j<n; j++){
              scanf(" %c", &mat[i][j]);
          }
        }
        for(i=0; i<n; i++){
          for(j=0; j<n; j++){
            if(mat[i][j]=='P'){
              //Checa a direita
              if(k>(n-(j+1))){
                l=(n-(j+1));
              }
              else{
                l=k;
              }
              for(l; l>0; l--){
                if(mat[i][(j+l)]=='L' && mat[i][j]=='P'){
                  mat[i][(j+l)]='A';
                  mat[i][j]='C';
                  maxl++;
                }
              }
              //Checa a esquerda
              if((j-k)<0){
                l=j;
              }
              else{
                l=k;
              }
              for(l; l>0; l--){
                if(mat[i][(j-l)]=='L' && mat[i][j]=='P'){
                  mat[i][(j-l)]='A';
                  mat[i][j]='C';
                  maxl++;
                }
              }
            }
          }
        }
        printf("%d\n", maxl);
        maxl=0;
      }
  }