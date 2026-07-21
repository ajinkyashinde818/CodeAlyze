#include <bits/stdc++.h>
using namespace std;

int main(){
  int R,G,B,N;
  int count = 0;
  
  cin >> R >> G >> B >> N;
  
  for(int r=0; r <= N; r++){
    for(int g=0; g <= N; g++){
      if(N - r * R - g * G < 0)
        continue;
      if((N - r * R - g * G) % B == 0){
        count++;
        continue;
      }
    }
  }

  cout << count << endl;

}
