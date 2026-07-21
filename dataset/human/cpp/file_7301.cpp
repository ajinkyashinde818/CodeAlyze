#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> a(N);
  for (int i=0;i<N;i++){
    cin >> a[i];
  }
  for (int i=1;i<N;i++){
    a[i]+=a[i-1];
  }
  long long sum=a[N-1];
  long long ans=1000000000000000;
  for (int i=0;i<N-1;i++){
    long long count=abs(2*a[i]-sum);
    ans=min(count,ans);
  }
  cout << ans << endl;
}
