#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  long long y=0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    y+=a[i];
  }

  vector<long long> ans(n-1);
  long long x = 0;
  for (int i = 0; i < n-1; i++)
  {
    x+=a[i];
    y-=a[i];
    ans[i] = abs(x-y); 
  }
  sort(ans.begin(),ans.end());

  cout << ans[0] << endl;
}
