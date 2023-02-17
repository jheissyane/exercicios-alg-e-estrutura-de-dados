#include <stdio.h>

  int main(){
    int t, n, c, m, ma, mb, q=0, i, j, k, bonita=0, kf, metade;
    scanf("%d", &t);
    for(t; t>0; t--){
      scanf("%d %d", &n, &c);
      int cores[n];
      for(i=0; i<n; i++){
        scanf("%d", &cores[i]);
      }
      scanf("%d", &m);
      for(i=0; i<m; i++){
        scanf("%d %d", &ma, &mb);
        ma--; mb--;
        metade=((mb-ma)+1)/2;
        for(k=1; k<=c; k++){
          for(j=ma; j<=mb; j++){
            if(cores[j]==k){
              q++;
            }
            if(q>metade){
              kf=k;
              bonita=1;
              break;
            }
          }
          q=0;
          if(bonita==1){
            printf("bonita %d\n", k);
            break;
          }
        }
        if(bonita==0){
          printf("feia\n");
        }
        bonita=0;
      }
    }
  }