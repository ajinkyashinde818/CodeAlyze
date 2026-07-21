#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double getTime() {
  return clock() / (double) CLOCKS_PER_SEC;
}

void read() {};

template<typename T, typename... Args>
void read(T& a, Args&... args) {
  cin >> a;
  read(args...);
}

void print() {};

template <typename T, typename... Args>
void print(T a, Args... args) {
  cout << a << " \n"[sizeof...(args) == 0];
  print(args...);
}

int main() {
  int n, r; cin >> n >> r;
  if(n >= 10) {
    print(r);
    return 0;
  }
  cout << (r + (100 * (10 - n))) << '\n';
}
