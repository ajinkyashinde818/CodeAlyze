#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int cnt = 0;

  for (int r = 0; r * R <= N; r++) {
    for (int g = 0; r * R + g * G <= N; g++) {
      if ((N - r * R - g * G) % B == 0) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
