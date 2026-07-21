#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<limits>
#include<bitset>
#include<functional>
#include<type_traits>
#include<queue>
#include<stack>
#include<array>
#include<random>
#include<utility>
#include<cstdlib>
#include<ctime>
#include <numeric>
#include <stdio.h>
using namespace std;

int main() {
    int n, r;
    int ans;
    cin >> n >> r;
    if ( n <= 9) {
        ans = r + 100 * (10 -n);
    } else
    {
        ans = r;
    }
    cout << ans << endl;
    return 0;
    
}
