#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<long long> a(n);

  int minus=0;
  bool flg=false;
  long long longmin=1000000000;
  for(int i=0; i<n; ++i){
    cin>>a[i];
    if(a[i]==0)flg=true;
    if(a[i]<0)++minus;
    longmin=min(longmin, abs(a[i]));
  }

  long long ans=0;
  if(minus%2==0 || flg==true){
    for(int i=0; i<n; ++i)ans+=abs(a[i]);
  }else{
    for(int i=0; i<n; ++i)ans+=abs(a[i]);
    ans-=longmin*2;
  }
  cout<<ans<<endl;
}
