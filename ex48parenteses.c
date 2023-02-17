#include <stdio.h>
#include <stdlib.h>

#define sucesso 1
#define falha 0

typedef struct parentesis{
    char parentese;
    struct parentesis* prox;
}elemento;

typedef struct fila{
    elemento* fila;
    int quant;
}lista;

void criaLista(lista *p){
    p->quant = 0;
    p->fila  = NULL;
}

int inserepilha(lista * lista, char n){
    if(lista->quant == 0){
        lista->fila             = (elemento*)malloc(sizeof(elemento));
        lista->fila->parentese  = n;
        lista->fila->prox       = NULL;
        lista->quant            = 1;
        return sucesso;
    }
    else{
        elemento* aux;
        elemento* novo;
        aux = lista->fila;
        novo = (elemento*)malloc(sizeof(elemento));

        novo->parentese   = n;
        novo->prox  = aux;
        lista->fila = novo;
        lista->quant++;
        return sucesso;
    }
}

int excluiElemento(lista* lista, int n){
    if(lista->quant == 0){
        printf("nenhum elemento!\n");
        return falha;
    }
    else{
        if(n == 1){
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
                if(n == i+1){
                    excluso = aux;//isola elemento a ser excluido
                    aux2->prox = aux->prox;//liga o detras com o seguindo ao da frente
                    free(excluso);
                    lista->quant--;
                    return sucesso;
                }
                aux2 = aux2->prox;
                aux  = aux->prox;
            }
            return falha;
        }
    }
}

int analise(lista *p){
    int i;
    int j;
    int confirm;

    elemento *aux;
    elemento *aux2;
    aux = p->fila;

    for(i=0; i< p->quant; i++){
        //printf("%di", i);
        aux2 = aux;
        confirm = 0;
        for(j=i; j < p->quant; j++){
            if(aux->parentese == ')' && aux2->parentese == '('){
                confirm = 1;
                aux->parentese  = '*';
                aux2->parentese = '*';
            }
            //printf("%dj", j);
            aux2 = aux2->prox;
        }
        aux = aux->prox;
        //printf("\n");
    }

    aux = p->fila;
    for(i=0; i < p->quant; i++){
        if(aux->parentese == ')'){
            return falha;
        }
        aux = aux->prox;
    }
    //printf("\n");
    return sucesso;
}

int main(){
    char n;
    lista pilha;
    criaLista(&pilha);
    while(n != '\n'){
        n = getchar();
        if(n == '(' || n == ')'){
            inserepilha(&pilha,n);
        }
    }
    if(analise(&pilha) == sucesso){
        printf("correta\n");
    }
    else{
        printf("incorreta\n");
    }
}