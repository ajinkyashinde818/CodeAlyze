#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<int> v(N); 
    ll sum = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        if(v[i]<0) cnt++;
        v[i] = abs(v[i]);
        sum += v[i];
    }

    if(cnt%2==0) cout << sum << endl;
    else {
        sort(v.begin(), v.end());
        cout << sum - 2*v[0] << endl;
    }
    

}
