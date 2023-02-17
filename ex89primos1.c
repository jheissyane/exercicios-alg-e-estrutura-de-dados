#include <stdio.h>

  int main(){
    int n, x, y, i, j=2, k=3, primo=1;
    scanf("%d", &n);
    int primos[n];
    primos[0]=2;
    scanf("%d %d", &x, &y);
      for(i=1; i<n; i++){
        while(1){
          for(j=2; (j*j)<=k; j++){
            if(k%j==0){
              primo=0;
              break;
            }
          }
          if(primo==1){
            primos[i]=k;
            k++;
            break;
          }
          k++;
          primo=1;
        }
      }
      for(i=(x-1); i<y; i++){
        if(i==(y-1)){
          printf("%d\n", primos[i]);
        }
        else{
          printf("%d ", primos[i]);
        }
      }
  }