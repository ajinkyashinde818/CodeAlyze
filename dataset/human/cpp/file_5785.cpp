#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

int N;
int64_t L;
vector<string> s;
constexpr int64_t M = 2000010;
using P = pair<int, int>;
vector<vector<int64_t>> pool;
int64_t ans = 0;

int64_t g(int64_t depth){
    int64_t n = 1;
    int64_t m = n;
    while(true){
        if(depth % n == 0) m = n;
        n *= 2;
        if(n > depth) break;
    }
    return m;
}

void dfs(int64_t a, int64_t d){
    if(pool[a][0] == -1 && pool[a][1] == -1) return;
    if(pool[a][0] != -1){
        if(pool[a][1] == -1){
            ans ^= g(L - d);
        }
        dfs(pool[a][0], d + 1);
    }
    if(pool[a][1] != -1){
        if(pool[a][0] == -1){
            ans ^= g(L - d);
        }
        dfs(pool[a][1], d + 1);
    }
}

int main(){
    cin >> N >> L;
    
    s.resize(N);
    pool.resize(M, vector<int64_t>(2));
    for(int i = 0; i < M; ++i){
        pool[i][0] = -1;
        pool[i][1] = -1;
    }

    int64_t m = 1;
    for(int i = 0; i < N; ++i){
        cin >> s[i];
        int64_t v = 0;
        for(auto c : s[i]){
            int a = int(c - '0');
            if(pool[v][a] == -1){
                pool[v][a] = m++;
            }
            v = pool[v][a];
        }
    }
    dfs(0, 0);
    cout << (ans != 0 ? "Alice" : "Bob") << endl;
}
