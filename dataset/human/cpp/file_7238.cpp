#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
using namespace std;

int main(){
    long long n, sum = 0, a;
    cin >> n;
    vector<long long> csum(n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        if(!i){
            csum[i] = a;
            continue;
        }
        csum[i] += csum[i-1] + a;
    }
    long long ans = 1LL<<58;
    for (int i = 0; i < n-1; i++) {
        ans = min(ans, abs(sum - 2*csum[i]));
    }
    cout << ans << endl;
    return 0;
}
