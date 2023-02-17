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
    int n, i, j=1, k, primo=1, num=3;
    scanf("%d", &n);
    int v[n];
      for(i=0; i<n; i++){
        scanf("%d", &v[i]);
      }
      ordena(v, n);
      for(i=0; i<n; i++){
        if(v[i]==1){
          printf("2");
        }
        else{
          while(j<v[i]){
            for(k=2; (k*k)<=num; k++){
              if(num%k==0){
                primo=0;
                break;
              }
            }
            if(primo==1){
              j++;
            }
            num++;
            primo=1;
          }
          printf("%d", (num-1));
        }
        if(i==(n-1)){
          printf("\n");
        }
        else{
          printf(" ");
        }
      }
  }