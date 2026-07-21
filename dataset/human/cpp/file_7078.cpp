#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    vector<int> countA(N + 1), countB(N + 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        ++countA[A[i]];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
        ++countB[B[i]];
    }
    set<pair<int, int>> S;
    for (int i = 1; i <= N; ++i) {
        if (countA[i] + countB[i] > N) {
            cout << "No\n";
            return 0;
        }
        if (countB[i] != 0) {
            S.insert({countA[i] + countB[i], i});
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < N; ++i) {
        auto it = S.end();
        --it;
        if (it->second == A[i]) {
            --it;
        }
        auto P = *it;
        cout << P.second << " ";
        S.erase(it);
        --countB[P.second];
        if (countB[P.second] > 0) {
            --P.first;
            S.insert(P);
        }
        S.erase({countA[A[i]] + countB[A[i]], A[i]});
        --countA[A[i]];
        if (countB[A[i]] > 0) {
            S.insert({countA[A[i]] + countB[A[i]], A[i]});
        }
    }
    cout << '\n';
    return 0;
}
