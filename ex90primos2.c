#include <stdio.h>

  int main(){
    int x, y, i, j, k, q=0, primo=1;
    scanf("%d %d", &x, &y);
      for(i=x; i<=y; i++){
        if(i==2 || i==1){
          q++;
          i=3;
        }
        for(j=2; (j*j)<=i; j++){
          if(i%j==0){
            primo=0;
            break;
          }
        }
        if(primo==1){
          q++;
        }
        primo=1;
      }
      printf("%d\n", q);
  }