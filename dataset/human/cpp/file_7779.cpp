#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin>>n;
  vector<ll> a(n),sum;
  ll tmp=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    tmp+=a[i];
    sum.push_back(tmp);
  }
  vector<ll> ans;
  for(int i=0;i<n-1;i++){
    ans.push_back(abs(2*sum[i]-sum[n-1]));
  }
  cout<<*(min_element(ans.begin(),ans.end()));
  
}
