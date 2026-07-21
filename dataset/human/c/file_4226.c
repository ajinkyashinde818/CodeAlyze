#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007

long dp[100005];
int a[100005];

int main(void){
  int N,M,i,d1,d2;
  char str[100],*p;
  
  fgets(str,sizeof(str),stdin);
  p=strtok(str," \n");
  N=atoi(p);
  p=strtok(NULL," \n");
  M=atoi(p);
  
  dp[0]=1;
  
  for(i=0;i<M;i++){
  	fgets(str,sizeof(str),stdin);
    a[i]=atoi(str);
    dp[a[i]]=-1;
  }
  if(dp[1]==-1){
    dp[1]=0;
  }else{
    dp[1]=1;
  }
  for(i=2;i<N+1;i++){
    if(dp[i]==-1){
    }else{
      d1=dp[i-1],d2=dp[i-2];
      if(dp[i-1]==-1) d1=0;
      if(dp[i-2]==-1) d2=0;
      dp[i]=d1+d2;
      dp[i]%=mod;
    }
  }
  
  printf("%ld",dp[N]);
  
  return 0;
}
