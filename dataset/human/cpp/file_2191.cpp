#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9+9;

int main() {
  int N;
  cin >> N;
  int smallest{INF};
  int negates{};
  long long sum{};

  for (int i{}; i < N; ++i) {
    int A; cin >> A;
    if (A < 0) ++negates;
    A = abs(A);
    smallest = min(smallest, A);
    sum += A;
  }
  if (negates % 2 != 0)
    sum -= smallest * 2;

  cout << sum << endl;
}
