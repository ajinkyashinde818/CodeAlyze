#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int g[N];

int n;
vector<int> V[N];

void init(){
    memset(g, -1, sizeof(g));
    long long s = 0;
    for(int i=1; ;i++){
        s = s + i;
        if(s >= N)  break;
        g[s] = i;
    }
}

void solve(int stg, int base, int num){
    if(num == 0){
        return;
    }
    for(int i=0; i<num; i++){
        V[stg].push_back(base + i);
        V[stg+1+i].push_back(base + i);
    }
    solve(stg+1, base + num, num - 1);
}

int main(){
    init();
    while(~scanf("%d", &n)){
        if(g[n] != -1){
            puts("Yes");
            printf("%d\n", g[n]+1);
            solve(0, 1, g[n]);
            for(int i=0; i<=g[n]; i++){
                printf("%d", V[i].size());
                for(int j=0; j<V[i].size(); j++){
                    printf(" %d", V[i][j]);
                }
                puts("");
                V[i].clear();
            }
        } else {
            puts("No");
        }
    }
	return 0;
}
