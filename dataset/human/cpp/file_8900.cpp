#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <bitset>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef long long LL;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<string, int> PSI;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define SORTG(c) sort((c).begin(),(c).end(),greater<auto>())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define REP(i,n)  for(int i=0; i<(n); i++)

//constant
//--------------------------------------------
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
const LL MOD = 1e9+7; 
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n,vector<char> (n)), b(m, vector<char>(m));
  REP(i,n){
    REP(j, n){
      cin >> a[i][j];
    }
  }
  REP(i,m){
    REP(j,m){
      cin >> b[i][j];
    }
  }
  bool ans = false;
  REP(i, n-m+1){
    REP(j, n-m+1){
      bool flg = true;
      REP(k, m){
        REP(l, m){
          if(a[i+k][j+l]!=b[k][l]){
            flg=false;
            break;
          }
        }
        if(flg==false) break;
      }
      if(flg){
        ans = true;
        break;
      }
    }
    if(ans) break;
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}
