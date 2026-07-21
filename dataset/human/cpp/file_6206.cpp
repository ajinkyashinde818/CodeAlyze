#include<iostream>

using namespace std;

typedef long long int lld;

lld n, c, x[100000], v[100000], cw[100001], ccw[100001], mcw[100001], mccw[100001], rst;

int main() {
    cin >> n >> c;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> v[i];
    
    for(int i = 1; i <= n; i++) {
        cw[i] = cw[i-1] + v[i-1];
        ccw[i] = ccw[i-1] + v[n-i];
    }
    for(int i = 1; i <= n; i++) {
        cw[i] -= x[i-1];
        ccw[i] -= c - x[n-i];
    }
    
    for(int i = 1; i <= n; i++) {
        mcw[i] = max(mcw[i-1], cw[i]);
        mccw[i] = max(mccw[i-1], ccw[i]);
        //cout << mcw[i] << ' ' << mccw[i] << endl;
    }
    
    rst = max((lld)0, max(mcw[n], mccw[n]));
    //cout << rst << endl;
    
    for(int i = 1; i <= n; i++) {
        rst = max(rst, mccw[n-i] + cw[i] - x[i-1]);
        //cout << mccw[n-i] + cw[i] - x[i-1] << ' ';
        rst = max(rst, mcw[n-i] + ccw[i] - c + x[n-i]);
        //cout << mcw[n-i] + ccw[i] - c + x[n-i] << endl;
    }
    cout << rst;
    return 0;
}
