#include <stdio.h>
#define N 1000

void binario(int n){
    if(n==0)
        return;
    else{
        binario(n/2);
        printf("%d", n%2);
    }
}


int main(){
    int k, i, vet[N];
    scanf("%d", &k);
    
    for(i=1; i<=k; i++){
        scanf("%d", &vet[i]);
    }
    for(i=1; i<=k; i++){
        binario(vet[i]);
        printf("\n");
        }

        return 0;
}