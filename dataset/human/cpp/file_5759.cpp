#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
long long xo = 0;
long long L;
int N;
struct Trie{
  Trie *f[2];
  Trie(){
     memset(f,0,sizeof(f));
  }
}*T;
void ins(Trie *T,string &s,int pos){
   if(pos == (int)s.size()){
      return ;
   }
   if(T->f[s[pos] - '0'] == NULL){
      T->f[s[pos] - '0'] = new Trie;
   }
   ins(T->f[s[pos] - '0'],s,pos + 1);
}
long long get(long long val){
   int rez = 0;
   while(! (val & 1)){
      val >>= 1;
      rez++;
   }
   return 1LL << rez;
}
void dfs(Trie * T,int lvl){
   int nrfi = 0;
   if(T->f[0] != NULL){
      nrfi++;
      dfs(T->f[0],lvl + 1);
   }
   if(T->f[1] != NULL){
      nrfi++;
      dfs(T->f[1],lvl + 1);
   }
   if(nrfi ==  1){
      xo ^= get(L - lvl);
   }
}
int main() {
    T = new Trie;
    cin >> N >> L;
    for(int i = 1;i <= N;i++){
       string a;
       cin >> a;
       ins(T,a,0);
    }
    dfs(T,0);
    cout << (xo == 0 ? "Bob" : "Alice");
    return 0;
}
