#include <bits/stdc++.h>
using namespace std;

int main(){
  int r , g , b , N;
  cin >> r >> g >> b >> N;
  int answer = 0;
  for(int i = 0; i <= 3000; i++){
    for(int j = 0; j <= 3000; j++){
      int v = r * i + g * j;
      if(N >= v && (N - v) % b == 0){
        answer++;
      }
    }
  }
  cout << answer << endl;
}
