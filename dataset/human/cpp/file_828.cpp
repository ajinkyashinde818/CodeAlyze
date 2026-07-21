#include<bits/stdc++.h>
using namespace std;
int main(){
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int count = 0;

  for(int i=0; i<=N; i++){
    for(int j=0; j<=N; j++){
      if((N - (R*i + G*j)) %B == 0){
        if((N - (R*i + G*j)) >= 0){
        count++;
        }
      }
    }
  }
  cout << count << endl;
}
