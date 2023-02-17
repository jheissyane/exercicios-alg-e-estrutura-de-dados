#include <stdio.h>

void altura_crescente (int* vet, int n){
  int i, i1, aux;
    for(i=0; i<n; i++){
      for(i1=i; i1<n; i1++){
        if(vet[i1]<vet[i]){
          aux=vet[i1];
          vet[i1]=vet[i];
          vet[i]=aux;
        }
      }
    }
}

  int main(){
    int t, n, i, j;
    scanf("%d", &t);
      for(i=0; i<t; i++){
        scanf("%d", &n);
        int h[n];
          for(j=0; j<n; j++){
            scanf("%d", &h[j]);
          }
          altura_crescente(h, n);
          for(j=0; j<n; j++){
            printf("%d ", h[j]);
          }
        printf("\n");
      }
  }