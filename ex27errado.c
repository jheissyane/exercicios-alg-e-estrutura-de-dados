//Feito por André Luiz Teixeira Kohlrausch


/*
 * O Banco Inteligente
 * 
 * Caixas automáticos (ATMs – Automated Teller Machines) nos bancos são uma ótima invenção mas, às
 * vezes, precisamos de dinheiro trocado e a máquina nos entrega notas de R$100, 00. Outras vezes, desejamos
 * sacar um valor um pouco maior e, por questão de segurança, gostaríamos de receber todo o valor em notas
 * de R$100, 00, mas a máquina nos entrega um monte de notas de R$20, 00.
 * 
 */
#include<stdio.h>

#define NTS 6

void preenche_notas(int * notas);

long int verifica (int * notas,long int valor_saque, int possibilidades);

int main(){
    
    int notas[NTS];
    long int valor_saque,resultado;
    
    scanf("%d",&saque);
    
    preenche_notas(notas); 
    
    resultado = verifica(notas,valor_saque,0);
    
    printf("%d\n",resultado);
    
   
}


long int verifica (int * notas,long int valor_saque, int possibilidades){
    
   //FALTANTE
    
    
    
}

void preenche_notas(int * notas){
    
    int contador;
    
    for(contador = 0; contador < NTS; contador++;){
    
        scanf("%d",&notas[contador]);
    
    }
}