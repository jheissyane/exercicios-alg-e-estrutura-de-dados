#include <stdio.h>
#define MAX 100 * 100


int overflow_(int numero1, char operador, int numero2, int overflow){
    int resultado;
    if(operador == '+')
        resultado = numero1 + numero2;
    else
        resultado = numero1 * numero2;

    if(resultado>overflow)
        printf("overflow\n");
    else
        printf("no overflow\n");
}

int main(){
    int overflow, numero1, numero2;
    char operador;
    scanf("%d", &overflow);
    scanf("%d %c %d", &numero1, &operador, &numero2);


    overflow_(numero1, operador, numero2, overflow);

 //  printf("%d\n", valorFinal);
   
   return 0;
}