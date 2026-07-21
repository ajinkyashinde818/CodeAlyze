#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  long long sum = 0;

  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  int neg_n = 0;
  for (int i = 0; i < N; i++)
  {
    if (A[i] < 0)
      neg_n++;
  }

  int check = 0;

  for (int i = 0; i < N; i++)
  {
    if (A[i] == 0)
    {
      check = 1;
    }
  }

  if (check == 1)
  {
    for (int i = 0; i < N; i++)
    {
      sum += abs(A[i]);
    }
  }
  else if (neg_n % 2 == 0)
  {
    for (int i = 0; i < N; i++)
    {
      sum += abs(A[i]);
    }
  }
  else
  {
    vector<int> B(N);
    for (int i = 0; i < N; i++)
    {
      B[i] = abs(A[i]);
    }
    sort(B.begin(), B.end());
    for (int i = 1; i < N; i++)
    {
      sum += abs(B[i]);
    }
    sum -= abs(B[0]);
  }
  cout << sum << endl;
}
