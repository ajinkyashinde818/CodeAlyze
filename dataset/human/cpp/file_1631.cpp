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
#include <bitset>

using namespace std;
typedef long long int LL;
typedef long long int ll;
typedef pair<long long int, long long int> pii;
typedef pair<double, double> pdd;

#define SORT(c) sort((c).begin(),(c).end())
#define BACKSORT(c) sort((c).begin(),(c).end(),std::greater<LL>())
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int idx = 0;
  int sum = 0;

  while(true){
    idx++;
    sum += idx;
    if(sum==n){
        cout << "Yes" << endl;
        vector<vector<int>> v(idx + 1,vector<int>(0));
        int first = 1;
        REP(j, idx + 1)
        {
          int num = idx  - j;
          REP(k,num){
            v[j].push_back(first);
            v[j + k + 1].push_back(first);
            first++;
          }
        }
        cout << idx + 1 << endl;
        REP(j, idx + 1)
        {
          cout << v[j].size() << " ";
          REP(k,v[j].size()){
            cout << v[j][k];
            if(k!=v[j].size()-1){
              cout << " ";
            }
          }
          cout << endl;
        }
        break;
    }
    else
    {
      if(sum>n){
        cout << "No" << endl;
        break;
      }
    }
  }
}
