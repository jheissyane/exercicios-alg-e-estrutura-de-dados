#include <stdio.h>

//prot�tipos:

//verifica o valor maximo possivel da multiplica��o do vetor:
int maxVetor(int* v,int n);

//verifica a quantidade de multiplica�oes de numeros no vetor � igual ao valor maximo 'maior':
int quantMaior(int* v, int n, int maior);

//fun�oes:

int maxVetor(int* v,int n){
    int maior = -99999999;
    int i, j;
    for(i=0; i<n; i++){
        for(j=i; j<n; j++){
            if(v[i]*v[j] > maior){
                maior = v[i]*v[j];
            }
        }
    }
    return maior;
}

int quantMaior(int* v, int n, int maior){
    int i, j;
    int quant = 0;
    for(i=0; i < n; i++){
        for(j=i; j < n; j++){
            if(v[i]*v[j] == maior){
                quant++;
            }
        }
    }
    return quant;
}

int main(){
    int n;
    int i;
    scanf("%d", &n);
    while(n--){
        int m;
        scanf("%d", &m);
        int v[m];
        for(i=0; i<m; i++){
            scanf("%d", &v[i]);
        }
        printf("%d\n", quantMaior(v,m,maxVetor(v,m)));
    }
}