#include <stdio.h>

long int fib(long int n){
   if(n==0)
     return(0);
    else if(n==1)
           return(1);
          else return(fib(n-1)+fib(n-2));
  }
  
  int main() {
    long int n, i;
    scanf("%ld", &n);
    for(i=0; i<n;i++)
       printf("%ld ",fib(i));
     printf("%ld\n",fib(i)); 
  return 0;
  }