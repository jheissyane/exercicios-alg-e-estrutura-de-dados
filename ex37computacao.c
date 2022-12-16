#include <stdio.h>
#define MAX 100 * 100


int converter_base(int numero){
int i;

if(numero!=0){

converter_base(numero/4);

if(numero%4==0)
    printf("A");
else if(numero%4==1)
    printf("C");
else if(numero%4==2)
    printf("G");
else if(numero%4==3)
    printf("T");

}


}

int main(){
    int teste, numero;
    scanf("%d", &teste);

    while(teste--){
        scanf("%d", &numero);
        
        converter_base(numero);

        printf("\n");
    }
   
   return 0;
}