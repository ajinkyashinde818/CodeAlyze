#include <bits/stdc++.h>

using namespace std;

const string YES = "Yes";

const string NO = "No";

void solve(int N, vector<int> A, vector<int> B) {
    vector<int> cnt_A(N + 1), cnt_B(N + 1);
    for (int i = 0; i < N; i++) {
        cnt_A.at(A.at(i))++;
        cnt_B.at(B.at(i))++;
    }
    for (int i = 1; i <= N; i++) {
        if (cnt_A.at(i) + cnt_B.at(i) > N) {
            cout << NO << endl;
            return;
        }
    }
    cout << YES << endl;
    vector<int> C(N + 1), D(N + 1);
    for (int i = 1; i <= N; i++) {
        C.at(i) = C.at(i - 1) + cnt_A.at(i);
        D.at(i) = D.at(i - 1) + cnt_B.at(i);
    }
    int x = 0;
    for (int i = 1; i <= N; i++) {
        x = max(x, C.at(i) - D.at(i - 1));
    }
    for (int i = 0; i < N - 1; i++) {
        cout << B.at((i - x + N) % N) << " ";
    }
    cout << B.at((N - 1 - x + N) % N) << endl;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> B.at(i);
    }
    solve(N, move(A), move(B));
    return 0;
}
