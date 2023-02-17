#include <stdio.h>
#include <stdlib.h>
#define sucesso 1
#define falha 0

typedef struct lista{
    int num;
    struct lista* prox;
}lista;

//prototipos:

//aloca e inicializa primeiro elemento da lista
lista* criaLista();

//aloca se nao estiver alocado, e insere elemento 'n' na lista
lista* insereLista(lista *p,int n);

//analisa se elemento 'n' existe na lista
int repetido(lista* p, int n);

//exibe lista:
void printLista(lista *p);

//destroi lista, desalocando campos
void destroi(lista* p);

//funcoes:

lista* criaLista(){
    lista* p = (lista*)malloc(sizeof(lista));
    p->num   = (int)   NULL;
    p->prox  = (lista*)NULL;
    return p;
}

lista* insereLista(lista *p,int n){
   if(!p->num){
        p->num = n;
        p->prox = NULL;
        return p;
   }
    else{
        lista* aux;
        aux = (lista*)malloc(sizeof(lista));

        aux->num  = n;
        aux->prox = p;
        return(aux);

    }
}

int repetido(lista* p, int n){
    if(!p->num){
        return falha;
    }
    if(!p->prox){
        if(p->num){
            if(p->num == n){
                return sucesso;
            }
            else{
                return falha;
            }
        }
        else{
            return falha;
        }
    }
    lista* aux = p;
    while(aux->prox){
        if(aux->num == n){
            return sucesso;
        }
        aux = aux->prox;
    }
    if(aux->num == n){
        return sucesso;
    }
    return falha;
}


void printLista(lista *p){
    lista * aux = p;
    if(aux->num == NULL){
        return;
    }
    while(aux->prox){
        printf("%d ", aux->num);
        aux = aux->prox;
    }
    printf("%d ", aux->num);
    printf("\n");
}

void destroi(lista* p){
    lista* aux = p;
    lista* aux2;
    while(aux->prox){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(aux);
}

int main(){
    int entrada;
    lista* p;
    int n;

    scanf("%d", &n);
    while(n--){
        p = criaLista();
        while(scanf("%d", &entrada)){
            if(entrada <0){
                break;
            }
            if(repetido(p,entrada) == falha){
                p = insereLista(p,entrada);
            }
        }
        printLista(p);
        destroi(p);
    }
}
