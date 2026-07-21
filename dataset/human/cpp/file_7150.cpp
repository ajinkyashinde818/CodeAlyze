#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
using namespace std;
typedef long long ll;

int main(){

    int n; cin >> n;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    ll sumleft[n], sumright[n];
    sumleft[0] = a[0];
    for(int i=1; i<n; i++){
        sumleft[i] = sumleft[i-1] + a[i];
        // cout << sumleft[0] << endl;
    }

    sumright[n-1] = 0;
    for(int i=n-2; i>=0; i--){
        sumright[i] = sumright[i+1] + a[i+1];
        // cout << sumright[0] << endl;
    } 

    ll vmin = 1e18;
    for(int i=0; i<n-1; i++){
        vmin = min(vmin, abs(sumleft[i] - sumright[i]));
    }

    cout << vmin;

    return 0;
}
