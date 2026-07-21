#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <stack>

using namespace std;
typedef long long ll;

#define MAX_N 1000000
#define INF 1000000

int a[MAX_N];
int b[MAX_N];


int main() {

  // ---------------------
  // Input
  
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int N, R;
  cin >> N >> R;

  // ---------------------
  // 

  int hoge = 0;
  
  if (N >= 10) cout << R << endl;
  else {
    hoge = R + 100*(10-N);
    cout << hoge << endl;
  }
  
  return 0;
  
}
