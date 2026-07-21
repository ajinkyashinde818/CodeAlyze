#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int cntA[N] = {}, cntB[N] = {};
int A[N] = {}, B[N] = {}, ans[N] = {};
struct node {
    int val, a = 0, b = 0;
} arr[N];
struct cmp {
    inline bool operator()(const node &x, const node &y) {
        return x.a + x.b < y.a + y.b;
    }
};
priority_queue<node, vector<node>, cmp> pq;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        cntA[A[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
        cntB[B[i]]++;
    }
    for (int i = 1; i <= n; i++)
        if (cntB[i]) pq.emplace(node({i, cntA[i], cntB[i]}));
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        node tmp, R = {0, 0, 0};
        int x, a, b;
        flag = false;
        while (!pq.empty()) {
            tmp = pq.top(), pq.pop();
            //cout << tmp.val << " " << tmp.a << " " << tmp.b << '\n';
            if (tmp.val == A[i]) {
                R = tmp;
                continue;
            }
            x = tmp.val, a = tmp.a, b = tmp.b;
            if (cntA[x] != a || cntB[x] != b) {
                pq.emplace(node({x, cntA[x], cntB[x]}));
                continue;
            }
            flag = true;
            ans[i] = x;
            cntB[x]--;
            if (b > 1) pq.emplace(node{x, cntA[x], cntB[x]});
            break;
        }
        if (R.val) pq.emplace(R);
        if (!flag) break;
        cntA[A[i]]--;
    }
    if (flag) {
        cout << "Yes\n";
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " \n"[i == n];
    }
    else cout << "No\n";
    return 0;
}
