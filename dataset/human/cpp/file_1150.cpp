#include<bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long R, G, B, N;
    cin >> R >> G >> B >> N;
    unsigned long ans{0};
    for(unsigned long i = 0; i * R <= N; ++i){
        for(unsigned long j = 0; i * R + j * G <= N; ++j){
            unsigned long k = N - (i * R + j * G);
            if(!(k % B))++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
