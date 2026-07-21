#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>

using namespace std;

int main()
{
  int N, R;
  cin >> N >> R;

  if (N < 10)
  {
    cout << R + 100 * (10 - N) << endl;
  }
  else
  {
    cout << R << endl;
  }
}
