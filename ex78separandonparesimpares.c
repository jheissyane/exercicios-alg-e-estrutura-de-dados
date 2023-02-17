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
    int n, i, par=0, imp=0, ip=0, ii=0;
    scanf("%d", &n);
    int num[n];
      for(i=0; i<n; i++){
        scanf("%d", &num[i]);
          if(num[i]%2==0){
            par++;
          }
          else{
            imp++;
          }
      }
      int pares[par], impares[imp];
      for(i=0; i<n; i++){
        if(num[i]%2==0){
          pares[ip]=num[i];
          ip++;
        }
        else{
          impares[ii]=num[i];
          ii++;
        }
      }
      ordena(pares, par); ordena(impares, imp);
        for(i=0; i<par; i++){
          if(i==(par-1)){
            printf("%d\n", pares[i]);
          }
          else{
            printf("%d ", pares[i]);
          }
        }
        for(i=(imp-1); i>=0; i--){
          if(i==0){
            printf("%d\n", impares[i]);
          }
          else{
            printf("%d ", impares[i]);
          }
        }
  }