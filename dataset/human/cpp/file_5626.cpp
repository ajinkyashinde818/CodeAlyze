#include <bits/stdc++.h>
using namespace std;

template<typename T, char start='a', int C=26>
struct Trie{
    struct Node{
        vector<int> ch;
        T val;
        Node(){
            val = 0;
            ch.resize(C, -1);
        }
    };

    vector<Node> nodes;

    Trie(){ nodes.push_back(Node()); }

    void update(int nd, T v){
        nodes[nd].val += v;
    }
    
    int add(int nd, int d, const string& S, T v){
        if(int(S.size()) == d){
            update(nd, v);
            return nd;
        }else{
            int c = S[d] - start;
            if(nodes[nd].ch[c] == -1){
                nodes[nd].ch[c] = nodes.size();
                nodes.push_back(Node());
            }
            return add(nodes[nd].ch[c], d+1, S, v);
        }
    }
    int add(const string& S, T v){ return add(0, 0, S, v); }

    int64_t calc(int nd, int64_t d){
        int c0 = nodes[nd].ch[0], c1 = nodes[nd].ch[1];
        int64_t ans = 0;
        if((c0 >= 0) != (c1 >= 0)) ans ^= (d&(-d));
        if(c0 >= 0) ans ^= calc(c0, d-1);
        if(c1 >= 0) ans ^= calc(c1, d-1);
        return ans;
    }
    int64_t calc(int64_t L){ return calc(0, L); }
};

int main(){
    int N;
    int64_t L;
    cin >> N >> L;
    Trie<int, '0', 2> trie;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        trie.add(s, 1);
    }
    int64_t G = trie.calc(L);
    cout << (G ? "Alice" : "Bob") << endl;
}
