#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<utility>

using namespace std;

int main(){
    long long n, c, ans = 0;
    cin >> n >> c;
    vector<long long> p1(n + 2), p2(n + 2),x(n + 2), v(n + 2);
    for(int i = 1; i < n + 1; i++){
        cin >> x[i] >> v[i];
    }
    x[n + 1] = c; v[n + 1] = 0;
    for(int i = 1; i < n + 1; i++){
        p1[i] = p1[i - 1] + v[i] - (x[i] - x[i - 1]);
    }
    for(int i = 1; i < n + 1; i++){
        p1[i] = max(p1[i - 1], p1[i]);
    }
    for(int i = n; i >= 0; i--){
        p2[i] = p2[i + 1] + v[i] - (x[i + 1] - x[i]);
    }
    for(int i = n - 1; i >= 0; i--){
        p2[i] = max(p2[i], p2[i + 1]);
    }
    for(int i = 1; i < n + 1; i++){
        long long tmp = p1[i], tmp2 = p2[i + 1] - x[i];
        if(i < n && tmp2 > 0) tmp += tmp2;
        ans = max(ans, tmp);
    }
    for(int i = 1; i < n + 1; i++){
        long long tmp = p2[i], tmp2 = p1[i - 1] - (c - x[i]);
        if(i > 1 && tmp2 > 0) tmp += tmp2;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
