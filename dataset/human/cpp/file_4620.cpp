#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <numeric>
#include <limits>
#include <cmath>
#include <iomanip>
#include <sstream>
 
#define ALL(a)  (a).begin(),(a).end()
 
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll ans = 0;

    ll n, r;
    cin >> n >> r;

    if (n < 10) r += 100 * (10 - n);

    

    cout << r << endl;
}
