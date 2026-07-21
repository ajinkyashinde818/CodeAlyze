#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  int negatives = 0;
  int smallest = -1;
  int smallestIndex = -1;
  for (int i = 0; i < n; i++) {
    int v = a.at(i);
    if (v < 0) {
      negatives++;
    }
    int absed = abs(v);
    if (smallest == -1 || smallest > absed) {
      smallest = absed;
      smallestIndex = i;
    }
  }

  long sum = 0;
  bool evenNegatives = negatives%2 == 0;
  for (int i = 0; i < n; i++) {
    if (evenNegatives || smallestIndex != i) {
      sum += abs(a.at(i));
    } else {
      sum -= abs(a.at(i));
    }
  }
  cout << sum << endl;
  return 0;
}
