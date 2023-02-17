#include <stdio.h>

void ordena (int* vet, int n){
  int i, i1, aux;
    for(i=0; i<n; i++){
      for(i1=i; i1<n; i1++){
        if(vet[i1]<vet[i]){
          aux=vet[i1];
          vet[i1]=vet[i];
          vet[i]=aux;
        }
      }
    }
}

typedef struct boys{
  int score;
  int resolvidos;
} boys;

  int main(){
    int t, duracao, q_problemas, tempo=0, i;
    boys john, jack, joseph;
    scanf("%d", &t);
      for(t; t>0; t--){
        john.score=0; john.resolvidos=0;
        jack.score=0; jack.resolvidos=0;
        joseph.score=0; joseph.resolvidos=0;
        scanf("%d %d", &duracao, &q_problemas);
        int problemas[q_problemas];
        for(i=0; i<q_problemas; i++){
          scanf("%d", &problemas[i]);
        }
        //john
        for(i=0; i<q_problemas; i++){
          if(tempo+problemas[i]<=duracao){
            tempo+=problemas[i];
            john.score+=tempo;
            john.resolvidos++;
          }
          else{
            break;
          }
        }
        tempo=0;
        //ordena
        ordena(problemas, q_problemas);
        //jack
        for(i=0; i<q_problemas; i++){
          if(tempo+problemas[i]<=duracao){
            tempo+=problemas[i];
            jack.score+=tempo;
            jack.resolvidos++;
          }
          else{
            break;
          }
        }
        tempo=0;
        //joseph
        for(i=(q_problemas-1); i>=0; i--){
          if(tempo+problemas[i]<=duracao){
            tempo+=problemas[i];
            joseph.score+=tempo;
            joseph.resolvidos++;
          }
          else{
            break;
          }
        }
        tempo=0;
        //ganhador
          //john
          if(john.resolvidos>=jack.resolvidos && john.resolvidos>=joseph.resolvidos){
            if(john.resolvidos==jack.resolvidos){
              if(john.score<jack.score){
                printf("John %d %d\n", john.resolvidos, john.score);
              }
              else{
                printf("Jack %d %d\n", jack.resolvidos, jack.score);
              }
            }
            else if(john.resolvidos==joseph.resolvidos){
              if(john.score<joseph.score){
                printf("John %d %d\n", john.resolvidos, john.score);
              }
              else{
                printf("Joseph %d %d\n", joseph.resolvidos, joseph.score);
              }
            }
            else{
              printf("John %d %d\n", john.resolvidos, john.score);
            }
          }
          //jack
          else if(jack.resolvidos>=john.resolvidos && jack.resolvidos>=joseph.resolvidos){
            if(jack.resolvidos==john.resolvidos){
              if(jack.score<john.score){
                printf("Jack %d %d\n", jack.resolvidos, jack.score);
              }
              else{
                printf("John %d %d\n", john.resolvidos, john.score);
              }
            }
            else if(jack.resolvidos==joseph.resolvidos){
              if(jack.score<joseph.score){
                printf("Jack %d %d\n", jack.resolvidos, jack.score);
              }
              else{
                printf("Joseph %d %d\n", joseph.resolvidos, joseph.score);
              }
            }
            else{
              printf("Jack %d %d\n", jack.resolvidos, jack.score);
            }
          }
          //joseph
          else if(joseph.resolvidos>=john.resolvidos && joseph.resolvidos>=jack.resolvidos){
            if(joseph.resolvidos==john.resolvidos){
              if(joseph.score<john.score){
                printf("Joseph %d %d\n", joseph.resolvidos, joseph.score);
              }
              else{
                printf("John %d %d\n", john.resolvidos, john.score);
              }
            }
            else if(joseph.resolvidos==jack.resolvidos){
              if(joseph.score<jack.score){
                printf("Joseph %d %d\n", joseph.resolvidos, joseph.score);
              }
              else{
                printf("Jack %d %d\n", jack.resolvidos, jack.score);
              }
            }
            else{
              printf("Joseph %d %d\n", joseph.resolvidos, joseph.score);
            }
          }
      }
  }