#include <stdio.h>
#define sucesso 1
#define falha 0


typedef struct lista{
    char * nome;
    int num;
    char * numero;
    struct lista * prox;
}elemento;

typedef struct desc{
    elemento * prim;
    elemento * ult;
    int quant;
}lista;

int criaLista(lista *p){
    p->prim  = NULL;
    p->ult   = NULL;
    p->quant = 0;

    return sucesso;
}

int insereLista(lista *lista,int n,char * buffer){
    if(lista->quant == 0){
        lista->prim = (elemento*)malloc(sizeof(elemento));
        lista->ult  = lista->prim;
        lista->prim->num   = n;
        lista->prim->numero = (char*)malloc((strlen(buffer)+1)*sizeof(char));
        strcpy(lista->prim->numero,buffer);
        lista->prim->prox  = NULL;
        lista->quant       = 1;
        return sucesso;
    }
    else{
        elemento * aux;
        aux = lista->ult;

        aux->prox  = (elemento*)malloc(sizeof(elemento));
        lista->ult = aux->prox;

        aux->prox->num  = n;
        aux->prox->numero = (char*)malloc((strlen(buffer)+1)*sizeof(char));
        aux->prox->prox = NULL;
        (lista->quant)++;
        return sucesso;
    }
}

void printLista(lista *lista){
    elemento * aux = lista->prim;
    int i;
    for(i=0; i< lista->quant; i++){
        printf("%d-> ", aux->num);
        aux = aux->prox;
    }
    printf("\n");
}

void upper(lista * C,char * buffer){
    elemento * aux;
    aux = C->prim;
    int i=1;
    while(i < C->quant){
        if(strcmp(aux->numero,buffer))
        aux = aux->prox;
    }
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
                lista->ult = aux;
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

    char op;
    char buffer[20];

    while(op != 'F'){
        op = getchar();
        getchar();
        gets(buffer);

        if(op == 'I'){
            int num;
            char * ligacoes[20];

            getchar();
            gets(ligacoes);
            scanf("%d", &num);

            insereLista(&lista_1,num,ligacoes);
        }
        if(op == 'R'){
            excluiElemento(&lista_1,buffer);
        }
        if(op == 'L'){
            upper(lista_1,buffer);
        }
        if(op == 'F'){
            break;
        }
        getchar();
    }
    printLista(&lista_1);
}

