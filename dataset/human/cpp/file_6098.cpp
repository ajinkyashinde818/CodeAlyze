#include<bits/stdc++.h>
using namespace std;

int main(){

    long long n, C; cin >> n >> C;
    vector<long long> x(n + 2, 0);
    vector<long long> v(n + 2, 0);
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> v[i];
    }

    x[n + 1] = C;

    vector<long long> a(n + 2);
    vector<long long> b(n + 2);

    for(int i = 1; i <= n; i++){
        a[i] = -(x[i] - x[i - 1]) + v[i];
    }

    for(int i = n; i >= 1; i--){
        b[i] = -(x[i + 1] - x[i]) + v[i];
    }

    /*for(int i = 1; i <= n; i++){
        cout << a[i] << " " << b[i] << endl;
    }*/

    for(int i = 2; i <= n; i++) a[i] += a[i - 1];
    for(int i = n - 1; i >= 0; i--) b[i] += b[i + 1];

    long long ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, max(a[i], b[i]));
        //cout << a[i] << " " << b[i] << endl;
    }

    vector<long long> c(n + 2);
    for(int i = 1; i <= n; i++){
        c[i] = -2*(x[i] - x[i - 1]) + v[i];
    }

    for(int i = 2; i <= n; i++) c[i] += c[i - 1];

    long long q = c[1];
    for(int i = 2; i <= n; i++){

        if(c[i] <= q) c[i] = q;
        else q = c[i];
    }

    /*for(int i = 1; i <= n; i++) cout << c[i] << " ";
    cout << endl;*/

    long long dis = 0;
    long long vv = 0;
    for(int k = n; k >= 2; k--){
        dis += x[k + 1] - x[k];
        vv += v[k];
        ans = max(ans, c[k - 1] + vv - dis);
    }

    dis = 0;
    vv = 0;

    vector<long long> d(n + 2);
    for(int i = n; i >= 1; i--){
        d[i] = -2*(x[i + 1] - x[i]) + v[i];
    }

    for(int i  = n - 1; i >= 1; i--) d[i] += d[i + 1];

    q = d[n];
    for(int i = n - 1; i >= 1; i--){

        if(d[i] <= q) d[i] = q;
        else q = d[i];
    }

    /*for(int i = 1; i <= n; i++) cout << d[i] << " ";
    cout << endl;*/

    for(int k = 1; k < n; k++){
        dis += x[k] - x[k - 1];
        vv += v[k];
        ans = max(ans, d[k + 1] + vv - dis);
    }

    cout << ans << endl;
    return 0;
}
