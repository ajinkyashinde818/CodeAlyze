#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int c = 0;

  for(int i = 0; R*i <= N; i++){
    for(int j = 0; R*i+G*j<=N; j++){
      if((N-R*i-G*j)%B==0) c++;
    }
  }

  cout << c << endl;

}
