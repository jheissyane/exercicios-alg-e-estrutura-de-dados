#include <stdio.h>
#define maximo 100

/**
 * inf/UFG - AED1: lista de exercicios de recursividade - 10
 * O programa a seguir analiza uma matriz de setas --A,V,<,>--
 * e conta o numero de casas seguras,ou seja, de um caminho que
 * nao leve ate fora dos limites da matriz, usando uma matriz
 * auxiliar para marcar os caminhos nao seguros
 */
void trilha(char m[][maximo],int aux[][maximo],int lin,int col){
    if(m[lin+1][col] == 'A' || m[lin-1][col] == 'V' || m[lin][col-1] == '>' || m[lin][col+1] == '<'){
        if(m[lin+1][col] == 'A'){
            aux[lin+1][col] = 1;
            trilha(m,aux,lin+1,col);
        }
        if(m[lin-1][col] == 'V'){
            aux[lin-1][col] = 1;
            trilha(m,aux,lin-1,col);
        }
        if(m[lin][col-1] == '>'){
            aux[lin][col-1] = 1;
            trilha(m,aux,lin,col-1);
        }
        if(m[lin][col+1] == '<'){
            aux[lin][col+1] = 1;
            trilha(m,aux,lin,col+1);
        }
    }
    return;
}

void varrer(char m[][maximo],int aux[][maximo],int n){
    int i=0;
    while(i<n){
        if(m[0][i] == 'A'){
            aux[0][i] = 1;
            trilha(m,aux,0,i);
        }
        i++;
    }
    i=0;
    while(i<n){
        if(m[i][0] == '<'){
            aux[i][0] = 1;
            trilha(m,aux,i,0);
        }
        i++;
    }
    i=0;
    while(i<n){
        if(m[i][n-1] == '>'){
            aux[i][n-1] = 1;
            trilha(m,aux,i,n-1);
        }
        i++;
    }
    i=0;
    while(i<n){
        if(m[n-1][i] == 'V'){
            aux[n-1][i] = 1;
            trilha(m,aux,n-1,i);
        }
        i++;
    }
}
int main(){
    int n;
    int i, j;

    scanf("%d", &n);
    char v[maximo][maximo];

    int aux[maximo][maximo];
    for(i=0;i<n; i++){
        for(j=0; j<n; j++){
            aux[i][j] = 0;
        }
    }

    for(i=0; i<n; i++){
        getchar();
        for(j=0; j<n; j++){
            v[i][j] = getchar();
        }
    }
    varrer(v,aux,n);
    int total = 0;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(aux[i][j] == 1){
                total++;
            }
        }
    }
    printf("%d\n", (n*n)-total);
}