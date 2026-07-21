#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;

int R, G, B, N;
int memo[3001][3001];

int dfs(int r, int g)
{
  int sum = R*r+G*g;
  int ret = 0;
  if (memo[r][g] != 0) return 0;
  if ((N-sum) % B == 0) {
    ret++;
  }
  if (sum + R <= N)
    ret += dfs(r+1, g);
  if (sum + G <= N)
    ret += dfs(r, g+1);
  memo[r][g] = ret;
  return ret;
}

int main()
{
  cin >> R >> G >> B >> N;
  int ans = dfs(0, 0);
  cout << ans << endl;
  return 0;
}
