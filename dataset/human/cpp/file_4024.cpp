#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  double xs,ys,xt,yt;cin>>xs>>ys>>xt>>yt;
  ll n;cin>>n;
  double x[n],y[n],r[n];
  for(ll i=0;i<n;i++)cin>>x[i]>>y[i]>>r[i];
  double d[n][n];
  for(ll i=0;i<n;i++){
    for(ll j=i;j<n;j++){
      d[i][j]=max((double)0,pow(pow(x[i]-x[j],2)+pow(y[i]-y[j],2),0.5)-r[i]-r[j]);
      d[j][i]=d[i][j];
    }
  }
  for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
      for(ll k=0;k<n;k++){
        d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
      }
    }
  }
  double ans=pow(pow(xt-xs,2)+pow(yt-ys,2),0.5);
  for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
      double kyo=max((double)0,pow(pow(x[i]-xs,2)+pow(y[i]-ys,2),0.5)-r[i]);
      double kyoo=max((double)0,pow(pow(x[j]-xt,2)+pow(y[j]-yt,2),0.5)-r[j]);
      ans=min(ans,kyo+kyoo+d[i][j]);
    }
  }
  cout<<fixed<<setprecision(10)<<ans<<endl;
}
