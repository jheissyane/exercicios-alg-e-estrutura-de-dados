#include <stdio.h>

int insertion (int*v, int t){
  int aux, i=0, j=1, q=0;
  while(j<t){
    aux=v[j];
    i=j-1;
    while(i>=0 && (v[i]>aux)){
      v[i+1]=v[i];
      i--;
      q++;
    }
    v[i+1]=aux;
    j++;
  }
  return q;
}

int selection(int* vet, int n){
  int i, i1, menor, indmenor, aux, q=0;
    for(i=0; i<(n-1); i++){
      menor=vet[i];
      indmenor=i;
      for(i1=(i+1); i1<n; i1++){
        if(vet[i1]<menor){
          menor=vet[i1];
          indmenor=i1;
        }
      }
      aux=vet[i];
      vet[i]=vet[indmenor];
      vet[indmenor]=aux;
      q++;
    }
    return q;
}

  int main(){
    int i, n, q_insertion, q_selection;
    scanf("%d", &n);
    int vet1[n], vet2[n];
      for(i=0; i<n; i++){
        scanf("%d", &vet1[i]);
        vet2[n]=vet1[n];
      }
      q_insertion=insertion(vet1, n);
      q_selection=selection(vet2, n);
      printf("%d %d\n", q_insertion, q_selection);
  }