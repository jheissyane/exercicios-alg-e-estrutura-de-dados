#include <stdio.h>

void ordena (int* vet, int n){
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
    int n, i, l, k;
    scanf("%d", &n);
    int v[n];
      for(i=0; i<n; i++){
        scanf("%d", &v[i]);
      }
      ordena(v, n);
      scanf("%d %d", &l, &k);
      printf("%d\n", (v[(l-1)]+v[(k-1)]));
  }