#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

//#define DEBUG


int main(void)
{
  int N;
  int R;
  cin >> N >> R;
  if(N>=10)
  {
    cout << R;
  }
  else
  {
    cout << R + 100*(10-N);
  }
  
  
  return 0;
}
