#include <stdio.h>

void makeMoldura(int i, int j, int maximo,int x, int y){
    if(i == maximo && j == maximo){
        return;
    }

}

int main(){
    int n;
    scanf("%d", &n);
    int matriz[n][n];
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    makeMoldura(matriz,0,0,n,x,y);
}