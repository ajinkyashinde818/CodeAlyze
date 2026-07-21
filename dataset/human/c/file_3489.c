#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ull unsigned long long int
#define ll long long
#define l long
#define sd(x) scanf("%d",x) 
#define sld(x) scanf("%ld",x) 
#define slld(x) scanf("%lld",x) 
#define sllu(x) scanf("%llu",x) 
#define ss(x) scanf("%s",x) 
#define rep(x) for(book[x].onoff=0;book[x].onoff<2;book[x].onoff++)
#define min(x,y) x<y?x:y

int main(){
  int N,pos;
  sd(&N);
  ull K,v,c;
  sllu(&K);
  int A[N+1],B[200001]={};
  for(int i=1;i<=N;i++)
    sd(&A[i]);
  pos=1;
  B[pos]=1;
  for(ull u=2;u<=K+1;u++){
    pos=A[pos];
    if(u==K+1){
      printf("%d",pos);
      return 0;
    };
    if(B[pos]!=0){
      v=u-B[pos];
      c=B[pos]-1;
      break;
    };
    B[pos]=u;
  };
  //printf("%llu %llu",v,c);
  v=((K-c)%v)+c;
  pos=1;
  for(int i=1;i<=v;i++){
    pos=A[pos];
  };
  printf("%d",pos);
};
