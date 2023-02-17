#include <stdio.h>

int mdc(int n, int d){
  int i, mdc, maior;
  maior= n>d ? n : d;
    for(i=1; i<maior; i++){
      if(n%i==0 && d%i==0){
        mdc=i;
      }
    }
    return mdc;
}

  int main(){
    int k, d, n, cont=2;
    scanf("%d", &k);
    while(k!=0){
      if(k==1){
        printf("0/1\n");
      }
      else if(k==2){
        printf("1/1\n");
      }
      else{
        for(d=1; d>=0; d++){
          for(n=1; n<d; n++){
            if(mdc(n, d)==1){
              cont++;
              if(cont==k){
                printf("%d/%d\n", n, d);
                goto sair;
              }
            }
          }
        }
      }
      sair:
      cont=2;
      scanf("%d", &k);
    }
  }