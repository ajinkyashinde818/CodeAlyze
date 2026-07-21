#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>

using namespace std;
//DP用
template<class T> inline bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
const long long INF = 1LL << 60;

long long gcd (long long a,long long b) {
    if(a % b == 0) {
        return b;
    }else {
        return (gcd(b,a%b));
    }
}

int main() {
    int  n,r;
    cin >> n >> r;
    if(n >= 10) {
        cout << r;
        return 0;
    }else {
        cout << r+100*(10-n);
        return 0;
    }
}
