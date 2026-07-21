#include <bits/stdc++.h>
using namespace std;

int grundy[205][105];

// calculate grundy
int solve(int w, int b){
    if(w==0 && b==0) return 0;
    if(grundy[w][b] != -1) return grundy[w][b];
    set<int> S;
    if(w > 0) S.insert(solve(w-1, b));
    if(b > 0) S.insert(solve(w+1, b-1));
    for(int i=1;i<=min(b,w);i++){
        S.insert(solve(w,b-i));
    }
    int res = 0;
    while(S.count(res)) res++;
    return grundy[w][b] = res;
}

int main() {
    for(int i=0;i<=200;i++) fill(grundy[i], grundy[i]+101, -1);
    int N, X = 0;
    cin >> N;
    for(int i=0;i<N;i++){
        int w, b;
        cin >> w >> b;
        X ^= solve(w, b);
    }
    cout << (X == 0) << endl;
    return 0;
}
