#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<numeric>
using namespace std;
using ll = long long;
int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  int m = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] < 0){
      m++;
      a[i] *= -1;
    }
  }
  if(m % 2 == 0){
    ll sum = 0;
    for(int i = 0; i < n; i++){
      sum += a[i];
    }
    cout << sum << endl;
  }else{
    ll sum = 0;
    ll mini = 1001001001;
    for(int i = 0; i < n; i++){
      mini = min(mini, a[i]);
      sum += a[i];
    }
    cout << sum - mini * 2<< endl;
  }

    return 0;
}
