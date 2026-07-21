/* https://atcoder.jp/contests/abc125/tasks/abc125_d */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

/* {{{ Variables */
int N;
vector<int> A;
/* }}} */

int main(int argc, char *argv[])
{
  /* {{{ Input */
  cin >> N;

  A = vector<int>(N);

  for (int& e: A)
    cin >> e;
  /* }}} */

  /* {{{ Output */
  int min_abs = 1e9;
  int min_arg = -1;
  int num_minus = 0;

  for (int i = 0; i < N; ++i) {
    int a = A.at(i);

    if (a < 0) {
      num_minus++;
    }

    if (abs(a) <= min_abs) {
      min_abs = abs(a);
      min_arg = i;
    }
  }

  long long sum = 0;

  for (int i = 0; i < N; ++i) {
    long long a = abs(A.at(i)*1ll);

    if (num_minus%2 == 1 && min_arg == i) {
      sum -= a;
    } else {
      sum += a;
    }
  }

  cout << sum << endl;
  /* }}} */

  return 0;
}
