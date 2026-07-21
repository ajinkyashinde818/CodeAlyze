#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
  int n;
  cin>>n;
  vector<LL> v(n);
  int cnt=0, minN=1000000001, idx=0;
  for(int i=0;i<n;i++){
    scanf("%lld",&v[i]);
    if(v[i]<0) cnt++;
    if(minN>abs(v[i])){
      minN = abs(v[i]);
      idx=i;
    }
  }
  if(cnt%2!=0){
    for(int i=0;i<n-1;i++){
      if(v[i]<=0){
        v[i]*=-1;
        v[i+1]*=-1;
      }
    }
    if(v[idx]>0) v[idx]*=-1;
    if(n-1!=idx&&v[n-1]<0) v[n-1]*=-1;
  }else{
    for(int i=0;i<n;i++){
      if(v[i]<0){
        v[i]*=-1;
      }
    }
  }
  LL ans=accumulate(v.begin(),v.end(),0LL);
  cout<<ans<<endl;
}
