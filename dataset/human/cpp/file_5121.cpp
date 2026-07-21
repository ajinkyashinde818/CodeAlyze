#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <climits>
#include <iomanip>

using namespace std;

template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
bool chmax(T &a, T b)
{
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  int N;
  int R;

  cin >> N >> R;

  int internal_R;

  if (N >= 10)
  {
    internal_R = R;
  }
  else
  {
    internal_R = R + 100 * (10 - N);
  }

  cout << internal_R;

  return 0;
}
