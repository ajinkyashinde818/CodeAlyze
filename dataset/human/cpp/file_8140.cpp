#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long LL;
LL i,j,k,n,m;
LL mod=1000000007;
string s;

int main() {
  cin >>n;
  std::vector<LL> v(n),hv(n);
  LL sum =0;
  LL abssum =0;
  for(i=0;i<n;++i) {
    cin>>v[i];
    sum +=v[i];
    abssum +=abs(v[i]);
  }
  hv[0]=v[0];
  LL dsum = abssum;
  LL diff = sum - hv[0];
  dsum = min(dsum, abs(hv[0]-diff));
  for(i=1;i<n-1;++i) {
    hv[i] = v[i] + hv[i-1];
    diff = sum - hv[i];
    dsum = min(dsum, abs(hv[i]-diff));
  }
  cout << dsum << endl;
  return 0;
}
