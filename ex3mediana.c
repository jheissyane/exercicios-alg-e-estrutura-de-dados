#include <stdio.h>
#define N 1000

void bubbleSort(int vet[], int n){
    int i, cont, aux;
    for(cont=1; cont<n; cont++){
        for(i=0; i<n-1; i++){
            if(vet[i]>vet[i+1]){
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
            }
        }
    }
}

void mediana(int vet[], int n){
    float mediana;
    if(n%2 == 0){
        mediana = (float)(vet[n/2] + vet[(n/2)-1])/2;
    }else{
        mediana = (float)vet[n/2];
    }
    printf("%.2f\n", mediana);
}

int main(){
    int vet[N], n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }
    bubbleSort(vet, n);
    mediana(vet, n);
return 0;
}