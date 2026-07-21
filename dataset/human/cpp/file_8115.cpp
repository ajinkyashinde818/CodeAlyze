#include <iostream>
#include <algorithm>
#include <string>
#include <functional> 
#include <vector>
#include <numeric>
#include <stack>
#include <queue>
#include <utility>
//#include <cmath>
#include <cstdlib>

using namespace std;

int main(){

    int n;
    cin >> n ;
    long long a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    long long minmum = 100000000000000000;
    long long sum = 0LL,sub =0LL;
    for(int i=0;i<n;i++) sum += a[i];
    for(int i=0 ; i < n-1 ;i++){
        sub += a[i];
        minmum = min(minmum,abs(sum-sub*2));
    }
    cout << minmum;
    return 0;
}
