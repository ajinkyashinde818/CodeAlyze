#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
  int R,G,B,N;
  cin >> R >> G >> B >> N;
  long long ans = 0;
  for(int i = 0;i < N / R + 1;i++){
    for(int j = 0;j < N / G + 1;j++){
      for(int k = 0;k < N / B + 1;k++){
        if(i * R + j * G + k * B == N){
          ans++;
          /*cout << i << '/' << j << '/' << k << endl;*/
        }if(i * R + j * G + k * B > N){
          break;
        }
        if(i * R + j * G + (k+100) * B < N){
          k += 99;
        }
      }
    }
  }
  cout << ans << endl;
}
