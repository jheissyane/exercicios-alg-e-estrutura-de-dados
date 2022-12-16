#include <stdio.h>
#define MAX 100 * 100


int testar_palindromo(int numero){
int i;

i = ((numero%10)*1000)+(((numero/10)%10)*100)+ (((numero/100)%10)*10)+ numero/1000;

    if(i==numero)
        printf("yes");
    else
        printf("no");
}

int main(){
    int teste, numero;
    scanf("%d", &teste);

    while(teste--){
        scanf("%d", &numero);
        
        testar_palindromo(numero);

        if(teste!=0)
            printf(" ");
    }




 //  printf("%d\n", valorFinal);
   
   return 0;
}