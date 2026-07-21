#include <iostream>
  #include <complex>
  #include <vector>
  #include <string>
  #include <algorithm>
  #include <cstdio>
  #include <numeric>
  #include <cstring>
  #include <ctime>
  #include <cstdlib>
  #include <set>
  #include <map>
  #include <unordered_map>
  #include <unordered_set>
  #include <list>
  #include <cmath>
  #include <bitset>
  #include <cassert>
  #include <queue>
  #include <stack>
  #include <deque>
 #include <iomanip>
#include <fstream>
#include <climits>
 
  using namespace std;
   
 
//abcdefghijklmnopqrstuvwxyz
//ABCDEFGHIJKLMNOPQRSTUVWXYZ

  typedef long long ll;
  typedef long double lld;
  typedef unsigned long long ull;
  int INF = INT_MAX;
  ll mod = 1000000007;
  // lld PI = 3.141592653;



  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
     int n;
     cin>>n;
     vector<int> a(n), b(n), c(n);
     vector<pair<int,int>> indexes(n+1, {INF, 0});
     for (int i = 0;i<n;i++) {cin>>a[i]; indexes[a[i]].first = min(indexes[a[i]].first, i); indexes[a[i]].second = max(indexes[a[i]].second, i);}
      for (int i = 0;i<n;i++) cin>>b[i];
      pair<int,int> cant = {INF, -1};
      // for (int i = 1;i<=n;i++) cout<<indexes[i].first<<" "<<indexes[i].second<<endl;
      for (int i = 0;i<n;i++){
        if (indexes[b[i]].first == INF || indexes[b[i]].second == INF) continue;

        // cout<<indexes[b[i]].first<<" "<<indexes[b[i]].second<<endl;
        // cout<<i<<" "<<endl;
        // cout<<indexes[b[i]].second - i<<endl;
        int f = indexes[b[i]].first - i;
        int s = indexes[b[i]].second - i;
        // cout<<f<<" "<<s<<endl;
        // cout<<i<<endl;
        // cout<<indexes[b[i]].first<<" "<<indexes[b[i]].second<<endl;
        cant.first = min({f, cant.first, s});
       cant.second = max({s, cant.second, f});
        // cout<<cant.first<<endl;
      }
      // cout<<cant.first<<" "<<cant.second<<"\n";
      set<int> cannot;
      for (int t = cant.first; t<=cant.second;t++) cannot.insert((t+n)%n);
      for (int k = 0;k<n;k++){
        if (cannot.count(k)) continue;

        int step = (k+n)%n;
        // cout<<k<<endl;
        for (int i = 0;i<n;i++){
            c[(i+step)%n] = b[i];


        }
        cout<<"Yes\n";
        for (int i = 0;i<n;i++) cout<<c[i]<<" ";
        cout<<"\n";
      return 0;
      }
      cout<<"No\n";
}
