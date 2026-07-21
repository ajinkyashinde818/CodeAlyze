#include<bits/stdc++.h>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

int main(){
  int R, G, B, N;
  cin >> R >> G >> B >> N;

  int ans = 0;
  for (int i=0; i<= (N / R); i++){
    for (int j=0; j<= (N - i * R) / G; j++){
      int k = N - i * R - j * G;
      if (k % B == 0 && k / B >= 0){
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
