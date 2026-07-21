// Atcoder
  // Practice Problems
  // D - Flipping Signs
  #include <bits/stdc++.h>
  #include <iostream>
  #include <map>
  #include <queue>
  #include <set>
  #include <string>   
  #include <vector>
  #include <numeric>
  using namespace std;
  typedef long long int ll;
  typedef pair<ll, int> PLI;
  typedef pair<int, int> PII;
  const ll mxsize = 1e5 + 5;
  #define fastIO                                                                 \
    ios_base::sync_with_stdio(false);                                            \
    cin.tie(NULL);                                                               \
    cout.tie(NULL);
  
  /******************************************* IMPORTANT CODE SNIPPETS ************************************************/ 
  
  ll pow(ll x, ll n) {
    if (n == 0)
      return 1ll;
    ll temp;
    temp = pow(x, n / 2);
    if (n % 2 == 0)
      return temp * temp;
    else
      return x * temp * temp;
  }

  ll gcd(ll a, ll b) {
    if (b == 0)
      return a;
    return gcd(b, a % b);
  }

  int sum_digit(int val) {
    if (val < 0)
      return -1;
    if (val == 0)
      return 0;
    int ans = 0;
    while (val > 0) {
      ans = ans + val % 10;
      val = val / 10;
    }
    return ans;
  }

  ll count_div(ll l, ll r, ll val) {
    if (l % val == 0)
      return (((r / val) - (l / val)) + 1);
    else
      return ((r / val) - (l / val));
  }

  int powmod(int x, int y, int m) {
    int res = 1;
    // x = x % mod;
    while (y > 0) {
      if (y & 1)
        res = (res * x) % m;
      cout << res << endl;
      y = y / 2;
      cout << x << endl;
      x = (x * x) % m;
    }
    // cout << res << endl;
    return res;
  }
  /******************************************** CODE STARTS FROM HERE *************************************************/ 
  
  int main()
  {
    fastIO;
    ll n;
    cin >> n;
    ll arr[n];
    for(ll i = 0 ; i < n ; i++)
    cin >> arr[i];
    ll countneg = 0 , minval = INT_MAX , sum = 0;
    for(ll i = 0 ; i < n ; i++)
    {
      if(arr[i] < 0) countneg++;
      minval = min(minval , abs(arr[i]));
      sum = sum + abs(arr[i]);
    }
    if(countneg % 2 == 0)
    {
      cout << sum;
      return 0;
    }
    else
    {
      sum = sum - 2 * abs(minval);
      cout << sum;
      return 0;
    }
  }
