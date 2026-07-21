#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;  cin >> n;
  vector<long> a(n);

  long minus = 0, mini = 1e9+3, rui = 0;
  bool iszero = false;
  for(int i=0; i<n; i++){
    cin >> a[i];
    rui += abs(a[i]);
    mini = min(mini, abs(a[i]));
    if(a[i] == 0)  iszero = true;
    else if(a[i] < 0)  minus++;
  }

  if(iszero){
    cout << rui << endl;
    return 0;
  }else if(minus % 2){
    cout << rui - mini*2 << endl;
  }else{
    cout << rui << endl;
  }

  return 0;
}
