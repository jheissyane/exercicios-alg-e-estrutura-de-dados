#include <stdio.h>

//fatorial duplo
int fatorial(int n){
  if(n==1)
    return 1;
  else
    return n*fatorial(n-2);
}

int main(){
  int n;
  scanf("%d",&n);
  if(n%2==0){
    printf("%d\n", fatorial(n-1));
  }
  else{
  printf("%d\n",fatorial(n));
  }
  return 0;
}