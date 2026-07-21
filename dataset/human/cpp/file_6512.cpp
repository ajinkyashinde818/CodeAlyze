//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <time.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int N;
string S;

int main(){
  cin >> N >> S;

  if (S[0] == 'W' || S[2*N-1] == 'W'){
    cout << 0 << endl;
    return 0;
  }

  ll ans = 1, now = 1;
  for (int i = 1; i < 2 * N; i++){
    if (S[i] == 'B'){
      if (now % 2 != 0){
        ans *= now; now--;
      }else{
        now++;
      }
    }else{
      if (now % 2 == 0){
        ans *= now; now--;
      }else{
        now++;
      }
    }
    if (now < 0){
      cout << 0 << endl;
      return 0;
    }
    ans %= MOD;
  }

  if (now != 0){
    cout << 0 << endl;
    return 0;
  }

  for (ll i = 1; i <= N; i++){
    ans *= i; ans %= MOD;
  }
  cout << ans << endl;


  return 0;
}
