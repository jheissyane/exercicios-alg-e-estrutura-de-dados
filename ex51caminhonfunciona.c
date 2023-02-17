#include <stdio.h>
#include <string.h>
#include <uchar.h>

#define sucesso 1
#define falha 0


typedef struct lista{
    char curva[10];
    char rua[10];
    struct lista * prox;
    struct lista * ant;
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

void destroi(lista * d){
    elemento * aux = d->prim;
    int i;
    for(i=0; i< d->quant; i++){
        free(aux);
        aux = aux->prox;
    }
    free(d);
}

int insereLista_1(lista *lista,char* n){
    if(lista->quant == 0){
        lista->prim = (elemento*)malloc(sizeof(elemento));
        lista->ult  = lista->prim;
        strcpy(lista->prim->curva,n);
        lista->prim->prox = NULL;
        lista->prim->ant  = NULL;
        lista->quant      = 1;
        return sucesso;
    }
    else{
        elemento * aux;
        aux = lista->ult;

        aux->prox  = (elemento*)malloc(sizeof(elemento));
        lista->ult = aux->prox;
        strcpy(aux->prox->curva,n);
        aux->prox->prox = NULL;
        aux->prox->ant  = aux;
        (lista->quant)++;
        return sucesso;
    }
}

int insereLista_2(lista *lista,char* n){
    if(lista->quant == 0){
        lista->prim = (elemento*)malloc(sizeof(elemento));
        lista->ult  = lista->prim;
        strcpy(lista->prim->rua,n);
        lista->prim->prox = NULL;
        lista->prim->ant  = NULL;
        lista->quant      = 1;
        return sucesso;
    }
    else{
        elemento * aux;
        aux = lista->ult;

        aux->prox  = (elemento*)malloc(sizeof(elemento));
        lista->ult = aux->prox;
        strcpy(aux->prox->rua,n);
        aux->prox->prox = NULL;
        aux->prox->ant  = aux;
        (lista->quant)++;
        return sucesso;
    }
}

void printLista(lista * lista){
    elemento * aux = lista->ult;

    printf("(%s)", aux->curva);
    char   buffer[10] = "ESQUERDA\n";

    int i;
    for(i=0; i < (lista->quant)-1; i++){
        if(strcmp(buffer,"ESQUERDA") == 0){
            printf("DIREITA\n");
        }
        else{
            printf("ESQUERDA\n");
        }
        aux = aux->ant;
        printf("%s", aux->rua);
        printf("\n");
    }
    if(strcmp(buffer,"ESQUERDA") == 0){
            printf("DIREITA\n");
        }
        else{
            printf("ESQUERDA\n");
        }
    printf("CASA\n");
}

void printInverso(lista * lista){
    elemento * aux = lista->ult;
    int i;
    for(i=0; i< lista->quant; i++){
        printf("%s-> ", aux->curva);
        aux = aux->ant;
    }
}

int insereAntes(lista * lista, int n){
    if(lista->quant == 0){
        lista->prim = (elemento*)malloc(sizeof(elemento));
        strcpy(lista->prim->curva,n);

        lista->prim->prox = NULL;
        lista->prim->ant  = NULL;
        lista->quant      = 1;
        return sucesso;
    }
    else{
        elemento* aux;
        elemento* novo;
        aux = lista->prim;
        novo = (elemento*)malloc(sizeof(elemento));

        strcpy(novo->curva,n);
        novo->prox  = aux;
        aux->ant    = novo;
        lista->prim = novo;
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
        if(strcmp(lista->prim->curva,n)== 0){
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
                if(strcmp(aux->curva,n) == 0){
                    excluso = aux;//isola elemento a ser excluido
                    aux2->prox = aux->prox;//liga o detras com o seguindo ao da frente
                    free(excluso);
                    lista->quant--;
                    return sucesso;
                }
                aux2 = aux2->prox;
                aux  = aux->prox;
            }
            if(strcmp(aux->prox->curva,n) == 0){
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
    char escola[20] = "ESCOLA";
    char buffer[20];
    char buffer2[20];
    elemento* aux;
    int i=0;

    int n;
    scanf("%d", &n);
    getchar();
    while(n--){
        buffer[0] = '\0';
        buffer2[0]= '\0';
        while(strcmp(buffer2,escola) != 0){
            gets(buffer);
            gets(buffer2);

            printf("%s", buffer);
            printf("%s", buffer2);

            if(lista_1.quant == 0){
                lista_1.prim = (elemento*)malloc(sizeof(elemento));

                lista_1.ult  = lista_1.prim;
                strcpy(lista_1.prim->curva,n);

                lista_1.prim->prox = NULL;
                lista_1.prim->ant  = NULL;
                lista_1.quant      = 1;
            }
            else{
                aux = lista_1.ult;
                aux->prox  = (elemento*)malloc(sizeof(elemento));

                lista_1.ult = aux->prox;
                strcpy(aux->prox->curva,n);

                aux->prox->prox = NULL;
                aux->prox->ant  = aux;
                lista_1.quant++;
            }
            i++;
        }
        escola[20] = "ESQUERDA";
        aux = lista_1.ult;
        while(i--){
            if(strcmp("ESQUERDA",aux->curva) == 0){
                printf("DIREITA\n");
            }
            else{
                printf("ESQUERDA\n");
            }
            aux = aux->ant;
            if(strcmp(aux->rua,"ESCOLA") != 0){
                printf("%s", aux->rua);
            }
            printf("%s", aux->rua);
            printf("\n");
        }
        printf("casa\n");
        destroi(&lista_1);
    }
}