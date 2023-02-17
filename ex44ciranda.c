#include <stdio.h>
#include <string.h>

typedef struct criancas{
  char nome[31];
  int valor;
}criancas;

  int main(){
    int n, i, sobrando, ultimo_numero, pos=0;
    scanf("%d", &n);
    criancas crianca[n];
    int q_criancas=n;
      for(i=0; i<n; i++){
        scanf("%s %d", &crianca[i].nome, &crianca[i].valor);
      }
      ultimo_numero=crianca[0].valor;
      while(q_criancas>1){
        //impar
        if(ultimo_numero%2!=0){
          if(pos==(n-1)){
            pos=-1;
          }
          for(i=(pos+1); i<n; i++){
            if(crianca[i].valor!=0){
              ultimo_numero--;
              if(ultimo_numero==0){
                ultimo_numero=crianca[i].valor;
                crianca[i].valor=0;
                q_criancas--;
                pos=i;
                break;
              }
            }
            if(i==(n-1)){
              i=0;
            }
          }
        }
        //par
        else{
          if(pos==0){
            pos=n;
          }
          for(i=(pos-1); i>=0; i--){
            if(crianca[i].valor!=0){
              ultimo_numero--;
              if(ultimo_numero==0){
                ultimo_numero=crianca[i].valor;
                crianca[i].valor=0;
                q_criancas--;
                pos=i;
                break;
              }
            }
            if(i==0){
              i=n;
            }
          }
        }
      }
      for(i=0; i<n; i++){
        if(crianca[i].valor!=0){
          printf("%s\n", crianca[i].nome);
        }
      }
  }