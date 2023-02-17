#include <stdio.h>

  int main(){
    int t, i, a, b, c, k, x=0;
    scanf("%d", &t);
      for(i=0; i<t; i++){
        scanf("%d %d %d %d", &a, &b, &c, &k);
        while((a*x*x+b*x+c)<k){
          x++;
        }
        printf("%d\n", x);
        x=0;
      }
  }