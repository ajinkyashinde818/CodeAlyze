#include<stdio.h>
#include<stdlib.h>
int cmpint(const void *a,const void *b){
  return *(int* )b - *(int* )a;
}//b-aかaーbで小さい順か大きい順に決められる

int main(){
  int N;
  scanf("%d",&N);
  int i,j;
  int a[3*N];
  for(i=0;i<3*N;i++){
    scanf("%d",&a[i]);
  }
  qsort(a,3*N,sizeof(int),cmpint);
  long long int count=0;
  for(i=0;i<N;i++){
    count+=a[1+2*i];
  }
  printf("%lld",count);
}
