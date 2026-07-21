#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    long long int sum = 0;
    for(int i = 0; i < n; i++) sum += a[i];
    long long int snukesum = a[0];
    sum -= a[0];
    long long int ans = abs(sum - snukesum);
    for(int i = 1; i < n-1; i++){
        sum -= a[i];
        snukesum += a[i];
        if(abs(sum - snukesum) < ans) ans = abs(sum - snukesum);
    }
    cout << ans << endl;
    return 0;
}
