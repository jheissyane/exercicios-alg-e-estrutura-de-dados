#include <stdio.h>
#include <stdlib.h>
#define sucesso 1
#define falha 0

typedef struct lista{
    int num;
    int check;
    struct lista* prox;
}lista;

//prototipos:

//aloca e inicializa primeiro elemento da lista
lista* criaLista();

//aloca se nao estiver alocado, e insere elemento 'n' na lista
void insereLista(lista *p,int n);

//exibe lista:
void printLista(lista *p);

//destroi lista, desalocando campos
void destroi(lista* p);

//analisa se elemento 'n' ja foi colocado na lista
int mark(lista* p);

//desmarca os elementos marcados
void desmark(lista* p);

//exibe os valores da lista em ordem inversa a chegada usando recursividade
void passList(lista* q, lista* p);

//cria lista com os 'n' menores valores da lista p
void makeListMenores(lista* result, lista* p, int n);

//cria lista com os 'n' maiores valores da lista p
void makeListMaiores(lista* result, lista* p, int n);

//funcoes:

lista* criaLista(){
    lista* p = (lista*)malloc(sizeof(lista));
    p->check = 0;
    p->num   = (int)   NULL;
    p->prox  = (lista*)NULL;
    return p;
}

void insereLista(lista* p,int n){
   if(!p->num){
        p->num = n;
        p->check = 0;
        p->prox = NULL;
        return;
   }
    else{
        lista* aux = p;
        while(aux->prox){
            aux = aux->prox;
        }
        aux->prox = (lista*)malloc(sizeof(lista));

        aux->prox->num  = n;
        aux->prox->check = 0;
        aux->prox->prox = NULL;
        return;

    }
}


void printLista(lista *p){
    lista * aux = p;
    while(aux->prox){
        printf("%d ", aux->num);
        aux = aux->prox;
    }
    printf("%d ", aux->num);
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

int mark(lista* p){
    if(p->check == 1){
        return sucesso;
    }
    else{
        return falha;
    }
}

void desmark(lista* p){
    lista* aux = p;
    while(aux->prox){
        aux->check = 0;
        aux = aux->prox;
    }
    aux->check = 0;
}

void passList(lista* q, lista* p){
    if(q->prox){
        passList(q->prox,p);
    }
    insereLista(p,q->num);
    //printf("%d ", lista->num);
}


void makeListMenores(lista* result, lista* p, int n){
    int menor;
    lista* menorP;
    lista* aux;
    while(n--){
        aux = p;
        menor = 999999999;
        while(aux->prox){
            if(aux->num < menor && mark(aux) == falha){
                menor = aux->num;
                menorP = aux;
            }
            aux = aux->prox;
        }
        if(aux->num < menor && mark(aux) == falha){
            menor = aux->num;
            menorP = aux;
        }
        menorP->check = 1;
        insereLista(result,menorP->num);
    }
}

void makeListMaiores(lista* result, lista* p, int n){
    int maior;
    lista* maiorP;
    lista* aux;
    while(n--){
        aux = p;
        maior = -999999999;
        while(aux->prox){
            if(aux->num > maior && mark(aux) == falha){
                maior = aux->num;
                maiorP = aux;
            }
            aux = aux->prox;
        }
        if(aux->num > maior && mark(aux) == falha){
            maior = aux->num;
            maiorP = aux;
        }
        maiorP->check = 1;
        insereLista(result,maiorP->num);
    }
}

int main(){
    int entrada;
    lista* p;
    lista* maiores;
    lista* menores;
    int numMaiores;
    int numMenores;
    int n;

    scanf("%d", &n);
    scanf("%d", &numMaiores);
    scanf("%d", &numMenores);
    p = criaLista();
    while(n--){
        scanf("%d", &entrada);
        insereLista(p,entrada);
    }
    maiores = criaLista();
    menores = criaLista();

    makeListMaiores(maiores,p,numMaiores);
    desmark(p);
    makeListMenores(menores,p,numMenores);

    passList(menores,maiores);
    printLista(maiores);
    printf("\n");
    //printLista(p);
    destroi(p);
    destroi(menores);
    destroi(maiores);
}