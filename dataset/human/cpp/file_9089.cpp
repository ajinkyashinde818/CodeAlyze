#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cstring>
#include<climits>
#include<sstream>
#include<deque>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<bitset>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef long long ll;

int N,M;

bool same(vector<string> &A,vector<string> &B,int bx,int by) {
  rep(dx,M) {
    rep(dy,M) {
      int x = bx + dx;
      int y = by + dy;
      if( !( x < N && y < N ) ) return false;
      if( A[y][x] != B[dy][dx] ) return false;
    }
  }
  return true;
}

bool comp(vector<string> &A,vector<string> &B) {
  rep(i,N-M+1) {
    rep(j,N-M+1) {
      if( same(A,B,j,i) ) return true;
    }
  }
  return false;
}

int main() {
  cin >> N >> M;
  vector<string> A(N);
  rep(i,N) cin >> A[i];
  vector<string> B(M);
  rep(i,N) cin >> B[i];
  puts(comp(A,B)?"Yes":"No");
  return 0;
}
