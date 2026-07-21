#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  long long sum=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum += a[i];
  }
  long long sunuke=0;
  long long arai=sum;
  long long candidate;
  long long ans = 9223372036854775807;
  for(int i=0;i<n-1;i++){
    sunuke+=a[i];
    arai-=a[i];
    candidate = abs(sunuke - arai);
    ans = min(ans,candidate);
  }
  cout << ans << endl;
  return 0;
}
