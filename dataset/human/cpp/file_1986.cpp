#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <map>
#include <numeric>

using namespace std;
typedef long long ll;

int main() {
  ll N,ans=0ll,cnt=0ll;
  cin>>N;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    ll tmp;
    cin>>tmp;
    if(tmp<0){
      cnt++;
      tmp = -tmp;
    }
    A[i]=tmp;
  }
  sort(A.begin(),A.end());
  for(int i=0;i<N;i++){
    if(cnt%2==1 && i==0){
      ans-=A[i];
      continue;
    }
    ans+=A[i];
  }
  cout<<ans<<endl;
}
