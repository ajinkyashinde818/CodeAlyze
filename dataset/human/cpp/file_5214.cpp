#include <bits/stdc++.h>
using namespace std;

void solve(void){
  int RI, N, R;
  
  cin >> N >> R;
  
  if(N<10){
  	RI = R + 100*(10-N);
  }
  else
  {
    RI = R;
  }
  
  cout << RI << endl;
  
  return;
}

int main(int argc, const char * argv[]) {

    // cinを高速にするためのおまじない
    cin.tie(0);
    ios::sync_with_stdio(false);

  solve();
  
  return 0;
}
