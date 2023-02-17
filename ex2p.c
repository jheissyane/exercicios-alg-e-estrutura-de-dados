#include <stdio.h>
#include <math.h>

  int main(){
    int n, i;
    double area, raio1, raio2, a, b, c, p, b1, b2, altura, pi=3.14159265;
    char type;
    scanf("%d", &n);
      for(i=0; i<(n*2); i++){
        scanf("%c ", &type);
          if(type=='C'){
            scanf("%lf", &raio1);
            area=pi*raio1*raio1;
            printf("%.0lf\n", round(area));
          }
          else if(type=='E'){
            scanf("%lf %lf", &raio1, &raio2);
            area=pi*raio1*raio2;
            printf("%.0lf\n", round(area));
          }
          else if(type=='T'){
            scanf("%lf %lf %lf", &a, &b, &c);
            p=(a+b+c)/2;
            area=sqrt(p*(p-a)*(p-b)*(p-c));
            printf("%.0lf\n", round(area));
          }
          else if(type=='Z'){
            scanf("%lf %lf %lf", &b1, &b2, &altura);
            area=((b1+b2)*altura)/2;
            printf("%.0lf\n", round(area));
          }
      }
  }
  