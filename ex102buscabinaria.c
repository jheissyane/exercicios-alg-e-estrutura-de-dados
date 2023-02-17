#include <stdio.h>

int i=0;

int acha_numero (int* v, int q, int k){
    if(i<q){
      if(v[i]==k){
        return (i+1);
      }
      else{
        i++;
      }
    }
    else{
      return 0;
    }
    acha_numero(v, q, k);
}

  int main(){
    int t, k, q=0, v[100], posicao;
    scanf("%d", &t);
      for(t; t>0; t--){
        scanf("%d", &k);
        scanf("%d", &v[q]);
          while(v[q]!=-1){
            q++;
            scanf("%d", &v[q]);
          }
          posicao=acha_numero(v, q, k);
          if(posicao==0){
            printf("ausente\n");
          }
          else{
            printf("%d\n", posicao);
          }
          q=0;
          i=0;
      }
  }