#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct node{
    int c0 = -1, c1 = -1;
    int depth;
    bool dead = false;
    node(int d) : depth(d) {}
};

vector<node> nodes;
string s;

void grow_tree(int v, int p){
    nodes[v].dead = true;
    if(p == s.size()) return;
    if(nodes[v].c0 == -1){
        nodes.emplace_back(nodes[v].depth + 1);
        nodes.emplace_back(nodes[v].depth + 1);
        int c0 = nodes.size() - 2, c1 = nodes.size() - 1;
        nodes[v].c0 = c0;
        nodes[v].c1 = c1;
    }
    grow_tree(s[p] == '0' ? nodes[v].c0 : nodes[v].c1, p + 1);
}

ll grundy(ll h){
    ll p = 1;
    while(h % (p * 2) == 0) p *= 2;
    return p;
}

ll dfs(int v, ll h){
    if(!nodes[v].dead){
        return grundy(h);
    }
    if(nodes[v].c0 == -1){
        return 0;
    }
    ll ret = 0;
    ret ^= dfs(nodes[v].c0, h - 1);
    ret ^= dfs(nodes[v].c1, h - 1);
    return ret;
}

int main(){
    ll N, L;
    cin >> N >> L;

    nodes.emplace_back(0);
    for(int i=0;i<N;i++){
        cin >> s;
        grow_tree(0, 0);
    }

    if(dfs(0, L + 1)) cout << "Alice" << endl;
    else cout << "Bob" << endl;

    return 0;
}
