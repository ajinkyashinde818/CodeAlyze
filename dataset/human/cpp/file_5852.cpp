#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
カロリーの累積和？
向きを変えるのか

x*2とC-xが移動距離
全部のパターンで調べるとか
時計、班時計、方向転換
N^2になっちゃうな
時計と班時計の累積和だけで組み合わせとか
N^2

往復した場合の累積和
普通の累積和
最大和だけ用意しとくとか、DP
*/
int main(){
  ll N,C,ans=0,cal=0; cin>>N>>C;
  vector<ll> X(N+1,0), V(N+1,0),DPR(N+1,0),DPL(N+1,0),DPRR(N+1,0),DPLL(N+1,0);
  for(ll i=1; i<=N; i++) cin>>X[i]>>V[i];
  //DPR
  for(ll i=1; i<=N; i++){
    cal+=V[i];
    DPR[i]=max(DPR[i-1],cal-X[i]);
  }
  //DPL
  cal=0;
  for(ll j=N; j>0; j--){
    cal+=V[j];
    DPL[N-j+1]=max(DPL[N-j],cal-(C-X[j]));
  }  
  //DPRR
  cal=0;
  for(ll i=1; i<=N; i++){
    cal+=V[i];
    DPRR[i]=max(DPRR[i-1],cal-X[i]*2);
  }
  //DPLL
  cal=0;
  for(ll j=N; j>0; j--){
    cal+=V[j];
    DPLL[N-j+1]=max(DPLL[N-j],cal-(C-X[j])*2);
  }
  //時計反時計
  ans=max(DPR[N],DPL[N]);
  //ひきかえし
  for(ll i=1; i<=N; i++) ans=max(ans,DPRR[i]+DPL[N-i]);
  for(ll i=1; i<=N; i++) ans=max(ans,DPLL[i]+DPR[N-i]);
  cout<<ans<<endl;
}
