#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
  int n, r;
  cin >> n >> r;
  int rate;
  if(n < 10) cout << r + 100 * (10 - n) << endl;
  else cout << r << endl;
}
