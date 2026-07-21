#include <bits/stdc++.h>
using namespace std;

int main(){
  int R,G,B,N;
  cin >> R >> G >>B >> N;
  int counter = 0;
  for(int i = 0; i <= N; i++){
    for(int j = i; j <= N; j++){
      if(i % R == 0 && (j-i) % G == 0 && (N-j) % B == 0)
        counter++;
    }
  }
  
  cout << counter << endl;
}
