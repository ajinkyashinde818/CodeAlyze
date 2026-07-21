#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
    LL N;
    cin >> N;
    vector<LL>  a(N), b(N);
    for(int i = 0;i < N;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    LL ans1 = 0;
    for(int i = 0;i < N-1;i++){
        if(b[i] < 0){
            b[i] *= -1;
            b[i+1] *= -1;
        }
        ans1 += b[i];
    }
    ans1 += b[N-1];
    LL ans2 = 0;
    for(int i = 0;i < N;i++)    ans2 += abs(a[i]);
    LL m = 1e10;
    for(int i = 0;i < N;i++)    m = min(m, abs(a[i]));
    ans2 -= m*2;
    cout << max(ans1, ans2) << endl;
}
