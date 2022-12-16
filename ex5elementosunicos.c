#include <stdio.h>
#define N 5000

int main(){
    int vet[N], n, cont, conteu=0, aux, i;

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
            if(vet[i] != vet[i+1] && vet[i] != vet[i-1]){
                conteu++;
            }
        }
        printf("%d\n", conteu);

        return 0;
        
}