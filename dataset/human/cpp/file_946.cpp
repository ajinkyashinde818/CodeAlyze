#include <iostream>

using namespace std;

int main() {
  int R,G,B,N,ans{},p;
  cin >> R >> G >> B >> N;
  for(int r = 0; r*R <= N; ++r) {
    for(int g = 0; p=r*R+g*G, p <= N; ++g) {
      if ((N-p)%B == 0) ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
