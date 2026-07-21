#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <functional>

using namespace std;
const int INT_INF = 500000000;
const long long LL_INF = (long long)pow(10, 18);
typedef long long ll;

ll N, C;
ll x[100004] = {0};
ll v[100004] = {0};
ll dp1[100004] = {0};
ll dp2[100004] = {0};
ll dp3[100004] = {0};
ll dp4[100004] = {0};

int main() {
   cin >> N >> C;
   for (int i=0; i < N; i++) {
      cin >> x[i] >> v[i];
   }
   ll v_0toN = 0;
   ll v_Nto0 = 0;
   for (int i=0; i<N; i++) {
      v_0toN += v[i];
      v_Nto0 += v[N-i-1];
      if (dp1[i] >= v_0toN - x[i]) {
	 dp1[i+1] = dp1[i];
	 dp3[i+1] = dp3[i];
      } else {
	 dp1[i+1] = v_0toN - x[i];
	 dp3[i+1] = v_0toN - 2*x[i];
      }
      ll k = v_Nto0 - (C - x[N-i-1]);
      if (dp2[N-i+1] < k) {
	 dp2[N-i] = k;
	 dp4[N-i] = v_Nto0 - 2 * (C - x[N-i-1]);
      } else {
	 dp2[N-i] = dp2[N-i+1];
	 dp4[N-i] = dp4[N-i+1];
      }
      //cout << "i:" << i << " dp1: " << dp1[i] << " dp2: " << dp2[i] << endl;
     //cout << "i:" << i << " dp3: " << dp3[i] << " dp4: " << dp4[i] << endl;
   }
   ll a = 0;
   ll b = 0;
   for (int i=0; i<=N; i++) {
      //cout << "i:" << i << " dp1: " << dp1[i] << " dp2: " << dp2[i] << endl;
     // cout << "i:" << i << " dp3: " << dp3[i] << " dp4: " << dp4[i] << endl;
      a = max(dp4[i+1] + dp1[i], a);
      b = max(dp3[i] + dp2[i+1] , b);
   }
   //cout << a << " " << b << endl;
   cout << max(a, b) << endl;

   return 0;
}
