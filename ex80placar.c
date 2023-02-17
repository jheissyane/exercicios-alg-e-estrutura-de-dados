#include <stdio.h>
#include <string.h>

typedef struct alunos{
  char nome[21];
  int prob_res;
} alunos;

  int main(){
    int i, i1, aux, n;
    char aux_char[21];
    scanf("%d", &n);
    alunos aluno[n];
      for(i=0; i<n; i++){
        scanf("%s %d", &aluno[i].nome, &aluno[i].prob_res);

      }
      //ordena os alunos
        //por nota
        for(i=0; i<n; i++){
          for(i1=i; i1<n; i1++){
            if(aluno[i1].prob_res>aluno[i].prob_res){
              aux=aluno[i1].prob_res;
              aluno[i1].prob_res=aluno[i].prob_res;
              aluno[i].prob_res=aux;
                strcpy(aux_char, aluno[i1].nome);
                strcpy(aluno[i1].nome, aluno[i].nome);
                strcpy(aluno[i].nome, aux_char);
            }
          }
        }
        //por ordem alfabética
        for(i=0; i<n; i++){
          for(i1=i; i1<n; i1++){
            if(aluno[i].prob_res==aluno[i1].prob_res){
              if(strcmp(aluno[i].nome, aluno[i1].nome)>0){
                strcpy(aux_char, aluno[i1].nome);
                strcpy(aluno[i1].nome, aluno[i].nome);
                strcpy(aluno[i].nome, aux_char);
              }
            }
          }
        }
      for(i=0; i<n; i++){
        if(i==(n-1)){
          printf("%s %d #reprovado(a)\n", aluno[i].nome, aluno[i].prob_res);
        }
        else{
          printf("%s %d\n", aluno[i].nome, aluno[i].prob_res);
        }
      }
  }