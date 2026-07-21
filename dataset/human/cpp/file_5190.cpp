#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  ll N,R;
  cin >> N >> R;
  ll ans;
  if(N >= 10){
    ans = R;
  } else { 
    ans = R + 100 * (10-N);
  }
  cout << ans << endl;
  
}
