#include <iostream>
using namespace std;

int main() {
  int x, y, z, n;
  cin >> x >> y >> z >> n;
  int count = 0;
  int x_c = 0;
  int y_c = 0;
  while (n - x_c * x >= 0) {
    y_c = 0;
    while (n - x_c * x - y_c * y >= 0) {
	  if ((n - x_c * x - y_c * y) % z == 0) count++;
      y_c++;
    }
    x_c++;
  }
  cout << count << endl;
  return 0;
}
