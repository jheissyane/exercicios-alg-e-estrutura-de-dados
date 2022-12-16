#include <stdio.h>
#define MAX 100 * 100


int retornar_ano(int numero){
    int anosBi, ano=1986;
if(numero>ano){
    anosBi = (numero-ano)/1460;
    while(ano<numero){
        ano += 76;
    }
    printf("%d\n", ano + anosBi);
} else {
    anosBi = (ano-numero)/1460;
    while(ano>numero){
        ano -= 76;
    }
    ano += 76;
  //  printf("%d\n", anosBi);
    printf("%d\n", ano - anosBi);
}
}

int main(){
    int teste, numero;
    scanf("%d", &numero);


retornar_ano(numero);

 //  printf("%d\n", valorFinal);
   
   return 0;
}