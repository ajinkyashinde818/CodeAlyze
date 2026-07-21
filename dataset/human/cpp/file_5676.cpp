#include <bits/stdc++.h>
using namespace std;
 
using tpl = tuple<char, int>;
typedef pair<int,int> pii;
typedef long long ll;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

/*
  Trieを管理するクラス
  現在の実装では、小文字のみ含む文字列にだけ対応している
  大文字や、他のアスキー文字に対応させたい場合は、
  childrenの配列サイズを大きくとれば良い
  機能:
  addで文字列をtrieに追加していく
  各文字ノードの個数や、各ノードの子孫のノードの数をO(1)で数え上げることができる
  また、ある文字列が存在するかをfindで検索することができる
  デストラクタでメモリが自動的に解法される
 */
class Trie{
public:
    // Trieのノード
    // self_char:自身のchar(-1の場合、root)
    // children:次の文字ノードへのポインタ
    // sum_of_descendant_and_self:現在のノードの子孫の合計ノード数
    struct node_t{
        char self_char;
        int sum_of_descendant;
        node_t *children[26];
        node_t(char node_char){
            self_char=node_char;
            sum_of_descendant=0;
            for(int i=0;i<26;i++)children[i]=NULL;
        }
        node_t(){
            self_char=-1;
            sum_of_descendant=0;
            for(int i=0;i<26;i++)children[i]=NULL;
        }
    };
    Trie(){
        root=new node_t();
        for(int i=0;i<(int)(sizeof(nodes_sum)/sizeof(nodes_sum[0]));i++)
            nodes_sum[i]=0;
    }
    // trieを消去
    ~Trie(){
        _del(root);
    }
    // trieにstringを追加
    void add(const string &str){
        _add(str,0,root);
    }
    // 文字列がtrie中に存在するか検索
    // 末尾まで辿れなくても発見したものとみなす
    bool find(const string &str){
        return _find(str,0,root);
    }
private:
    bool _find(const string &str,int str_pos,node_t *cur){
        if(str_pos==(int)str.size())return true;
        else{
            node_t *nxt=cur->children[str[str_pos]-'0'];
            if(nxt==NULL)return false;
            else return _find(str,str_pos+1,nxt);
        }
    }
    void _del(node_t *cur){
        if(cur==NULL)return;
        for(int i=0;i<26;i++)
            _del(cur->children[i]);
        delete cur;
    }
    // trieにstringを追加
    int _add(const string &str,int str_pos,node_t *cur){
        if(str_pos==(int)str.size())return cur->sum_of_descendant+1;
        else{
            int prv_sum=0;
            if(cur->children[str[str_pos]-'0']==NULL){
                cur->children[str[str_pos]-'0']=new node_t(str[str_pos]);
                nodes_sum[str[str_pos]-'0']++;
            }
            else
                prv_sum=cur->children[str[str_pos]-'0']->sum_of_descendant+1;
            cur->sum_of_descendant-=prv_sum;
            int cur_sum=_add(str,str_pos+1,cur->children[str[str_pos]-'0']);
            cur->sum_of_descendant+=cur_sum;
            return cur->sum_of_descendant+1;
        }
    }
public:
    // Trieのroot
    node_t *root;
    // 文字ごとのノード数
    int nodes_sum[26];
};


int N;
ll L;
string ss[100010];
ll dp[100010];


ll grundy2(ll n){
    ll ans = 1;
    while(n % 2 == 0){
        n /= 2;
        ans *= 2;
    }
    return ans;
}

void rec(Trie::node_t *node, ll depth, multiset<ll> &s){
    int ch_cnt = 0;
    for(int i = 0; i < 2; i++){
        if(node->children[i] != NULL){
            ch_cnt++;
            if(depth -1 > 0){
                rec(node->children[i], depth - 1, s);
            }
        }
    }
    if(ch_cnt == 1) s.insert(depth);
}

int main(){

    cin >> N >> L;
    for(int i = 0; i < N; i++) cin >> ss[i];
    // trieを作る
    Trie trie;
    for(int i = 0; i < N; i++){
        trie.add(ss[i]);
    }

    multiset<ll> s;
    rec(trie.root, L, s);

    ll ans = 0;
    for(auto n : s){
        ans ^= grundy2(n);
    }

    if(ans != 0){
        cout << "Alice"<< endl;
    }
    else {
        cout << "Bob" << endl;
    }
    

    return 0;
}
