#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,C;

ll dist(ll a,ll b){
  ll c=abs(a-b);
  return min(c,N-c);
}

ll solve(vector<ll> x,vector<ll> v){
  ll ans=0;
  map< ll , ll > mp;
  ll sum=0;

  for(int i=N-1;i>=0;i--){
    sum+=v[i];
    ll dist=C-x[i];
    mp[i]=sum-dist*2LL;
    if(i+1<N)mp[i]=max(mp[i],mp[i+1]);

    //    cout<<i<<' '<<mp[i]<<' '<<x[i]<<' '<<v[i]<<endl;
  }
  
  sum=0;
  for(int i=0;i<N;i++){
    sum+=v[i];
    ans=max(ans, sum+mp[i+1]-x[i] );
    ans=max(ans, sum-x[i] );
    //    cout<<sum<<' '<<x[i]<<' '<<mp[i+1]<<endl;
  }
  //  cout<<endl;
  return ans;
}


int main(){
  cin>>N>>C;
  vector<ll> x(N), v(N);
  for(int i=0;i<N;i++){
    cin>>x[i]>>v[i];
    x[i]%=C;
  }

  ll fi=solve(x,v);

  typedef pair<ll,ll> P;

  vector< P > tmp;
  for(int i=0;i<N;i++){
    tmp.push_back( P( (C-x[i])%C ,v[i]));
  }
  sort(tmp.begin(), tmp.end());
  vector<ll> nx=x,nv=v;
  for(int i=0;i<N;i++){
    nx[i]=tmp[i].first;
    nv[i]=tmp[i].second;
  }
  
  ll se=solve(nx,nv);

  cout<< max(fi,se) <<endl;
  return 0;
}
