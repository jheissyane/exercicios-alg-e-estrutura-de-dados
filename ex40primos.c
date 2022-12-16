#include <stdio.h>

  int main(){
    int q, i;
    int n;
    scanf("%d", &q);
      for(i=0; i<q; i++){
        scanf("%d", &n);
          if(n==2 || n==3 || n==5 || n==7){
            printf("primo\n");
          }
          else if(n%2==0 || n%3==0 || n%5==0 || n%7==0){
            printf("composto\n");
          }
          else{
            printf("primo\n");
          }
      }
  }