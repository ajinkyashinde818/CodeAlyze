#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<string> A(N), B(M);
  for (auto & a : A)
    cin >> a;
  for (auto & b : B)
    cin >> b;
  auto cnt = N - M + 1;
  for (int i1 = 0; i1 < cnt; ++i1)
  {
    for (int j1 = 0; j1 < cnt; ++j1)
    {
      int i2, j2;
      for (i2 = i1; i2 < i1 + M; ++i2)
      {
        for (j2 = j1; j2 < j1 + M; ++j2)
        {
          if (A[i2][j2] != B[i2 - i1][j2 - j1])
            break;
        }
        if (j1 + M != j2)
          break;
      }
      if (i1 + M != i2)
        continue;
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
