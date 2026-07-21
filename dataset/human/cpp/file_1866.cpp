#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m; cin >> n >> m;
    vector<bool> used(n+1, false);
    vector<int> e(m);
    for(int i = 0; i < m; i++){
        cin >> e[i];
    }

    reverse(e.begin(), e.end());
    for(int i = 0; i < m; i++){
        if(used[e[i]] == false){
            cout << e[i] << endl;
            used[e[i]] = true;
        }
    }

    for(int i = 1; i <= n; i++){
        if(used[i] == false) cout << i << endl;
    }
    return 0;
}
