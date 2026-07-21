#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct rooted_tree{
    vector<int> parent;
    vector<vector<int> > children;
    vector<int> depth;
    vector<vector<int> > dbl;
    int root;
    int n, logn;
    
    rooted_tree(int n, int r = 0):n(n){
        parent.resize(n);
        children.resize(n);
        depth = vector<int>(n, 0);
        dbl = vector<vector<int> >(n, vector<int>(log2(n)+2, -1));
        root = r;
        logn = log2(n)+2;
    }
    
    void makeDepthTable(int v = 0){
        for(auto i : children[v]){
            depth[i] = depth[v] +1;
            makeDepthTable(i);
        }
    }
    
    void makeDoublingTable(){
        for(int i=0; i<n; i++){
            dbl[i][0] = parent[i];
        }
        for(int i=0; i+1<logn; i++){
            for(int j=0; j<n; j++){
                if(dbl[j][i] != -1){
                    dbl[j][i+1] = dbl[dbl[j][i]][i];
                }
            }
        }
    }
    
    int lca(int a, int b){
        if(depth[a] < depth[b]) swap(a,b);
        while(depth[a] != depth[b]){
            for(int i=0, sqi=2; i<logn; i++, sqi*=2){
                if(depth[a] -sqi < depth[b]){
                    a = dbl[a][i];
                    break;
                }
            }
        }
        if(a==b) return a;
        for(int i=logn-1; i>=0; i--){
            if(dbl[a][i] != dbl[b][i]){
                return lca(dbl[a][i], dbl[b][i]);
            }
        }
        return lca(dbl[a][0], dbl[b][0]);;
    }
};

int main(){
    int n;
    cin >> n;
    rooted_tree t(n);
    for(int i=1; i<n; i++){
        int p;
        cin >> p;
        p--;
        t.parent[i] = p;
        t.children[p].push_back(i);
    }
    t.makeDepthTable();
    t.makeDoublingTable();

    queue<int> wait;
    wait.push(0);
    int prev = 0;
    long long int ans = 0;
    while(!wait.empty()){
        int curr = wait.front();
        wait.pop();
        ans += t.depth[prev] +t.depth[curr] -2*t.depth[t.lca(prev, curr)];
        for(int i=0; i<(int)t.children[curr].size(); i++){
            wait.push(t.children[curr][i]);
        }
        prev = curr;
    }
    cout << ans << endl;
    return 0;
}
