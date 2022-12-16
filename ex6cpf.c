    #include <stdio.h>

 void verificar_cpf(int *cpf){
    int verificador1, verificador2;

    verificador1 = (cpf[0] + cpf[1] * 2 + cpf[2] * 3 +  cpf[3] * 4 + cpf[4] * 5 + cpf[5] * 6 + cpf[6] * 7 + cpf[7] * 8 + cpf[8] * 9)%11;
    verificador2 = (cpf[0] * 9 + cpf[1] * 8 + cpf[2] * 7 +  cpf[3] * 6 + cpf[4] * 5 + cpf[5] * 4 + cpf[6] * 3 + cpf[7] * 2 + cpf[8])%11;
 
    if(verificador1 == cpf[9] && verificador2 == cpf[10])
        printf("CPF valido\n");
    else
        printf("CPF invalido\n");
 
 }

    int main(){
        int teste, i, vetor[11];

        scanf("%d", &teste);


    while(teste--){
        for(i=0;i<11;i++){
            scanf("%d", &vetor[i]);
        }
        verificar_cpf(vetor);
    }


        return 0;
    }