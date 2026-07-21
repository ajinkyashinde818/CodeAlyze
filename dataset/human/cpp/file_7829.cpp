#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const auto INF = (ll)1e16;  
using  p = pair<int,int>;
using  v = vector<int>;

int main(){
   int n;
   cin >> n;
   auto a = vector<ll>(n,0);
   ll y = 0;
   for (int i = 0; i < n; i++)
   {
      cin >> a[i];
      y+=a[i];
   }
   ll x = 0;
   ll _min = INF;
   for (int i = 0; i < n-1; i++)
   {
      x+=a[i]*2;
      _min = min(_min,abs(x-y));
   }
   cout << _min;
}
