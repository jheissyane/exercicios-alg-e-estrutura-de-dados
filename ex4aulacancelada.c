#include <stdio.h>
#define N 1000

int main(){
    int vet[N], k, i, n, contnat=0;
    scanf("%d%d", &n, &k);
    for(i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }
    for(i=0; i<n; i++){
        if(vet[i]<=0){
            contnat++;
        }
    }
        if(contnat<k){
            printf("SIM\n");
        }
        else if(contnat>=k){
            printf("NAO\n");
            for(i=n; i>=0; i--){
                if(vet[i]<=0){
                    
                }
            }
            
   }

            return 0;
}
