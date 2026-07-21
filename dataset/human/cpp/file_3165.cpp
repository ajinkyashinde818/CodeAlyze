#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "math.h"
#include "cstring"
#include "stack"
#include "queue"

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll> > mat;

int main()
{
  int n;
  cin >> n;
  ll a[100100];
  int parity = 0;
  ll minabs = 100000000000;
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (a[i] < 0)
    {
      parity++;
    }
    if (minabs > abs(a[i]))
    {
      minabs = abs(a[i]);
    }
    ans += abs(a[i]);
  }
  cout << (parity % 2 == 0 ? ans : ans - 2 * minabs) << "\n";
}
