#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  
  bool out = false;
  if(n%2 == 0){
    for(int i=0; i < (n/2)+1; i++){
      if(out) cout << ' ';
      cout << 0;
      out = true;
    }
    for(int i=0; i < (n/2)-1; i++){
      if(out) cout << ' ';
      cout << m;
      out = true;
    }
    cout << endl;
    return 0;
  }
  else
  {
    for(int i=0; i < (n+1)/2; i++){
      if(out) cout << ' ';
      cout << 0;
      out = true;
    }
    for(int i=0; i < (n-1)/2; i++){
      if(out) cout << ' ';
      cout << m;
      out = true;
    }
    cout << endl;
    return 0;
  }
  return 0;
}
