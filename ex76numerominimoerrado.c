#include <stdio.h>
#include <math.h>

  int main(){
    int n, i, min=0;
    long long int produto_a=1, produto_min=0;
    scanf("%d", &n);
    int a[n];
      for(i=0; i<n; i++){
        scanf("%d", &a[i]);
        produto_a*=a[i];
      }
      while(produto_min<=produto_a){
        min++;
        produto_min=pow(min, n);
      }
      printf("%d\n", min);
  }