#include <stdio.h>

  int main(){
    int n, i, crescente=1, decrescente=1;
    scanf("%d", &n);
    int m[n];
      for(i=0; i<n; i++){
        scanf("%d", &m[i]);
      }
      for(i=1; i<n; i++){
        if(m[i]<m[(i-1)]){
          crescente=0;
          break;
        }
      }
      //decrescente
      for(i=1; i<n; i++){
        if(m[i]>m[(i-1)]){
          decrescente=0;
          break;
        }
      }
      if(crescente==0 && decrescente==0){
        printf("nao\n");
      }
      else{
        printf("sim\n");
      }
  }