#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base :: sync_with_stdio(0);
   cin.tie(0) , cout.tie(0);
   int n;
   cin >> n;
   long long sum = 0LL;
   int tot = 0 , mini = 1e9;
   for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      sum += abs(x);
      tot += (x < 0);
      mini = min(mini , abs(x));
   }
   if (tot % 2 == 0) {
      cout << sum << '\n';
   } else {
      cout << sum - 2 * mini << '\n';
   }
   return 0;
}
