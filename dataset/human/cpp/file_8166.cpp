#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <map>
#include <utility>
#include <numeric>
#include <typeinfo>

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> asum(N+1);
  asum.at(0)=0;
  long long sum=0;
  for(int i=1;i<N+1;i++){
    long long a;
    cin >> a;
    sum+=a;
    asum.at(i)=sum;
  }

  long long ans=100000000000000000;
  for(int i=1;i<N+1-1;i++){
    long long x=asum.at(i);
    long long y=asum.at(N)-asum.at(i);
    ans=min(ans,abs(x-y));
  }
  cout << ans << endl;

  return 0;
}
