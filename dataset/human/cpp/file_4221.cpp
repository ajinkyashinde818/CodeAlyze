#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long t;
  cin >> t;
  if (t < 4) {
    cout << t << endl;
    return 0;
  }
  vector<long long> steps;
  vector<long long> stops;
  long long j = 1;
  long long now = 0;
  long long time = 1;
  while (true) {
    now += j;
    steps.push_back(j);
    stops.push_back(now);
    if (now * 2 + j * 3 - 1 > t) break;
    j *= 3;
    ++time;
  }
  long long rest = t - now;
  for (long long i = steps.size() - 1; i >= 0;) {
    if (rest == 0) break;
    if (rest - (stops[i] - 1) < 0) {
      --i;
    }
    rest -= steps[i];
    ++time;
  }
  cout << time << endl;

  return 0;
}
