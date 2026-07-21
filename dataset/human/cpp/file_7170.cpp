#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long>m(n);
    vector<long long>a(n);
    long long tmp, sum=0;
    for(int i=0; i<n; i++){
        cin >> tmp;
        m[i]=tmp;
        sum += tmp;
        a[i] = sum;
    }
    
    long long ans = 1e15;
    for(int i=0; i<n-1; i++){
        ans = min(ans, abs(a[i]-(sum-a[i])) );
    }
    cout << ans << endl;
    return 0;
}
