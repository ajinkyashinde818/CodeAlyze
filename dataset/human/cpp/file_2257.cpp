#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> v;
    int cnt = 0;
    bool has_zero = false;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;

        if (a < 0)
            cnt += 1;

        if (a != 0)
            v.push_back(abs(a));
        else
            has_zero = true;
    }
    
    sort(v.begin(), v.end());

    long long int ans = 0;
    if (cnt % 2 == 0 || has_zero){
        for (auto i: v)
            ans += i;
    }
    else{
        for (int i = 1; i < (int) v.size(); i++)
            ans += v[i];
        ans -= v[0];
    }

    cout << ans << '\n';

    return 0;
}
