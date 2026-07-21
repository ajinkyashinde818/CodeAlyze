#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;

int main(){
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    // cumulative sum
    for(int i=1; i<n; i++){
        a[i] += a[i-1];
    }

    long long int diff = INF;
    for(int i=0; i<n-1; i++){
        if(diff > abs(a[n-1] - 2 * a[i])) diff = abs(a[n-1] - 2 * a[i]);
    }
    cout << diff << endl;
    return 0;
}
