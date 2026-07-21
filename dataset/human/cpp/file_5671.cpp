#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

struct node{
    char val;
    int depth;
    vector<node> next;
};

node* getNode(node &cur, char c){
    for(int i = 0; i < cur.next.size(); i++){
        if(cur.next[i].val == c) return &(cur.next[i]);
    }
}

bool hasChar(node &cur, char c){
    for(int i = 0; i < cur.next.size(); i++){
        if(cur.next[i].val == c) return true;
    }
    return false;
}

int cnt;
vector<node> v;

void addNode(node &cur, char c){
    node n;
    cnt++;
    n.depth = cur.depth+1;
    n.val = c;
    cur.next.push_back(n);
}

ll L;
ll xo;

void dfs(node &cur){
    int s = cur.next.size();
    if(s == 1){
        for(int i = 0; i <= 62; i++){
            if(L-cur.depth & ((ll)1<<i)){
                xo ^= ((ll)1<<i);
                break;
            }
        }
    } 
    for(int i = 0; i < s; i++){
        dfs(cur.next[i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int N;
    cin >> N >> L;
    node root;
    root.depth = 0;
    root.val = '0';
    for(int i = 0; i  < N; i++){
        node* cur = &root;
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            if(hasChar(*cur, s[j])){
                cur = getNode(*cur, s[j]);
            }else{
                addNode(*cur, s[j]);
                cur = getNode(*cur, s[j]);
            }
        }
    }
    dfs(root);
    if(xo == 0){
        cout << "Bob" << endl;
    }else{
        cout << "Alice" << endl;
    }
}
