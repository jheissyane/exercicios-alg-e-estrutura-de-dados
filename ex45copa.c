#include <stdio.h>
#include <stdlib.h>

#define sucesso 1
#define falha 0


typedef struct lista{
    int num;
    struct lista * prox;
}elemento;

typedef struct desc{
    elemento* fila;
    int quant;
}lista;

int criaLista(lista *p){
    p->fila = NULL;
    p->quant = 0;

    return sucesso;
}

int insereLista(lista *lista,int n){
    if(lista->quant == 0){//insere o primeiro
        lista->fila = (elemento*)malloc(sizeof(elemento));
        lista->fila->num  = n;
        lista->fila->prox = NULL;
        lista->quant      = 1;
        return sucesso;
    }
    else{
        elemento * aux;
        aux = lista->fila;
        while(aux->prox){//percorre a lista
            aux = aux->prox;
        }
        aux->prox = (elemento*)malloc(sizeof(elemento));
        aux = aux->prox;//ir pra elemento alocado

        aux->num = n;
        aux->prox = NULL;
        (lista->quant)++;
        return sucesso;
    }
}

int excluiElemento(lista* lista, int n){
    if(lista->quant == 0){
        return falha;
    }
    else{
        if(lista->fila->num == n){
            elemento* aux = lista->fila;
            lista->fila = aux->prox;
            lista->quant--;
            free(aux);
            return sucesso;
        }
        else{
            elemento* aux  = lista->fila->prox;//um a frente
            elemento* aux2 = lista->fila;//um atras
            elemento* excluso;//elemento a ser excluido pelo free()
            int i;

            for(i=0; i<(lista->quant)-1; i++){
                if(aux->num == n){
                    excluso = aux;//isola elemento a ser excluido
                    aux2->prox = aux->prox;//liga o detras com o seguindo ao da frente
                    free(excluso);
                    lista->quant--;
                    return sucesso;
                }
                aux2 = aux2->prox;
                aux  = aux->prox;
            }
            if(aux->prox->num == n){//verifica ultimo
                free(aux->prox);
                aux->prox = NULL;
                lista->quant--;
                return sucesso;
            }
            else{
                return falha;
            }
        }
    }
}

void printLista(lista *lista){
    elemento * aux = lista->fila;
    int i;
    for(i=0; i< lista->quant; i++){
        printf("%d ", aux->num);
        aux = aux->prox;
    }
    printf("\n");
}

int main(){
    lista nova;
    criaLista(&nova);

    int n;
    int i=0;
    int element;
    scanf("%d", &n);

    while(i<n){
        scanf("%d", &element);
        insereLista(&nova,element);
        i++;
    }
    i = 0;

    int m;
    scanf("%d", &m);
    int sairam;
    while(i<m){
        scanf("%d", &sairam);
        excluiElemento(&nova,sairam);
        i++;
    }
    printLista(&nova);
}