#include <iostream>
#include <algorithm>
#include <ostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <cmath>
#include <cstring>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using ll = long long;

template <typename T, typename U>
std::ostream &operator<<(std::ostream &out, std::pair<T, U> p)
{
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, std::vector<T> v)
{
  out << "[";
  for (int i = 0; i < v.size(); ++i)
  {
    out << v[i] << (i == (v.size() - 1) ? "" : ", ");
  }
  out << "]";
  return out;
}

int n;
std::vector<int> a;

int main()
{
  cin >> n;
  a.resize(n);

  int n_minus = 0, a_min = int(1e9) + 1;
  ll sum = 0LL;

  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];

    sum += abs(a[i]);
    a_min = std::min(a_min, abs(a[i]));

    if (a[i] < 0)
    {
      n_minus++;
    }
  }

  if (n_minus % 2 == 0)
  {
    cout << sum << endl;
  }
  else
  {
    cout << sum - 2 * a_min << endl;
  }

  return 0;
}
