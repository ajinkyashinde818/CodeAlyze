#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  ll mn = 3 * 1e15;
  int n;
  cin >> n;
  int arr[n];
  ll sum = 0;
  ll cur = 0;
  for(int i = 0;i < n;i++){
    cin >> arr[i];
    sum += arr[i];
  }
  for(int i = 0;i < n - 1;i++){
    cur += arr[i];
    mn = min(mn, abs(cur - (sum - cur)));
//    cout << cur << endl;
  }
  //
  cout << mn;
}
