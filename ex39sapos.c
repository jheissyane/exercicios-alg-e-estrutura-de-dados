#include <stdio.h>

  int main(){
    int n_pedras, n_sapos, i, pi, p, d;
    scanf("%d %d", &n_pedras, &n_sapos);
    int pedras[n_pedras];
      for(i=0; i<n_pedras; i++){
        pedras[i]=0;
      }
      for(i=0; i<n_sapos; i++){
        scanf("%d %d", &pi, &d);
          for(p=(pi-1); p<n_pedras; p+=d){
            pedras[p]=1;
          }
          for(p; p>=0; p-=d){
            pedras[p]=1;
          }
      }
      for(i=0; i<n_pedras; i++){
        printf("%d\n", pedras[i]);
      }
  }