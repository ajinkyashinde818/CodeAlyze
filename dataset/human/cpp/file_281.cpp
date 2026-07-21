#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <sstream>
#include <set>
using namespace std;
using ll = long long;

class range {private: struct I{int x;int operator*(){return x;}bool operator!=(I& lhs){return x<lhs.x;}void operator++(){++x;}};I i,n;
public:range(int n):i({0}),n({n}){}range(int i,int n):i({i}),n({n}){}I& begin(){return i;}I& end(){return n;}};

int main() {
  int R,G,B,N;
  cin >>R>>G>>B>>N;
  int ret=0;
  for (int r : range(N+1)) {
    for (int g : range(N+1)) {
      int rest = N-r*R-g*G;
      if (rest >= 0 && rest % B == 0) ret++;
    }
  }
  cout << ret << endl;
}
