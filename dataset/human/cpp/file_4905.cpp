#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



ifstream fin ("calafat.in");
ofstream fout ("calafat.out");

int n, r;

int main()
{
  cin >> n;
  cin >> r;
  if (n >= 10) {
    cout << r;
  }
  else
    cout << r + 100 * (10 - n);
  return 0;
}
