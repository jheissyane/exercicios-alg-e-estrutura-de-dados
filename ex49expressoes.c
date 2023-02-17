#include <stdio.h>
#include <string.h>

  int main(){
    int t, i, j, tamanho, correta=1;
    char e[1000];
    scanf("%d", &t);
    getchar();
    for(t; t>0; t--){
      scanf("%[^\n]", &e);
      getchar();
      tamanho=strlen(e);
        for(i=0; i<tamanho; i++){
          achou:
          //"()"
          if(e[i]=='('){
            e[i]='0';
            if(i!=(tamanho-1)){
              for(j=(i+1); j<tamanho; j++){
                if(e[j]==')'){
                  e[j]='0';
                  goto achou;
                }
              }
              correta=0;
            }
            else{
              correta=0;
              break;
            }
          }
          else if(e[i]==')'){
            correta=0;
            break;
          }
          //"[]"
          else if(e[i]=='['){
            e[i]='0';
            if(i!=(tamanho-1)){
              for(j=(i+1); j<tamanho; j++){
                if(e[j]==']'){
                  e[j]='0';
                  goto achou;
                }
              }
              correta=0;
            }
            else{
              correta=0;
              break;
            }
          }
          else if(e[i]==']'){
            correta=0;
            break;
          }
          //"{}"
          else if(e[i]=='{'){
            e[i]='0';
            if(i!=(tamanho-1)){
              for(j=(i+1); j<tamanho; j++){
                if(e[j]=='}'){
                  e[j]='0';
                  goto achou;
                }
              }
              correta=0;
            }
            else{
              correta=0;
              break;
            }
          }
          else if(e[i]=='}'){
            correta=0;
            break;
          }
        }
        if(correta==1){
          printf("bem-formada\n");
        }
        else{
          printf("mal-formada\n");
        }
        correta=1;
    }
  }