#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void iterate(vector<ll> &v) {
    for(int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    ll N, C; cin >> N >> C;
    vector<ll> dist(N, 0), value(N, 0);

    for(int i = 0; i < N; ++i) {
        cin >> dist[i] >> value[i];
    }

    vector<ll> left(N, 0), leftReturn(N, 0);
    ll val = 0, dst = 0;
    for(int i = 0; i < N; ++i) {
        val += value[i];
        dst = dist[i];
        left[i] = val - dst;
        leftReturn[i] = val - dst * 2;
    }
    leftReturn[0] = max(leftReturn[0], 0LL);
    for(int i = 1; i < N; ++i) {
        leftReturn[i] = max(leftReturn[i], leftReturn[i-1]);
    }


    vector<ll> right(N, 0), rightReturn(N, 0);
    val = 0, dst = 0;
    for(int i = N - 1; i >= 0; --i) {
        val += value[i];
        dst = C - dist[i];
        right[i] = val - dst;
        rightReturn[i] = val - dst * 2;
    }
    rightReturn[N-1] = max(rightReturn[N-1], 0LL);
    for(int i = N - 2; i >= 0; --i) {
        rightReturn[i] = max(rightReturn[i], rightReturn[i+1]);
    }

    ll result = 0;
    for(int i = 0; i + 1 < N; ++i) {
        result = max(result, left[i] + rightReturn[i+1]);
    }
    result = max(result, left[N-1]);

    for(int i = N-1; i - 1 >= 0; --i) {
        result = max(result, right[i] + leftReturn[i-1]);
    }
    result = max(result, right[0]);

    cout << result << endl;

    return 0;
}
