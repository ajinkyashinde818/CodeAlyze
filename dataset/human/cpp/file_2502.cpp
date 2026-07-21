#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
using namespace std;


typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)


int main(){
  int n;
  cin >> n;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  int count = 0;
  ll sum = 0;
  ll mi = INT_MAX;
  for(int i = 0; i < n; ++i){
    if(A[i] < 0){
     count++;
     sum += -A[i];
    } else {
      sum += A[i];
    }
    mi = min(mi, abs(A[i]));

  }

  if(count % 2 == 0){
    cout << sum << endl;
  } else {
    cout << sum - 2 * mi << endl;
  }
}
