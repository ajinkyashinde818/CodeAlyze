#include<bits/stdc++.h>
using namespace std;

using i64 = long long int;

int main(){
    int n;
    cin >> n;
    vector<i64> acc;
    for(int i=0;i<n;++i){
        i64 a;
        cin >> a;
        if(i == 0)acc.push_back(a);
        else acc.push_back(a+acc.back());
    }

    i64 ans = 2000000000;
    for(int i=0;i<n-1;++i){
        i64 tmp = abs(acc[i] - (acc.back() - acc[i]));
        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}
