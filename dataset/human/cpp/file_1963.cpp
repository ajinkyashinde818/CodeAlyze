#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef long long ll;
const ll InF = 1e9 + 1;

int main() {
  int N,flag;
  ll sum,minval;
  cin>>N;
  vector<ll> A(N);
  sum = 0;
  minval = InF;
  for(int i = 0; i < N; i++) {
    cin>>A[i];
    if(A[i]<0) flag++;
    sum += llabs(A[i]);
    minval = min(minval,llabs(A[i]));
  }
  if(flag%2==0) cout<<sum<<endl;
  else cout<<sum-2*minval<<endl;
  return 0;
}
