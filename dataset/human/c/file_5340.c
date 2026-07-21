#include<stdio.h>
#include<stdbool.h>
#define rep(i,n) for(int i=0; i < (n); i++)
const int INF = 1001001001;
int main(){
  int n,m,x;
  scanf("%d%d%d",&n,&m,&x);
  int c[13];
  int a[13][13];
  rep(i,n){
    scanf("%d",&c[i]);
    //printf("%d",c[i]);
    rep(j,m){
      scanf("%d",&a[i][j]);
      //printf("%d",a[i][j]);
    }
  }
  int ans =INF;
  rep(s,1<<n){//便宜的にsを使用し、2^nの探索をするforを作成している
    int cost=0;//金額
    int d[13]={0};//選択した参考書のm個の理解度を格納する箱
    rep(i,n){
      if(s>>i&1){//iビット目が１だった場合
        cost+=c[i];//c[i]のコストを足している
        rep(j,m){
          d[j]+=a[i][j];//m個の理解度を足している
        }
      }
    }
    //printf("%d\n",cost);

    bool ok =true;
    rep(j,m){
      //printf("%d",d[j]);
      if(d[j]<x){
        ok = false;
        break;
      }
    }
    if(ok==true){
      if(ans>cost){
        ans = cost;
      }
    }
  }
  if(ans==INF){
    printf("%d",-1);
  }
  else{
    printf("%d\n",ans);
  }
  return 0;
}
