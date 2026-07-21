#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

using i64 = int64_t;

int n,m;

int main() {
    cin >> n >> m;
    vector<int> used(n+10,0);
    vector<int> in(m);
    for(int i=0;i<m;i++) cin >> in[i];
    for(int i=m-1;i>=0;i--){
        if(used[in[i]]==1) continue;
        cout << in[i] << endl;
        used[in[i]] = 1;
        //cout << "used " << in[i] << " " << used[in[i]] << endl;
    }
    //for(int i=1;i<=n;i++) cout << i << " " << used[i] << endl;
    for(int i=1;i<=n;i++){
        if(!used[i]) cout << i << endl;
    }

    return 0;
}
