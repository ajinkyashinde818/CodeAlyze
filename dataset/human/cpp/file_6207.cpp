#include <iostream>
#include <ccomplex>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <functional>
#include <cmath>
#include <iomanip>
#include <map>
#include <numeric>
#include <list>
#include <assert.h>
#include <math.h>
#include <valarray>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <complex>
#include <list>
#include <time.h>
#include <stack>
#include <locale>
#include <clocale>
#include <ctype.h>
#include <wchar.h>
#include <random>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long int LL;
typedef long long int ll;
typedef pair<long long int, long long int> pii;
typedef pair<double, double> pdd;

#define SORT(c) sort((c).begin(),(c).end())
#define BACKSORT(c) sort((c).begin(),(c).end(),std::greater<LL>())
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

int main() {
  LL N, C;
  cin >> N >> C;
  vector<pii> sushi(N);

  REP(i,N){
    LL x, v;
    cin >> x >> v;
    sushi[i] = make_pair(x, v);
  }

  vector<LL> ruiseki(N+1);

  ruiseki[0] = 0;

  REP(i,N){
    ruiseki[i + 1] = ruiseki[i] + sushi[i].second;
  }

  vector<LL> saiteki_f(N+1);
  vector<LL> saiteki_f_2(N+1);

  saiteki_f[0] = 0;
  saiteki_f_2[0] = 0;

  REP(i,N){
    saiteki_f[i + 1] = max(saiteki_f[i], ruiseki[i + 1] - sushi[i].first);
    saiteki_f_2[i + 1] = max(saiteki_f_2[i], ruiseki[i + 1] - sushi[i].first*2);
  }

  vector<LL> saiteki_b(N+1);
  vector<LL> saiteki_b_2(N+1);

  saiteki_b[N] = 0;
  saiteki_b_2[N] = 0;

  for (int i = N-1; i >= 0;--i){
    saiteki_b[i] = max(saiteki_b[i+1], (ruiseki[N]-ruiseki[i]) - (C-sushi[i].first));
    saiteki_b_2[i] = max(saiteki_b_2[i+1], (ruiseki[N]-ruiseki[i]) - (C-sushi[i].first)*2);
  }

  LL max_eiyou = 0;

  REP(i,N+1){
    LL eiyou1 = saiteki_f[i] + saiteki_b_2[i];
    if(eiyou1>max_eiyou){
      max_eiyou = eiyou1;
    }
    LL eiyou2 = saiteki_f_2[i] + saiteki_b[i];
    if(eiyou2>max_eiyou){
      max_eiyou = eiyou2;
    }
  }

  cout << max_eiyou << endl;
}
