#include <bits/stdc++.h>
using namespace std;

int main(void){
  int n, m; cin >> n >> m;
  if(n % 2 == 1){
    for(int i = 0; i < n/2 + 1; i++){
      if(i == 0)
        cout << 0;
      else
        cout << " " << 0;
    }
    for(int i = 0; i < n/2; i++){
        cout << " " << m;
    }
    cout << endl;
  }else{
    for(int i = 0; i < n/2 + 1; i++){
      if(i == 0)
        cout << 0;
      else
        cout << " " << 0;
    }
    for(int i = 0; i < n/2 - 1; i++){
      cout << " " << m;
    }
    cout << endl;
  }
  return 0;
}
