#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010


int main(){
  int n, m;
  bool used[SIZE*2] = {};
  int a[SIZE*3] = {};
  
  scanf("%d%d", &n, &m);

  for(int i=0;i<m;i++){
    scanf("%d", a+i);
  }

  reverse(a, a+m);
  for(int i=0;i<n;i++){
    a[i+m] = i+1;
  }

  for(int i=0;i<n+m;i++){
    if(!used[a[i]]){
      printf("%d\n", a[i]);
      used[a[i]] = true;
    }
  }
  
  return 0;
}
