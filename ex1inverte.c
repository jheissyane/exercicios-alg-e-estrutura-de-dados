#include <stdio.h>
#define N 1000

int main(){
    int vet[N], n, j, i, vet2[N], maior=-999, menor=999;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &vet[i]);
    } 
    j=0;
    for(i=n; i>0; i--){
        vet2[j] = vet[i-1];
        j++;
    }
    
     for(i=0; i<n-1; i++){
        printf("%d ", vet[i]);
    }
    printf("%d", vet[n-1]);
    printf("\n");

    for(i=0; i<n-1; i++){
        printf("%d ", vet2[i]);
    }
    printf("%d", vet2[n-1]);
    printf("\n");

    for(i=0; i<n; i++){
        if(vet[i] > maior){
            maior = vet[i];
        }
        if(vet[i] < menor){
            menor = vet[i];
        }
    }

    printf("%d\n", maior);
    printf("%d\n", menor);
   

return 0;
}