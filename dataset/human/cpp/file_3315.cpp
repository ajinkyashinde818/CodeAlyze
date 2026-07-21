#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
long long int mod = 1e9;

int main(){
  int n; cin >> n;
  long long int sum = 0;
  long long int mn = 1e9;
  int c = 0;
  for(int i=0; i<n; i++) {
    long long int a;
    cin >> a;
    if(a < 0) c++;
    a = abs(a);
    mn = min(mn, a);
    sum += a;
  }
  
  if(c%2 == 0) cout << sum << endl;
  else cout << sum - mn*2 << endl;


  return 0;
}




// EOF
