#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main() {
  long long n; cin >> n; long long m=1e9, minus=0,zero=0,sum=0;
  for (int i=0; i<n; i++) {
    long long a; cin >> a;
    sum+=abs(a);
    if (a!=0) m=min(m,abs(a));
    else zero++;
    if (a<0) minus++;
  }
  if (minus % 2 == 0) cout << sum << endl;
  else {
    if (zero>=1) cout << sum << endl;
    else cout << sum - 2*m << endl;
  }
}
