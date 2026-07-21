#include<bits/stdc++.h>
using namespace std;

uint_fast64_t N, t, a, b;

int main(){
    scanf("%llu", &N);
    t = (static_cast<uint_fast64_t>(sqrt(8 * N + 1) + 0.0001) - 1) / 2;
    if(N != t * (t + 1) / 2)return 0 & puts("No");
    puts("Yes");
    vector<vector<uint_fast64_t>> tap(t + 1);
    for(size_t i = 0; i < N; ++i){
        tap[a].push_back(i + 1);
        tap[a + b + 1].push_back(i + 1);
        ++a;
        if(a + b + 1 > t){
            a = 0;
            ++b;
        }
    }
    cout << t + 1;
    for(auto i : tap){
        cout << endl << t;
        for(auto j : i){
            cout << " " << j;
        }
    }
    cout << endl;
    return 0;
}
