#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int val = 0, den = 1;
    string s;
    cin >> s;
    int f = 0;
    for (auto &&i : s) {
        if(!f){
            if(i == '.') f++;
            else {
                val = val*10+i-'0';
            }
        }else {
            if(i == '(') break;
            val = val*10+i-'0';
            den = den*10;
        }
    }
    f = 0;
    int val2 = 0, den2 = den;
    for (auto &&i : s) {
        if(!f){
            if(i == '(') f++;
        }else {
            if(i == ')') break;
            val2 = val2*10+i-'0';
            den2 = den2*10;
        }
    }
    if(den2 != den){
        den2 -= den;
        int g = __gcd(den, den2);
        val *= den2/g; val += val2*(den/g);
        den *= (den2/g);
    }
    int g = __gcd(val, den);
    val /= g; den /= g;
    cout << val << "/" <<  den << "\n";
    return 0;
}
