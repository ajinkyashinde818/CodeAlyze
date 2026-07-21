#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> a(n);
    long long minus_cnt = 0;
    for(long long i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < 0){
            minus_cnt++;
        }
    }

    long long ans = 0;
    if(minus_cnt % 2 == 0){
        for(long long i = 0; i < n; i++) ans += abs(a[i]);
    }
    else{
        long long minv = 1e15;
        for(long long i = 0; i < n; i++) minv = min(minv, abs(a[i])), ans += abs(a[i]);
        ans -= 2*minv;
    }
    cout << ans << endl;
    return 0;
}
