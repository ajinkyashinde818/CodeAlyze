#include <bits/stdc++.h>
using namespace std;
int main () {
  long R, G, B, N;
  cin >> R >> G >> B >> N;
  long count = 0;
  for(int i = 0; i <= N; i += R){
    for(int j = 0; j <= N - i; j += G){
      if((N - i - j) % B == 0)count++;
    }
  }
  cout << count << endl;
  return 0;
}
