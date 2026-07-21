#include<iostream>
    #include<stdio.h>
    //#include <bits/stdc++.h>
    #include<vector>
    #include<float.h>
    #include<iomanip>
    #include<algorithm>
    #include<string>
    #include<cstring>
    #include<math.h>
    #include<sstream>
    #include<set>
    #include<map>
    #include<queue>
    #include<deque>

    #define INF 1e9
    #define rep(i,n)for(int i=0;(i)<(int)(n);i++)
    #define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
    #define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
    #define vec(type,n) vector<type>(n)
    #define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))

    using namespace std;
    using ll = long long;
	  
    int main(){
      int n;
      cin>>n;
      VEC(ll,a,n);
      auto sum = vec(ll,n);
      rep(i,n)sum[i] = 0;
      sum[0] = a[0];
      REP(i,1,n-1)sum[i] += (sum[i-1]+a[i]);
      ll ans = INF*1000;
      rep(i,n){
        if(i == n-1)continue;
        ans = min(ans,abs(sum[i]-(sum[n-1]-sum[i])));
      }
      cout<<ans;
    }
