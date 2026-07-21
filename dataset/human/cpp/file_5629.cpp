#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
using namespace std;

int n;

const int maxn = 1e6 + 5;

int trie[maxn][2];
char s[maxn];
long long L;
int tot;
bool vis[maxn];
void insert(char *str, int len){
    int cur = 0;
    for(int i = 0;i < len;i++){
        int ch = str[i] - '0'; 
        if(trie[cur][ch] == -1){
            trie[cur][ch] = ++tot;
            memset(trie[tot], -1, sizeof(trie[tot]));
        }
        cur = trie[cur][ch];
    }
    vis[tot] = true;
}

long long dfs(int u, long long depth){
    //cout << u << " " << depth << endl;
    if(u == -1){
        long long tmp = L + 1 - depth;
        return (tmp & (-tmp));
    }
    if(vis[u]){
        return 0;
    } 
    long long ans = 0;
    ans ^= dfs(trie[u][0], depth + 1);
    ans ^= dfs(trie[u][1], depth + 1);
    return ans;
}


int main(){
    cin >> n >> L;
    tot = 0;
    memset(trie[tot], -1, sizeof(trie[tot]));
    memset(vis, false, sizeof(vis));
    for(int i = 1;i <= n;i++){
        scanf("%s", s);
        int len = strlen(s);
        insert(s, len);
    }
    long long res = dfs(0, 0);
    if(res != 0){
        cout << "Alice" << endl;
    }else{
        cout << "Bob" << endl;
    }
    return 0;
}
