#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
static const ll MOD = 1000000007;

int main(){
  int N,R;
  cin >> N >> R;
  if(N >= 10){
    cout << R << endl;
  }else{
    cout << R + 100 * (10 - N) << endl;
  }
    
}
