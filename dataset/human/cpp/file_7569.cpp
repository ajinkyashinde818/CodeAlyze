#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
map <int ,int> mpa,mpb;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  int a[N];
  ll sum=0;
  for(int i=0;i<N;i++){
    cin >> a[i];
    sum+=a[i];
  }
  ll ans=10000000000;
  ll sum2=0;
  for(int i=0;i<N-1;i++){
    sum2+=a[i];
    ans=min(ans,abs(sum-2*sum2));
  }
  cout << ans << endl;
  return 0;
}
