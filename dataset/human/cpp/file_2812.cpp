#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool zero = false;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i] == 0){
            zero = true;
        }
    }

    long long abs_sum = 0;
    for(int i=0;i<n;i++){
        abs_sum += abs(a[i]);
    }

    if(zero){
        cout << abs_sum << endl;
        return 0;
    }

    vector<int> neg_accum(n+1, 0);
    for(int i=0;i<n;i++){
        neg_accum[i+1] = neg_accum[i] + (a[i]<0?1:0);
    }
    long long maxx = 0;
    for(int i=0;i<n;i++){
        int neg_num = (neg_accum[i] % 2) + ((neg_accum[n] - neg_accum[i+1]) % 2) + (a[i] < 0 ? 1: 0);
        if(neg_num % 2 == 0){
            maxx = abs_sum;
        }
        else{
            maxx = max(maxx, abs_sum - 2 * abs(a[i]));
        }
    }
    cout << maxx << endl;
    return 0;
}
