#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 2e5;
lint ps[MAX_N+5];

int main(){
  int n; cin >> n;
  
  for(int i=0;i<n;i++){
    lint a; cin >> a;
    ps[i+1] = ps[i] + a;
  }
  
  lint ans = 1e30;
  for(int i=0;i<n-1;i++)
    ans = min(ans, abs(ps[n]-2*ps[i+1]));
    
  cout << ans << endl;
  return 0; 
}
