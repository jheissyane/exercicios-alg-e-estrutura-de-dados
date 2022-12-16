#include <stdio.h>
#include <math.h>

  int main(){
    int n, i;
    double area, r1, r2, a, b, c, p, b1, b2, h, pi=3.14159265;
    char tipo;
    scanf("%d", &n);
      for(i=0; i<(n*2); i++){
        scanf("%c ", &tipo);
          if(tipo=='C'){
            scanf("%lf", &r1);
            area=pi*r1*r1;
            printf("%.0lf\n", round(area));
          }
          else if(tipo=='E'){
            scanf("%lf %lf", &r1, &r2);
            area=pi*r1*r2;
            printf("%.0lf\n", round(area));
          }
          else if(tipo=='T'){
            scanf("%lf %lf %lf", &a, &b, &c);
            p=(a+b+c)/2;
            area=sqrt(p*(p-a)*(p-b)*(p-c));
            printf("%.0lf\n", round(area));
          }
          else if(tipo=='Z'){
            scanf("%lf %lf %lf", &b1, &b2, &h);
            area=((b1+b2)*h)/2;
            printf("%.0lf\n", round(area));
          }
      }
  }
  