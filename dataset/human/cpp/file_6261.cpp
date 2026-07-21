#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;


signed main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
    
    vector<vector<int>> fl(301, vector<int>(301, -1));
    function<int(int,int)> f = [&](int x, int y){
        if(fl[x][y] != -1)
            return fl[x][y];
        set<int> s;
        if(x)
            s.emplace(f(x - 1, y));
        if(y)
            s.emplace(f(x + 1, y - 1));
        for(int i = 1; i <= min(x, y); ++i)
            s.emplace(f(x, y - i));
        int idx = 0;
        while(s.find(idx) != s.end())
            ++idx;
        return fl[x][y] = idx;
    };
    int x = 0;
    for(int i = 0; i < n; ++i)
        x ^= f(a[i], b[i]);
    cout << !bool(x) << endl;
}
