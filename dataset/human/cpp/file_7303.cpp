#include<iostream>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    long long a[200000], s = 0, ss = 0, absmin = INT_MAX;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    for(int i = 0; i < n-1; i++){
        ss += a[i];
        absmin = min(absmin, abs(s - (2 * ss)));
    }
    cout << absmin << endl;
    return 0;
}
