#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m; cin >> n >> m;
  stack<int> st;
  for(int i = n; i > 0; i--) st.push(i);
  FOR(i,0,m) {
    int in; cin >> in;
    st.push(in);
  }
  bool used[n+1]; CLR(used);
  while(!st.empty()) {
    int x = st.top(); st.pop();
    if(!used[x]) {
      cout << x << endl;
      used[x] = true;
    }
  }
  return 0;
}
