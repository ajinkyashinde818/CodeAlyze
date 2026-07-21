#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<long long>;
using pll = pair<long long, long long>;
#define rep(i,n) for(long long i(0);(i)<(n);(i)++)


void solve(long long R, long long G, long long B, long long N){
    ll cnt = 0;
    for(ll r=0; r*R<= N; r++){
        for(ll g=0; (g*G+r*R)<= N; g++){
            ll tmp = N - r*R - g*G;
            if(tmp % B == 0)
                cnt ++;
        }
    }

    cout << cnt << endl;
}

int main(){
    long long R;
    scanf("%lld",&R);
    long long G;
    scanf("%lld",&G);
    long long B;
    scanf("%lld",&B);
    long long N;
    scanf("%lld",&N);
    solve(R, G, B, N);
    return 0;
}
