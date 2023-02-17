#include <stdio.h>
#define N 2000


void buscarecursiva(int vet[], int n, int i){
    if(i==n){
        printf("VALOR NAO ENCONTRADO\n");
        return;
    }
    else{
        if(vet[i]==n){
            printf("%d\n", i+1);
            return;
        }
        else{
            buscarecursiva(vet, n, i+1);
        }
    }
}

int main(){
    int vet[N], n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }
    scanf("%d", &n);

    buscarecursiva(vet, n, 0);

    return 0;
}