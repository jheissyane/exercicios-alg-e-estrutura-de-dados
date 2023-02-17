#include <stdio.h>
#include <stdlib.h>
#define sucesso 1
#define falha 0

typedef struct Lista{
    int cor;
    struct Lista *prox;
}elemento;

typedef struct Descritor{
    elemento *first;
    int quant;
}lista;

void zeraVetor(int *v,int n){
    while(n--){
        v[n] = 0;
    }
}

int criaLista(lista *p){
    p->first = NULL;
    p->quant = 0;

    return sucesso;
}

int insereLista(lista *lista,int n){
    if(lista->quant == 0){
        lista->first = (elemento*)malloc(sizeof(elemento));
        lista->first->cor  = n;
        lista->first->prox = NULL;
        lista->quant      = 1;
        return sucesso;
    }
    else{
        elemento * aux;
        aux = lista->first;
        while(aux->prox){
            aux = aux->prox;
        }
        aux->prox = (elemento*)malloc(sizeof(elemento));
        aux = aux->prox;

        aux->cor = n;
        aux->prox = NULL;
        (lista->quant)++;
        return sucesso;
    }
}

void contagem(lista C,int* quant,int inicio, int fin){
    elemento *aux;
    aux = C.first;
    int i=1;
    while(i<inicio){//caminha ate o ponto de inicio de contagem
        aux = aux->prox;
        i++;
    }
    while(i<=fin){
        quant[(aux->cor)-1]++;
        aux = aux->prox;
        i++;
    }
}

void destroi(lista *C){
    elemento *aux = C->first;
    elemento *aux2;
    while(C->quant--){
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(C);
}

int main(){
    int T;
    int n, c;
    int a, b;
    int m;
    int anao;
    int i;
    int confirm;

    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n, &c);
        //vetor para uso do indice como base de quantidade de cada cor
        int Ntoucas[c];
        lista anoes;
        //lista usada para simular a fila de anoes
        criaLista(&anoes);




        while(n--){
            scanf("%d", &anao);
            insereLista(&anoes,anao);
        }
        //zera vetor pra adicao
        zeraVetor(Ntoucas,c);




        scanf("%d", &m);
        while(m--){
            int maior = -999999;
            int indice;
            scanf("%d %d", &a, &b);
            contagem(anoes,Ntoucas,a,b);
            confirm = 0;
            for(i=0; i < c; i++){
                if(Ntoucas[i] > maior){
                    maior = Ntoucas[i];
                    indice = i;
                    confirm = 1;
                }
                else{
                    if(Ntoucas[i] == maior){
                        confirm = 0;
                    }
                }
            }
            if(confirm == 0){
                printf("feia\n");
            }
            else{
                printf("bonita %d\n", indice+1);
            }
            indice = 0;
            zeraVetor(Ntoucas,c);
        }
        destroi(&anoes);
    }
}