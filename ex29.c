#include <stdio.h>

/**
 * inf/UFG - AED1: lista de exercicios de recursividade - 9
 * o programa a seguir usa a recursividade para exibir a
 * resolucao de uma torre de hanoi,passo a passos com base
 * no numero 'n' de blocos:
 * D => destino
 * O => origem
 * A => auxiliar
 **/
void hanoi(int n, char a,char b,char c){
    if(n == 1){
        printf("(%c,%c)\n", a, b);
    }
    else{
        hanoi(n-1,a,c,b);
        printf("(%c,%c)\n", a, b);
        hanoi(n-1,c,b,a);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    hanoi(n,'O','D','A');
}