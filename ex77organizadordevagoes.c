#include <stdio.h>

int ovt (int* vet, int n){
  int i, i1, aux, q=0;
    for(i=0; i<n; i++){
      for(i1=i; i1<n; i1++){
        if(vet[i1]<vet[i]){
          aux=vet[i1];
          vet[i1]=vet[i];
          vet[i]=aux;
          q++;
        }
      }
    }
    return q;
}

  int main(){
    int t, q, i, j, trocas;
    scanf("%d", &t);
      for(i=0; i<t; i++){
        scanf("%d", &q);
        int v[q];
          for(j=0; j<q; j++){
            scanf("%d", &v[j]);
          }
        printf("%d\n", ovt(v, q));
      }
  }