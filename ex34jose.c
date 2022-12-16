#include <stdio.h>
#define MAX 100 * 100


int retornar_inverso(int numero1, int numero2){
int i, j;
i = ((numero1%10)*100)+(((numero1/10)%10)*10)+ numero1/100;
j = ((numero2%10)*100)+(((numero2/10)%10)*10)+ numero2/100;

if(j>i)
    printf("%d\n", j);
else
    printf("%d\n", i);
}

int main(){
    int teste, numero1, numero2;
    scanf("%d %d", &numero1, &numero2);


retornar_inverso(numero1, numero2);

 //  printf("%d\n", valorFinal);
   
   return 0;
}