#include<stdio.h>
#include<iostream>

int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main(void){
  long long int ans=0;
  int K,N;
  int A[200000];
  scanf("%d %d",&K,&N);
  for(int m=0;m<N;m++){
      scanf("%d",&A[m]);
  }
  qsort(A,N,sizeof(int),compare_int);
  int max=0;
  int num;
  for(int m=0;m<N-1;m++){
      int a=A[m+1]-A[m];
      if(max<a){
            num=m;
            max=a;
        }
  }
  if(max<K-A[N-1]+A[0]){
      num=N-1;
      max=K-A[N-1]+A[0];
  }
  printf("%d",K-max);

}
