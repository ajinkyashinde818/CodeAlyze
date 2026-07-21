#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

using ipair = pair<int,int>;

int INF = 1e9+7;

using ipair = pair<int,int>;
bool operator>(const ipair a,const ipair b){return a.first > b.first;}


int M = 2019;

int main(){

  int N;
  cin >> N;


  int minus_odd = 0;;
  int minus_even = 0;;

  ll min_odd = INF;
  ll min_even = INF;

  ll ans = 0;

  rep(i, N){
    ll tmp;
    cin >> tmp;
    if(i%2==0){ 
      if(tmp < 0) minus_even++;
      tmp = abs(tmp);
      ans += tmp;
      min_even = min(min_even, tmp);
    }else {
      if(tmp < 0) {
        minus_odd++;
      }
      tmp = abs(tmp);
      ans += tmp;
      min_odd = min(min_odd, tmp);
    }
  }

  if((minus_even+minus_odd) %2 == 1){
    ans -= 2 * min(min_odd, min_even);
  }

  cout << ans << endl;

}
