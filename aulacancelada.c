#include <stdio.h>
#include <conio.h>    
void troca(int* a, int*b){
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
}
    
void insertionSort(int n, int vet[]){
    int i,j,aux,menor, indMenor     ;
    for (i=0; i<n-1; i++          ){
        for(j=i+1;j<n;j++         ){
            if( vet[j] > vet[i]   ){
                aux    = vet[i]    ;
                vet[i] = vet[j]    ;
                vet[j] = aux       ;
            }
        }
    }
}
int main(){
    int n, k, i, j, cont, vetor[1000];
    while(1){
        scanf("%d %d", &n, &k);
        if(n <= 1000 && n >= 0 && k <= 1000 && k >= 0){
            break;
        }
    }
    for(i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    for(i = 0; i < n; i++){
        if(vetor[i] > 0){
            cont++;
        }
    }
    if(cont >= k){
        printf("NAO\n");
        for(i = 0; i < n; i++){
            insertionSort(n, vetor);
            if(vetor > 0){
                printf("%d\n", vetor[i]);
            }
        }   
    }
    else{
        printf("SIM");
    }
    getch();
}