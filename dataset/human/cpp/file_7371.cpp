#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  long long arr[n];
  long long Sum = 0, arai = 0, com = 0, ads = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];

    Sum += arr[i];
  }
  arai = arr[0];
  com = abs(Sum - 2 * arai);
  for (int i = 1; i < n - 1; i++) {
    arai += arr[i];
    ads = abs(Sum - 2 * arai);

    if (ads < com) {
      com = ads;
    }
  }

  cout << com << endl;
  return 0;
}
