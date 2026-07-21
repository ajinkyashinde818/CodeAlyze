#include <stdio.h>
int main(void){
  int K, N, i, save, con;
  int tmp=0;
  int a[200000];
  
  if(scanf("%d%d",&K,&N)==1);
  for(i=0;i<N;i++)
    if(scanf("%d",&a[i])==1);
  
  for(i=0;i<N-1;i++){
    save=a[i+1]-a[i];
    if(save>tmp)
      tmp=save;}
  
  save=K-a[N-1]+a[0];
  if(save>tmp)
    tmp=save;
  
  con=K-tmp;
  printf("%d",con);
  
  return 0;
}
