#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N;
    cin >> N;
    vector<long long> A(N+1);
    for ( int i=1; i<=N; i++ )
        cin >> A.at(i);

    /*
     * ans.at[i].at(0) : i番目を-1倍したときの最大値
     * ans.at[i].at(1) : i番目を-1倍しなかったときの最大値 */
    vector<vector<long long>> ans(N+1, {0, 0});
    ans.at(1).at(0) = -1 * A.at(1);
    ans.at(1).at(1) = A.at(1);
    for ( int i=2; i<N; i++ ) {
        ans.at(i).at(0) = max(ans.at(i-1).at(0) + A.at(i),  /* i-1番目とi番目を-1倍した場合 */
                              ans.at(i-1).at(1) - A.at(i)); /* i番目だけ-1倍した場合 */
        ans.at(i).at(1) = max(ans.at(i-1).at(0) - A.at(i),
                              ans.at(i-1).at(1) + A.at(i));
    }

    long long final_ans = max(ans.at(N-1).at(0) - A.at(N), ans.at(N-1).at(1) + A.at(N));
    cout << final_ans << endl;
    return 0;
}
