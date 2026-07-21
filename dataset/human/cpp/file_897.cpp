#include <bits/stdc++.h>
using namespace std;

int main(){
  int r,g,b,n;
  int count = 0;
  cin >> r >> g >> b >> n;
  
  for(int i=0; i<n+1; i++){
    for(int j=0; j<n+1-i; j++){
      if((n-i*r-j*g) % b == 0){
        if(n-i*r-j*g >= 0){
          count++;
        }
      }
    }
  }
  
  cout << count << endl;
}
