#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

const int INF = numeric_limits<int>::max() / 2;

template<typename T>
T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    int n;
    cin >> n;
    vector<long long> plus, minus;
    for(int i = 0; i < n; i++){
        long long a;
        cin >> a;
        if(a > 0) plus.push_back(a);
        else minus.push_back(a);
    }
    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end(), greater<long long>());

    long long ans = 0;
    if(minus.size() == 0){
        for(long long a: plus) ans += a;
    }else if(minus.size() % 2 == 0){
        for(long long a: plus) ans += a;
        for(long long a: minus) ans += -1 * a;
    }else{
        if(plus.size() == 0){
            for(long long a: minus) ans += -1 * a;
            ans += 2 * minus[0];
        }else{
            for(long long a: plus) ans += a;
            for(long long a: minus) ans += -1 * a;
            ans -= 2 * min(plus[0], -1 * minus[0]);
        }
    }
    cout << ans << endl;
    
}
