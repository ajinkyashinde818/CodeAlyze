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

typedef struct hon{
  int cost;
  int up[12];
  int onoff;
}lebro;

l hyouka(lebro*book,int N,int M,int X){
  l sum=0;
  int ski[12]={};
  for(int i=0;i<N;i++){
    if(book[i].onoff==0){
      sum+=book[i].cost;
      for(int j=0;j<M;j++){
        ski[j]+=book[i].up[j];
      };
    };
  };
  //printf("%ld\n",sum);
  for(int j=0;j<M;j++){
    //printf("%d\n",ski[j]);
    if(ski[j]<X)return 10000000;
  };
  return sum;
};
  
int main(){
  int N,M,X;
  l ans=10000000;
  sd(&N);sd(&M);sd(&X);
  lebro book[12];
  for(int i=0;i<N;i++){
    sd(&book[i].cost);
    for(int j=0;j<M;j++)
      sd(&book[i].up[j]);
  };
  rep(0)rep(1)rep(2)rep(3)rep(4)rep(5)rep(6)rep(7)
    rep(8)rep(9)rep(10)rep(11){
    ans=min(hyouka(book,N,M,X),ans);
  };
  if(ans==10000000)printf("-1");
  else printf("%ld",ans);
};
