#include <bits/stdc++.h>

        using namespace std;
        typedef long long ll;
        void __print(int x) {cerr << x;}
        void __print(long x) {cerr << x;}
        void __print(long long x) {cerr << x;}
        void __print(unsigned x) {cerr << x;}
        void __print(unsigned long x) {cerr << x;}
        void __print(unsigned long long x) {cerr << x;}
        void __print(float x) {cerr << x;}
        void __print(double x) {cerr << x;}
        void __print(long double x) {cerr << x;}
        void __print(char x) {cerr << '\'' << x << '\'';}
        void __print(const char *x) {cerr << '\"' << x << '\"';}
        void __print(const string &x) {cerr << '\"' << x << '\"';}
        void __print(bool x) {cerr << (x ? "true" : "false");}

        template<typename T, typename V>
        void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
        template<typename T>
        void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
        void _print() {cerr << "]\n";}
        template <typename T, typename... V>
        void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
        #ifndef ONLINE_JUDGE
        #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
        #else
        #define debug(x...)
        #endif
        const long long INF  = 1e18;
        int md = 1e9+7;
   
        int main()
        {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            int n;
            cin>>n;
            vector<int>a(n),b(n);
            for(int i=0;i<n;i++)
                cin>>a[i];
            for(int i=0;i<n;i++)
                cin>>b[i];
            int prev = -1;
            int j=0;
            for(int i=0;i<n;i++)
            {
                if(prev!=a[i])
                    j = 0;
                if(a[i]==b[i])
                {
                    for(;j<n;j++)
                    {
                        if(a[i]!=a[j] && b[j]!=a[i])
                        {
                            swap(b[i],b[j]);
                            break;
                        }
                    }
                    
                }
                if(a[i]==b[i])
                {
                    cout<<"No";
                    exit(0);
                }
                prev = a[i];
            }
            cout<<"Yes\n";
            for(int i:b)
                cout<<i<<' ';
        }

        //https://www.youtube.com/watch?v=ZQqccia8bVo
