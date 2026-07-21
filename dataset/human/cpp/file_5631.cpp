#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=60;

template<int char_size>
struct Trie{
    struct TrieNode{
        char c; int dep;
        vector<int> nxt,idxs;
        TrieNode(char c,int dep):c(c),dep(dep),nxt(char_size,-1){}
    };
    vector<TrieNode> Nodes;
    function<int(char)> ctoi;
    Trie(function<int(char)> ctoi):ctoi(ctoi){
        Nodes.emplace_back('$',0);
    }
    inline int &next(int node,int c){
        return Nodes[node].nxt[c];
    }
    inline int &next(int node,char c){
        return next(node,ctoi(c));
    }
    void add(const string &s,int x){
        int node=0;
        for (int i=0;i<s.size();++i){
            int k=ctoi(s[i]);
            if (next(node,k)<0){
                next(node,k)=Nodes.size();
                Nodes.emplace_back(s[i],i+1);
            }
            node=next(node,k);
        }
        Nodes[node].idxs.emplace_back(x);
    }
    int find(const string &s){
        int node=0;
        for (int i=0;i<s.size();++i){
            int k=ctoi(s[i]);
            if (next(node,k)<0) return -1;
            node=next(node,k);
        }
        return node;
    }
    template<typename F>
    void query(const string &s,const F &f,int l){
        int node=0;
        for (int i=l;i<s.size();++i){
            node=next(node,s[i]);
            if (node<0) return;
            for (auto &idx:Nodes[node].idxs) f(idx);
        }
    }
    int size(){return Nodes.size();};
    vector<int> idxs(int node){return Nodes[node].idxs;}
    int ch(int node){
        int res=0;
        if (~next(node,0)) res|=1<<0;
        if (~next(node,1)) res|=1<<1;
        return (res==1||res==2);
    }
    int dep(int node){return Nodes[node].dep;}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; ll L; cin >> N >> L;
    vector<string> S(N);
    for (int i=0;i<N;++i) cin >> S[i];
    Trie<2> trie([](char c){return c-'0';});
    for (int i=0;i<N;++i) trie.add(S[i],i);
    ll G=0,s=trie.size();
    for (int i=0;i<s;++i) if (trie.ch(i)){
        ll d=L-trie.dep(i),grundy;
        for (int i=MAX;i>=0;--i)
            if (d&1LL<<i) grundy=1LL<<i;
        G^=grundy;
    }
    cout << (G?"Alice":"Bob") << '\n';
}
