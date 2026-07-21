#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<ll, ll, ll> T;

int N, M;
vector<string> a, b;

int main(void){
    
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i){ string s; cin >> s; a.push_back(s); }
    for(int i = 0; i < M; ++i){ string s; cin >> s; b.push_back(s); }
    
    for(int i = 0; i <= N - M; ++i){
        for(int j = 0; j <= N - M; ++j){
            vector<string> v;
            for(int y = 0; y < M; ++y){
                string s;
                for(int x = 0; x < M; ++x) s.push_back(a[i + y][j + x]);
                v.push_back(s);
            }
            if(v == b){ printf("Yes\n"); return 0; }
        }
    }
    printf("No\n");
    
    return 0;
}
