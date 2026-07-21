#include <bits/stdc++.h>
using namespace std;

int main() {
  int R,G,B,N,n;
  cin >> R >> G >> B >> N;
  n=0;
  for(int i=0;i<=N;i+= R){
    for(int j=0;(i+j)<=N;j += G){
      if(((N-i-j)%B)==0 && (N-i-j)>=0){
        n++;
      }
    }
  }
    cout << n << endl;
}
