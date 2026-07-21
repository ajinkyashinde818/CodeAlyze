#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<climits>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int n,r; cin >> n >> r;
  if(n>=10)cout  << r << endl;
  else{
    cout << r + 100 * (10-n) << endl;
  }
  return 0;
}
