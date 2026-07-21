#include<stdio.h>
int main(){
  int n,i,j,M=1000000;
  char p[1000010]={1,1};
  for(i=2;i*i<M;i++){
    if(p[i])continue;
    for(j=i*i;j<M;j+=i)p[j]=1;
  }
  while(scanf("%d",&n),n){
    for(i=j=0;n;i++){
      n-=1-p[i];
      j+=(1-p[i])*i;
    }
    printf("%d\n",j);
  }
  return 0;
}
