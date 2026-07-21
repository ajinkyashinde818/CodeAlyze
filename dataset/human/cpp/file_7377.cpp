#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
#include <math.h>
using namespace std;

int main(void){
    long long n, a[200020];
    long long sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    long long min = 1e18, k = sum;
    for (int i = 1; i < n; i++) {
        sum -= a[i - 1];
        if (min > abs(2 * sum - k)) min = abs(2 * sum - k);
    }
    cout << min << endl;
}
