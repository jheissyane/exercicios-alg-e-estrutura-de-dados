#include <stdio.h>

  int main(){
    int n, k, num, i, q=0;
    scanf("%d %d", &n, &k);
      for(i=0; i<n; i++){
        scanf("%d", &num);
          if(num==k){
            q++;
          }
      }
      printf("%d\n", q);
  }