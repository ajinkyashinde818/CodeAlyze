#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dot[7] ={
  5000000,
  2500000,
  1250000,
   625000,
   312500,
   156250,
    78125
};
int get(string s, int k){
  //k - 0..31
  int l = k % 4;
  int m = 7 - k / 4;
  if(isdigit(s[m])){
    int n = s[m] - '0';
    return n >> l & 1;
  }else{
    int n = s[m] - 'a' + 10;
    return n >> l & 1;
  }
}
string tos(int N){
  stringstream ss;
  ss<<N;
  return ss.str();
}


int main(){
  int N;
  while(cin>>N){
    REP(i, N){
      string s;
      cin>>s;
      int low = 0;
      int high = 0;
      REP(i, 7) low += dot[i] * get(s, 6 - i);
      REP(i, 24) high += (1<<i) * get(s, 7 + i);
      string t;
      if(get(s, 31)) t += "-";
      t += tos(high);
      t += ".";
      string l = tos(low);
      while(l.size() < 7) l = "0" + l;
      t += l;
      int end = t.size() - 1;
      while(t[end] == '0' && t[end - 1] != '.') end--;
      cout<<t.substr(0, end + 1)<<endl;
    }
  }
  return 0;
}
