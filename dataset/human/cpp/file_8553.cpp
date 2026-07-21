#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <functional>
#include <iomanip>

using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using P = pair<int, int>;
using LL = long long;

#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define IN_LL(v) LL v;cin>>v;
#define IN(v) int v;cin>>v;
#define OUT(v) cout<<v<<endl
#define MOD 1000000007

int main() {
  IN(N); IN(M);

  vector<string> A, B;
  REP(i, N) {
    string S;
    cin >> S;
    A.push_back(S);
  }
  REP(i, M) {
    string S;
    cin >> S;
    B.push_back(S);
  }
  REP(di, N-M+1) {
    REP(dj, N-M+1) {
      bool same = true;
      REP(i, M) {
        REP(j, M) {
          if (A[i+di][j+dj] != B[i][j]) {
            same = false;
            break;
          }
        }
        if (!same)
          break;
      }
      if (same) {
        OUT("Yes");
        return 0;
      }
    }
  }
  OUT("No");

  return 0;
}
