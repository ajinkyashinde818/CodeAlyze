#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

class range {
private:
  struct Iterator {
    int val;
    int operator*() {return val;}
    bool operator!=(Iterator &itr) {return val < itr.val;}
    void operator++() {++val;}
  };
  Iterator i, n;
public:
  range(int n) : i({0}), n({n}) {}
  range(int i, int n) : i({i}), n({n}) {}
  Iterator &begin() {return i;}
  Iterator &end() {return n;}
};

template<class T> T at(vector<T> v, int i) {return v[(i % (int)v.size() + v.size()) % v.size()];}

int main() {
  int t, d, ta, tb, da, db;
  cin >> t >> d >> ta >> tb >> da >> db;
  double res = 1e9;
  for (int i : range(d + 1)) if (i % da == 0) {
    for (int j : range(d + 1)) if (j % db == 0) {
      if (1 <= i + j && i + j <= d) res = min(res, abs(t - (double)(ta * i + tb * j) / (i + j)));
    }
  }
  cout << fixed << setprecision(15) << res << endl;
}
