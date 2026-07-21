#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;
  long long a;
  int cntm = 0;
  long long ans=0;
  long long minnum = 1000000000;

  for (long long i = 0; i < n; i++)
  {
    cin >> a;
    ans+=abs(a);
    minnum = min(minnum,abs(a));
    if(a<0) cntm++;
  }

  if(cntm%2 == 1){
    ans -= minnum*2;
  }
  cout << ans << endl;

}
