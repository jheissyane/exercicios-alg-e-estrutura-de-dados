#include <stdio.h>
#define N 1000
  
     int main(){
        int vet[N], n, i, cont, aux;
        scanf("%d", &n);
        for(i=0; i<n; i++){
            scanf("%d", &vet[i]);
        }
        for(cont=1; cont<n; cont++){
            for(i=0; i<n-1; i++){
                if(vet[i]>vet[i+1]){
                   aux = vet[i];
                   vet[i] = vet[i+1];
                   vet[i+1] = aux;
                }
            }
        }
        for(i=0; i<n; i++){
            printf("%d\n", vet[i]);
        }
     }