#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int N;
ll a[200005];

int main() {

  cin >> N;
  ll sum=0;
  for( int i=0;i<N;i++){
    cin>>a[i];
    sum+=a[i];
  }

  ll sum2 = a[0];
  ll m = (ll)abs(sum-sum2*2);  
  for( int i=1;i<N-1;i++){
    sum2+=a[i];
    m = min(m,(ll)abs(sum-sum2*2));

  }
  cout<<m<<endl;;
        
    

  return 0;
}
