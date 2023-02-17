#include <stdio.h>

typedef struct tempo_chegada{
  int horas;
  int minutos;
} tempo_chegada;

  int main(){
    int t, n, i, j, k, l, aux, maquinas=0; maquinas_necessarias=0;
    scanf("%d", &t);
      for(i=0; i<t; i++){
        scanf("%d", &n);
        tempo_chegada horario[n];
          for(j=0; j<n; j++){
            scanf("%d %d", &horario[j].horas, &horario[j].minutos);
          }
          //ordena
          for(k=0; k<n; k++){
            for(l=k; l<n; l++){
              //ordena horas
              if(horario[l].horas<horario[k].horas){
                //troca horas
                aux=horario[l].horas;
                horario[l].horas=horario[k].horas;
                horario[k].horas=aux;
                //troca minutos
                aux=horario[l].minutos;
                horario[l].minutos=horario[k].minutos;
                horario[k].minutos=aux;
              }
              //ordena minutos
              if(horario[l].horas==horario[k].horas && horario[l].minutos<horario[k].minutos){
                //troca horas
                aux=horario[l].horas;
                horario[l].horas=horario[k].horas;
                horario[k].horas=aux;
                //troca minutos
                aux=horario[l].minutos;
                horario[l].minutos=horario[k].minutos;
                horario[k].minutos=aux;
              }
            }
          }
          //checa quantidade de maquinas necessarias
          for(j=0; j<n; j++){
            for(k=j; k<n; k++){
              if(horario[k].horas==horario[j].horas && horario[k].minutos==horario[j].minutos){
                maquinas++;
              }
            }
            if(maquinas>maquinas_necessarias){
              maquinas_necessarias=maquinas;
            }
            j+=maquinas;
            maquinas=0;
          }
          printf("%d\n", maquinas_necessarias);
      }
  }