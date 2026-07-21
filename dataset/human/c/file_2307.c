#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>





int main(void){
int n,k;
long long int s;
scanf("%d%d%lld",&n,&k,&s);
long long int ans[n];
int i;
/*for(i=0;i<n;i=i+2){
  if(k>0){
    if(s>i){
    ans[i]=i;
    ans[i+1]=s-i;
  }
  else{
    ans[i]=i;
    ans[i+1]=i-s;
  }
  }
  else{
    ans[i]=1000000000;
    ans[i+1]=1000000000;
  }
  k--;
}*/
for(i=0;i<n;i++){
  if(k>0){
    ans[i]=s;
    k--;
  }
  else{
    ans[i]=1000000000-1;
  }
}
for(i=0;i<n;i++){
  printf("%lld ",ans[i]);
}


  return 0;
}
