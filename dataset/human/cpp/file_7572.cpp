#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<long long> b(n);
  long long sum=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum += a[i];
    b[i] = sum;
  }
  long long ans = abs(sum-2*b[0]);
  for(int i=1;i<n-1;i++){
    ans=min(ans,abs(sum-2*b[i]));
  }
  cout << ans << endl;
}
