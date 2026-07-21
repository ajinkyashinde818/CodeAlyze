#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1LL<<50;

int main(void){
    
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    long long allSum = std::accumulate(a.begin(), a.end(), 0LL); 
    
    long long ans = INF;
    long long snuke = 0;
    
    for (int i = 0; i < n-1; i++){
        snuke += a[i];
        long long arai = allSum - snuke;
        
        ans = min(ans, abs(snuke-arai));
    }
    cout << ans << endl;
}
