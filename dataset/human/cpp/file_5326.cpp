#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef long double ld;

using namespace std;
int main()
{
  int n , r;
  cin >> n >> r;
  cout << (n >= 10 ? r : r + 100 * (10 - n)) << endl;
  return 0;
}
