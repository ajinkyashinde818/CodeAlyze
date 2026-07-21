#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ii {
    int a, b;
    bool operator < (ii o) const {
        return tie(a, b) < tie(o.a, o.b);
    }
};
struct iii {
    int a, b, c;
    bool operator < (iii o) const {
        return tie(a, b, c) < tie(o.a, o.b, o.c);
    }
};
istream &operator >> (istream &is, ii &st) { is >> st.a >> st.b; return is; }
template <typename T> istream &operator >> (istream &is, vector<T> &vec) { for (auto &v: vec) is >> v; return is; }
template <typename T> ostream &operator << (ostream &os, vector<T> &vec) {
    for (int i = 0; i < (int)vec.size(); i++) {
        os << vec[i];
        if (i < (int)vec.size() - 1) os << " ";
    }
    return os;
}

const int MOD = 1000000007;
const int INF = 1000000000;
const int MAXN = 1000005;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    cin >> A >> B;
    
    vector<int> cntA(N+1), cntB(N+1);
    for (int i = 0; i < N; i++) {
        cntA[A[i]]++;
        cntB[B[i]]++;
    }
    for (int i = 1; i <= N; i++) {
        if (cntA[i] + cntB[i] > N) {
            cout << "No\n";
            return 0;
        }
    }
    
    reverse(B.begin(), B.end());
    vector<int> idxSame;
    int mid = -1;
    for (int i = 0; i < N; i++) {
        if (A[i] == B[i]) {
            idxSame.push_back(i);
            mid = A[i];
        }
    }
    for (int i = 0; i < N && !idxSame.empty(); i++) {
        if (A[i] == mid || B[i] == mid) continue;
        swap(B[idxSame.back()], B[i]);
        idxSame.pop_back();
    }
    cout << "Yes\n";
    cout << B << "\n";
    
}
