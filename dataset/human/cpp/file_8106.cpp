#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    long long a[N];
    long long sunuke = 0;
    long long arai = 0;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        arai += a[i];
    }
    long long ans = INFINITY;
    for(int i = 0; i < N-1; i++){
        sunuke += a[i];
        arai -= a[i];
        ans = min(abs(sunuke - arai), ans);
    }
    cout << ans << endl;
    return 0;
}
