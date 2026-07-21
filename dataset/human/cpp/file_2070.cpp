#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
  long N; cin >> N;
  long A[100005];
  for (int i = 0; i < N; i++)
    cin >> A[i];
  
  long ans = 0, mn_abs = 1000000000, how_many_minus = 0;
  for (int i = 0; i < N; i++)
  {
    ans += abs(A[i]);
    mn_abs = min(mn_abs, abs(A[i]));
    if (A[i] < 0)
    {
      how_many_minus ++;
    }
  }
  
  if (how_many_minus % 2 == 0)
  {
    cout << ans << endl;
  }
  else // how_many_minus % 2 == 1
  {
    cout << ans - mn_abs * 2 << endl;
  }
  
  return 0;
}
