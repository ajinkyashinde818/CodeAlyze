#include <iostream>

using namespace std;

int main(){
  int R, G, B, N;
  long long ret = 0;
  cin >> R >> G >> B >> N;
  for (int r=0; r<=N / R; r++){
    for (int g=0; g<=(N - R*r) / G; g++){
      if ((N - r*R - g*G) % B == 0) ret++;
    }
  }
  cout << ret << endl;
  return 0;
}
