#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    long long n; cin >> n;
    long long sum = 0;
    vector<long long> v;
    for(int i = 0; i < n; i++){
        long long a; cin >> a;
        sum += a;
        v.push_back(sum);
    }

    long long ans = 1e18;
    for(int i = 0; i < n - 1; i++){
        ans = min(ans, abs(2*v[i] - sum));
    }
    cout << ans << endl;
}
