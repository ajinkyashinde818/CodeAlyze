#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <climits>
#include <map>
using namespace std;

long long A[2000020];
long long sumx[2000020];
long long sumy[2000020];
int n;

int main() {
    cin >> n;
    for ( long long i = 0; i < n; i++ ) {
        cin >> A[i];
    }
    
    sumx[0] = A[0];
    sumy[n-1] = A[n-1];
    for ( long long i = 1, j = n - 2; i < n; i++, j-- ) {
        sumx[i] = A[i] + sumx[i-1];
        sumy[j] = A[j] + sumy[j+1];
        //cout << sumx[i] << " " << sumy[i] << endl;
    }
    
    unsigned long long mn = (1<<31);
    for ( int i = 0; i < n - 1; i++ ) {
        long long x = sumx[i];
        long long y = sumy[i + 1];
        long long sum = x - y;
        if ( sum < 0 ) sum = -sum;
        //cout << x << " " << y << endl;
        if (sum < mn) mn = sum;
    }

    cout << mn << endl;
    
    return 0;
}
