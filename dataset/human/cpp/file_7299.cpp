#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(false);
	int n;
    cin >> n;
    ll c = 0 , d = 0 , b = 1000000000000000000000000000000000 , a[n];
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
        c += a[i];
    }
    for(int i = 0 ; i < n - 1 ; i++) {
        d += a[i];
        if(i < n) b = min(b , abs(c - d * 2));
    }
    cout << b << endl;
}
