#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
vector<int> adj[MAX];
bool vis[MAX];
void dfs(int src){
    vis[src] = true;
    for(int nxt: adj[src]){
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    int val = 0;
    for(int i = 0; i < n; i++) cin >> a[i], val ^= a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    vector<int> check_a, check_b;
    for(int i = 0; i < n; i++) check_a.push_back(a[i]);
    check_a.push_back(val);
    for(int i = 0; i < n; i++) check_b.push_back(b[i]);
    sort(check_a.begin(), check_a.end());
    sort(check_b.begin(), check_b.end());
    int it1 = 0, it2 = 0;
    int skip = -1;
    while(it1 != n + 1 && it2 != n){
        while(it1 <= n && check_a[it1] != check_b[it2]) skip = check_a[it1], it1++;
        if(it1 == n + 1 || check_a[it1] != check_b[it2]) break;
        it1++, it2++;
    }
    if(it2 != n){
        cout << -1 << '\n';
        return 0;
    }
    if(skip == -1) skip = check_a.back();
    vector<pair<int, int>> use;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]) continue;
        use.emplace_back(a[i], b[i]);
    }
    use.emplace_back(val, skip);
    if((int) use.size() == 1){
        cout << 0 << '\n';
        return 0;
    }
    reverse(use.begin(), use.end());
    set<int> vert;
    for(auto e: use) vert.insert(e.first), vert.insert(e.second);
    map<int, int> conv;
    int cnt = 0;
    int num = 0;
    for(int x: vert) conv[x] = cnt, cnt++;
    for(int i = 1; i < (int) use.size(); i++){
        auto e = use[i];
        int u = conv[e.first], v = conv[e.second];
        adj[u].push_back(v); adj[v].push_back(u);
        num++;
    }
    int comp = 0;
    for(int i = 0; i < (int) vert.size(); i++){
        if(!vis[i]) dfs(i), comp++;
    }
    cout << (num + comp - 1) << '\n';
    return 0;
}
