#include <stdio.h>

  int main(){
    int n, i, j, q, lanchonetes=0;
    scanf("%d", &n);
    int l[n];
      for(i=0; i<n; i++){
        scanf("%d", &l[i]);
      }
    scanf("%d", &q);
    int d[q];
      for(i=0; i<q; i++){
        scanf("%d", &d[i]);
          for(j=0; j<n; j++){
            if(l[j]<=d[i]){
              lanchonetes++;
            }
          }
          printf("%d", lanchonetes);
          for(j=0; j<n; j++){
            if(l[j]<=d[i]){
              printf(" %d", (j+1));
            }
          }
          printf("\n");
        lanchonetes=0;
      }
  }