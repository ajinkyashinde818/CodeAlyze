#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
char s[100005];

LL L;
int n, l;
struct trie{
    trie *nt[2];
    bool ok;
    trie(){
        nt[0] = nt[1] = NULL;
        ok = 0;
    }
};

trie *root = new trie();

void add(trie *cur, int i){
    if(i == l+1){
        cur->ok = 1;
    }
    else{
        int c = s[i]-'0';
        if(cur->nt[c] == NULL) cur->nt[c] = new trie();
        add(cur->nt[c], i+1);
    }
}
LL ans = 0;
void dfs(trie *cur, int j){
    if(cur->ok) return;
    for(int i=0;i<2;i++){
        if(cur->nt[i] == NULL){
            LL v = L+1-j, mul = 1;
            for(int j=0;j<60;j++){
                if((v>>j)&1) break;
                mul *= 2;
            }

            ans ^= mul;
        }
        else dfs(cur->nt[i], j+1);
    }
}

int main(){
    scanf("%d%lld", &n, &L);   
    for(int i=1;i<=n;i++){
        scanf("%s", s+1);
        l = strlen(s+1);
        add(root, 1);
    }
    dfs(root, 1);
    if(ans == 0) printf("Bob\n");
    else printf("Alice\n");
}
