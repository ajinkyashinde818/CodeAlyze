#include <bits/stdc++.h>

using namespace std;
int n;
long long c, x[100001], v[100001], p[100001], s[100002], px[100001], sx[100002];
int main(){
    cin >> n >> c;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> v[i];
        p[i] = p[i - 1] + v[i] - (x[i] - x[i - 1]);
    }
    for(int i = n; i >= 1; i--){
        if(i == n){
            s[i] = s[i + 1] + v[i] - (c - x[i]);
        }
        else{
            s[i] = s[i + 1] + v[i] - (x[i + 1] - x[i]);
        }
    }
    for(int i = 1; i <= n; i++){
        px[i] = max(px[i - 1], p[i] - x[i]);
    }
    for(int i = n; i >= 1; i--){
        sx[i] = max(sx[i + 1], s[i] - (c - x[i]));
    }
    long long mx = 0;
    for(int i = 1; i <= n; i++){
        mx = max(mx, max(max(p[i], s[i]), max(px[i - 1] + s[i], sx[i + 1] + p[i])));
    }
    cout << mx;
}
