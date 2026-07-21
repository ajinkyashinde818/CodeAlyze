#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, r;
  scanf("%d %d", &n, &r);

  if (n >= 10) {
    cout << r << endl;
    return 0;
  }

  cout << (r + 100 * (10 - n)) << endl;
  
  return 0;
}
