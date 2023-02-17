#include <stdio.h>
#define sucesso 1
#define falha 0


typedef struct lista{
    int num;
    struct lista * prox;
}elemento;

typedef struct desc{
    elemento * prim;
    int quant;
}lista;

int criaLista(lista *p){
    p->prim  = NULL;
    p->quant = 0;

    return sucesso;
}

int insereLista(lista *lista,int n){
    if(lista->quant == 0){
        lista->prim = (elemento*)malloc(sizeof(elemento));
        lista->prim->num  = n;
        lista->prim->prox = NULL;
        lista->quant      = 1;
        return sucesso;
    }
    else{
        elemento * aux = lista->prim;
        int i = 1;
        while(i < lista->quant){
            aux = aux->prox;
            i++;
        }

        aux->prox  = (elemento*)malloc(sizeof(elemento));

        aux->prox->num  = n;
        aux->prox->prox = NULL;
        (lista->quant)++;
        return sucesso;
    }
}

void printLista(lista *lista){
    elemento * aux = lista->prim;
    int i;
    if(lista->quant == 0){
        printf("lista vazia\n");
        return;
    }
    printf("lista ");
    for(i=0; i< lista->quant; i++){
        printf("%d ", aux->num);
        aux = aux->prox;
    }
    printf("\n");
}

void insertList(lista * C,int p, int e){
    elemento * aux;
    aux = C->prim;
    while(aux->num != e){
        aux = aux->prox;
    }
    if(aux->prox){
        elemento * aux2 = aux->prox;
        aux->prox = (elemento*)malloc(sizeof(elemento));
        aux->prox->num  = p;
        aux->prox->prox = aux2;
        C->quant++;
    }
    else{
        aux->prox = (elemento*)malloc(sizeof(elemento));
        C->quant++;
    }
}

int insereAntes(lista * lista, int n){
    if(lista->quant == 0){
        lista->prim = (elemento*)malloc(sizeof(elemento));
        lista->prim->num  = n;
        lista->prim->prox = NULL;
        lista->quant      = 1;
        return sucesso;
    }
    else{
        elemento* aux;
        elemento* novo;
        aux = lista->prim;
        novo = (elemento*)malloc(sizeof(elemento));

        novo->num   = n;
        novo->prox  = aux;
        lista->prim = novo;
        lista->quant++;
        return sucesso;
    }
}
int cont(lista* C, int a){
    elemento *aux = C->prim;
    int i;
    for(i=0; i < C->quant; i++){
        if(aux->num == a){
            return i+1;
        }
        aux = aux->prox;
    }
    return 0;
}

int numElements(lista * C,int a, int b){
    if(cont(C,a)- cont(C,b) <0){
        return cont(C,b)-cont(C,a);
    }
    return cont(C,a)-cont(C,b);
}

int excluiElemento(lista* lista, int n){
    if(lista->quant == 0){
        printf("nenhum elemento!\n");
        return falha;
    }
    else{
        if(lista->prim->num == n){
            elemento* aux = lista->prim;
            lista->prim = aux->prox;
            lista->quant--;
            free(aux);
            return sucesso;
        }
        else{
            elemento* aux  = lista->prim->prox;//um a frente
            elemento* aux2 = lista->prim;//um atras
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
            if(aux->prox->num == n){
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

int main(){
    lista lista_1;
    criaLista(&lista_1);
    int n;
    scanf("%d", &n);
    int i;
    int numero;
    //printLista(&lista_1);
    for(i=0; i<n; i++){
        scanf("%d", &numero);
        insereLista(&lista_1,numero);
        //printLista(&lista_1);
    }
    char op;
    op = ' ';
    while(op){
        op = getchar();
        if(op == 'I'){
            int p;
            int e;
            scanf("%d %d", &p, &e);
            insertList(&lista_1,p,e);//insere p depois de e
            printf("inserido %d\n", p);
        }
        if(op == 'R'){
            int p;
            scanf("%d", &p);
            excluiElemento(&lista_1,p);
            printf("removido %d\n", p);
        }
        if(op == 'C'){
            int a;
            int b;
            scanf("%d %d", &a, &b);
            printf("quantidade %d\n", numElements(&lista_1,a,b)-1);
        }
        if(op == 'M'){
            printLista(&lista_1);
        }
        if(op == 'F'){
            printf("fim\n");
            break;
        }
    }
}