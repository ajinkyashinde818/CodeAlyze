#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int N, R;

int main() {
  cin >> N >> R;

  if (N >= 10)
    cout << R << endl;
  else
    cout << R + 100 * (10 - N) << endl;

  return 0;
}
