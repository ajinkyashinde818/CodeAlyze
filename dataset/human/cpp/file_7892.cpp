#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int N; cin >> N;
    long long arr[N+1];
    for(int i=0; i<N+1; ++i) arr[i]=0;
    for(int i=0; i<N; ++i){
        long long a; cin >> a;
        arr[i+1] = arr[i]+a;
    }
    long long ans=10000000000;
    for(int i=1; i<N; ++i){
        ans = min(ans, abs(arr[N]-2*arr[i]));
    }
    cout << ans << endl;
    return 0;
}
