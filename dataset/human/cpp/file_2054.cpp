#include <bits/stdc++.h>
using namespace std;
vector<int> W(100001);

int main()
{
  int64_t N, a, neg = 0, res = 0;
  cin >> N;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> a;
    if (a < 0)
      neg++;
    A.at(i) = abs(a);
  }
  sort(A.begin(), A.end());
  for (int i = 0; i < N; i++)
  {
    res += A.at(i);
  }
  if (neg % 2)
    res -= 2 * (A.at(0));
  cout << res << endl;
}
