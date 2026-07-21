#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  long long ans=0,min=1e9,a,cnt=0;
  for(int i=0;i<n;i++){
    cin >> a;
    if(a<0)cnt++;
    a=abs(a);
    if(a<min)min=a;
    ans+=a;
  }
  if(cnt%2)ans-=2*min;
  cout << ans << endl;
  return 0;
}
