#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<long long>a(n);
  vector<long long>sum(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sum[0]=a[0];
  for(int i=1;i<n;i++){
    sum[i]=a[i]+sum[i-1];
  }
  long long sa=LLONG_MAX;
  for(int i=0;i<n-1;i++){
    long long a=sum[i];
    long long b=sum[n-1]-sum[i];
    //cout<<a<<" "<<b<<endl;
    sa=min(sa,abs(a-b));
  }
  cout<<sa<<endl;
  return 0;
}
