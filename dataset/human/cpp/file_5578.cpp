//#include <ext/pb_ds/assoc_container.hpp> 
     //#include <ext/pb_ds/tree_policy.hpp> 
    #include <iostream>
    #include <iomanip>
    #include <sstream>
    #include <cstring>
    #include <vector>
    #include <deque>
    #include <queue>
    #include <set>
    #include <map>
    #include <valarray>
    #include <iterator>
    #include <functional>
    #include <limits>
    #include <algorithm>
    #include <numeric>
    #include <cmath>
    #include <cassert>
    #include <unordered_map>
    #include <unordered_set>
    #include <stack>
    using namespace std;
    #define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #define trace(x) cerr << #x << ": " << x << " " << endl;
     
    typedef int64_t ll;
     
    #define endl '\n'
    #define int ll
    ll mod=1e18;
    ll mod1=1e9+5;
     
    ll power(ll a,ll b)
    {
        if(b==0) return 1;
        else if(b%2==0)
            return power((((a%mod)*(a%mod))%mod),b/2)%mod;
        else return ((a%mod)*(power((((a%mod)*(a%mod))%mod),b/2)%mod))%mod;
    }
     
   //  using namespace __gnu_pbds;
     //#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
    //find_by_order(k)  returns iterator to kth element starting from 0;
    //order_of_key(k) returns count of elements strictly smaller than k;
    //erase,insert same as normal set
  

    int32_t main()
    {
        IOS
  
        
        int n,r;
        cin>>n>>r;
        if(n>=10)
        {
            cout<<r<<endl;
        }
        else
        {
            cout<<r+100*(10-n);
        }


    }
