#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long>a(n);
  for(int i=0;i<n;i++)
    cin >> a.at(i);
  long long r=n-2,l=1,sum=-a.at(0),sum2=a.at(0),ans;
  for(int i=0;i<n;i++)
    sum+=a.at(i);
  ans=abs(sum-sum2);
  for(int i=1;i<n-1;i++){
    sum-=a.at(i);
    sum2+=a.at(i);
    ans=min(ans,abs(sum-sum2));
  }
  cout << ans << endl;
  return 0;
}
