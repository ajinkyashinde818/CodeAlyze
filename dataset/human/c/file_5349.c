#include<stdio.h>
#include<stdbool.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)

const int INF = 100000000;

int main(){
  int n, m, x, a[13][13], c[13];
  scanf("%d%d%d",&n,&m,&x);
  rep(i,n) {
    scanf("%d",&c[i]);
    rep(j,m) scanf("%d",&a[i][j]);
  }
  
  int ans = INF;
  rep(s,1<<n) {
    int cost = 0;
    int d[13] = {0};
    rep(i,n) {
    	if (s>>i&1) {//ビット演算子を用いて二進数的に事象を調べ上げる
      	  cost += c[i];
          rep(j,m) {
            d[j] += a[i][j];
          }
    	}
    }//各事象のコストの和と理解度の和を求める
    //printf("%d\n",cost);
    
    bool ok = true;
    rep(j,m) {
      //printf("%d\n",d[j]);
      if (d[j] < x) {
        ok = false;
        break;
      }
    }//調べたものが条件を満たしているかを判定する
    
    if((ok) && (cost < ans)) ans = cost;
    //もし最安値を更新したらansに代入
  }
  
  if (ans == INF) printf("%d",-1);
  else printf("%d\n", ans);
  return 0;
  
}
