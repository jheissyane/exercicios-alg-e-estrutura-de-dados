#include <stdio.h>


void numeros(int num){
  if(num==-1)
    return;
  else{
    numeros(num-1);
    printf("%d ",num);
    }
  }
  
  int main(){
     int n;
     scanf("%d",&n);
     numeros(n);
      	  
      return(0);
    }
