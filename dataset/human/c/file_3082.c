#include<stdio.h>
 
int main(void){
  int K = 0,N = 0;
  int a[200000];
  int *p;
  int max = 0,def = 0;
  p = a;
 
  scanf("%d %d\n",&K,&N );
  scanf("%d",p);
  for(int i = 1;i < N; i++ ){
    scanf(" %d",(p+i) );
    if((*(p + i) - *(p + i -1)) > max){
      max = *(p + i) - *(p + i -1);
    }
  }
  if(((*p - 0) + (K - *(p+N-1))) > max){
    max = (*p - 0) + (K - *(p+N-1));
  }
  def = K - max;
  printf("%d\n",def );
  return 0;
}
