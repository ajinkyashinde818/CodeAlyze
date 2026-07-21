#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
ll INF = 500000000000000;
int main(){
  int N;
  cin >> N;
  ll a[N];

  for(int i=0;i<N;i++){
  	cin >> a[i];
  } 

  ll sum = 0;
  for(int i=0;i<N;i++){
  	sum += a[i];
  }

  ll ans = INF;
  ll sunuke = 0;
  for(int i=0;i<N-1;i++){
  	sunuke += a[i];
  	ll error = abs(sum - 2*sunuke);
  	ans = min(ans, error);
  }

  cout << ans <<endl;
  return 0;
}
