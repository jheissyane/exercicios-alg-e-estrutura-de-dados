#include <stdio.h>
#include <string.h>

  int main(){
    int q, n=0, t, i;
    char s[10000];
    scanf("%d", &q);
    getchar();
        for(q; q>0; q--){
          scanf("%[^\n]", &s);
          getchar();
            t=strlen(s);
              for(i=0; i<t; i++){
                if(s[i]=='A' || s[i]=='a' || s[i]=='E' || s[i]=='e' || s[i]=='I' || s[i]=='i' || s[i]=='O' || s[i]=='o' || s[i]=='U' || s[i]=='u'){
                  n++;
                }
              }
              printf("%d\n", n);
              n=0;
        }
  }