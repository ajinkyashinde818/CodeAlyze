#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX;
const ll MOD = 1e9+7;

struct Trie {
  int depth;
  int children_size;
  Trie *next[0x100];
  Trie():depth(-1),children_size(0) { fill(next, next+0x100, (Trie*)0); }
  Trie(int d):depth(d),children_size(0) { fill(next, next+0x100, (Trie*)0); }
};
Trie *find(string t, Trie *r) {
  for (int i = 0; i<t.length(); ++i) {
    char c = t[i];
    if (!r->next[c]){
      r->next[c] = new Trie(i);
      r->children_size++;
    }
    r = r->next[c];
  }
  return r;
}

ll dfs(ll &L,Trie* node){
  if(node->children_size==0) return 0;
  ll ret=0;
  if(node->children_size==1){
    ll height = L-node->depth-1;
    ret ^= (-height)&height;
  }
  if(node->next['0']!=NULL){
    ret ^= dfs(L,node->next['0']);
  }
  if(node->next['1']!=NULL){
    ret ^= dfs(L,node->next['1']);
  }
  return ret;
}

int main() {
  ll N,L;cin >> N >> L;
  Trie* root = new Trie();
  repeat(i,N){
    string s;
    cin >> s;
    find(s,root);
  }
  cout <<(dfs(L,root)==0? "Bob":"Alice") << endl;
  return 0;
}
