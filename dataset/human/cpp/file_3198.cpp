#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<long long int> v;
  int count = 0;
  for(int i = 0;i < n;i++)
  {
    long long int a;
    cin >> a;
    if(a < 0)
    {
      a = a * (-1);
      count++;
    }
    v.push_back(a);
  }
  long long int sum = 0;
  if(count % 2 == 0)
  {
    for(int i = 0;i < n;i++)
    {
      sum += v.at(i);
    }
  }
  else
  {
    sort(v.begin(),v.end());
    for(int i = 1;i < n;i++)
    {
      sum += v.at(i);
    }
    sum = sum - v.at(0);
  }
  cout << sum << "\n";

  return 0;
}
