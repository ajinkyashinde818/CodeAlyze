#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <unordered_map>

using namespace std;

typedef long long ll;


int main(void) {
  int R, G, B, N;
  cin >> R >> G >> B >> N;

  int count = 0;
  for (int r = 0; R * r <= N; r++) {
    for (int g = 0; G * g <= N - R * r; g++) {
      if ((N - R * r - G * g) % B == 0) {
      // for (int b = 0; B * b <= N - R * r - G * g; b++) {
        // if (r * R + g * G + b * B == N) {
          count++;
        // }
      }
    }
  }
  cout << count << endl;
}
