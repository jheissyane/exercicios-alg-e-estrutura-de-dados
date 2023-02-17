#include <stdio.h>

void fibonacci(long int n, long int i, long int a, long int b){
    if(i==n){
        printf("%ld\n", a);
        return;
    }
    else{
        //printf("%d ", a);
        fibonacci(n, i+1, b, a+b);
    }
}

int main(){
    long int n, i, fib;
    scanf("%d", &n);{
        for (i=0; i<n; i++){
            scanf("%ld", &fib);
            fibonacci(fib, 0, 0, 1);
        }
    }
    
    return 0;
}