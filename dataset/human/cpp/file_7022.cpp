#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    static int num[2][200001];
    for(int k=0; k<2; k++) for(int i=0; i<N; i++){
        int a;
        cin >> a;
        num[k][a]++;
    }
    vector<int> ord;
    for(int i=1; i<=N; i++) ord.push_back(i);
    // 前ほどBが多い
    sort(ord.begin(), ord.end(), [&](int i, int j){ return num[0][i]-num[1][i] < num[0][j]-num[1][j]; });

    int offset = 0;
    vector<int> V[2];
    for(int i : ord){
        int l0 = V[0].size(), l1 = V[1].size();
        int r0 = l0 + num[0][i], r1 = l1 + num[1][i];
        offset = max(offset, min(r0, r1) - max(l0, l1));
        for(int k=0; k<2; k++) for(int t=0; t<num[k][i]; t++) V[k].push_back(i);
    }

    rotate(V[1].begin(), V[1].end()-offset, V[1].end());

    vector<pair<int, int>> ans(N);
    for(int i=0; i<N; i++){
        if(V[0][i] == V[1][i]){
            cout << "No" << endl;
            return 0;
        }
        ans[i] = {V[0][i], V[1][i]};
    }

    cout << "Yes" << endl;
    sort(ans.begin(), ans.end());
    for(int i=0; i<N; i++) cout << ans[i].second << " \n"[i==N-1];
    return 0;
}
