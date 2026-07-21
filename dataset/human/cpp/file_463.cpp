#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main(void){
  int R, G, B, n;
  int counter = 0;
  cin >> R >> G >> B >> n;

  for (int r = 0; r <= n; r += R) {
    for (int g = 0; g <= n - r; g += G) {
      int b = n - r - g;
      if (b % B == 0) {
        counter ++;
      }
    }
  }


  cout << counter << '\n';
  return 0;
}
