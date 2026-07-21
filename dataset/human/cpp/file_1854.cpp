#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<int> e(m);
    vector<pair<int,int>> num;
    for (int i=0;i<n;++i)
        num.emplace_back(i+1,i+1);
    for (int i=0;i<m;++i){
        int e; cin >> e;
        num[--e].first=-i;
    }
    sort(num.begin(),num.end());
    for (int i=0;i<n;++i) cout << num[i].second << '\n';
}
