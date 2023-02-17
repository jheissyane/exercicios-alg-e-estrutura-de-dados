#include <stdio.h>
#include <string.h>

int i=0;
int q=0;

void conta_digito (char* n, char k, int tamanho){
  if(i<tamanho){
    if(n[i]==k){
      q++;
    }
    i++;
    conta_digito(n, k, tamanho);
  }
}

  int main(){
    int t, tamanho;
    char k, n[32];
    scanf("%d", &t);
    getchar();
    scanf("%c", &k);
    getchar();
      for(t; t>0; t--){
        scanf("%s", &n);
        getchar();
        tamanho=strlen(n);
        conta_digito(n, k, tamanho);
        printf("%d", q);
        if(t==1){
          printf("\n");
        }
        else{
          printf(" ");
        }
        q=0; i=0;
      }
  }