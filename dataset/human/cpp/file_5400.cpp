#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll ;

int main()
{
  
  int n,r;
  cin>>n>>r;
  if(n>=10) cout<<r;
  else cout << r+1000-(100*n);
  
}
