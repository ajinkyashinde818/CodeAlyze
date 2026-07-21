#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int temp=0,k,s;
void saiki(int* c,int S,int n){
  if(S==0){
    temp++;
    return;
  }
  int i,t;
  if(n!=2){
    if(S<k)
      t=S;
    else
      t=k;
    for(i=0;i<=t;i++){
      c[n]=i;
      saiki(c,S-i,n+1);
    }
  }else if(S<=k)
    temp++;
}
int main(void){
int c[3];
scanf("%d %d",&k,&s);
  saiki(c,s,0);
  printf("%d\n",temp);
  return 0;
}
