#include <stdio.h>
#include <string.h>

typedef struct frases{
  char frase[1000];
} frases;

  int main(){
    int i, j, tamanho, q=0, asc=0, desc=0;
    char aux[1000];
    frases frases[100];
      while(asc==0 && desc==0){
        scanf("%[^\n]", &frases[q].frase);
        getchar();
        if(frases[q].frase[0]=='A' && frases[q].frase[1]=='S' && frases[q].frase[2]=='C'){
          asc=1;
        }
        else if(frases[q].frase[0]=='D' && frases[q].frase[1]=='E' && frases[q].frase[2]=='S' && frases[q].frase[3]=='C'){
          desc=1;
        }
        q++;
      }
      q--;
      //ordena
      if(asc==1){
        for(i=0; i<q; i++){
          for(j=i; j<q; j++){
            if(strcmp(frases[j].frase, frases[i].frase)<0){
              strcpy(aux, frases[j].frase);
              strcpy(frases[j].frase, frases[i].frase);
              strcpy(frases[i].frase, aux);
            }
          }
        }
      }
      else{
        for(i=0; i<q; i++){
          for(j=i; j<q; j++){
            if(strcmp(frases[j].frase, frases[i].frase)>0){
              strcpy(aux, frases[j].frase);
              strcpy(frases[j].frase, frases[i].frase);
              strcpy(frases[i].frase, aux);
            }
          }
        }
      }
      for(i=0; i<q; i++){
        printf("%s\n", frases[i].frase);
      }
  }