#include <iostream>
#include <vector>
#include <climits>
using int64 = long long;
using namespace std;

int main()
{
  int n;
  cin >> n;
  int64 absSum = 0;
  int negativeCount = 0;
  int absMin = INT_MAX;
  for (int i = 0; i < n; ++i)
  {
    int tmp;
    cin >> tmp;
    if (tmp < 0)
    {
      ++negativeCount;
      tmp = -tmp;
    }
    absMin = tmp < absMin ? tmp : absMin;
    absSum += tmp;
  }
  
  if ((negativeCount & 1) == 0)
  {
    cout << absSum << endl;
  }
  else
  {
    cout << (absSum - 2 * absMin) << endl;
  }
  
  return 0;
}
