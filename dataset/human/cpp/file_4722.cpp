/**
 * Title:
 * Url:
 */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<numeric>
#include<functional>
#include<sstream>
#include<iomanip>

using namespace std;

#define ll long long

int main() {
    int n, r; cin >> n >> r;
    if(n>=10) {
        cout << r << endl;
    } else {
        cout << r + 100*(10-n) << endl;
    }
    return 0;
}
