#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
 
int main() {
 
  int long long t=0,i=0,j=0,N,R;
  int ans;
  
  cin >> N >> R;

  if (N>=10)
  {
    ans=R;
  }else
  {
    ans=R+100*(10-N);
  }
  
  
  cout << ans <<endl;
  return 0;
}
