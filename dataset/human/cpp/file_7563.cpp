#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <utility>
#include <map>
#include <set>
#include <ios>
#include <iomanip>
#include <functional>
#include <queue>

#define int long long

int inf = (1LL <<  62);

using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<int> v;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        sum += x;
        v.push_back(x);
    }
    vector<int> ans;
    int a = 0;
    for(int i = 0; i <= n - 2; i++){
        a += v[i];
        int x = abs(sum  -  a * 2);
        ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    cout << ans[0];
}
