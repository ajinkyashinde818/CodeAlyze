#include <stdio.h>
int main(){
  int N;
  int Ap[100000];
  int Am[100000];
  int A;
  int i,j=0,k=0;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&A);
    if (A >= 0){
      Ap[j] = A;
      j++;
    }else if(A < 0){
      Am[k] = A;
      k++;
    }
  }
  int max = -20000;
  int min = 20000;
  long sum = 0;
  long tmp;
  int a,b;
  if (j == N){
    j = 0;
    for (j=0;j<N;j++){
      sum += Ap[j];
      if (Ap[j] < min){
        min = Ap[j];
        i = j;
      }
    }
    printf("%ld\n",sum - 2*Ap[i]);
    j = 0;
    tmp = min;
    if (i == 0){
      for(j=2;j<N;j++){
        printf("%ld %d\n",tmp,Ap[j]);
        tmp = tmp - Ap[j];
      }
      printf("%d %ld\n",Ap[1],tmp);
    }else{
      for(j=1;j<N;j++){
        if(j != i){
          printf("%ld %d\n",tmp,Ap[j]);
          tmp = tmp - Ap[j];
        }
      }
      printf("%d %ld\n",Ap[0],tmp);
    }
  }else if(k == N){
    k = 0;
    for (k=0;k<N;k++){
      sum -= Am[k];
      if (Am[k] > max){
        max = Am[k];
        i = k;
      }
    }
    printf("%ld\n",sum + 2*Am[i]);
    k = 0;
    tmp = max;
    for(k=0;k<N;k++){
      if(k != i){
        printf("%ld %d\n",tmp,Am[k]);
        tmp = tmp - Am[k];
      } 
    }
  }else{
    for(a=0;a<j;a++){
      sum += Ap[a];
    }
    for(b=0;b<k;b++){
      sum -= Am[b];
    }
    printf("%ld\n",sum);
    a = 1;
    b = 1;
    tmp = Am[0];
    for(a=1;a<j;a++){
      printf("%ld %d\n",tmp,Ap[a]);
      tmp = tmp - Ap[a];
    }
    printf("%d %ld\n",Ap[0],tmp);
    tmp = Ap[0] - tmp;
    for(b=1;b<k;b++){
      printf("%ld %d\n",tmp,Am[b]);
      tmp = tmp - Am[b];
    }
  }
  return 0;
}
