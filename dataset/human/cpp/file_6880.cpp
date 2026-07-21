#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A_vec(N), B_vec(N);
    for (int i = 0; i < N; ++i)
        cin >> A_vec.at(i);
    for (int i = 0; i < N; ++i)
        cin >> B_vec.at(i);
    vector<int> cumcnt_A(N + 1, 0), cumcnt_B(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        ++cumcnt_A.at(A_vec.at(i));
        ++cumcnt_B.at(B_vec.at(i));
    }
    for (int i = 1; i <= N; ++i) {
        int cnt = cumcnt_A.at(i) + cumcnt_B.at(i);
        if (cnt > N) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 0; i < N; ++i) {
        cumcnt_A.at(i + 1) += cumcnt_A.at(i);
        cumcnt_B.at(i + 1) += cumcnt_B.at(i);
    }
    int max_diff = - N - 1;
    for (int i = 0; i < N; ++i) {
        int diff = cumcnt_A.at(i + 1) - cumcnt_B.at(i);
        if (max_diff < diff)
            max_diff = diff;
    }
    cout << "Yes" << endl;
    cout << B_vec.at((-max_diff + N) % N);
    for (int i = 1; i < N; ++i)
        cout << " " << B_vec.at((i - max_diff + N) % N);
    cout << endl;
}
