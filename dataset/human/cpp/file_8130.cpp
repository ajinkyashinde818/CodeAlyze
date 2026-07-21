#include <bits/stdc++.h>
using namespace std;

int main(void){

    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    vector<long long> sums1(n);
    sums1[0] = a[0];
    for(int i=1; i<n; i++) {
        sums1[i] = a[i] + sums1[i-1];
    }
    
    vector<long long> sums2(n);
    sums2[n-1] = a[n-1];
    for(int i=n-2; i>=0; i--) {
        sums2[i] = a[i] + sums2[i+1];
    }
    
    long long min = 9999999999;
    for(int i=0; i<n-1; i++) {
        long long delta = sums1[i]-sums2[i+1] > 0 ? sums1[i]-sums2[i+1] : -(sums1[i]-sums2[i+1]);
        if(min > delta) min = delta;
    }
    
    cout << min << endl;
    
    return 0;
}
