#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  long long b,mini = 1000000000000000;
  vector<long long> a(n + 1,0);
  for(int i = 1;i <=n;i++){
    cin >> b;
    a[i] = b + a[i - 1];
  }
  for(int i = 1;i < n;i++){
    mini = min(mini,llabs(a[i] - (a[n] - a[i])));
  }
  cout << mini << endl;
}
