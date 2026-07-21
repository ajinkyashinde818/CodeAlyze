#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
//typedef long long unsigned int ll;
typedef long long ll;
//typedef pair<ll, ll> edge;
//typedef tuple<ll, ll, ll> tp;
const ll INF = 1e18;
 
int main() {
  ll n;
  cin >> n;
  ll a[n];
  ll mi = INF;
  ll sum = 0;
  
  int flag1 = 0;
  for(int i=0; i<n; i++){
    cin >> a[i];
    mi = min(abs(a[i]), mi);
    sum += abs(a[i]);
    if(a[i] == 0) flag1 = 1;
  }
  
  if(flag1 == 1){
    cout << sum << endl;
    exit(0);
  }
  
  int flag2 = 1;
  for(int i=0; i<n-1; i++){
    if(a[i]*flag2 < 0) flag2 = -1;
    else flag2 = 1;
  }
  if (a[n-1]*flag2 < 0) cout << sum - 2*mi << endl;
  else cout << sum << endl;
  
}
